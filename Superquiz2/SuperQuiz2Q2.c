/* prog.c
 * A variant of structexample3.c from lab 5 with the following changes:
 *
 * 1. The student struct now contains a firstname, a lastname and a student ID
 *    instead of a name and an age.
 * 2. The input data file is again a CSV file but the fields are firstname,
 *    lastname and student ID (an int).
 *
 * Richard Vong, August 2019.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 80      // The longest line this program will accept
#define MAX_NUM_STUDENTS 500    // The maximum number of students this program can handle
#define MAX_NAME_SIZE 50        // The maximum allowable name length

// The declaration of the student record (or struct). Note that
// the struct contains the first and last names as arrays of characters.

typedef struct student_s Student;

struct student_s {
    char firstname[MAX_NAME_SIZE];
    char lastname[MAX_NAME_SIZE];
    int studentId;
    Student* next;              // Pointer to next student in a list
};

// Create a pool of student records to be allocated on demand

Student studentPool[MAX_NUM_STUDENTS];  // The student pool
int firstFree = 0;

// Return a pointer to a new student record from the pool, after
// filling in the provided first and last name and student ID fields.
// Returns NULL if the student pool is exhausted.
Student* newStudent(const char* firstname, const char* lastname, int studentId)
{
    Student* student = NULL;
    if (firstFree < MAX_NUM_STUDENTS) {
        student = &studentPool[firstFree];
        firstFree += 1;
        strncpy(student->firstname, firstname, MAX_NAME_SIZE);
        student->firstname[MAX_NAME_SIZE - 1] = '\0';  // Make sure it's terminated
        strncpy(student->lastname, lastname, MAX_NAME_SIZE);
        student->lastname[MAX_NAME_SIZE - 1] = '\0';  // Make sure it's terminated
        student->studentId = studentId;
        student->next = NULL;
    }
    return student;
}

// Read a single student from a csv input file with student first name in first column,
// second name in the second column and studentId in the last (third) column.
// Returns: A pointer to a Student record, or NULL if EOF occurs or if
// a line with fewer than 2 commas is read.
Student* readOneStudent(FILE* file)
{

    char buffer[MAX_LINE_LENGTH];  // Buffer into which we read a line from stdin
    Student* student = NULL;       // Pointer to a student record from the pool

    char* inputLine = fgets(buffer, MAX_LINE_LENGTH, file);
    if (inputLine != NULL) {        //Only proceed if we read something
        char* commaPos1 = strchr(buffer, ',');
        char* commaPos2 = strrchr(buffer, ',');
        if (commaPos1 != commaPos2) {   //Check if less than 2 commas is read. If there is 1 comma, then the two commaPos are the same.
            int studentID = atoi(commaPos2 + 1);
            *commaPos2 = '\0';
            char* lastName = commaPos1 + 1;
            *commaPos1 = '\0';

            student = newStudent(buffer, lastName, studentID);
        }
    }
    return student;
}


// Returns true if and only if student student1 should precede (i.e., is "less than") student student2 in the list.
bool precedes(const Student* student1, const Student* student2)
{
    int firstNameCmp = strcmp(student1->firstname, student2->firstname);
    int lastNameCmp = strcmp(student1->lastname, student2->lastname);

    if (firstNameCmp < 0) {
        return 1;
    } else if (firstNameCmp == 0) {
        if (lastNameCmp < 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Inserts the student student into the list of students that has list as its first element.
// The return value is the new list head; it will be either student if the new student went
// at the head of the list or list otherwise. Function uses a helper function Preceeds to determine
// if a student's name preceeds another.

Student* insert(Student* student, Student* list)
{
    Student* curr = list;
    Student* prev = NULL;

    if (precedes(student, list) == 1) { //Condition to add student to head of list
        student->next = list;
        return student;
    } else {
        while (curr != NULL && student != NULL && precedes(curr, student) == 1) { //Loop through list looking at positions
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) { //Condition if inserting at the end of the list
            prev->next = student;
        } else if (precedes(curr, student) == 0) { //Otherwise add it to correct position and change pointers
            prev->next = student;
            student->next = curr;
        }
        return list;
    }
}

// Reads a list of students from a given file. Input stops when
// a blank line is read, or an EOF occurs, or an illegal input
// line is encountered.
// Returns a pointer to the first student in the list or NULL if no
// valid student records could be read.
Student* readStudents(FILE *file)
{
    Student* first = NULL;     // Pointer to the first student in the list
    Student* student = readOneStudent(file);
    while (student != NULL) {
        if (first == NULL) {
            first = student;   // Empty list case
        } else {
            first = insert(student, first); // Insert new read student into list
        }
        student = readOneStudent(file);
    }
    return first;
}

// printOneStudent: prints a single student, passed by value
void printOneStudent(Student student)
{
    printf("%s %s (%d)\n", student.firstname, student.lastname, student.studentId);
}


// printStudents: print all students in a list of students, passed
// by reference
void printStudents(const Student* student)
{
    while (student != NULL) {
        printOneStudent(*student);
        student = student->next;
    }
}


// Main program. Read a linked list of students from a csv file, then display
// the contents of that list.
int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: prog filename\n");
        exit(1);
    }
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "File \'%s\' not found\n", argv[1]);
        exit(1);
    } else {
        Student* studentList = readStudents(inputFile);
        printStudents(studentList);

        // The program could now do various things that make use of
        // the linked list, like deleting students and adding new ones,
        // but the program is already quite long enough!
    }
}
