using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second < y.second;
    }
  };

  static string sortCharacterByFrequency(const string &str) {
    string sortedString = "";
    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> q;
    unordered_map<char, int> m;

    for (auto c: str) {
        m[c]++;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        q.push(make_pair(it->first, it->second));
    }

    while (q.size() > 0) {
        auto f = q.top();
        q.pop();
        sortedString.push_back(f.first);
    }

    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
