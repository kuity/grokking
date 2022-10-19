using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

// xxxxxx op b
class Expression {
    public:
        vector<char> operators {};
        vector<int> operands {};
        Expression() = default;

        void push_operand(int x) {
            operands.push_back(x);
        }

        void push_operator(char x) {
            operators.push_back(x);
        }

        bool resolve() {
            if (!(operators.size() > 0 && operands.size() > 1)) {
                return false;
            }
            auto op = operators.back();
            operators.pop_back();
            int b = operands.back();
            operands.pop_back();
            int a = operands.back();
            operands.pop_back();
            cout << "a: " << a << ", b: " << b << ", op: " << op << endl;

            if (op == '+') {
                operands.push_back(a+b);
            } else if (op == '-') {
                operands.push_back(a-b);
            } else {
                operands.push_back(a*b);
            }
            return true;
        }
};

class EvaluateExpression {
 public:
  static vector<int> diffWaysToEvaluateExpression(const string& input) {
    vector<int> result;
    vector<Expression> q {};
    q.push_back(Expression());

    for (auto c: input) {
        auto lim = q.size();
        cout << c << ": lim=" << lim << endl;
        for (auto i=0; i<lim; i++) {
            if (isdigit(c)) {
                int num = c - '0';
                auto expr = q.front();
                auto expr_cpy = expr;
                q.erase(q.begin());
                // resolve immediately 
                expr.push_operand(num);
                auto resolved = expr.resolve();
                if (resolved) {
                    q.push_back(expr);
                }
                
                // resolve later
                expr_cpy.push_operand(num);
                q.push_back(expr_cpy);
            } else {
                q[i].push_operator(c);
            }
        }
    }

    for (auto e: q) {
        cout << "----------------" << endl;
        for (auto a: e.operands) {
            cout << a << " ";
        }
        cout << endl;
        for (auto a: e.operators) {
            cout << a << " ";
        }
        cout << endl;

        auto go = e.resolve();
        while(go) {
            go = e.resolve();
        }
        auto r = e.operands.back();
        cout << "pushing: " << r << endl;
        result.push_back(r);
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
