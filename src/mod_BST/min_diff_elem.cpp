using namespace std;

#include <iostream>
#include <vector>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    int low = 0;
    int sz = arr.size();
    int high = sz-1;
    if (arr[high] < key) {
        return arr[high];
    }

    int result = -1;
    int difference = arr[high];

    while(low <= high) {
        // cout << "low: " << low << ", high: " << high << endl;
        auto m = low + (high-low)/2;
        auto m_num = arr[m];
        if (m_num == key) {
            return m_num;
        }

        auto diff = abs(m_num - key);
        if (diff < difference) {
            difference = diff;
            result = m_num;
        }

        if (key < m_num) {
            high = m-1;
        } else {
            low = m+1;
        }
    }

    // not found: we would have checked everything, so just return the result
    return result;
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}
