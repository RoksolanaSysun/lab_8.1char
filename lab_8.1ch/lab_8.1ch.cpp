#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* s) { // s - �������� �� ������� �����
    int k = 0;
    int pos = 0; // pos - ������� ������� ������
    char* t;

    while ((t = strchr(s + pos, '!')) && *(t + 1) == '!' && *(t + 2) == '!') { // t - �������� �� '!'
        k++;
        pos = t - s + 1; // pos - ��������� ������ ���� ������� '!'
    }

    return k;
}

char* Change(char* s) { // s - �������� �� ������� �����
    char* t = new char[strlen(s) * 2 + 1]; // ��������� ��������� ���� ��� ����
    char* p;
    int pos1 = 0; // pos1 - ������� ������� ������
    int pos2 = 0;
    *t = 0;

    while ((p = strchr(s + pos1, '!')) && *(p + 1) == '!' && *(p + 2) == '!') { // p - �������� �� '!'
        pos2 = p - s + 3; // pos2 - ������� ���������� ������� ���� ����� '!'

        // ������ ������� ����� ����� "!!!"
        strncat(t, s + pos1, p - s - pos1);

        // ������ ����� "***" ��� ����� ����� ����� "!!!"
        strcat(t, "***");

        pos1 = pos2;
    }

    // ������ ������� ����� ���� �������� �����
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
