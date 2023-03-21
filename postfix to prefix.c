#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
char stack[MAX];
int top = -1;
void push(char c)
{
  stack[++top] = c;
}
char pop()
{
  return stack[top--];
}
void reverse(char array[])
{
    char temp[30];
    int i,j=-1;
    for(i=0;i<strlen(array);i++)
    {
        temp[i]=array[i];
        ++j;
    }
    for(i=0;i<strlen(array);i++)
    {
        array[i]=temp[j];
        --j;
    }
    array[++i]='\0';
}
int isOperator (char x)
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
void convert(char postfix[],char prefix[])
{
  int i, j = 0,symbol;
  for(i=(strlen(postfix)-1);i>=0;i--)
  {
    symbol=postfix[i];
    if (isOperator(symbol))
	{
	    push(symbol);
	}
    else
	{
	  prefix[j++] = symbol;
	  while ((top!=-1) && (stack[top] == '#'))
	  {
	      pop();
	      prefix[j++]=pop ();
	  }
	  push('#');
	 }
   }
   prefix[j]='\0';
   reverse(prefix);
   printf ("Prefix expression is: ");
   printf ("%s \n",prefix);
}
int main()
{
  char postfix[MAX],prefix[20];
  printf ("Enter the postfix expression\n");
  scanf("%s",postfix);
  convert(postfix,prefix);
  return 0;
}
