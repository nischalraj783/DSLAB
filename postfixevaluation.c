#include<stdio.h> //standard Input Output header file
int stack[20]; //implementation of stack
int top = -1; //to check if stack is empty 
void push(int x) //function to perform push operation
{
        stack[++top] = x;//incrementation of top
}
int pop()//function to perform pop operation
{
        return stack[top--];//decrementation of top
}
int main()//main function
{
 	  	char exp[20];//initializing expression size
   		 char *p;//initializing pointer to save address
  		  int a1,a2,a3,num;//declaring operands and num
 		   printf("Enter the expression :\n ");//printing statement
  		  scanf("%s",exp);//assigning the value in exp
   		 p = exp;
    while(*p != '\0')	//checks for null character that indicates end of string.
   	 {
        		if(isdigit(*p))//checks if the pointer p is pointing to a number 
        {
            num = *p - 48;//ascii conversion 
            push(num);
        }
        else
        {
            a1 = pop();
            a2 = pop();
            switch(*p)//switch statement for respective operation 
            {
            case '+':// performs addition 
        	    {
               	 a3 = a1 + a2;
               	 break;
            }
            case '-':// performs subtraction 
           	 {
            	    a3 = a2 - a1;
             	   break;
          		  }
            case '*'://performs multiplication
           	 {
             	   a3 = a1 * a2;
             	   break;
          		  }
           case '/'://performs division
       	     {
              	  a3 = a2 / a1;
              	  break;
          	  }
            }
            push(a3);
   	     }
        p++; //incrementing pointer variable
    }
    printf("\nThe result of expression %s = %d\n\n",exp,pop());//printing statement
    return 0;
}
