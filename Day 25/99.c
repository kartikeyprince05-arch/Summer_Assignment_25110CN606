#include <stdio.h>
#include <string.h>
#define MAX_CITIES 100
#define MAX_LEN 50
int main() {
   char cities[MAX_CITIES][MAX_LEN], temp[MAX_LEN];
   int n, i, j;
   printf("Enter number of cities: ");
   scanf("%d", &n);
   printf("Enter city names:\n");
   for (i = 0; i < n; i++) {
       scanf("%s", cities[i]);
   }
   for (i = 0; i < n - 1; i++) {
       for (j = i + 1; j < n; j++) {
           if (strcmp(cities[i], cities[j]) > 0) {
               strcpy(temp, cities[i]);
               strcpy(cities[i], cities[j]);
               strcpy(cities[j], temp);
           }
       }
   }
   printf("\nCities in alphabetical order:\n");
   for (i = 0; i < n; i++) {
       printf("%s\n", cities[i]);
   }
   return 0;
}