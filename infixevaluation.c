#include <stdio.h>
int main()
{   
     int oprnd1, oprnd2;//declaring opernads variable
     char oprtr; //+,-,*, /
     int result , invalid = 0; // invalid is a flag, assume valid
     printf("Enter operand 1\n");
     scanf("%d", &oprnd1);//fetching operand 1
     printf("Enter operand 2\n");
     scanf("%d", &oprnd2);//fetching operand 2
     printf("Enter operator 1\n");
     scanf("%c", &oprtr); // dummy for \n after oprnd2
     scanf("%c", &oprtr);
     switch (oprtr)
     {
        case '+': result = oprnd1 + oprnd2;
                  break;
        case '-': result = oprnd1 - oprnd2;
                  break;
        case '*': result = oprnd1 * oprnd2;
                  break; 
        case '/': result = oprnd1 / oprnd2;
                  break;
        default: invalid = 1;
                 printf("invalid operator\n");
                 break;
     }
     if (!invalid)
         printf("result = %d\n", result);
     return 0;
}
