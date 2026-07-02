#include <stdio.h>
#include <string.h>
#define MAX_LEN 200
int main() {
   char str[MAX_LEN];
   int i = 0, words = 0;
   char prevChar = '\0';
   printf("Enter a sentence: ");
   fgets(str, sizeof(str), stdin);
   while (1) {
       if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\0') {
           // Count a word only if previous character was not whitespace
           if (prevChar != ' ' && prevChar != '\n' && prevChar != '\t' && prevChar != '\0') {
               words++;
           }
       }
       prevChar = str[i];
       if (str[i] == '\0')
           break;
       i++;
   }
   printf("Total number of words: %d\n", words);
   return 0;
}