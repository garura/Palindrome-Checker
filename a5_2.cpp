//============================================================================
//File Name   : a5_2.cpp
//Author      : Chris Jordan
//Revision History: None
//Date             Version     Change ID    Author          Comment
//7-18-15          1.0         NA           Chris Jordan    None
//============================================================================


#include <iostream>
#include "mystring.h"
#include <cctype>

using namespace std;
using namespace cs2b_mystring;

bool isAPalindrome(myString string, int start, int end);
void checkForPalindrome();

int main() {

    checkForPalindrome();

}





// base case: start >= end (return true)
// strategy: if char is not a letter, go to next char
//           compare myString[start] to myString[end].
// if true:  compare myString[start+1] to myString[end-1].

bool isAPalindrome(myString string, int start, int end) {
    while ((isspace(string[start]) || ispunct(string[start])) && start<end) {
            start += 1;
    }
    while ((isspace(string[end]) || ispunct(string[end])) && end>0) {
            end -= 1;
    }
    if (start >= end) {
        return true;
    }
    else if (toupper(string[start]) == toupper(string[end])) {
        return isAPalindrome(string, start+1, end-1);
    }
    else {
        return false;
    }
}




void checkForPalindrome() {
    myString check = myString();
    bool playing = true;
    while (playing) {
        cout << "Enter a string: ";
        check.read(cin, '\n');
        if (check == "quit") {
            playing = false;
        }
        else {
            if (isAPalindrome(check, 0, (int) check.length()-1)) {
                cout << check << " is a palindrome" << endl;
            }
            else {
                cout << check << " is not a palindrome" << endl;
            }
        }
    }
}



/* Output
 Enter a string: A man, a plan, a canal; Panama
 A man, a plan, a canal; Panama is a palindrome
 Enter a string: butter
 butter is not a palindrome
 Enter a string: quit
*/








