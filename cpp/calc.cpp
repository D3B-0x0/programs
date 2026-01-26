// Simple Linux calculator for beginners

#include <iostream>

using namespace std;

int main() {
  cout << "🐧 Linux Calculator - Enter two numbers and an operation\n";
  cout << "Operations: + (add), - (subtract), * (multiply), / (divide)\n";
  cout << "Type 'q' to quit\n\n";

  double num1, num2;
  char op;

  while (true) {
    cout << "First number (or q to quit): ";
    if (!(cin >> num1)) break;

    cout << "Operation (+ - * /): ";
    cin >> op;
    if (op == 'q') break;

    cout << "Second number: ";
    if (!(cin >> num2)) break;

    cout << "Result: ";
    switch (op) {
      case '+': cout << num1 << " + " << num2 << " = " << (num1 + num2) << "\n"; break;
      case '-': cout << num1 << " - " << num2 << " = " << (num1 - num2) << "\n"; break;
      case '*': cout << num1 << " * " << num2 << " = " << (num1 * num2) << "\n"; break;
      case '/': 
        if (num2 == 0) cout << "Cannot divide by zero!\n";
        else cout << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
        break;
      default: cout << "Invalid operation!\n";
    }
    cout << "\n";
  }

  cout << "Happy coding! 🚀\n";
  return 0;
}


