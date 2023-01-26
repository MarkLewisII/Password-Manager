/*
#################################
# Author: Mark Lewis            #
# Date Started : 23 / 01 / 23   #
# Last Edit : 26 / 01 / 23      #
#################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
// string GeneratePassword(int);
void GeneratePassword(int);
void test();


int main()
{
    // string pass = "test";

    int passLength = 0;

    // Read the service and username / Emaill that the password is to be assigned to

    cout << "Enter the desired legnth for your password." << endl;
    cin >> passLength;

    if (passLength <= 0)
    {
        cout << "Error: Password length must be greaer than 1." << endl;
    }
    else
    {
        cout << "Password = ";
        GeneratePassword(passLength);
        cout << endl;
        test();
    }

    return 0;
}

// void test() 
// {
//     main();
// }

// Create Account start

// Generate passwords

// string GeneratePassword(int passLength)
void GeneratePassword(int passLength)

{
    // const int passwordLength = passLength;
    // string password;
    char password[256] = {};//Fid a better way to handle the size of this array to save on memoy usage

    char characters[78] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           '!', '(', ')', '[', ']', '?', '`', '~', ';', ':', '#', '$', '%', '^', '&', '*'};

    int index;

    srand(time(0)); // Uses current time as a seed for the random character selection

    for (int i = 0; i < passLength; i++)
    {
        index = rand() % sizeof(characters);
        password[i] = characters[index];
    }

    for (int j = 0; j < passLength; j++)
    {
        cout << password[j];
    }

    // return password;
}

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

// View Existing acstd::coutns start

// Read password file
// Display information in file as a structured table

// View Existing accounts end