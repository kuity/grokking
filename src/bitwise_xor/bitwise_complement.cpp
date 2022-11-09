#include <iostream>
#include <math.h>

using namespace std;

class CalculateComplement {
    public:
     static int bitwiseComplement(int n) {
        auto x = n;
        auto counter = 0;
        while (x != 0) {
            x = x >> 1;
            counter++;
        }
        auto complement = n;
        cout << "counter is: " << counter << endl;
        int ones = pow(2, counter)-1;
        return complement ^ ones;
    }
};

int main(int argc, char* argv[]) {
  // your code goes here
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}