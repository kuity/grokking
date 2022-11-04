using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      auto tracker = 0;
      for (auto e: arr) {
        tracker = tracker ^ e;
        // cout << "tracker is now: " << tracker << endl;
      }
      // just return it as other numbers have cancelled themselves out
      return tracker;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}