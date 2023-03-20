#include<stdio.h>
#include<string.h> 
#include<ctype.h> 
 
int stack[50];
int top=-1;
void push(int item)
{
 stack[++top]=item; 
}
char pop() 
{
 return stack[top--]; 
}
int isoperator(char symbol)
{
    switch(symbol){
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
            return 1;
            break;
    default:return 0;
            break;
}
}
int evaluate(char postfix[])
{
  char symbol;
  int op1,op2;
  int i=0;
  for(i=0;i<strlen(postfix);i++)
  {
    symbol=postfix[i];
    if(isoperator(symbol)==0)
    {
     push(symbol-'0'); 
    }
    else
    {
      op2=pop(); 
      op1=pop();
      switch(symbol)
      {
       case '+': push(op1+op2);
           break; 
       case '-': push(op1-op2);
           break; 
       case '*': push(op1*op2);
           break; 
       case '/': push(op1/op2);
           break; 
       case '^': push(op1^op2);
           break;
      }
    }
  }
  return stack[top];
}
void main()
{
 char postfix[30]="123*+"; 
 printf("The postfix expression is %s \n",postfix);
 printf("Evaluation of postfix expression is %d \n",evaluate(postfix)); 
} 
