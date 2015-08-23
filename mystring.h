/*
 ============================================================================
 File Name   : mystring.h
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 7-14-15          1.0         NA           Chris Jordan    None
 ============================================================================
 Description:     Header file for class myString. myString is designed to 
                  be a string class, adding convenience to and reducing errors
                  of working with c-strings.

 Public Funtions:
 
 myString();
 Precondition:    None.
 Postcondition:   An object of class myString has been created, which has a
                  c-string with only '\0'.

 myString(const char *inMyCString);
 Precondition:    inMyCString is a c-string.
 Postcondition:   An object of class myString has been created, which has a
                  inMyCString c-string.

 myString(const myString& right);
 Precondition:    right is a myString object.
 Postcondition:   An object of class myString has been created, which is a copy
                  of (the myString object) right.

 ~myString();
 Precondition:    The memory for a myString object is being deallocated.
 Postcondition:   The variable that myCString was pointing to has had its memory
                  deallocated.

 myString operator= (const myString& right);
 Precondition:    right is a myString object.
 Postcondition:   The variable that the left.myCString was pointing to has been
                  deallocated, and left.myCString now points to a copy of 
                  right.myCString.

 friend std::ostream& operator<< (std::ostream& out, const myString& right);
 Precondition:    out is an ostream. right is a myString object.
 Postcondition:   right.myCString is sent to the ostream (out).

 friend std::istream& operator>> (std::istream& in, myString& right);
 Precondition:    in is an istream. right is a myString variable.
 Postcondition:   The istream, in, will read up to 127 characters, ignoring any
                  leading whitespace, and stops at the first whitespace. The 
                  variable that right.myCString was pointing to on the heap has 
                  had its memory deallocated, and right.myCString is now pointing
                  to a new c-string from the in buffer.

 void read(std::istream& in, char delim);
 Precondition:    in is an istream. delim is the character that will be the
                  delimiting char for extraction.
 Postcondition:   The istream, in, will read up to 127 characters, including any 
                  leading whitespace, and stop as the first occurence of the
                  char, delim. The variable that right.myCString was pointing to
                  on the heap has had its memory deallocated, and right.myCString
                  is now pointing to a new c-string from the in buffer.

 long length() const;
 Precondition:    None.
 Postcondition:   Returns a long with the value of strlen(myCString).

 friend bool operator< (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left 
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is less than 0, false otherwise.

 friend bool operator<= (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is less than or equal to 0, false otherwise.

 friend bool operator> (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is greater than 0, false otherwise.

 friend bool operator>= (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is greater than or equal to 0, false otherwise.

 friend bool operator== (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is 0, false otherwise.

 friend bool operator!= (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is not 0, false otherwise.

 char operator[](int index) const;
 Precondition:    Calling object is a const myString object.
 Postcondition:   Returns the value of myCString[index].

 char& operator[](int index);
 Precondition:    Calling object is a myString object (not const).
 Postcondition:   Returns a reference to myCString[index].

 friend myString operator+ (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a new myString object, whose myCString data member
                  points to a new c-string on the heap with a value of the
                  concatenation of left.myCString and right.myCString.

 myString operator+= (const myString& right);
 Precondition:    right is a myString object or a c-string.
 Postcondition:   myCString is assigned the value of the concatenation of 
                  right.myCString and myCString.
 */


#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs2b_mystring {

   class myString {
   public:
      myString();
      myString(const char *inMyCString);
      myString(const myString& right);
      ~myString();
      myString operator= (const myString& right);
      friend std::ostream& operator<< (std::ostream& out, const myString& right);
      friend std::istream& operator>> (std::istream& in, myString& right);
      void read(std::istream& in, char delim);
      long length() const;
      friend bool operator< (const myString& left, const myString& right);
      friend bool operator<= (const myString& left, const myString& right);
      friend bool operator> (const myString& left, const myString& right);
      friend bool operator>= (const myString& left, const myString& right);
      friend bool operator== (const myString& left, const myString& right);
      friend bool operator!= (const myString& left, const myString& right);
      char operator[](int index) const;
      char& operator[](int index);
      friend myString operator+ (const myString& left, const myString& right);
      myString operator+= (const myString& right);
   private:
      char *myCString;
   }; // class end
} // namespace end

#endif


/* Output:
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Now reading myStrings from file

 ----- first, word by word
 Read string = The
 Read string = first
 Read string = time
 Read string = we
 Read string = will
 Read string = read
 Read string = individual
 Read string = words,
 Read string = next
 Read string = we
 Read string = read
 Read string = whole
 Read string = lines

 ----- now, line by line
 Read string = The  first  time  we  will
 Read string =     read individual words, next
 Read string = we read whole lines

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between myStrings
 Comparing app to apple
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing apple to
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 Comparing  to Banana
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing Banana to Banana
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

 ----- Testing relations between myStrings and char *
 Comparing he to hello
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing why to wackity
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true

 ----- Testing concatentation on myStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
 + cow = cow
 cow + bell = cowbell

 ----- Testing concatentation between myString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde

 ----- Testing shorthand concat/assign on myStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy

 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming

 ----- Testing copy constructor and operator= on myStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return myStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo
*/
