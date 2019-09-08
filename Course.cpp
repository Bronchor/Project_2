#include "Course.h"

Course::Course(int courseNumber, std::string courseName, unsigned int credits, double grade) : tmp(this)
{
    this->next = nullptr;               // this node has a pointer to the next node
    this->courseNumber = courseNumber;  // this node contains data for a course number
    this->courseName = courseName;      // this node contains data for a course name
    this->credits = credits;            // this node contains data for course credits (0-4)
    this->grade = grade;                // this node contains data for course grade (0.0-4.0)
}