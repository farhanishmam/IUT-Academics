//71A

#include<stdio.h>
#include<string.h>
 
int main(void){
    int n,l;
    char ch[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&ch);
        l=strlen(ch);
        if(l<=10) printf("%s\n",ch);
        else printf("%c%d%c\n",ch[0],l-2,ch[l-1]);
 
    }
 
}