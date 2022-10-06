using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    queue<string> holder;
    holder.push("(");

    // holder contains intermediate strings
    while (holder.size() > 0) {
        auto s = holder.front();
        holder.pop();
        int num_leftp = 0;
        int num_rightp = 0;
        for (auto c: s) {
            if (c=='(') { num_leftp++; } else { num_rightp++; }
        }
        if (num_leftp == num && num_rightp == num) { result.push_back(s); continue; }

        if ((num_leftp-num_rightp) > 0 && num_rightp < num) {
            auto new_s = s;
            new_s.push_back(')');
            holder.push(new_s);
        }

        if (num_leftp < num) {
            auto new_s = s;
            new_s.push_back('(');
            holder.push(new_s);           
        }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(4);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}


/*
1. (((
2. ()((, (()(, ((()
3. ()()(, ()((), (())(, (()(), ((())
4. ()()(), ()(()), (())(), (()()), ((()))
*/

