#pragma once

#include "User.h"

void showList(vector<User>&);

void showLogs(User&);

bool isNewUser(string&, vector<User>&);

bool isNewLogin(string&, User);

string encrypt(string&);


void showUsers(vector<User>&);