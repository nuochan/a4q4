//
//  main.cpp
//  a4q4
//
//  Created by Chris Chen on 2014-03-15.
//  Copyright (c) 2014 Nuo Chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int size = 0;
int bin2Dec(const char [], const int);
int bin2Dec(const char []);

int main()
{
    int maxSize = 65535;
    string binaryString;
    char binStr[maxSize];
    int invalidNumber = 0;
    
    do{
        invalidNumber = 0;
        cout << "enter a binary number: ";
        cin >> binaryString;
        cin.sync();
        
        for(int i = 0; i < binaryString.length(); i++){
            if(binaryString[i] != '1' && binaryString[i] != '0'){
                invalidNumber++;
            }
        }
        if(invalidNumber > 0){
            cout << "invalid input." << endl;
        }else cout << "input legit." << endl;
    }while(invalidNumber != 0);

    size = static_cast<int>(binaryString.length());
    strncpy(binStr, binaryString.c_str(), sizeof(binStr));
    cout << "the decimal equivalent of: " << binaryString << " is " << bin2Dec(binStr) << endl;
    return 0;
}

int bin2Dec(const char binaryString[]){
    int dec = 0;
    for(int i = 0; i < size; i++){
        switch (binaryString[i]) {
            case '1':
                dec = dec + pow( 2, size - i - 1 );
                break;
            case '0':
                dec = dec + pow( 0, size - i - 1 );
                break;
            default:
                break;
        }
    }
    return dec;
}
