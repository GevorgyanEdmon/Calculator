#include <algorithm>
#include <iostream>

using namespace std;
double a, b, result;
char op;

int main() {
    cout << "Enter number a: ";
    cin >> a;

    cout << "Enter number b: ";
    cin >> b;
    cout << "Введите арифметическую операцию: ";
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
