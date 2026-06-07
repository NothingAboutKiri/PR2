#include "task1_fermat.h"
#include "task2_euclid.h"
#include "task3_inverse.h"
#include "task4_shamir_file.h"
#include "task5_text.h"
#include "task6_fraction.h"
#include "task7_text.h"
#include <clocale>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int punkt;

    while (true) {
        cout << "\n";
        cout << "1. Теорема Ферма и разложение степени в двоичный вид\n";
        cout << "2. Расширенный алгоритм Евклида\n";
        cout << "3. Обратный элемент по модулю\n";
        cout << "4. Шифр Шамира для файла\n";
        cout << "5. Атака посередине\n";
        cout << "6. Цепная дробь и линейное уравнение\n";
        cout << "7. Стандарты современной криптографии в РФ\n";
        cout << "0. Выход\n";
        cout << "> ";

        cin >> punkt;

        switch (punkt) {
            case 1:
                run_task1();
                break;
            case 2:
                run_task2();
                break;
            case 3:
                run_task3();
                break;
            case 4:
                run_task4();
                break;
            case 5:
                run_task5();
                break;
            case 6:
                run_task6();
                break;
            case 7:
                run_task7();
                break;
            case 0:
                return 0;
            default:
                cout << "Такого пункта меню нет.\n";
                break;
        }
    }
}
