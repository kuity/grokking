using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

class EvaluateExpression {
 public:
  static vector<int> diffWaysToEvaluateExpression(const string& input) {
    vector<int> result;
    // base case: if the input string is a number, parse and add it to output.
    if (input.find("+") == string::npos && input.find("-") == string::npos &&
        input.find("*") == string::npos) {
      result.push_back(stoi(input));
    } else {
      for (int i = 0; i < input.length(); i++) {
        char chr = input[i];
        if (!isdigit(chr)) {
          // break the equation here into two parts and make recursively calls
          vector<int> leftParts = diffWaysToEvaluateExpression(input.substr(0, i));
          vector<int> rightParts = diffWaysToEvaluateExpression(input.substr(i + 1));
          for (auto part1 : leftParts) {
            for (auto part2 : rightParts) {
              if (chr == '+') {
                result.push_back(part1 + part2);
              } else if (chr == '-') {
                result.push_back(part1 - part2);
              } else if (chr == '*') {
                result.push_back(part1 * part2);
              }
            }
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("1+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
