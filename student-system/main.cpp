//
//  main.cpp
//  student-system
//
//  Created by Leon Redman on 4/18/22.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


 int main() {
     // declared & initialized array
const string studentData[] = {
    
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Leon,Redman,lredma5@wgu.edu,49,23,50,21,SOFTWARE"
};
    
     
     // F1. Print course title, Prog. Language used, your WGU ID, and full name
     cout << "C867 Scripting & Programming Applications" << endl;
     cout << "Programming Language: C++" << endl;
     // your WGU student ID,
     cout << "WGU Student ID: #009923434" << endl;
     // and your name, in main()
     cout << "Name: Leon Redman" << endl << endl;
     cout << "Displaying all students:" << endl;
     // cout << "Displaying all students:" << endl;
     
     // F2. Create an instance of the Roster class called classRoster.
     const int numDays = 5;
     
     Roster classRoster;  // runs and parses everything using the constructor
     
     // F3. - Add each student to classRoster.
     for (int i = 0; i < 5; i++) {
         classRoster.studentParse(studentData[i]);
     }
     
     
     // - Convert the following pseudo code to complete the  main() function:
   
     classRoster.printAll();
     
    
     classRoster.printInvalidEmails();
     // - loop through classRosterArray and for each element:
     
     // classRoster.printAverageDaysInCourse(/*current_object's student id*/);
     // Note: For current_object's student id, use getter for classRosterArray to access student id.
     cout << endl << "Displaying Average For Each Student" << endl << endl;
     for ( int i = 0; i < numDays; i++) classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->Student::getStudentID());
    
         
     classRoster.printByDegreeProgram(SOFTWARE);
     
     
     classRoster.remove("A3");
    
     
     classRoster.remove("A3");  // expected: should print a message saying such a student with this ID was not found.
  
     
     // 5. Implement the destructor to release the memory that was allocated dynamically in Roster.
     classRoster.~Roster();
     
     return 0;
 };

