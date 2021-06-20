// Reverse the words in a sentence—i.e., “My name is Chris” becomes “Chris is
// name My.” Optimize for time and space.

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <string>

std::string reverse_the_sentence(std::string sentence) {
  std::reverse(sentence.begin(), sentence.end());
  sentence.insert(sentence.end(), ' ');
  int n = sentence.length();

  int j = 0;

  for (int i = 0; i < n; ++i) {
    if (sentence[i] == ' ') {
      std::reverse(sentence.begin() + j, sentence.begin() + i);
      j = i + 1;
    }
  }
  sentence.pop_back();
  return sentence;
}
int main(int argc, const char **argv) {
  std::string sentence = "My name is Chris";
  std::cout << "reverse: " << reverse_the_sentence(sentence) << std::endl;
  return 0;
}