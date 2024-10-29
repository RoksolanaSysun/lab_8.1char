#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* s) { // s - вказівник на початок рядка
    int k = 0;
    int pos = 0; // pos - позиція початку пошуку
    char* t;

    while ((t = strchr(s + pos, '!')) && *(t + 1) == '!' && *(t + 2) == '!') { // t - вказівник на '!'
        k++;
        pos = t - s + 1; // pos - наступний символ після першого '!'
    }

    return k;
}

char* Change(char* s) { // s - вказівник на початок рядка
    char* t = new char[strlen(s) * 2 + 1]; // резервуємо достатньо місця для замін
    char* p;
    int pos1 = 0; // pos1 - позиція початку пошуку
    int pos2 = 0;
    *t = 0;

    while ((p = strchr(s + pos1, '!')) && *(p + 1) == '!' && *(p + 2) == '!') { // p - вказівник на '!'
        pos2 = p - s + 3; // pos2 - позиція наступного символа після трьох '!'

        // Додаємо частину рядка перед "!!!"
        strncat(t, s + pos1, p - s - pos1);

        // Додаємо заміну "***" для кожної трійки знаків "!!!"
        strcat(t, "***");

        pos1 = pos2;
    }

    // Додаємо залишок рядка після останньої заміни
    strcat(t, s + pos1);

    strcpy(s, t);
    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of '!!!'" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}
