/*
#################################
# Author: Mark Lewis            #
# Date Started : 23 / 01 / 23   #
# Last Edit : 31 / 01 / 23      #
#################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdio>

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

void GetService(Entry currentEntry);
void GetEmail(Entry currentEntry);
void GetUsername(Entry currentEntry);
void GetPassword(Entry curentEntry);

void CreateNewFile();

void test(); // Disposable test function for looping

int main()
{
    Entry currentEntry;
    fstream PasswordTest;

    PasswordTest.open("Accounts/PasswordTest.txt");

    if (!PasswordTest)
    {
        cout << "An existing Password file was not found." << endl
             << "Creating a new one..." << endl;
        CreateNewFile();
    }
    // Read the service and username / Emaill that the password is to be assigned to
    GetService(currentEntry);
    GetEmail(currentEntry);
    GetUsername(currentEntry);
    GetPassword(currentEntry);
    WriteDataToFile(currentEntry);

    test(); // temp test file

    return 0;
}

void GetService(Entry currentEntry)
{
    cout << "Enter the service that this accout belongs to." << endl;
    cin >> currentEntry.Service;
}

void GetEmail(Entry currentEntry)
{
    const char *emailDomains[5] = {"@gmail.com",
                                   "@yahoo.com",
                                   "@outlook.com",
                                   "@hotmail.com",
                                   "@hotmail.co.uk"};
    int emailCheck;
    char choice; 

    cout << "Enter the  email address used with this acount." << endl;
    cin >> currentEntry.Email;

    for (int i = 0; i < sizeof(emailDomains); i++)
    {
        (currentEntry.Email.find(emailDomains[i]) != string::npos) ? emailCheck = 1 : emailCheck = 0;
    }

    if (emailCheck == 0)
    {
        cout << "Warning: Entered email address does not fit a recognised domain."
             << "Would you like to proceed with current the entered email address or enter a new one?"
             << "Enter new email? Y/N"
             << endl;
        cin >> choice;
    }

    if ((choice == 'y') || (choice == 'Y'))
    {
        GetEmail(currentEntry);
    }
}

void GetUsername(Entry currentEntry)
{
    cout << "Enter the  usesrname for this acount." << endl;
    cin >> currentEntry.Username;
}

void GetPassword(Entry currentEntry)
{
    int passLength = 0;

    cout << "Enter the desired legnth for your password." << endl;
    cin >> passLength;

    if (passLength <= 0)
    {
        cout << "Error: Password length must be greaer than 1." << endl;
    }
    else
    {
        currentEntry.Password = GeneratePassword(passLength);
    }
}

void CreateNewFile()
{
    fstream PasswordTest; // Temp name

    PasswordTest.open("Accounts/PasswordTest.txt", ios::out);
    if (!PasswordTest)
    {
        cout << "Error: Unable to create a new file." << endl;
    }
    else
    {
        cout << "A new file has been created successfully." << endl;
    }

    PasswordTest << "+" << setfill('-') << setw(22)
                 << "+" << setw(27)
                 << "+" << setw(15)
                 << "+" << setw(28)
                 << "+" << endl;
    PasswordTest << "|Service" << setfill(' ') << setw(20)
                 << "|Email" << setw(30)
                 << "|Username" << setw(15)
                 << "|Password" << setw(20)
                 << "|" << endl;
    PasswordTest << "+" << setfill('-') << setw(22)
                 << "+" << setw(27)
                 << "+" << setw(15)
                 << "+" << setw(28)
                 << "+" << endl;
}

void WriteDataToFile(Entry currentEntry)
{
    fstream PasswordTest; // Temp file name

    PasswordTest.open("Accounts/PasswordTest.txt", ios::app); // Open password file
    if (!PasswordTest)
    {
        cout << "Error: Unable to open file." << endl;
    }

    PasswordTest << "|" << currentEntry.Service << setw(20)
                 << "|" << currentEntry.Email << setw(30)
                 << "|" << currentEntry.Username << setw(15)
                 << "|" << currentEntry.Password << setw(20)
                 << "|";
    PasswordTest << "+" << setfill('-') << setw(22)
                 << "+" << setw(27)
                 << "+" << setw(15)
                 << "+" << setw(28)
                 << "+" << setfill(' ') << endl;

    PasswordTest.close(); // Close oppened password file
}

void DeleteFile()
{
    char filename[] = "Accounts/PasswordTest.txt";
    int result = remove(filename);

    if (result != 0)
    {
        cout << "Error: Unable to delete file..." << endl;
    }
    else
    {
        cout << "File successfully deleted..." << endl;
    }
}

void test() // Temp function for looping while testing
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