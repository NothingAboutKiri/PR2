#include "euclid.h"
#include "math_utils.h"
#include <iostream>
using namespace std;

void run_euclid() {
    int c = 11;
    int m = 13;

    cout << "\nРасширенный алгоритм Евклида для c*d mod m = 1\n";
    cout << "Дано: c = " << c << ", m = " << m << "\n";

    cout << "\nОбычный алгоритм Евклида:\n";
    int a = c;
    int b = m;
    while (b != 0) {
        int q = a / b;
        int r = a % b;
        cout << a << " = " << b << " * " << q << " + " << r << "\n";
        a = b;
        b = r;
    }

    int u, v;
    int d = extended_gcd(c, m, u, v);

    cout << "\nРасширенный алгоритм дает коэффициенты u и v:\n";
    cout << c << " * " << u << " + " << m << " * " << v << " = " << d << "\n";

    if (d == 1) {
        int inverse = (u % m + m) % m;
        cout << "d = u mod m = " << inverse << "\n";
        cout << "Проверка: " << c << " * " << inverse << " mod " << m
             << " = " << (c * inverse) % m << "\n";
    } else {
        cout << "Обратного элемента нет, потому что НОД не равен 1.\n";
    }
}
