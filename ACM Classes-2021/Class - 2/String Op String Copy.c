#include <stdio.h>
#include <string.h>  //Remember to include the header

int main() {
  char str1[20] = "C programming";
  char str2[20];

  // copying str1 to str2
  strcpy(str2, str1);

  puts(str2);

  return 0;
}
