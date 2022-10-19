using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    int low = 0;
    int sz = arr.size();
    int high = sz-1;
    int found_ind = -1;

    while(low <= high) {
        // cout << "low: " << low << ", high: " << high << endl;
        auto m = low + (high-low)/2;
        auto m_num = arr[m];
        if (m_num == key) {
            found_ind = m;
        }

        if (key < m_num) {
            high = m-1;
            continue;
        } else {
            low = m+1;
        }
    }

    if (found_ind == -1) {
        return make_pair(-1, -1);
    }

    low = found_ind;
    high = found_ind;
    while(arr[low]==key && low >= 0) {
        low--;
    }
    while(arr[high]==key && high < sz) {
        high++;
    }
    return make_pair(++low, --high);
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}