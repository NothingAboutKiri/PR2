#include "fermat.h"
#include "euclid.h"
#include "inverse.h"
#include "shamir_file.h"
#include "mitm_attack.h"
#include "fraction_equation.h"
#include "rf_crypto_standards.h"
#include <clocale>
#include <iostream>
using namespace std;

enum class MenuItem {
    Exit = 0,
    Fermat = 1,
    Euclid = 2,
    Inverse = 3,
    ShamirFile = 4,
    MitmAttack = 5,
    FractionEquation = 6,
    RussianCryptoStandards = 7
};

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

        switch (static_cast<MenuItem>(punkt)) {
            case MenuItem::Fermat:
                run_fermat();
                break;
            case MenuItem::Euclid:
                run_euclid();
                break;
            case MenuItem::Inverse:
                run_inverse();
                break;
            case MenuItem::ShamirFile:
                run_shamir_file();
                break;
            case MenuItem::MitmAttack:
                run_mitm_attack();
                break;
            case MenuItem::FractionEquation:
                run_fraction_equation();
                break;
            case MenuItem::RussianCryptoStandards:
                run_rf_crypto_standards();
                break;
            case MenuItem::Exit:
                return 0;
            default:
                cout << "Такого пункта меню нет.\n";
                break;
        }
    }
}
