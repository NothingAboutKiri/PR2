#include "text_file.h"
#include <fstream>
#include <iostream>
using namespace std;

void print_text_file(const char *path) {
    ifstream file(path);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << path << "\n";
        return;
    }

    char ch;
    while (file.get(ch)) {
        cout << ch;
    }

    cout << "\n";
    file.close();
}
