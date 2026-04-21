#include <algorithm>
#include <iostream>

using namespace std;
double a, b, result;
char op;

double EnterNum() {
    double x;
    cout << "Enter number x: ";
    cin >> x;
    return x;
}

int main() {
    a = EnterNum();
    b = EnterNum();
    cout << "Enter operation: ";
    cin >> op;
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                cout << "Деление на ноль" << endl;
                return 0;
            } else {
                result = a / b;
            }
            break;

        default: cout << "Ошибка: неподдерживаемая операция" << endl;
            return 0;
    }
    cout << result << endl;
}
