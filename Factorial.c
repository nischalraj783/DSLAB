#include<stdio.h> //Pre-processor directives
int factorial(int); //Function Prototyping
int main() 
{
 int num;
 printf("\n Enter N value : \n");
 scanf("%d”, &num);//fetching the value of n from user
 printf("\nFACTORIAL = %d",factorial(num));//Calling function factorial() and printing the return value
}
int factorial(int n)//function definition 
{
 if(n==0) // If n==0 , return 0
  return 0;
 else if(n==1) // If n==1, return 1
  return 1;
 else //multiplying n with recursive function factorial(n-1)
  return n*factorial(n-1);
}
