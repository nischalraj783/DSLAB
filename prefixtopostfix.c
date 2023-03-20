#include<stdio.h>//Standard input otput
#include<string.h>
#include<stdlib.h>//stadard library function
# define MAX 20 //declaring size
char stack[MAX];//intializing string and stack array
int top=-1;//giving top value as -1
void push(char symbol)//function to push
{
   stack[++top]=symbol;//pushing symbol into stack
}
char pop()
{
    return stack[top--];
}
int isoperator(char x)
{
  switch(x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
      return 1;
    }
  return 0;
}
void convert(char prefix[],char postfix[])//function to convert into postfix expression
{
   int symbol,i,j=0; 
   for(i=0;i<(strlen(prefix));i++)//loop to convert into postfix
   {
     symbol=prefix[i];
     if(isoperator(symbol))
     {
         push(symbol);
     }
     else
     { 
       postfix[j++]=symbol;//else store in postfix array
       while((top!=-1)&&(stack[top]=='#'))//while loop if it is not empty 
       {
        pop(); 
        postfix[j++]=pop();// store the poped elemt in the 
       }
       push('#');
     }
   }
   postfix[j]='\0';
   printf("Postfix expression is:\t");
   printf("%s",postfix);//print the postfix expression
}
void main()//main function
{
 char prefix[30],postfix[30];
 printf("Enter the prefix expression\n");//print 
 scanf("%s",prefix);
 convert(prefix,postfix);//calling postfix function
}
