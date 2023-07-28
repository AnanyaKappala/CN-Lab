/*write a c program to swap content of two variables using function and pointer.*/
#include<stdio.h>
int swapfunction(int p, int q){
    int t=p;
    p=q;
    q=t;
    printf("Swapped numbers %d %d",p,q);
}
int main(){
    int p,q;
    printf("Enter two numbers:");
    scanf("%d %d",&p,&q);
    int *a=&p;
    int *b=&q;
    swapfunction(p,q);
}