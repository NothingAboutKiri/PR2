#include "task6_fraction.h"
#include "math_utils.h"
#include <iostream>
#include <vector>
using namespace std;

void run_task6() {
    int A = 439;
    int B = 118;
    int D = 3;

    cout << "\nЗадание 6. Цепная дробь и линейное уравнение в целых числах\n";
    cout << "Уравнение: " << A << "a + " << B << "b = " << D << "\n";

    cout << "\nАлгоритм Евклида и цепная дробь:\n";
    int n = A;
    int d = B;
    vector<int> cf;

    while (d != 0) {
        int q = n / d;
        int r = n % d;
        cout << n << " = " << d << " * " << q << " + " << r << "\n";
        cf.push_back(q);
        n = d;
        d = r;
    }

    cout << A << "/" << B << " = [";
    for (int i = 0; i < (int)cf.size(); i++) {
        if (i > 0) cout << "; ";
        cout << cf[i];
    }
    cout << "]\n";

    int u, v;
    int g = extended_gcd(A, B, u, v);

    cout << "\nРасширенный алгоритм Евклида:\n";
    cout << A << " * " << u << " + " << B << " * " << v << " = " << g << "\n";

    if (D % g != 0) {
        cout << "Решений нет, потому что D не делится на НОД.\n";
        return;
    }

    int k = D / g;
    int a = u * k;
    int b = v * k;

    cout << "Умножаем коэффициенты на D / НОД = " << k << "\n";
    cout << "Частное решение: a = " << a << ", b = " << b << "\n";
    cout << "Проверка: " << A << " * " << a << " + " << B << " * " << b
         << " = " << A * a + B * b << "\n";
    cout << "Общее решение:\n";
    cout << "a = " << a << " + " << B / g << "t\n";
    cout << "b = " << b << " - " << A / g << "t\n";
}
