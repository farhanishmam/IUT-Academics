// Program to find the average of n numbers using arrays

#include <stdio.h>
int main()
{
     int marks[10], i, n;
     float sum = 0.0;
     float average;

     printf("Enter number of elements: ");
     scanf("%d", &n);

     for(i=0; i<n; ++i)
     {
          printf("Enter number%d: ",i+1);
          scanf("%d", &marks[i]);

          // adding integers entered by the user to the sum variable
          sum += marks[i];
     }

     average = sum/n;
     printf("Average = %f", average);

     return 0;
}
