// Binary Search in C

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) //Function Definition 
 {
  if (high >= low) //checking if high>=low
   {
    int mid=low+(high-low)/2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;
    // Search the left half
    if (array[mid] > x
        return binarySearch(array, x, low, mid - 1);
    // Search the right half
        return binarySearch(array, x, mid + 1, high);
   }
   return -1; //returning the value -1 if not found
}

int main(void) //main function

{
  int x;//declaring variable x which will hold 
  int array[] = {3, 4, 5, 6, 7, 8, 9};//Declaring array in sorted form
  int n = sizeof(array); //storing the value of array in 'n' variable
  printf("\nEnter the value to searched :");
  scanf("%d",&x); //fetching the value to be searched from user 
  int result=binarySearch(array,x,0,n-1)+1; //calling the recursive binarySearch function
  if (result == -1) //Checking if value is not found in array
    printf("\nNot found");
  else 
    printf("\nElement is found at index %d", result); //printing the postion value
}
