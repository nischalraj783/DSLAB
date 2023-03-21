#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5
int arr[size];
int R=-1,F=0,te=0;

void push()
{
    int n;
    if(te==size)
    {
      printf("Queue is full");
    }
    else
    {
        printf("Enter a number ");
        scanf("%d",&n);
        R=(R+1)%size;
        arr[R]=n;
        te=te+1;             
    }
}
void pop()
{
    if(te==0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Number Deleted = %d",arr[F]);
        F=(F+1)%size;
        te=te-1;
     }
}
void display()
{
     int i,x;
     if(te==0)
     {
        printf("Queue is empty");
     }
     else
     {    
         x=F;
         for(i=1; i<=te; i++)
         {
            printf("%d ",arr[x]);
            x=(x+1)%size;
         }
      }
}
int main()
{
    int choice;
   while(choice!=4)
   {
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
                
            case 3:display();
                break;
            case 4:
                 break;
            default:
                printf("Wrong Choice");
        }
   }
   return;
}
