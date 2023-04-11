//
//  roster.h
//  student-system
//
//  Created by Leon Redman on 4/18/22.
//  .h file for Declarations of functions

#ifndef roster_h
#define roster_h


#include "student.h"

using namespace std;

    // create Roster class

class Roster {
    
    // inside class create an array of pointers called classRoster with 5 elements, array of pointers is, Object Type: Student / Name: classRosterArray
    //contains pointers to objects of class Student
   
   
public:
    
    
    Student* classRosterArray[5]; // made public to do average function
   
    int lastArrayIndex = -1;   // set index of classRosterArray, -1 means empty array
    const int studentDataArray = 5;
    
    // Declare Public functions - to move data in and out of object:
   
    // Parse each set of data identified in the “studentData Table.”
    void studentParse(string studentData);
    
    // 'Add function' grabs student data and makes a student object in classRosterArray
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    // remove(string studentID)
    void remove(string studentID);
    
    // printAll() that prints a complete tab-separated list of student data
    void printAll();
    
    // printAverageDaysInCourse(string studentID) - prints student’s average num of days
    void printAverageDaysInCourse(string studentID);
    
    // printInvalidEmails() verifies student email addresses and displays all invalid
    void printInvalidEmails();
    
    // printByDegreeProgram(DegreeProgram degreeProgram) - prints student info for degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // Destructor function is needed for class
    ~Roster();
    
    
};

#endif /* roster_h */

