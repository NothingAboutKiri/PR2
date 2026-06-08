#include "fermat.h"
#include "math_utils.h"
#include <iostream>
using namespace std;

void run_fermat() {
    int a = 23;
    int x = 3;
    int p = 5;

    cout << "\nСравнение по модулю простого числа\n";
    cout << "Дано: a = " << a << ", x = " << x << ", p = " << p << "\n";

    cout << "\nПроверка условий теоремы Ферма:\n";
    cout << "p = " << p << (is_prime(p) ? " является простым числом\n" : " не является простым числом\n");
    cout << "НОД(" << a << ", " << p << ") = " << gcd_int(a, p) << "\n";

    if (is_prime(p) && gcd_int(a, p) == 1) {
        int reduced_power = x % (p - 1);
        int result = 1;
        int base = a % p;

        cout << "Условия выполнены, поэтому степень можно уменьшить:\n";
        cout << "x mod (p - 1) = " << x << " mod " << p - 1 << " = " << reduced_power << "\n";

        for (int i = 1; i <= reduced_power; i++) {
            result = (result * base) % p;
            cout << "Шаг " << i << ": result = result * " << base << " mod " << p
                 << " = " << result << "\n";
        }

        cout << "Ответ через теорему Ферма: " << result << "\n";
    } else {
        cout << "Теорему Ферма применить нельзя.\n";
    }

    cout << "\nМетод через разложение степени в двоичный вид:\n";
    int power = x;
    int base = a % p;
    int result = 1;
    int step = 1;

    while (power > 0) {
        cout << "Шаг " << step << ": степень = " << power
             << ", основание = " << base
             << ", результат = " << result << "\n";

        if (power % 2 == 1) {
            result = (result * base) % p;
            cout << "Степень нечетная, умножаем результат: " << result << "\n";
        }

        base = (base * base) % p;
        power = power / 2;
        step++;
    }

    cout << "Ответ бинарным методом: " << result << "\n";
}
