#include "inverse.h"
#include "math_utils.h"
#include <iostream>
using namespace std;

void run_inverse() {
    int c = 2;
    int m = 11;

    cout << "\nНахождение c^(-1) mod m\n";
    cout << "Дано: c = " << c << ", m = " << m << "\n";

    int u, v;
    int d = extended_gcd(c, m, u, v);

    cout << "Расширенный алгоритм Евклида:\n";
    cout << c << " * " << u << " + " << m << " * " << v << " = " << d << "\n";

    if (d == 1) {
        int inverse = mod_inverse(c, m);
        cout << "c^(-1) mod m = " << inverse << "\n";
        cout << "Проверка: " << c << " * " << inverse << " mod " << m
             << " = " << (c * inverse) % m << "\n";
    } else {
        cout << "Обратного элемента нет.\n";
    }
}
