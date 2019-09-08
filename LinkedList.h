#ifndef __LinkedList__
#define __LinkedList__

#include "Course.h"
#include "RecursionCounter.h"

class LinkedList
{

public:
    LinkedList() { head = nullptr; }
    ~LinkedList();

    void PrintList() const;
    void Insert(Course * newCourse);
    int Size() const;
    double CalculateGPA() const;

    Course *GetListHead() { return head; }

private:
    Course *head;
    RecursionCounter rcTmp;

    Course* InsertHelper(Course *head,Course *newCourse);
    int SizeHelper(Course const *cursor) const;
    void PrintListHelper(Course const *cursor) const;
    void DestructorHelper(Course *cursor);
    double CalculateTotalGradePoints(Course const *cursor) const;
    unsigned int CalculateTotalCredits(Course const *cursor) const;

};

#endif