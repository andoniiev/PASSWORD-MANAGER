#include "Func.h"

void showList(vector<User>& users) {
    cout << "Please choose the user: " << endl;
    for (int i = 0; i < users.size(); i++)
        cout << i + 1 << "- " << users.at(i).getUsername() << endl;
    cout << users.size() + 1 << "- Add new user\n";
    cout << users.size() + 2 << "- Exit\n";
}

void showLogs(User& user) {

    cout << "Logins and passwords for: " << user.getUsername() << endl;
    for (int i = 0; i < user.getLogins().size(); i++)
        cout << i + 1 << "- " << user.getLogins().at(i) << " " << user.getPasswords().at(i) << endl;
    cout << user.getLogins().size() + 1 << "- Add new login\n";
    cout << user.getLogins().size() + 2 << "- Exit\n";
}

bool isNewUser(string& newName, vector<User>& users) {
    bool isNew = true;
    for (int i = 0; i < users.size(); i++)
        for (int i = 0; i < users.size(); i++)
            if (users.at(i).getUsername() == newName)
                isNew = false;
    return isNew;
}

bool isNewLogin(string& newLogin, User user) {
    bool isNew = true;
    for (int i = 0; i < user.getLogins().size(); i++)
        if (user.getLogins().at(i) == newLogin)
            isNew = false;
    return isNew;
}

string encrypt(string& str) {
    string encrypted = str;
    char key[3] = { 'K','E','Y' };
    for (int i = 0; i < encrypted.size(); i++)
        encrypted[i] = str[i] ^ key[i % sizeof(key) / sizeof(char)];
    return encrypted;
}

void showUsers(vector<User>& users) {
    if (users.size() == 0) {
        cout << "No logins found\n";
    }
    else {
        for (int i = 0; i < users.size(); i++) {
            cout << users.at(i).getUsername() << " " << users.at(i).getPassword() << endl;
        }
    }
}