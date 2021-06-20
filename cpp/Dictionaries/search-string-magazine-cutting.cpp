/*
    QUESTION
    You are given a search string and a magazine. You seek to generate all the
   characters in search string by cutting them out from the magazine. Give an
   algorithm to efficiently determine whether the magazine contains all the
   letters in the search string.
*/
#include <ctype.h>
#include <iostream>
bool contains(std::string search_string, std::string magazine) {
  for (int i = 0; i < search_string.length(); ++i)
    search_string[i] = tolower(search_string[i]);
  for (int i = 0; i < magazine.length(); ++i)
    magazine[i] = tolower(magazine[i]);

  int n = search_string.length(), m = magazine.length();

  if (n > m) {
    return false;
  }

  int charFrequencyMap[26] = {0};

  for (int i = 0; i < n; ++i) {

    if (charFrequencyMap[search_string[i] - 'a']) {
      charFrequencyMap[search_string[i] - 'a']++;
    } else {
      charFrequencyMap[search_string[i] - 'a'] = 1;
    }
  }

  for (int i = 0; i < m; ++i) {
    if (charFrequencyMap[magazine[i] - 'a'] > 0) {
      charFrequencyMap[magazine[i] - 'a']--;
      n--;

      if (n == 0) {
        return true;
      }
    }
  }

  return false;
}

int main(int argc, char const *argv[]) {
  std::cout << (contains("boy", "overboy") ? "possible" : "nope") << std::endl;
  std::cout << (contains("acb", "overboy") ? "possible" : "nope") << std::endl;
  std::cout << (contains("olver", "overboy") ? "possible" : "nope") << std::endl;
  return 0;
}
