using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size()-1;
    if (arr[high] < key) {
        return -1;
    }
    while(low <= high) {
        // cout << "low: " << low << ", high: " << high << endl;
        auto m = low + (high-low)/2;
        auto m_num = arr[m];
        if (m_num == key) {
            return m;
        }

        if (key < m_num) {
            high = m-1;
            continue;
        } else {
            low = m+1;
        }
    }

    // cout << "low: " << low << ", high: " << high << endl;
    return low;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 6}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}