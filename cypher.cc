#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void displayMenu();
int keyAmount(int keyCount);
string encrypt(int key);
string decrypt(string text, int key);

int main()
{
    int choice;
    int key;
    key = 3;
    ifstream inStream;
    string inFileName = "input1.txt";
    ofstream outStream;
    string outFileName;
    string randomString;

    do
    {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;
        if (choice == 1)
        {
            keyAmount(key);
        }
        if (choice == 2)
        {
            encrypt(key);
            randomString = randomString + encrypt(key);
        }
        if (choice == 3)
        {
            randomString = randomString + decrypt(randomString, key);
        }
    } while (choice != 4);
    return 0;
}

void displayMenu()
{
    string choice;
    string one = "1. Set the shift key value \n";
    cout << one;
    string two = "2. Encrypt a file \n";
    cout << two;
    string three = "3. Decrypt a file \n";
    cout << three;
    string four = "4. Quit \n";
    cout << four;
}

int keyAmount(int key)
{
    int keyCount;
    int keyAmount = 3;
    do
    {
        cout << "Set a key amount between 1 and 10: ";
        cin >> keyCount;
        if (keyCount >= 1 && keyCount <= 10)
        {
            keyAmount = keyCount;
        }
    } while (keyCount < 1 || keyCount > 10);
    return 0;
}

string encrypt(int key)
{
    ifstream inStream;
    string inFileName = "input1.txt";
    ofstream outStream;
    string outFileName;
    char ch;
    int keyCount = 3;
    string randomString;

    cout << "Enter the input file name: ";
    cin >> inFileName;
    inStream.open(inFileName);
    if (inStream.fail()) // Run if input file cannot be opened
    {
        cout << "Error: the input file name does not exist " << endl;
        exit(0);
    }

    cout << "Enter the output file name: ";
    cin >> outFileName;
    outStream.open(outFileName);
    if (outStream.fail()) // Run if output file cannot be opened
    {
        cout << "Error: failed to open " << endl;
        exit(0);
    }
    while (!inStream.eof())
    {

        while (inStream.get(ch))
        {

            int length = randomString.length();
            for (int i = 0; i < length; i++)
            {
                int encryptKey = keyAmount(keyCount);
                ch = randomString.at(i);
                ch = ch + encryptKey;
            }
            cout << randomString;
        }
    }
    return 0;
    ;
}

string decrypt(string text, int key)
{
    ifstream inStream;
    string inFileName = "input1.txt";
    ofstream outStream;
    string outFileName;
    char ch;
    int keyCount = 3;
    string randomString;
    int length = randomString.length();

    cout << "Enter the input file name: ";
    cin >> inFileName;
    inStream.open(inFileName);
    if (inStream.fail()) // Run if input file cannot be opened
    {
        cout << "Error: the input file name does not exist " << endl;
        exit(0);
    }

    cout << "Enter the output file name: ";
    cin >> outFileName;
    outStream.open(outFileName);
    if (outStream.fail()) // Run if output file cannot be opened
    {
        cout << "Error: failed to open " << endl;
        exit(0);
    }
    while (!inStream.eof())
    {
        while (inStream.get(ch))
        {
            int encryptKey = keyAmount(keyCount);
            for (int i = 0; i < length; i++)
            {
                ch = randomString.at(i);
                ch = ch - encryptKey;
            }
        }
    }
    return 0;
    ;
}