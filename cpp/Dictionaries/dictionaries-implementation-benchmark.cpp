#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>

#include <stdlib.h>
#include <unistd.h>

class Timer {
 public:

  typedef std::chrono::system_clock clock_type;

  Timer() :start_time_(clock_type::now()) {}

  void reset() { start_time_ = clock_type::now(); }

  long elapsed_ms() { return elapsed_count<std::chrono::milliseconds>(); }
  long elapsed_us() { return elapsed_count<std::chrono::microseconds>(); }
  long elapsed_ns() { return elapsed_count<std::chrono::nanoseconds>(); }
 private:
  std::chrono::time_point<std::chrono::system_clock> start_time_;

  template <typename T>
  inline int elapsed_count() {
    return std::chrono::duration_cast<T>(
        clock_type::now() - start_time_).count();
  }
};

template <typename T>
void RunBench(const std::vector<std::pair<T, T> > &pairs, bool reserve) {
  {
    std::cout << "\nsorted list\n----------" << std::endl;
    Timer timer;
    std::vector<std::pair<T, T> > list = pairs;
    std::sort(list.begin(), list.end());
    std::cout << "create: " << timer.elapsed_ms() << std::endl;

    timer.reset();
    for (const auto &kv : pairs) {
      std::binary_search(
          list.cbegin(), list.cend(), kv,
          [&](const std::pair<T, T> &a,
              const std::pair<T, T> &b) { return a.first < b.first; });
    }
    std::cout << "search: " << timer.elapsed_ms() << std::endl;
  }

  {
    std::cout << "\nmap\n----------" << std::endl;
    Timer timer;
    std::map<T, T> map;
    for (const auto &kv : pairs) {
      map.insert(kv);
    }
    std::cout << "create: " << timer.elapsed_ms() << std::endl;

    timer.reset();
    for (const auto &kv : pairs) {
      map.find(kv.first);
    }
    std::cout << "search: " << timer.elapsed_ms() << std::endl;
  }

  {
    std::cout << "\nhash\n----------" << std::endl;
    Timer timer;
    std::unordered_map<T, T> hash;
    if (reserve) {
      hash.reserve(pairs.size());
    }
    for (const auto &kv : pairs) {
      hash.insert(kv);
    }
    std::cout << "create: " << timer.elapsed_ms() << std::endl;

    timer.reset();
    for (const auto &kv : pairs) {
      hash.find(kv.first);
    }
    std::cout << "search: " << timer.elapsed_ms() << "\n\n";

    std::cout << "bucket count = " << hash.bucket_count() << "\n";
    std::cout << "load factor = " << hash.load_factor() << "\n";
    std::cout << "max load factor = " << hash.max_load_factor() << "\n";
  }
}

int main(int argc, char **argv) {
  int c;
  bool use_string = false;
  bool reserve = false;
  std::size_t num = 1000000;
  while ((c = getopt(argc, argv, "hrsn:")) != -1) {
    switch (c) {
      case 'h':
        std::cout << "usage: " << argv[0] << " [-h] [-r] [-x] [-n num]\n";
        return 0;
        break;
      case 'n':
        num = static_cast<std::size_t>(atoi(optarg));
        break;
      case 'r':
        reserve = true;
        break;
      case 's':
        use_string = true;
        break;
      default:
        std::cout << "usage: " << argv[0] << " [-h] [-r] [-n num]\n";
        return 1;
    }
  }

  std::cout << "generating list with " << num
            << (use_string ? " string " : " integer ")
            << "pairs..." << std::endl;
  std::ifstream urandom("/dev/urandom",
                        std::ifstream::in | std::ifstream::binary);
  Timer gen_timer;

  if (use_string) {
    std::vector<std::pair<std::string, std::string> > pairs;
    if (reserve) {
      pairs.reserve(num);
    }
    char charbuf[16];
    for (std::size_t i = 0; i < num; i++) {
      urandom.read(charbuf, sizeof(charbuf));
      pairs.emplace_back(std::make_pair(std::string(charbuf, 8),
                                        std::string(charbuf + 8, 8)));
    }
    std::cout << "generated in " << gen_timer.elapsed_ms() << " ms\n";
    RunBench<std::string>(pairs, reserve);
  } else {
    std::vector<std::pair<int, int> > pairs;
    if (reserve) {
      pairs.reserve(num);
    }
    char charbuf[sizeof(int)];
    for (std::size_t i = 0; i < num; i++) {
      int key, val;
      urandom.read(charbuf, sizeof(charbuf));
      key = *reinterpret_cast<int*>(charbuf);
      urandom.read(charbuf, sizeof(charbuf));
      val = *reinterpret_cast<int*>(charbuf);
      pairs.emplace_back(std::make_pair(key, val));
    }
    std::cout << "generated in " << gen_timer.elapsed_ms() << " ms\n";
    RunBench<int>(pairs, reserve);
  }

  return 0;
}