#include <stdio.h>

typedef struct student_s Student;

struct student_s {
    char* name;
    int age;
    Student* next;
};

void printOneStudent(Student student)
{
    printf("%s (%d)\n", student.name, student.age);
}

void printStudents(const Student* student)
{
    while (student != NULL) {
        printOneStudent(*student);
        student = student->next;
    }
}


int main(int argc, char* argv[])
{
    Student student1 = {"Charlie", 16, NULL};
    Student student2 = {"Fred", 23, NULL};
    student1.next = &student2;
    printStudents(&student1);
}
