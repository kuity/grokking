using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
 public:
  // given a < b, return 2 chars a_char and b_char such that a_char < b_char
  static pair<char, char> wordOrder(string a, string b) {
    int index = 0;
    while(index < a.size() && index < b.size()) {
        auto ac = a[index], bc = b[index];
        if (ac != bc) { return make_pair(ac, bc); }
        else { index++; }
    }
    // the case like (xx, xxy) then there is no useful data so just return a placeholder
    return make_pair('x', 'x');
  }

  static string findOrder(const vector<string> &words) {
    unordered_map<char, vector<char>> adjacency_map;
    unordered_map<char, int> degree_map;
    queue<char> sources;
    string sortedOrder;

    // initialize degree_map
    for (auto word: words) {
        for (auto c: word) {
            degree_map[c] = 0;
        }
    }

    // we should only need to compare pairwise the adjacent indices of "words"
    // because assume 3 words, if a > b, and b > c, then the rule a > c is redundant
    for (auto i=0; i<words.size()-1; i++) {
        auto wd = words[i];
        auto next_wd = words[i+1];
        auto wordOrdering = wordOrder(wd, next_wd);
        auto parent = wordOrdering.first, child = wordOrdering.second;
        cout << "parent is " << parent << ", child is " << child << endl;
        if (parent != child) {
            if (adjacency_map.find(parent) != adjacency_map.end()) {
                auto values = adjacency_map[parent];
                if (find(values.begin(), values.end(), child) == values.end()) {
                    adjacency_map[parent].push_back(child);
                    degree_map[child]++;
                }
            } else {
                adjacency_map[parent] = {child};
                degree_map[child]++;
            }
        }
    }

    // cout << "degree_map for " << child << " is " << degree_map[child] << endl;
    for(auto i=degree_map.begin(); i!=degree_map.end(); i++) {
        if(i->second==0) {
            sources.push(i->first);
        }
    }

    while(!sources.empty()) {
        auto s = sources.front();
        sources.pop();
        sortedOrder.push_back(s);
        auto children = adjacency_map[s];
        for (auto c: children) {
            degree_map[c]--;
            if (degree_map[c] == 0) {
                sources.push(c);
            }
        }
    }

    if (sortedOrder.size() != degree_map.size()) {
        return {};
    }

    return sortedOrder;
  }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
