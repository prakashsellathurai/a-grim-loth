/**
* @file telephone-numbers-to-possible-words.cpp
* @author prakash (prakashsellathurai@gmail.com)
* @brief
    Telephone keypads have letters on each numerical key. Write a program that
    generates all possible words resulting from translating a given digit
    sequence (e.g. 145345) into letters.
* @version 0.1
* @date 2021-08-11
*
* @copyright Copyright (c) 2021
*
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int steps = 0;

void findCombination(
    const vector<vector<char>> &keypad,
    vector<int> numbers,
    string result,
    int n,
    int index
    ){

    steps++;
    int digit;
    int len;
    if(index == n){
        cout << result << endl;
        return;
    }
    if(index > n) return;

    digit = numbers[index];
    len = keypad[digit].size();
    for(int i=0;i<len;i++){
        findCombination(keypad, numbers, result+keypad[digit][i], n, index+1);
    }

}

int main(int argc, const char **argv) {

  vector<vector<char>> keypad = {
      {},
      {},
      {'A', 'B', 'C'},
      {'D', 'E', 'F'},
      {'G', 'H', 'I'},
      {'J', 'K', 'L'},
      {'M', 'N', 'O'},
      {'P', 'Q', 'R', 'S'},
      {'T', 'U', 'V'},
      {'W', 'X', 'Y', 'Z'},
  };

  vector<int> numbers = {2, 3, 4};
  int n = numbers.size();
  string result = "";
  int index = 0;
  findCombination(keypad, numbers, result,n, index);
  cout<<steps<<endl;
  return 0;
}