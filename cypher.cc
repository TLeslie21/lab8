#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std;

void displayMenu();
int key(int keyAmount);
string encrypt(string text, int key);
string decrypt(string text, int key);

int main()
{  
    return 0;
}

void displayMenu(){ 
    string choice;
    string one = "1. Set the shift key value";
    cout << one;
    string two = "2. Encrypt a file";
    cout << two;
    string three = "3. Decrypt a file";
    cout << three;
    string four = "4. Quit";
    cout << four;
}

int key(int keyAmount){
    int keyCount;
    cin >> keyCount;
    if (keyCount == 1){
        keyCount = 1;
    }
    if (keyCount == 2){
        keyCount = 2;
    }
    if (keyCount == 3){
        keyCount = 3;
    }
    if (keyCount == 4){
        keyCount = 4;
    }
    if (keyCount == 5){
        keyCount = 5;
    }
    if (keyCount == 6){
        keyCount = 6;
    }
    if (keyCount == 7){
        keyCount = 7;
    }
    if (keyCount == 8){
        keyCount = 8;
    }
    if (keyCount == 9){
        keyCount = 9;
    }
    if (keyCount == 10){
        keyCount = 10;
    }
    return 0;
}