#include <stdio.h>
#include <string.h>
int areAnagrams(char *str1, char *str2) {
   // If lengths are not equal, they cannot be anagrams
   if (strlen(str1) != strlen(str2)) {
       return 0;
   }
   // Frequency array for ASCII characters
   int charCount[256] = {0};
   // Increment for str1 and decrement for str2
   for (int i = 0; str1[i] && str2[i]; i++) {
       charCount[(unsigned char)str1[i]]++;
       charCount[(unsigned char)str2[i]]--;
   }
   // Check if all counts are zero
   for (int i = 0; i < 256; i++) {
       if (charCount[i] != 0) {
           return 0;
       }
   }
   return 1;
}
int main() {
   char str1[100], str2[100];
   printf("Enter first string: ");
   fgets(str1, sizeof(str1), stdin);
   printf("Enter second string: ");
   fgets(str2, sizeof(str2), stdin);
   // Remove newline characters from input strings
   str1[strcspn(str1, "\n")] = '\0';
   str2[strcspn(str2, "\n")] = '\0';
   if (areAnagrams(str1, str2)) {
       printf("\"%s\" and \"%s\" are Anagrams.\n", str1, str2);
   } else {
       printf("\"%s\" and \"%s\" are NOT Anagrams.\n", str1, str2);
   }
   return 0;
}