//
//  student.cpp
//  student-system
//
//  Created by Leon Redman on 4/18/22.
//
// student.cpp contains student class member function definitions.

#include <stdio.h>
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

    // create Student object

    // default constructor (empty, so set all strings to empty "" etc.
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    this->numDaysCompleteCourse[0] = 0;  // set each array item instead of loop for array
    this->numDaysCompleteCourse[1] = 0;
    this->numDaysCompleteCourse[2] = 0;
    this->degreeProgram = SOFTWARE;
}

    // full constructor using all parameters from table
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysCompleteCourse[], DegreeProgram degreeProgram)
{
    // this-> used to set local variables not a copy of itself, can also rename if wanted
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->numDaysCompleteCourse[0] = numDaysCompleteCourse[0]; // could use array loop instead also
    this->numDaysCompleteCourse[1] = numDaysCompleteCourse[1];
    this->numDaysCompleteCourse[2] = numDaysCompleteCourse[2];
    this->degreeProgram = degreeProgram;
}


    // Mutators (setters functions to move data in and out) (setters must use "this)

    void Student::setStudentID(string studentID)
    {
    this->studentID = studentID;
    }

    void Student::setFirstName(string firstName)
    {
    this->firstName = firstName;
    }

    void Student::setLastName(string lastName)
    {
    this->lastName = lastName;
    }

    void Student::setEmailAddress(string emailAddress)
    {
    this->emailAddress = emailAddress;
    }

    void Student::setAge(int age)
    {
    this->age = age;
    }

    void Student::setNumDaysCompleteCourse(int numDaysCompleteCourse[]){
        this->numDaysCompleteCourse[0] = numDaysCompleteCourse[0];
        this->numDaysCompleteCourse[1] = numDaysCompleteCourse[1];
        this->numDaysCompleteCourse[2] = numDaysCompleteCourse[2];
    }

    void Student::setDegreeProgram(DegreeProgram degreeProgram)
    {
        this->degreeProgram = degreeProgram;
    }

    //Accessor (getters, must use "this", but optional in constructors)
    string Student::getStudentID()
    {
        return this->studentID;
    }

    string Student::getFirstName()
    {
        return this->firstName;
    }

    string Student::getLastName()
    {
        return this->lastName;
    }

    string Student::getEmailAddress()
    {
        return this->emailAddress;
    }

    int Student::getAge()
    {
        return this->age;
    }

    int* Student::getNumDaysCompleteCourse()
    {
        return this->numDaysCompleteCourse;   // returns address of the pointer zero element
    }

    DegreeProgram Student::getDegreeProgram()
    {
        return this->degreeProgram;
    }


    // print() function for specific student data
    void Student::print()
    {

    // degreeProgram has an enum
    string degreeProgram_string;
    if (degreeProgram == DegreeProgram::SOFTWARE){
        degreeProgram_string = "Software";
    }
    else if (degreeProgram == DegreeProgram::SECURITY){
        degreeProgram_string = "Security";
    }
    else if (degreeProgram == DegreeProgram::NETWORK){
        degreeProgram_string = "Network";
    }
    
    cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t"  << "Age: " << age << "\t"  << "daysInCourse: {"  << numDaysCompleteCourse[0] << ", " << numDaysCompleteCourse[1] << ", " << numDaysCompleteCourse[2] << "} " << "Degree Program: " << degreeProgram_string << endl;
    
    return;
}
