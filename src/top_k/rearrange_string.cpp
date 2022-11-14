using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
  struct valueCompare {
    char operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return x.second < y.second;
    }
  };

 public:
  static string rearrangeString(const string &str) {
    string ans = "";
    // if char with most dupes has more than half the string len, is not doable
    // ow, maintain max heap and pop 2 elements, append 1 each to string and put back in heap
    unordered_map<char, int> m;
    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> q;
    for (auto c: str) {
      m[c]++;
    }

    for (auto it=m.begin(); it!=m.end(); it++) {
      q.push(make_pair(it->first, it->second));
    }


    // cout << q.top().second << endl;
    // cout << str.length()/2 << endl;
    if (q.top().second > (str.length()+1)/2) {
      return ans;
    }

    while(q.size() > 1) {
      auto s1 = q.top();
      q.pop();
      auto s2 = q.top();
      q.pop();
      ans.push_back(s1.first);
      ans.push_back(s2.first);
      if (s1.second > 1) {
        q.push(make_pair(s1.first, s1.second-1));
      }
      if (s2.second > 1) {
        q.push(make_pair(s2.first, s2.second-1));
      }
    }

    if (q.size() > 0) {
      ans.push_back(q.top().first);
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
