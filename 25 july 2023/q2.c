/*WAP to store n number of student details such as roll number, gender, mobile number mark in three subjects PHY,
chem and math and assisting the student list in the following formate.
SL.no
Roll number
Name
Gender
Mobile number
Phy mark
Chem mark
Math mark*/
#include <stdio.h>
struct student{
    int rolno;
    char name[50];
    char gender[1];
    int mobno;
    int phymark;
    int chemmark;
    int mathmark;
};
int main()
{
    int n;
    printf("Enter the no of students:");
    scanf("%d", &n);
    struct student students[n];
    for(int i=0;i<n;i++){
    printf("Enter the details of student %d: \n",i+1);
    printf("Roll.no: ");
    scanf("%d",&students[i].rolno);
    printf("Name: ");
    scanf("%s",students[i].name);
    printf("Gender (M/F): ");
    scanf("%s",&students[i].gender);
    printf("Mobile.no: ");
    scanf("%d",&students[i].mobno);
    printf("Physics Marks: ");
    scanf("%d",&students[i].phymark);
    printf("Chemistry Marks: ");
    scanf("%d",&students[i].chemmark);
    printf("Maths Marks: ");
    scanf("%d",&students[i].mathmark);
    }
    printf("\nStudent List: \n");
    for(int i=0;i<n;i++){
    printf("<--------------------------------------------------------------------------------------------------->");
    printf("SL.No: %d\nRoll.No:%d\nName: %s\nGender: %c\nMobile.No: %d\nPhy: %d\nChem: %d\nMath: %d\n",i+1,students[i].rolno,students[i].name,students[i].gender,students[i].mobno,students[i].phymark,students[i].chemmark,students[i].mathmark);
    }
    return 0;
}