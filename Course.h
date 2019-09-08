#ifndef __Course__
#define __Course__

#include <string>
#include "Observer.h"

class Course
{

public:

    Course(int courseNumber, std::string courseName, unsigned int credits, double grade);

    Course *next;

    unsigned int courseNumber;
    std::string courseName;
    unsigned int credits;
    double grade;

    Observer tmp;

};

#endif