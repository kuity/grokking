#include <iostream>

using namespace std;

class CalculateComplement {
    public:
     static int bitwiseComplement(int n) {
        // TODO: Write your code here
        auto x = n;
        auto counter = 0;
        while (x != 0) {
            x = x >> 1;
            counter++;
        }
        auto complement = n;
        cout << "counter is: " << counter << endl;

        x = 1;
        while (counter > 0) {
            complement = complement ^ x;
            cout << "complement is: " << complement << endl;
            x = x << 1;
            counter--;
        }
        return complement;
    }
};

int main(int argc, char* argv[]) {
  // your code goes here
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}