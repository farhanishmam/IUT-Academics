#include<stdio.h>

int main()
{
    char name[30];
    printf("Enter name: ");
    //scanf("%s",name); //Doesnt take space as input
    gets(name);     //Function to read string from user.
    //printf("Name: %s",name);
    puts("Name: ");
    puts(name);    //Function to display string.
    return 0;
}
