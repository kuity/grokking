using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    int low = 0;
    int high = numeric_limits<int>::max();

    while (low <= high) {
        // cout << "m is " << m << ", m_num is " << m_num << endl;
        auto m = low + (high-low)/2;
        auto m_num = reader->get(m);
        // if index within array bounds
        if (m_num == numeric_limits<int>::max()) {
            high = m-1;
        } else {
            low = m+1;
        }
    }

    // after searching, high should be set to the upper bound of the array now
    // cout << "high is " << high << endl;
    low = 0;

    while (low <= high) {
        auto m = low + (high-low)/2;
        auto m_num = reader->get(m);
        if (m_num == key) {
            return m;
        }
        if (m_num < key) {
            low = m+1;
        } else { 
            high = m-1;
        }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}
