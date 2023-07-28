/*Modify Q1 and inset and their field DOB (DD.MM.YYYY) assessed studied and display the student list (after gender
display DOB)*/
#include <stdio.h>
struct student
{
    int rolno;
    char name[50];
    char gender;
    int mobno;
    int phymark;
    int chemmark;
    int mathmark;
    char dob[11];
    char assessed;
    char studied;
};
int main()
{
    int n;
    printf("Enter the no of students:");
    scanf("%d", &n);
    struct student students[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of student %d: \n", i + 1);
        printf("Roll.no: ");
        scanf("%d", &students[i].rolno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender); 
        printf("Mobile.no: ");
        scanf("%d", &students[i].mobno);
        printf("Physics Marks: ");
        scanf("%d", &students[i].phymark);
        printf("Chemistry Marks: ");
        scanf("%d", &students[i].chemmark);
        printf("Maths Marks: ");
        scanf("%d", &students[i].mathmark);
        printf("DOB (DD.MM.YYYY): ");
        scanf("%s", students[i].dob);
        printf("Assessed (Y/N): ");
        scanf(" %c", &students[i].assessed); 
        printf("Studied (Y/N): ");
        scanf(" %c", &students[i].studied);
    }

    printf("\nStudent List: \n");
    for (int i = 0; i < n; i++)
    {
        printf("<--------------------------------------------------------------------------------------------------->\n");
        printf("SL.No: %d\nRoll.No: %d\nName: %s\nGender: %c\nMobile.No: %d\nPhy: %d\nChem: %d\nMath: %d\nDOB: %s\nAssessed: %c\nStudied: %c\n",
               i + 1, students[i].rolno, students[i].name, students[i].gender, students[i].mobno,
               students[i].phymark, students[i].chemmark, students[i].mathmark, students[i].dob,
               students[i].assessed, students[i].studied);
    }

    return 0;
}