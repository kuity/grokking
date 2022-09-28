using namespace std;

#include <iostream>
#include <vector>

// N is the highest number
int arith_sum(int N) {
  return N*(N+1)/2;
}

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    auto N = nums.size();
    auto S = arith_sum(N);
    for (int i: nums) {
      S-=i;
    }
    return S;
  }
};

int main() {
  vector<int> v {8, 3, 5, 2, 4, 6, 0, 1};
  auto N = MissingNumber().findMissingNumber(v);
  cout << N << endl;
}