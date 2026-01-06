// Calculator program

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
  cout << "Simple calculator - enter operation (+ - * /) or words (add, sub, mul, div). Type q or quit to exit.\n";

  while (true) {
    string op;
    cout << "\nOperation: ";
    if (!(cin >> op)) break;
    // normalize
    transform(op.begin(), op.end(), op.begin(), [](unsigned char c){ return tolower(c); });
    if (op == "q" || op == "quit" || op == "exit") break;

    // map word forms to single-char ops
    if (op == "add" || op == "plus") op = "+";
    else if (op == "sub" || op == "subtract" || op == "minus") op = "-";
    else if (op == "mul" || op == "multiply" || op == "times") op = "*";
    else if (op == "div" || op == "divide") op = "/";

    char operation = op.empty() ? '?' : op[0];
    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
      cout << "Invalid operation. Try + - * / or words like add, sub, mul, div.\n";
      continue;
    }

    double a = 0.0, b = 0.0;
    cout << "First number: ";
    if (!(cin >> a)) {
      cout << "Invalid number input. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    cout << "Second number: ";
    if (!(cin >> b)) {
      cout << "Invalid number input. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    cout << fixed << setprecision(10);
    switch (operation) {
      case '+': cout << "Result: " << (a + b) << '\n'; break;
      case '-': cout << "Result: " << (a - b) << '\n'; break;
      case '*': cout << "Result: " << (a * b) << '\n'; break;
      case '/':
        if (b == 0.0) cout << "Error: Division by zero!\n";
        else cout << "Result: " << (a / b) << '\n';
        break;
    }
  }

  cout << "Goodbye.\n";
  return 0;
}


