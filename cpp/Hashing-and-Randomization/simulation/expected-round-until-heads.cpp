#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <string>
using namespace std;

class ExpectedRoundSim {
public:
  int coins;
  const string HEADS = "HEAD", TAILS = "TAILS";
  bool coinToss() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0, 1),
                                std::default_random_engine());
    return gen();
  }
  string HeadOrTails() { return (coinToss() ? HEADS : TAILS); }

  int tosses_until_head() {
    int rounds = 0;
    string toss;
    do {
      toss = HeadOrTails();
      rounds += 1;

    } while (toss != HEADS);

    return rounds;
  }
  int tosses_until_tails() {
    int rounds = 0;
    string toss;
    do {
      toss = HeadOrTails();
      rounds += 1;

    } while (toss != TAILS);

    return rounds;
  }
  void run_head_experiment(int n) {
    // std::cout << "Tossing " << n << " coin at random on table" << std::endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int rounds = tosses_until_head();
      //   std::cout << i << " th coin took " << rounds << std::endl;
      sum += rounds;
    }
    std::cout << "Expected number of tosses until head per coin " << sum / n
              << std::endl;
  }
  void run_tail_experiment(int n) {
    // std::cout << "Tossing " << n << " coin at random on table" << std::endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int rounds = tosses_until_head();
      //   std::cout << i << " th coin took " << rounds << std::endl;
      sum += rounds;
    }
    std::cout << "Expected number of tosses until tail per coin " << sum / n
              << std::endl;
  }

  void run_sim() {

    
      run_head_experiment(1000000);
      run_tail_experiment(1000000);
      std::cout << std::endl;
    
  }
};
int main(int argc, const char **argv) {
  ExpectedRoundSim sim_1;
  sim_1.run_sim();
  return 0;
}