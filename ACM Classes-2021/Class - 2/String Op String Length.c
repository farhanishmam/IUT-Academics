#include <stdio.h>
#include <string.h>

int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','\0','r','a','m'};

    char str[100];
    gets(str);
    printf("%d",strlen(str));

    int aLen = strlen(a);
    int bLen = strlen(b);
    // using the %zu format specifier to print size_t
    //printf("%d \n",aLen);
    //printf("%d \n",bLen);
    //printf("Length of string b = %zu \n",);

    return 0;
}
