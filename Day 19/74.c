#include <stdio.h>
int main() {
   int rows, cols;
   printf("Enter number of rows: ");
   scanf("%d", &rows);
   printf("Enter number of columns: ");
   scanf("%d", &cols);
   int A[rows][cols], B[rows][cols], C[rows][cols];
   // Input first matrix
   printf("Enter elements of first matrix:\n");
   for(int i = 0; i < rows; i++) {
       for(int j = 0; j < cols; j++) {
           scanf("%d", &A[i][j]);
       }
   }
   // Input second matrix
   printf("Enter elements of second matrix:\n");
   for(int i = 0; i < rows; i++) {
       for(int j = 0; j < cols; j++) {
           scanf("%d", &B[i][j]);
       }
   }
   // Subtract matrices
   for(int i = 0; i < rows; i++) {
       for(int j = 0; j < cols; j++) {
           C[i][j] = A[i][j] - B[i][j];
       }
   }
   // Display result
   printf("Resultant Matrix (A - B):\n");
   for(int i = 0; i < rows; i++) {
       for(int j = 0; j < cols; j++) {
           printf("%d ", C[i][j]);
       }
       printf("\n");
   }
   return 0;
}