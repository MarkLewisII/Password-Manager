/*
#################################
# Author: Mark Lewis            #
# Date Started : 23 / 01 / 23   #
# Last Edit : 24 / 01 / 23      #
#################################
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
string GeneratePassword();

int main()
{
    string pass = "";
    int again = 0;
    do
    {

    pass = GeneratePassword();
    cout << "Password = " << pass << endl;
    cin >> again;
    } while (again == 1);


    return 0;
}

// Create Accoun start

// Generate passwords
string GeneratePassword()
{
    char password[12] = {};
    char characters[78] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           '!', '(', ')', '[', ']', '?', '`', '~', ';', ':', '#', '$', '%', '^', '&', '*'};

    int index;

    for (int i = 0; i < sizeof(password); i++)
    {
        index = rand() % sizeof(characters);
        password[i] = characters[index];
    }

    return password;
}
// Check passwords against dictionary
// Read the service and username / Emaill that the password is to be assigned to
// store all information to a structured file.

// Create account end

// Edit existing information start

// Check if the service and username / Email entered is already exists
// Notify user that account already exists
// Generate new password for that account

// Edit existing information end

// Delete account start

// Provide an option to Delete an account
// Read chosen account by service and username
// Delete all information associated with that account.

// Delete account end

// View Existing accoutns start

// Read password file
// Display information in file as a structured table

// View Existing accounts end