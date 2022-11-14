using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeStringKDistanceApart {
 public:
  struct valueCompare {
    char operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return x.second < y.second;
    }
  };

  static string reorganizeString(const string &str, int k) {
    if (k < 2) { return str; }

    string ans = "";
    unordered_map<char, int> m;
    // max heap
    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> q;
    for (auto c: str) {
      m[c]++;
    }

    for (auto it=m.begin(); it!=m.end(); it++) {
      q.push(make_pair(it->first, it->second));
    }

    vector<pair<pair<char, int>, int>> buf; // buffer containing pairs to go back into q; each has a buf_value
    while(q.size() > 0) {
      auto s1 = q.top();
      q.pop();
      ans.push_back(s1.first);

      // all buf_value can decrease by 1
      for (auto i=0; i<buf.size(); i++) {
        buf[i].second--;
      }

      // check buf_value of first element in buffer if can add back to q
      if (buf.size()>0 && buf[0].second==0) {
        q.push(buf[0].first);
        buf.erase(buf.begin());
      }

      // if char still has dupes after placing, it goes into buf2
      if (s1.second > 1) {
        buf.push_back(make_pair(make_pair(s1.first, s1.second-1), k-1));
      }
    }

    // If buf not empty, then there's no valid answer
    if (buf.size() > 0) {
        return "";
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("Programming", 3) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("mmpp", 2) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aab", 2) << endl;
  cout << "Reorganized string: " << RearrangeStringKDistanceApart::reorganizeString("aappa", 3)
       << endl;
}
