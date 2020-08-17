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

#define MAX_LINE_LENGTH 500      // The longest line this program will accept


#define MAX_NUM_STUDENTS 500    // The maximum number of students this program can handle
#define MAX_NAME_SIZE 50        // The maximum allowable name length

char buffer[MAX_LINE_LENGTH] = {0};


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

// The function returns a pointer to that character in s,
// or NULL if n <= 0 or no such occurrence of the character exists
char* strchrn(char* s, int c, int n)
{
    char* charOccur = NULL;
    int charCounter = 0;
    _Bool found = 0;

    while (found == 0 && *s != '\0') {
        if (*s == c) {
            charCounter++;
        }
        if (charCounter == n) {
            found = 1;
            charOccur = s;
        } else {
            s++;
        }
    }
    return charOccur;
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
        char* commaPos1 = strchrn(buffer, ',', 1);
        char* commaPos2 = strchrn(buffer, ',', 2);
        char* commaPos3 = strchrn(buffer, ',', 3);
        if (commaPos1 != commaPos2) {   //Check if less than 2 commas is read. If there is 1 comma, then the two commaPos are the same.
            int studentID = atoi(commaPos3 + 1);
            *commaPos3 = '\0';
            char* lastName = commaPos2 + 1;
            *commaPos2 = '\0';
            char* temp = commaPos1 + 1;
            *commaPos1 = '\0';
            printf("%s", temp);

            student = newStudent(buffer, lastName, studentID);
        }
    }
    return student;
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

    //char* infoPointer = NULL;
    char* comma = NULL;
    for (int i = 0; i <= 4; i++) {
        fgets(buffer, MAX_LINE_LENGTH, file);
    }
    comma = strchr(buffer, ',');
    *comma = '\0';
    //infoPointer = buffer;


    while (student != NULL) {
        if (first == NULL) {
            first = student;   // Empty list case
        } else {
            printf("hello");
            //first = insert(student, first); // Insert new read student into list
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

char* returnSationName(FILE *file)
{
    char* stationPointer = NULL;
    char* comma = NULL;
    for (int i = 0; i <= 2; i++) {
        fgets(buffer, MAX_LINE_LENGTH, file);
    }
    comma = strchr(buffer, ',');
    *comma = '\0';
    stationPointer = buffer;
    return stationPointer;
}




// Main program. Read a linked list of students from a csv file, then display
// the contents of that list.
int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: processtemps threshold\n");
        exit(1);
    }
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "File \'%s\' not found\n", argv[1]);
        exit(1);
    } else {
        char* stationName = returnSationName(inputFile);
        printf("%s\n", stationName);
        Student* studentList = readStudents(inputFile);
        printStudents(studentList);
    }
}
