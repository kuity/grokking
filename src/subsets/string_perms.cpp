using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LetterCaseStringPermutation {
 private:
    static char change_case (char c) {
        if (isupper(c)) 
            return tolower(c); 
        else
            return toupper(c); 
    }

 public:
  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    vector<int> alphabets;
    for (auto i=0; i<str.size(); i++) {
        auto c = str[i];
        if (isalpha(c)) {
            alphabets.push_back(i);
        }
    }

    vector<vector<int>> temp {{}};
    for (auto x: alphabets) {
        auto lim = temp.size();
        for(auto i=0; i<lim; i++) {
            auto new_v = temp[i];
            new_v.push_back(x);
            temp.push_back(new_v);
        }
    }

    for (auto v: temp) {
        string new_string = str;
        for (auto pos: v) {
            new_string[pos] = change_case(new_string[pos]);
        }
        permutations.push_back(new_string);
    }

    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
