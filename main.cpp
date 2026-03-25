#include <iostream>
#include "password_manager.h"

using namespace std;

int main()
{
    string master = "1234";
    string input;

    cout << "enter master password: ";
    cin >> input;

    if (input != master)
    {
        cout << "access denied\n";
        return 0;
    }

    password_manager pm;
    int choice;

    while (1)
    {
        cout << "\n1. add\n2. view\n3. search\n4. delete\n5. exit\nenter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            pm.add();
        }
        else if (choice == 2)
        {
            pm.view();
        }
        else if (choice == 3)
        {
            pm.search();
        }
        else if (choice == 4)
        {
            pm.remove_entry();
        }
        else if (choice == 5)
        {
            cout << "exiting...\n";
            break;
        }
        else
        {
            cout << "invalid choice\n";
        }
    }

    return 0;
}