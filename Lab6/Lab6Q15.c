#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char* name;
    int age;
    double height;
} Person;

Person* newPerson(char* name, int age, double height)
{
    Person* newHuman = NULL;
    int nameLen = strlen(name);
    newHuman = malloc(sizeof(Person));
    if (newHuman != NULL) {
        newHuman->name = malloc(nameLen + 1);
        if (newHuman->name != NULL) {
            strncpy(newHuman->name, name, nameLen + 1);
            newHuman->age = age;
            newHuman->height = height;
        } else {
            free(newHuman);
            newHuman = NULL;
        }
    }
    return newHuman;
}

void freePerson(Person* person)
{
    free(person->name);
    free(person);
}

int main(void)
{

    Person* employee = newPerson("Billy", 30, 1.68);
    printf("%s is age %d and is %.2f m tall\n", employee->name, employee->age, employee->height);
    freePerson(employee);
}
