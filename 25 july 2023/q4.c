/*Convert 1.2 into a menu-driven program to some of the following queries
Student menu
0 Quit
1 Store student data
2 Display student data
3 Display male and female categories separately
4 Display student data along with % mark sorted in % mark
5 Display the student date having a mobile number ending with 042
6 Display the highest and lowest mark in any subject as per the user's wish
*/
#include <stdio.h>
#include <string.h>

struct student
{
    int rolno;
    char name[50];
    char gender[2];
    int mobno;
    int phymark;
    int chemmark;
    int mathmark;
};

void displayStudent(struct student s)
{
    printf("Roll.No: %d\nName: %s\nGender: %s\nMobile.No: %d\nPhy: %d\nChem: %d\nMath: %d\n",
           s.rolno, s.name, s.gender, s.mobno, s.phymark, s.chemmark, s.mathmark);
}

float calculatePercentage(struct student s)
{
    return (s.phymark + s.chemmark + s.mathmark) / 3.0;
}

void sortStudentsByPercentage(struct student students[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (calculatePercentage(students[j]) < calculatePercentage(students[j + 1]))
            {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayHighestAndLowestMarks(struct student students[], int n)
{
    int highest = -1;
    int lowest = 101;

    for (int i = 0; i < n; i++)
    {
        if (students[i].phymark > highest)
            highest = students[i].phymark;
        if (students[i].chemmark > highest)
            highest = students[i].chemmark;
        if (students[i].mathmark > highest)
            highest = students[i].mathmark;

        if (students[i].phymark < lowest)
            lowest = students[i].phymark;
        if (students[i].chemmark < lowest)
            lowest = students[i].chemmark;
        if (students[i].mathmark < lowest)
            lowest = students[i].mathmark;
    }

    printf("Highest Mark: %d\nLowest Mark: %d\n", highest, lowest);
}

int main()
{
    int n = 0;
    struct student students[100];
    int choice;

    do
    {
        printf("\nStudent Menu\n");
        printf("0 Quit\n");
        printf("1 Store student data\n");
        printf("2 Display student data\n");
        printf("3 Display male and female categories separately\n");
        printf("4 Display student data sorted by percentage\n");
        printf("5 Display students with mobile number ending in 042\n");
        printf("6 Display the highest and lowest marks in any subject\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting the program. Goodbye!\n");
            break;

        case 1:
            printf("Enter the details of student %d: \n", n + 1);
            printf("Roll.no: ");
            scanf("%d", &students[n].rolno);
            printf("Name: ");
            scanf("%s", students[n].name);
            printf("Gender (M/F): ");
            scanf("%s", students[n].gender);
            printf("Mobile.no: ");
            scanf("%d", &students[n].mobno);
            printf("Physics Marks: ");
            scanf("%d", &students[n].phymark);
            printf("Chemistry Marks: ");
            scanf("%d", &students[n].chemmark);
            printf("Maths Marks: ");
            scanf("%d", &students[n].mathmark);
            n++;
            break;

        case 2:
            printf("\nStudent List: \n");
            for (int i = 0; i < n; i++)
            {
                printf("<--------------------------------------------------------------------------------------------------->\n");
                printf("SL.No: %d\n", i + 1);
                displayStudent(students[i]);
            }
            break;

        case 3:
            printf("\nMale Students:\n");
            for (int i = 0; i < n; i++)
            {
                if (strcmp(students[i].gender, "M") == 0)
                {
                    displayStudent(students[i]);
                }
            }
            printf("\nFemale Students:\n");
            for (int i = 0; i < n; i++)
            {
                if (strcmp(students[i].gender, "F") == 0)
                {
                    displayStudent(students[i]);
                }
            }
            break;

        case 4:
            sortStudentsByPercentage(students, n);
            printf("\nStudent List Sorted by Percentage:\n");
            for (int i = 0; i < n; i++)
            {
                printf("<--------------------------------------------------------------------------------------------------->\n");
                printf("SL.No: %d\n", i + 1);
                displayStudent(students[i]);
                printf("Percentage: %.2f\n", calculatePercentage(students[i]));
            }
            break;

        case 5:
            printf("\nStudents with mobile number ending in 042:\n");
            for (int i = 0; i < n; i++)
            {
                int lastDigits = students[i].mobno % 1000;
                if (lastDigits == 042)
                {
                    displayStudent(students[i]);
                }
            }
            break;

        case 6:
            displayHighestAndLowestMarks(students, n);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
