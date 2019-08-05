# DataStructure
Do the following exercise from the book. Follow the instructions for all assignments (one link up) and any specific additional instructions for each problem. 

Ch. 4, Programming Problem 8, pg. 157

Name the program charchain.cpp. Make sure the following requirements are met. 

Program must compile and run.
Create an ADT character string as a class (LinkedChar is name I am using) that uses a linked list of each character.
Do not use any STL container for the internal data structure.
The LinkedChar class minimally has the methods in the UML diagram below. You can add more methods.
Main function will have a menu of options.
Enter new string and store as linked list of characters in an ADT LinkedChar class
Get current length (number of characters stored) from the LinkedChar 
Find index of character in this LinkedChar 
Append another LinkedChar to this LinkedChar 
Test if another LinkedChar is submatch of this LinkedChar 
Quit
Example UML Class Diagram (missing attributes)

LinkedChar

 
LinkedChar();

LinkedChar(const std::string s);                

int length() const;

int index(char ch) const; // -1 if no match

void append(const LinkedChar& lc);

bool submatch(const LinkedChar& lc) const;

Remember to upload all files before submitting.

charchain.cpp

