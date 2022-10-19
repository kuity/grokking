using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class AbbreviatedWord {
 public:
  string str;
  int start = 0;
  int count = 0;

  AbbreviatedWord(string str, int start, int count) {
    this->str = str;
    this->start = start;
    this->count = count;
  }
};

class GeneralizedAbbreviation {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    vector<string> result;

    queue<vector<AbbreviatedWord>> temp;
    temp.push(vector<AbbreviatedWord> {AbbreviatedWord("", -1, 0)});
    for (auto c: word) {
        auto lim = temp.size();
        for (auto i=0; i<lim; i++) {
            auto v = temp.front();
            temp.pop();

            // Include the current char as an abbreviation
            auto included = v;
            if (included.back().start < 0) { // if back is not abbreviated
                included.push_back(AbbreviatedWord("", 1, 1));
            } else {
                included.back().count++;
            }

            // Exclude the current char as an abbreviation
            auto excluded = v;
            if (excluded.back().start < 0) {// if back is not abbreviated
                excluded.back().str.push_back(c);
            } else {
                string ns(1, c);
                excluded.push_back(AbbreviatedWord(ns, -1, 1));
            }
            temp.push(included);
            temp.push(excluded);
        }
    }

    while(temp.size() > 0) {
        auto v = temp.front();
        temp.pop();
        string s = "";
        cout << "----------------" << endl;
        for (auto a: v) {
            cout << a.str << "," << a.start << "," << a.count << endl;
            if (a.start < 0) {
                s.append(a.str);
            } else {
                s.append(to_string(a.count));
            }
        }
        result.push_back(s);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
