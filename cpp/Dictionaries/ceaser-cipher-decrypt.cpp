#include <assert.h>
#include <map>
#include <vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#include <cassert>
 
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

string encrypt(string text, int s) {
  string result = "";

  // traverse text
  for (int i = 0; i < text.length(); i++) {
    // apply transformation to each character
    // Encrypt Uppercase letters
    if (isupper(text[i]))
      result += tolower(char(int(text[i] + s - 65) % 26 + 65));

    // Encrypt Lowercase letters
    else
      result += char(int(text[i] + s - 97) % 26 + 97);
  }

  // Return the resulting string
  return result;
}
	// Unigram model frequencies for letters A, B, ..., Z
	const float ENGLISH_FREQS[26] = {
		0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406,
		0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074,
    };
	

  string Deshift(string text, int s) {
  string result = "";

  // traverse text
  for (int i = 0; i < text.length(); i++) {
    // apply transformation to each character
    // Encrypt Uppercase letters
    if (isupper(text[i]))
      result += tolower(char(int(text[i] - s - 65) % 26 + 65));

    // Encrypt Lowercase letters
    else
      result += char(int(text[i] - s - 97) % 26 + 97);
  }

  // Return the resulting string
  return result;
}
	
	// Returns the cross-entropy of the given string with respect to the English unigram frequencies, which is a positive floating-point number.
	double getEntropy(string str) {
		int sum = 0;
		int ignored = 0;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if      (65 <= c && c <=  90) sum += log(ENGLISH_FREQS[c - 65]);  // Uppercase
			else if (97 <= c && c <= 122) sum += log(ENGLISH_FREQS[c - 97]);  // Lowercase
			else ignored++;
		}
		return ((double)-sum / log(2)) / ((double)(str.length() - ignored));
	}

string Decrypt(string encryptedText) {
    vector<pair<double,int>> result;
  string text;
    for(int n=0;n<26;n++)
        {
        text = "";
        for(int i=0;i<encryptedText.length();i++)
            {
            if(isupper(encryptedText[i]))
                {
                if((encryptedText[i] - n - 97)<0)
                    text += 91 + (encryptedText[i] - n - 97);
                else
                    text += (encryptedText[i] - n - 97)%26 + 97;
                }
            else if(islower(encryptedText[i]))
                {
                if((encryptedText[i] - n - 97) < 0)
                    text += 123 + (encryptedText[i] - n - 97);
                else
                    text += (encryptedText[i] - n - 97)%26 + 97;
                }
            else
                text += encryptedText[i];
            }
          result.push_back({getEntropy(text),n});
        // cout << "plain text for key " << n << " :- " << text << " "<<getEntropy(text) << endl;
        }

      sort(result.begin(),result.end());
      
      // for(unsigned i = 0; i < 26; ++i) {
      //   std::cout << result[i].first << " "<<result[i].second  << std::endl;
      // }
      int shift = result[0].second;

      
    return Deshift(encryptedText,shift);
}

int main(int argc, char const *argv[]) {
  string text = "animation";
  int shift = 4;

  string cyphertext = encrypt(text, shift);
  cout << "\nCipher: " << cyphertext << endl;

  string decryptedText = Decrypt(cyphertext);
  cout << "Decrypted Text: " << decryptedText << endl;

  assertm((text == decryptedText) ,"Decryption works!");
  return 0;
}
