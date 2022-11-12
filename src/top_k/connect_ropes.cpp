using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:

  struct greater {
    bool operator()(const int& a, const int& b) const { return a > b; }
  };

  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    // put first 'K' numbers in the min heap
    vector<int> minHeap(ropeLengths.begin(), ropeLengths.end());
    make_heap(minHeap.begin(), minHeap.end(), greater());

    auto cost = 0;
    // keep taking shortest 2 ropes from heap
    while (minHeap.size() > 1) {
      auto new_rope = minHeap.front();
      pop_heap(minHeap.begin(), minHeap.end(), greater());
      minHeap.pop_back();
      new_rope += minHeap.front();
      pop_heap(minHeap.begin(), minHeap.end(), greater());
      minHeap.pop_back();
      minHeap.push_back(new_rope);
      push_heap(minHeap.begin(), minHeap.end(), greater());
      cost += new_rope;
    }

    return cost;
  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}
