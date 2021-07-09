#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;

int main(int argc, const char **argv) {

  map<char, int> weights = {{'A', 2}, {'B', 4}, {'C', 3}, {'D', 1}};

  int wtotal = 0;
  int wrndNr, wrndChoice;
  vector<int> sweights;

  for (auto data : weights) {
    wtotal += data.second;
    sweights.push_back(wtotal);
  }
  map<char, int> results = {};

  for (int i = 0; i < 10000; i++) {
    wrndNr = 0 + (rand() % (wtotal - 0 + 1));
    wrndChoice = lower_bound(sweights.begin(), sweights.end(), wrndNr) -
                 sweights.begin();

    auto it = weights.begin();
    std::advance(it, wrndChoice);
    results[it->first]++;
  }

  for (auto data : results) {
    std::cout << data.first << " : " << data.second << endl;
  }
  return 0;
}
