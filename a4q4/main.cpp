//
//  CS-110 Assignment 4 Question 4
//  Nuo Chen
//  200327119
//  Created by Nuo Chen on 2014-03-15.
//  Introduction:prompt user to input a sequence of '1' and '0'(binary numbers)
//               then turn them input decimal numbers and output
//

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

//globle variable size so that i dont have to pass it
//everytime i call function
int size = 0;
//int bin2Dec(const char [], const int);
//function translate binary numbers into decimal numbers
//date type of function is long which is 8 byte in 64 bit
//OS so the longest input string this function can handle
//would be 8 * 8 - 2 = 62 digits
long bin2Dec(const char []);

int main()
{
    //array declare as unsign because size of array
    //doesn't involve negative numbers
    const unsigned maxSize = 65535;
    //store input string
    string binaryString;
    //character array to pass to function bin2Dec
    char binStr[maxSize];
    //if user input numbers other than '0' and '1', prompt user
    //to re-input
    int invalidNumber = 0;
    
    //while loop for input string and check intput validity
    do{
        //input string
        invalidNumber = 0;
        cout << "enter a binary number: ";
        cin >> binaryString;
        //flush buffer
        cin.sync();
        
        //check validity
        for(int i = 0; i < binaryString.length(); i++){
            if(binaryString[i] != '1' && binaryString[i] != '0'){
                invalidNumber++;
            }
        }
        //output result
        if(invalidNumber > 0){
            cout << "invalid input." << endl;
        }else cout << "input legit." << endl;
    }while(invalidNumber != 0);

    //store size of input string in size
    size = static_cast<int>(binaryString.length());
    //turn a string into a character array
    strncpy(binStr, binaryString.c_str(), sizeof(binStr));
    //output the corespondent decimal number
    cout << "the decimal equivalent of: " << binaryString << " is " << bin2Dec(binStr) << endl;
    return 0;
}

long bin2Dec(const char binaryString[]){
    long dec = 0;
    for(int i = 0; i < size; i++){
        //if it's '1', plus 2^(size-i-1)*1
        //if it's '0', puls 2^(size-i-1)*0
        //defualt will never reach because input
        //validity has already been check before
        //calling the function
        switch (binaryString[i]) {
            case '1':
                dec = dec + pow( static_cast<float>(2), size - i - 1 ) * 1;
                break;
            case '0':
                dec = dec + pow( static_cast<float>(2), size - i - 1 ) * 0;
                break;
            default:
                break;
        }
    }
    return dec;
}
