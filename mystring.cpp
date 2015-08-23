/*
 ============================================================================
 File Name   : mystring.cpp
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 7-14-15          1.0         NA           Chris Jordan    None
 ============================================================================
 
 Description : Implementation file for myString class. An object of class myString
 contains one data member, myCString, which is a pointer to a c-string.

 The myCString gives myString objects some functionality of a string class. The
 variable that myCString points to is protected against memory leak.
 */

#include <iostream>
#include <cassert>
#include "mystring.h"

using namespace std;

namespace cs2b_mystring {






    myString::myString() {
        myCString = new char[1];
        strcpy(myCString, "");
    }






    myString::myString(const char *inMyCString) {
        myCString = new char[strlen(inMyCString)+1];
        strcpy(myCString, inMyCString);
    }






    myString::myString(const myString& right) {
        myCString = new char[strlen(right.myCString)+1];
        strcpy(myCString, right.myCString);
    }






    myString::~myString() {
        delete [] myCString;
    }






    myString myString::operator= (const myString& right) {
        if (this != &right) {
            delete [] myCString;
            myCString = new char[strlen(right.myCString)+1];
            strcpy(myCString, right.myCString);
        }
        return *this;
    }






    ostream& operator<< (ostream& out, const myString& right) {
        out << right.myCString;
        return out;

    }






    istream& operator>> (istream& in, myString& right) {
        
        char inBufferHolder[128];
        in.width(128);
        in >> inBufferHolder;
        delete [] right.myCString;
        right.myCString = new char [strlen(inBufferHolder)+1];
        strcpy(right.myCString, inBufferHolder);
        return in;
    }






    void myString::read(istream& in, char delim) {
        char inBufferHolder[128];
        in.getline(inBufferHolder, 128, delim);
        delete [] myCString;
        myCString = new char [strlen(inBufferHolder)];
        strcpy(myCString, inBufferHolder);
    }






    long myString::length() const {
        return (strlen(myCString));
    }






    bool operator< (const myString& left, const myString& right) {
        return (strcmp(left.myCString,right.myCString) < 0);
    }






    bool operator<= (const myString& left, const myString& right) {
        return (strcmp(left.myCString,right.myCString) <= 0);
    }






    bool operator> (const myString& left, const myString& right) {
        return (strcmp(left.myCString,right.myCString) > 0);
    }






    bool operator>= (const myString& left, const myString& right) {
        return (strcmp(left.myCString,right.myCString) >= 0);
    }






    bool operator== (const myString& left, const myString& right) {
        return (strcmp(left.myCString,right.myCString) == 0);
    }






    bool operator!= (const myString& left, const myString& right) {
        return (strcmp(left.myCString,right.myCString) != 0);
    }






    char myString::operator[](int index) const {
        assert(index >= 0 && index < strlen(myCString));
        return myCString[index];
    }






    char& myString::operator[](int index) {
        assert(index >= 0 && index < strlen(myCString));
        return myCString[index];
    }
    
    
    
    
    
    
    myString operator+ (const myString& left, const myString& right) {
        char *Cstring = new char [strlen(left.myCString) + strlen(right.myCString) + 1];
        myString result = myString(Cstring);
        strcpy(result.myCString, left.myCString);
        strcat(result.myCString, right.myCString);
        return result;
    }
    
    
    
    
    
    
    myString myString::operator+= (const myString& right) {
        *this = *this+right;
        return *this;
    }
    
    
} // namespace end
