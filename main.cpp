#include <iostream>

using namespace std;

char text[100];
int pos = 0;

double x1 = 0;
double x2 = 0;
char op = ' ';


double BuildNumber() {
    int arrInt[50];
    int countInt = 0;
    int arrFrac[50];
    int countFrac = 0;
    int hasDot = 0;

    while ((text[pos] >= '0' && text[pos] <= '9') || text[pos] == '.') {

        char symbol = text[pos];

        if (symbol == '.') {
            hasDot = 1;
        }
        else {
            int cifra = symbol - '0';

            if (hasDot == 0) {
                arrInt[countInt] = cifra;
                countInt = countInt + 1;
            } else {
                arrFrac[countFrac] = cifra;
                countFrac = countFrac + 1;
            }
        }
        pos = pos + 1;
    }

    double finalNumber = 0;
    int i = 0;
    while (i < countInt) {
        int power = (countInt - 1) - i;
        double multiplier = 1;
        int k = 0;
        while (k < power) {
            multiplier = multiplier * 10;
            k = k + 1;
        }
        finalNumber = finalNumber + (arrInt[i] * multiplier);
        i = i + 1;
    }

    i = 0;
    while (i < countFrac) {
        int power = i + 1;
        double divider = 1;
        int k = 0;
        while (k < power) {
            divider = divider * 10;
            k = k + 1;
        }
        finalNumber = finalNumber + (arrFrac[i] / divider);
        i = i + 1;
    }

    return finalNumber;
}

void Calc() {
    if (op == '+') x1 = x1 + x2;
    if (op == '-') x1 = x1 - x2;
    if (op == '*') x1 = x1 * x2;
    if (op == '/') x1 = x1 / x2;
}


int main() {

    cout << "Введите выражение (без пробелов): ";
    cin >> text;

    x1 = BuildNumber();

    while (true) {

        op = text[pos];

        if (op == '\0') {
            break;
        }

        pos = pos + 1;

        x2 = BuildNumber();

        Calc();
    }

    cout << "ответ: " << x1 << endl;

    return 0;
}