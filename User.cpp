#include "User.h"

User::User(string uname, string passw) {
    username = uname;
    password = passw;
}


void User::addLogin(string login, string pass) {
    logins.push_back(login);
    passwords.push_back(pass);
}



string User::getUsername() {
    return username;
}
string User::getPassword() {
    return password;
}

vector<string> User::getLogins() {
    return logins;
}

vector<string> User::getPasswords() {
    return passwords;
}