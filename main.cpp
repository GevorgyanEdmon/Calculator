#include <iostream>
#include <stdexcept>

using namespace std;

double result = 0;
double term = 0;
char last_sign = '+';
double num = 0;
char op = ' ';

void ReadFirstNumber() {
    cin >> result;
    term = result;
    result = 0;
}

bool ReadNextStep() {

    if (!(cin >> op)) return false;

    if (op != '+' && op != '-' && op != '*' && op != '/') {
        throw runtime_error("Unknown operation sign");
    }

    if (!(cin >> num)) return false;

    return true;
}

bool IsEnd() {
    return cin.peek() == '\n';
}

void DoMath() {
    if (op == '*') {
        term = term * num;
    }
    else if (op == '/') {
        if (num == 0) throw runtime_error("Division by zero");
        term = term / num;
    }
    else if (op == '+' || op == '-') {
        if (last_sign == '+') result = result + term;
        if (last_sign == '-') result = result - term;
        last_sign = op;
        term = num;
    }

}

void FinalizeMath() {
    if (last_sign == '+') result = result + term;
    if (last_sign == '-') result = result - term;
}

void StartCalculator() {
    ReadFirstNumber();

    if (cin.fail()) throw runtime_error("The expression must start with a number");

    while (ReadNextStep()) {
        DoMath();

        if (IsEnd()) break;
    }

    if (cin.fail()) {
        throw runtime_error("An invalid character has been entered");
    }

    FinalizeMath();
}


int main() {
    cout << "Enter expression: ";

    try {
        StartCalculator();
        cout << "Final Result: " << result << endl;
    }
    catch (const exception& error) {
        cout << "\nerror: " << error.what() << endl;
    }

    return 0;
}