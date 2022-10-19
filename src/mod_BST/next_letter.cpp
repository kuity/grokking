using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    int low = 0;
    int sz = letters.size();
    int high = sz-1;

    while(low <= high) {
        // cout << "low: " << low << ", high: " << high << endl;
        auto m = low + (high-low)/2;
        auto m_num = letters[m];
        if (m_num == key) {
            return letters[(m+1) % sz]; // if out of bounds, wrap back to start of array
        }

        if (key < m_num) {
            high = m-1;
            continue;
        } else {
            low = m+1;
        }
    }

    return letters[low % sz];
  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}
