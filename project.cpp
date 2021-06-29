#include <Windows.h>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Func.h"


using std::cin;
using std::to_string;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::fstream;



int main()
{

    int userChoice = 0;
    int userC = 0;


    string username;
    string userpass;


    
    string newUser;
    string newPassword;
    string newLogin;
    string newPasswordforUser;
    string verification;


    vector<User>users;

    fstream usersFile;

    fstream logsFile;

    
    usersFile.open("users.txt");

    if (!usersFile)
        cerr << "File not found\n";
    else 
        while (usersFile >> username >> userpass)
            users.push_back(User(username,encrypt(userpass)));
        
    usersFile.close();

    for (int i = 0; i < users.size();i++) {
        logsFile.open(users.at(i).getUsername() + ".txt");
        while (logsFile >> newLogin >> newPassword)
            users.at(i).addLogin(newLogin, encrypt(newPassword));
        logsFile.close();
    }

    while (userChoice != users.size() + 2) {
        system("CLS");
        showList(users);
        cin >> userChoice;

        if (userChoice == users.size() + 2) {
            system("CLS");
            cout << "Goodbye!\n";
        }

        else if (userChoice == users.size() + 1) {
            cout << "Please enter new user: ";
            cin >> newUser >> newPasswordforUser;

            if (isNewUser(newUser, users)) {
                users.push_back(User(newUser, newPasswordforUser));
                usersFile.open("users.txt", std::ios::app);
                    usersFile << newUser <<" "<< encrypt(newPasswordforUser)<<endl;
                    usersFile.close();
            }

            else {
                cout << "Sorry, this user already exists!\n";
                Sleep(1500);
            }
        }
        else {
            cout << "Please enter password for " << users.at(userChoice - 1).getUsername() << endl;
            cin >> verification;
            userC = -1;
            if (verification == users.at(userChoice - 1).getPassword()) {
                while (userC != users.at(userChoice - 1).getLogins().size() + 2) {

                    system("CLS");
                    showLogs(users.at(userChoice - 1));
                    cin >> userC;

                    if (userC == users.at(userChoice - 1).getLogins().size() + 1) {

                        cout << "Please enter new login and password: ";
                        cin >> newLogin>>newPassword;

                        if (newLogin == to_string(users.at(userChoice - 1).getLogins().size() + 2))
                            break;
                        if (isNewLogin(newLogin, users.at(userChoice - 1))) {

                            users.at(userChoice - 1).addLogin(newLogin, newPassword);
                            logsFile.open(users.at(userChoice - 1).getUsername() + ".txt", std::ios::app);
                            logsFile << newLogin << " " << encrypt(newPassword)<<endl;
                            logsFile.close();
                        }
                        else {
                            cout << "Sorry,such login already exists!\n";

                        }

                    }
                    else if (userC == users.at(userChoice - 1).getLogins().size() + 2)
                        break;
                }
            }
            else {
                cout << "Not approved!";
                Sleep(1000);
            }
        }
    }
}

