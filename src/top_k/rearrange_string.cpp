using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
 public:
  static string rearrangeString(const string &str) {
    // if char with most dupes has more than half the string len, is not doable
    // ow, maintain max heap and pop 2 elements, append 1 each to string and put back in heap
    return "";
  }
};

int main(int argc, char *argv[]) {
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
