#include <iostream>
#include <fstream>
#include <sstream>
#include "password_manager.h"
#include "encryption.h"

using namespace std;

void password_manager::add()
{
    string site, user, pass;

    cin.ignore();

    cout << "enter site: ";
    getline(cin, site);

    cout << "enter username: ";
    getline(cin, user);

    cout << "enter password: ";
    getline(cin, pass);

    ofstream file("data.txt", ios::app);

    if (!file)
    {
        cout << "file error\n";
        return;
    }

    file << site << "|" << user << "|" << encrypt(pass) << endl;
    file.close();

    cout << "data saved\n";
}

void password_manager::view()
{
    ifstream file("data.txt");
    string line;

    if (!file)
    {
        cout << "no data found\n";
        return;
    }

    if (file.peek() == EOF)
    {
        cout << "file is empty\n";
        return;
    }

    cout << "\nstored data:\n";

    while (getline(file, line))
    {
        stringstream ss(line);
        string site, user, pass;

        getline(ss, site, '|');
        getline(ss, user, '|');
        getline(ss, pass, '|');

        cout << "site: " << site
             << " | user: " << user
             << " | pass: " << decrypt(pass) << endl;
    }

    file.close();
}

void password_manager::search()
{
    string target, line;

    cin.ignore();
    cout << "enter site to search: ";
    getline(cin, target);

    ifstream file("data.txt");

    if (!file)
    {
        cout << "no data found\n";
        return;
    }

    int found = 0;

    while (getline(file, line))
    {
        stringstream ss(line);
        string site, user, pass;

        getline(ss, site, '|');
        getline(ss, user, '|');
        getline(ss, pass, '|');

        if (site == target)
        {
            cout << "found -> user: " << user
                 << " pass: " << decrypt(pass) << endl;
            found = 1;
        }
    }

    if (!found)
        cout << "no match found\n";

    file.close();
}

void password_manager::remove_entry()
{
    string target, line;

    cin.ignore();
    cout << "enter site to delete: ";
    getline(cin, target);

    ifstream file("data.txt");
    ofstream temp("temp.txt");

    if (!file || !temp)
    {
        cout << "file error\n";
        return;
    }

    int found = 0;

    while (getline(file, line))
    {
        stringstream ss(line);
        string site, user, pass;

        getline(ss, site, '|');
        getline(ss, user, '|');
        getline(ss, pass, '|');

        if (site != target)
        {
            temp << site << "|" << user << "|" << pass << endl;
        }
        else
        {
            found = 1;
        }
    }

    file.close();
    temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
        cout << "entry deleted\n";
    else
        cout << "site not found\n";
}