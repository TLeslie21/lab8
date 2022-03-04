#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void displayMenu();
int keyValue();
string encrypt(int key);
string decrypt(int key);

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
            key = keyValue();
        }
        if (choice == 2)
        {
            encrypt(key);
        }
        if (choice == 3)
        {
            decrypt(key);
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

int keyValue()
{
    int keyCount;
    do
    {
        cout << "Set a key amount between 1 and 10: ";
        cin >> keyCount;
    } while (keyCount < 1 || keyCount > 10);
    return keyCount;
    ;
}

string encrypt(int key)
{
    ifstream inStream;
    string inFileName = "input1.txt";
    ofstream outStream;
    string outFileName;
    char ch;

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
            ch = ch + key;
            outStream << ch;
        }
    }
    inStream.close();
    outStream.close();

    return 0;
}

string decrypt(int key)
{
    ifstream inStream;
    string inFileName = "input1.txt";
    ofstream outStream;
    string outFileName;
    char ch;

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
                ch = ch - key;
                outStream << ch;
            }
    }
    inStream.close();
    outStream.close();

    return 0;
}