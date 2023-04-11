//
//  student.h
//  student-system
//
//  Created by Leon Redman on 4/18/22.
//
// Create the Student class, which includes variables:
// student ID, first name, last name, email address, age, array of number of days to complete each course, degree program
// (class definition includes data members and member function declarations)

#ifndef student_h
#define student_h
#include<iostream>
#include <string>
#include"degree.h"

using namespace std;

class Student {
    
    public:
        const static int daysCompleteArraySize = 3;  // declares size of array constant
        
    private:
        // data members - variables set to private
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int numDaysCompleteCourse[daysCompleteArraySize];
        DegreeProgram degreeProgram;

   public:

    // 2 constructors - (need both)
    Student();   //  default constructor(empty)
    
    // constructor w/all input parameters provided from table
    Student (string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysCompleteCourse[], DegreeProgram degreeProgram);
    
    ~Student();  // declare destructor
    
    // Declare functions
    
    // (mutators - setters) in Student class: for each instance variable from part D1 set public
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumDaysCompleteCourse(int numDaysCompleteCourse[]); // send in as array
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // (accessors - getters) / public - retrieves copy of data stored)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge ();
    int* getNumDaysCompleteCourse(); // cannot return arrays, only pointers (pointer and array name are the same thing)
    DegreeProgram getDegreeProgram();
    
    // print() function to print specific student data
    void print();
};

#endif /* student_h */
