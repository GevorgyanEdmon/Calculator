#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    double num, result;
    char op;

    cout << "Enter virazhenie: ";
    try {
        if (!(cin >> result)) {
            throw runtime_error("iN BEGIN NOT NUMBER");
        }

        while (cin >> op >> num) {
            switch (op) {
                case '+':
                    result = result + num;
                    break;
                case '-':
                    result = result - num;
                    break;
                case '*':
                    result = result * num;
                    break;
                case '/':
                    if (num == 0) {
                        cout << "DIVISION ZERO" << endl;
                        return 0;
                    } else {
                        result = result / num;
                    }
                    break;
            }

            if (cin.peek() == '\n') {
                break;
            }
        }
        if (cin.fail()) {
            throw runtime_error("not number");
        }
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}