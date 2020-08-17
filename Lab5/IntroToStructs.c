#include <stdio.h>

struct student_s {
    char* name;
    int age;
   struct student_s* next;
} student1;

struct student_s student2;

void printStudents(const struct student_s* student)
{
    while (student != NULL){
        printf("%s (%d)\n", (*student).name, student->age);
        student = student->next;
    }
}


int main(int argc, char* argv[])
{
    student1.name = "Charlie";
    student1.age = 16;
    student1.next = &student2;
    student2.name = "Fred";
    student2.age = 23;
    student2.next = NULL;
    printStudents(&student1);
}
