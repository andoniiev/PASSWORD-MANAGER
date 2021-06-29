#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::endl;
using std::cout;
using std::vector;

class User
{
private:
    string username;
    string password;
    vector<string> logins;
    vector<string> passwords;

public:
    User(string, string);

    void addLogin(string, string);

   

    string getUsername();

    string getPassword();

    vector<string> getLogins();

    vector<string> getPasswords();
};

