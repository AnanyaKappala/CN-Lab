/*Write a C program to assign values to each member of the following structure. Pass the populated structure to a
function Using call-by-value and another function using call-by-address and print the value of each member of the
structure.
struct student_info{
int roll_no;
char name[50];
float CGPA;
struct dob age;
};*/
#include <stdio.h>

struct dob
{
    int day;
    int month;
    int year;
};

struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void printStudentInfoValue(struct student_info student)
{
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %d-%d-%d\n", student.age.day, student.age.month, student.age.year);
}

void printStudentInfoAddress(struct student_info *student)
{
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %d-%d-%d\n", student->age.day, student->age.month, student->age.year);
}

int main()
{
    struct student_info student1;

    printf("Enter Roll No: ");
    scanf("%d", &student1.roll_no);

    printf("Enter Name: ");
    scanf("%s", student1.name);

    printf("Enter CGPA: ");
    scanf("%f", &student1.CGPA);

    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &student1.age.day, &student1.age.month, &student1.age.year);

    printf("\nPrinting using call-by-value:\n");
    printStudentInfoValue(student1);

    printf("\nPrinting using call-by-address:\n");
    printStudentInfoAddress(&student1);

    return 0;
}