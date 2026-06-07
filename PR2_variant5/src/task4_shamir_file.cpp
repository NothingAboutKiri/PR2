#include "task4_shamir_file.h"
#include "math_utils.h"
#include <fstream>
#include <iostream>
using namespace std;

void encrypt_file_shamir(const char *input_path, const char *encrypted_path,
                         int p, int a, int b, int a_inverse) {
    ifstream input(input_path, ios::binary);
    ofstream encrypted(encrypted_path);

    if (!input.is_open()) {
        cout << "Не удалось открыть исходный файл: " << input_path << "\n";
        return;
    }

    if (!encrypted.is_open()) {
        cout << "Не удалось создать зашифрованный файл: " << encrypted_path << "\n";
        return;
    }

    char symbol;
    int number = 0;

    while (input.get(symbol)) {
        int m = (unsigned char)symbol;

        int x1 = mod_pow(m, a, p);
        int x2 = mod_pow(x1, b, p);
        int x3 = mod_pow(x2, a_inverse, p);

        cout << "\nБайт " << number << ": m = " << m << "\n";
        cout << "1) Алиса вычисляет x1 = m^a mod p = " << m << "^" << a
             << " mod " << p << " = " << x1 << "\n";
        cout << "2) Боб вычисляет x2 = x1^b mod p = " << x1 << "^" << b
             << " mod " << p << " = " << x2 << "\n";
        cout << "3) Алиса снимает свой ключ: x3 = x2^a_inverse mod p = " << x2
             << "^" << a_inverse << " mod " << p << " = " << x3 << "\n";
        cout << "В зашифрованный файл записывается число " << x3 << "\n";

        encrypted << x3 << " ";
        number++;
    }

    input.close();
    encrypted.close();
}

void decrypt_file_shamir(const char *encrypted_path, const char *decrypted_path,
                         int p, int b_inverse) {
    ifstream encrypted(encrypted_path);
    ofstream decrypted(decrypted_path, ios::binary);

    if (!encrypted.is_open()) {
        cout << "Не удалось открыть зашифрованный файл: " << encrypted_path << "\n";
        return;
    }

    if (!decrypted.is_open()) {
        cout << "Не удалось создать расшифрованный файл: " << decrypted_path << "\n";
        return;
    }

    int x3;
    int number = 0;

    while (encrypted >> x3) {
        int m = mod_pow(x3, b_inverse, p);

        cout << "\nРасшифрование байта " << number << ":\n";
        cout << "Боб вычисляет m = x3^b_inverse mod p = " << x3 << "^"
             << b_inverse << " mod " << p << " = " << m << "\n";

        decrypted.put((char)m);
        number++;
    }

    encrypted.close();
    decrypted.close();
}

void run_task4() {
    const char *input_path = "data/input.txt";
    const char *encrypted_path = "data/encrypted_shamir.txt";
    const char *decrypted_path = "data/decrypted.txt";

    int p = 257;
    int a = 5;
    int b = 7;

    cout << "\nЗадание 4. Шифр Шамира для файла\n";
    cout << "Исходный файл: " << input_path << "\n";
    cout << "Зашифрованный файл: " << encrypted_path << "\n";
    cout << "Расшифрованный файл: " << decrypted_path << "\n";

    cout << "\nПараметры:\n";
    cout << "p = " << p << " — простое число больше 255\n";
    cout << "a = " << a << " — секретная степень Алисы\n";
    cout << "b = " << b << " — секретная степень Боба\n";

    if (!is_prime(p)) {
        cout << "Ошибка: p должно быть простым.\n";
        return;
    }

    if (gcd_int(a, p - 1) != 1 || gcd_int(b, p - 1) != 1) {
        cout << "Ошибка: a и b должны быть взаимно простыми с p - 1.\n";
        return;
    }

    int a_inverse = mod_inverse(a, p - 1);
    int b_inverse = mod_inverse(b, p - 1);

    cout << "a_inverse = " << a_inverse << ", так как a * a_inverse mod (p - 1) = 1\n";
    cout << "b_inverse = " << b_inverse << ", так как b * b_inverse mod (p - 1) = 1\n";

    cout << "\nШифрование файла через файловые потоки ifstream/ofstream:\n";
    encrypt_file_shamir(input_path, encrypted_path, p, a, b, a_inverse);

    cout << "\nРасшифрование файла через файловые потоки ifstream/ofstream:\n";
    decrypt_file_shamir(encrypted_path, decrypted_path, p, b_inverse);

    cout << "\nШифрование и расшифрование завершены.\n";
}
