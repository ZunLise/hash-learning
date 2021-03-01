#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


struct Student {
    string login;
    string password;
    string mail;
    string group;

    void readData{};
    void createAccount{};
};

void Student::readData() {
    cin >> login
    cin >> password
    cin >> mail
    cin >> group
}

void Student::createAccount() {
    ofstream of("a.txt", ios::binary | ios::append);
    unsigned char hLogin, hPassword;
    hLogin = hash(login)
    hPassword = hash(password)
    of.write (&hLogin, sizeof(hLogin));
    of.write (&hPassword, sizeof(hPassword));
}

unsigned hash(string s){
    unsigned h = 0;
    for (int i = 0; i < s.size() ; i++)
        h = h * 101 + (unsigned) s[i];
    return h
}

void sign_up() {
    //

    //
}

int main() {
    //

    //
    return 0;
}
