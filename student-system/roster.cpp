//
//  roster.cpp
//  student-system
//
//  Created by Leon Redman on 4/18/22.
// cpp file for definitions -> actual function code

#include <stdio.h>
#include <iostream>
#include <string>
#include "roster.h"


using namespace std;

 
//  Define Roster class functions:

// a. Parse each set of data identified in the “studentData Table.” and add each student object to classRosterArray
void Roster::studentParse(string studentData){
    
    size_t rhs = studentData.find(",");                 // find the first comma and returns index
    string studentID = studentData.substr(0, rhs);      // subst starts at 0 and the right hand side index and gives us the ID
    
    size_t lhs = rhs + 1;                       // To reset lhs we add one after the comma and search to next comma left hand side
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int intNumber = stoi(studentData.substr(lhs, rhs - lhs));  // int uses STOI string to int, puts in the variable int Number
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string strDegreeProgram = studentData.substr(lhs, rhs - lhs);
    
     DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
    
    if (strDegreeProgram == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    else if (strDegreeProgram == "SECURITY"){
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (strDegreeProgram == "NETWORK"){
        degreeProgram = DegreeProgram::NETWORK; }
    
    // call add function - add(parsed data) to each student object to classRosterArray.
    add(studentID, firstName, lastName, emailAddress, intNumber, daysInCourse1,daysInCourse2, daysInCourse3,degreeProgram);
 }


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    // sets the instance variables from part D1 and updates the roster.
    // loop thru and add for all 5 students of the array
    int daysInArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3}; //data to be added back into an array
    
    classRosterArray[++lastArrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInArray, degreeProgram);
}


void Roster::remove(string studentID){
    // Function removes students from  roster by student ID. If student ID does not exist, prints error message stating student not found.
      
    bool completed = false;  // assume student id is false
    
    for ( int i = 0; i <= Roster::lastArrayIndex; i++)  // search for object with student id and run loop
    {
        if (classRosterArray[i]->getStudentID() == studentID)   //   If found then show id
        {
            completed = true;
            
                if (i < studentDataArray -1)
                {
                    Student* tempStudVar = classRosterArray[i];  // create temp varible
                    classRosterArray[i] = classRosterArray[studentDataArray - 1];
                    classRosterArray[studentDataArray - 1] = tempStudVar;
                }
                    Roster::lastArrayIndex--;
                }
        }
    if (completed)     // Can use flag(bool) to display if it has not been found, message is put inside loop
    {
        cout << endl << studentID << " removed from roster." << endl << endl;
         this->printAll();
       // return ;
    }
    else cout << endl << "Student with ID: " << studentID << " was not found."<< endl << endl;
    
}


void Roster::printAll(){
    // function that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
   // cout << "Displaying all students:" << endl;
    for (int i = 0; i <= Roster::lastArrayIndex; i++) Roster::classRosterArray[i]->print();  // each student has own print method
}


void Roster::printAverageDaysInCourse(string studentID){
    // Function  that correctly prints a student’s average number of days in the three courses.
    // The student is identified by the studentID parameter.
    // search for stud id with loop,
    // add and divide by 3 days in course,
    // use 4 loop ( get stud id to compare , get all 3)
   
    for ( int i = 0; i <= Roster::lastArrayIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << "Student ID: " << studentID <<
            ", average days in course is: " << (classRosterArray[i]->getNumDaysCompleteCourse()[0] +
                     classRosterArray[i]->getNumDaysCompleteCourse()[1] +
                     classRosterArray[i]->getNumDaysCompleteCourse()[2]) / 3 << endl;
        }
    }
}


void Roster::printInvalidEmails() {
    // Function verifies student email addresses, displays all invalid email addresses to user.
    // Note: A valid email should include an at sign ('@') and period ('.') and not include a space (' ').
    
    cout << endl << "Displaying all invalid emails:" << endl <<endl;
    for ( int i = 0; i <= Roster::lastArrayIndex; i++)          // will use same loop for email function
    {
        string email = classRosterArray[i]->getEmailAddress();  //Retrieves email address
        
        if ( email.find('.') == string::npos || email.find(' ') != string::npos || email.find('@') == string::npos)     // searches for conditions
            cout << email << " - this email is invalid" << endl;     // displays all the invalid emails
    }
}
    

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    // f. prints out student information for a degree program specified by an enumerated type.
    string degreeProgram_string;
    cout << endl << "Showing students in degree program: SOFTWARE" << endl << endl;
    for (int i = 0; i < 5; i++){
        if (degreeProgram == classRosterArray[i]->getDegreeProgram())
        {
            Roster::classRosterArray[i]->print();  // can just call function to print
        }
    }
}


Roster::~Roster(){
    // Including the destructor function
    return;
}
