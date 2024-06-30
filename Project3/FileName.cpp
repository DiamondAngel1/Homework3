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

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char* user = nullptr;
    int userLength = 0;
    UserInput(user, userLength);

    return 0;
}