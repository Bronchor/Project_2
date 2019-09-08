// Information 📄✔
//   I wrote all this code except what my instructor provided.
//
//   Project: (#2) Recursive Linked List
//   Student: Jackson Reed
//   Course: CS2420-610
//   Date: Sep 5, 2019

// Abstraction 🚙✔
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Observer.h"
#include "RecursionCounter.h"
using namespace std;

// Testing 🔍✔
int RecursionCounter::maxDepth = 0;
int RecursionCounter::currentDepth = 0;
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
std::set<void *> Observer::allocatedCourses;

int main() {

// Open File 📂✔
   const char dataFileName[] = "data.txt";  // specify name of data file
   ifstream fileData;                       // declare input file stream
   fileData.open(dataFileName);             // try to open file to read

// File Error 🛑✔
   if (!fileData.good())                                                // check for file errors
   {
      cout << "ERROR: can't open data file: " << dataFileName << endl;  // print error message
      cout << endl << "Press the [Enter] key to quit...";               // print final message

      cin.get();                                                        // wait for user input
      return -1;                                                        // return error code
   }

// Store Data 📦✔
    {
       LinkedList courseList;                                                       // create list to store data
       // LINKED LIST IS INITIALLY CREATED WITH ZERO COURSES 10/10 ✔
       string readField;                                                            // initialize read string

    while (!fileData.eof())                                                         // read file until the end
    {
        getline(fileData, readField, ',');                                          // read until a comma
        int courseNumber = stoi(readField);                                         // parse course number

        getline(fileData, readField, ',');                                          // read until a comma
        string courseName = readField;                                              // store course name

        getline(fileData, readField, ',');                                          // read until a comma
        unsigned int credits = stoi(readField);                                     // parse course credits

        getline(fileData, readField);                                               // read until a comma
        double grade = stod(readField);                                             // parse course grade

        Course* newCourse = new Course(courseNumber, courseName, credits, grade);   // create new course with data
        // COURSE CAN BE CONSTRUCTED FROM PARAMETERIZED CONSTRUCTOR 10/10 ✔
        courseList.Insert(newCourse);                                               // insert course in linked list
    }
        // COURSE IS PROPERLY DESTRUCTED AFTER GOING OUT OF SCOPE 10/10 ✔
        fileData.close();                                                           // close file at end of loop

// Use Data 🛠✔
   courseList.PrintList();                                  // print courses in order
   double gpa = courseList.CalculateGPA();                  // calculate and store GPA
   cout.precision(4);                                       // set decimal place precision
   cout << "Cumulative GPA: " << gpa << endl;               // print GPA with high precision
   cout << endl << "Press the [Enter] key to quit...";      // print final message
   cin.get();                                               // wait for user input
   }

return 0; }
