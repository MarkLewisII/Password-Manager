/*
#################################
# Author: Mark Lewis            #
# Date Started : 23 / 01 / 23   #
# Last Edit : 30 / 01 / 23      #
#################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Entry
{
public:
    string Service = " ";
    string Email = " ";
    string Username = " ";
    string Password;
};

string GeneratePassword(const int);
void WriteDataToFile(Entry currentEntry);

void test(); // Disposable test function for looping

int main()
{
    Entry currentEntry;

    int passLength = 0;

    // Read the service and username / Emaill that the password is to be assigned to

    cout << "Enter the service that this account belongs to." << endl;
    cin >> currentEntry.Service;

    cout << "Enter the  email address used with this acount." << endl;
    cin >> currentEntry.Email;

    cout << "Enter the  usesrname for this acount." << endl;
    cin >> currentEntry.Username;

    cout << "Enter the desired legnth for your password." << endl;
    cin >> passLength;

    if (passLength <= 0)
    {
        cout << "Error: Password length must be greaer than 1." << endl;
    }
    else
    {
        currentEntry.Password = GeneratePassword(passLength);
        WriteDataToFile(currentEntry);

        test();
    }

    return 0;
}

void WriteDataToFile(Entry currentEntry)
{
    fstream PasswordTest; // Temp file name

    PasswordTest.open("PasswordTest.txt", ios::app); // Open password file
    if (!PasswordTest)
    {
        cout << "Error creating / openning file." << endl;
    }
    else
    {
        cout << "File creation / openning was successful!" << endl;
    }

    PasswordTest << "Service --> " << currentEntry.Service << endl
                 << "Email --> " << currentEntry.Email << endl
                 << "Username --> " << currentEntry.Username << endl
                 << "Password --> " << currentEntry.Password << endl
                 << "==============================================" << endl;

    PasswordTest.close(); // Close oppened password file
}

void test()
{
    main();
}

string GeneratePassword(const int passLength)
{
    string password;
    password.reserve(passLength);

    char characters[78] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           '!', '(', ')', '[', ']', '?', '`', '~', ';', ':', '#', '$', '%', '^', '&', '*'};

    srand(time(0)); // Uses current time as a seed for the random character selection

    for (int i = 0; i < passLength; i++)
    {
        password += characters[rand() % sizeof(characters)];
    }

    return password;
}

// Create Account start

// Generate passwords

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