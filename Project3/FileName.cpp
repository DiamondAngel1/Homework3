#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

void UserInput(char*& user, int& length) {
    cout << "¬вед≥ть р€док: ";
    char temp[500];
    cin.getline(temp, 500);
    length = strlen(temp);
    user = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        user[i] = temp[i];
    }
    user[length] = '\0';
}

void CharsDel(char*& remove, int& length) {
    cout << "¬вед≥ть символи, €к≥ потр≥бно видалити: ";
    char temp[100];
    cin.getline(temp, 100);
    length = strlen(temp);
    remove = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        remove[i] = temp[i];
    }
    remove[length] = '\0';
}

bool DeleteOption(char c, const char* removeChars) {
    while (*removeChars) {
        if (c == *removeChars) {
            return true;
        }
        removeChars++;
    }
    return false;
}

void Delete(char*& user, int& length, const char* removeChars) {
    char* temp = new char[length + 1];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (!DeleteOption(user[i], removeChars)) {
            temp[j++] = user[i];
        }
    }
    temp[j] = '\0';
    delete[] user;
    user = new char[j + 1];
    for (int i = 0; i <= j; ++i) {
        user[i] = temp[i];
    }
    length = j;
    delete[] temp;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char* user = nullptr;
    int userLength = 0;
    UserInput(user, userLength);

    char* removeChars = nullptr;
    int removeLength = 0;
    CharsDel(removeChars, removeLength);

    Delete(user, userLength, removeChars);

    return 0;
}