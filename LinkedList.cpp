// Abstraction 🚙✔
#include "LinkedList.h"
using namespace std;

// Globals 🌎✔
double totalGradePoints = 0.0;
unsigned int totalCredits = 0;
int size = 0;

// Destruction 💀❌
LinkedList::~LinkedList()
{
    DestructorHelper(head);
    // COURSE IS PROPERLY DELETED FROM A LINKED LIST 0/25 ❌
}

void LinkedList::DestructorHelper(Course * cursor)
{
    if(cursor == nullptr)
    {
        return;
    }
    else
    {
        delete cursor;
        DestructorHelper(cursor->next);
    }

    RecursionCounter rcTmp;
}

// Insertion 🔌❌
void LinkedList::Insert(Course *newCourse)
{
    if(head == nullptr)                                         // list empty, append node
    {
        head = newCourse;
    }
    else if(newCourse->courseNumber < head->next->courseNumber) // this node comes before, prepend node
    {
        newCourse->next = head;
        head = newCourse;
    }
    else                                                        // this node comes after, traverse list
     {
        Course* previous = nullptr;
        previous = InsertHelper(head, newCourse);               // return a pointer to the node before node to insert
        newCourse->next = previous->next;                       // point node to insert where the node before used to
        previous->next = newCourse;                             // point node before to newly inserted node
     }
    // COURSES ARE INSERTED RECURSIVELY AND LIST MAINTAINS ASCENDING ORDER 0/30 ❌
}

Course * LinkedList::InsertHelper(Course* head, Course* newCourse)
{

    if(newCourse->courseNumber > head->courseNumber)
    {
        return head;
    }
    else
    {
        InsertHelper(head->next, newCourse);
    }
    RecursionCounter rcTmp;
    return head; // FIXME: ?
}

// Size 🐋❌
int LinkedList::Size() const
{
    return SizeHelper(head);
    // SIZE USES SIZE HELPER TO RECURSIVELY GET LENGTH OF LINKED LIST 0/10 ❌
}

int LinkedList::SizeHelper(Course const * cursor) const
{
    if(cursor == nullptr)
    {
        return size;
    }
    else
    {
        size++;
        SizeHelper(cursor->next);
    }
    RecursionCounter rcTmp;
    return size; // FIXME: ?
}

// Print 🖨❌
void LinkedList::PrintList() const
{
    cout << "Current List: (" <<  Size() << ")" << endl;
    PrintListHelper(head);
    cout << endl << endl;
    // PRINT FUNCTION RETURNS PROPER OUTPUT 0/30 ❌
}

void LinkedList::PrintListHelper(Course const * cursor) const // recursive helper for PrintList()
{
    if(cursor == nullptr)
    {
        return;
    }
    else
    {
        unsigned int courseNumber = cursor->courseNumber;
        string courseName = cursor->courseName;
        double grade = cursor->grade;
        unsigned int credits = cursor->credits;

        cout << courseNumber << " " << courseName << " Grade:" << grade << " Credit Hours: " << credits << endl;
        PrintListHelper(cursor->next);
    }
    RecursionCounter rcTmp;
}

// Calculate 🧮❌
double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
    if(cursor == nullptr) { return totalGradePoints; }          // base case (end of list)
    else                                                        // recursive case (not end)
    {
        totalGradePoints += cursor->grade * cursor->credits;    // increase rolling grade point total
        CalculateTotalGradePoints(cursor->next);                // call the function again recursively
    }
    RecursionCounter rcTmp;
    return totalGradePoints; // FIXME: ?
}

unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
    if(cursor == nullptr) { return totalCredits; }              // base case (end of list)
    else                                                        // recursive case (not end)
    {
        totalCredits += cursor->credits;                        // increase rolling course credit total
        CalculateTotalCredits(cursor->next);                    // call the function again recursively
    }

    RecursionCounter rcTmp;
    return totalCredits; // FIXME: ?
}

double LinkedList::CalculateGPA() const
{
    double cumulativeGPA;                                       // initialize local variable
    cumulativeGPA = totalGradePoints / totalCredits;            // calculate GPA from global
    return cumulativeGPA;                                       // return calculated value
}