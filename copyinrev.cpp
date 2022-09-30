/* Write a C program to read and write array and copy the contents of array A in array
B in reverse order then find sum of array A and array B and store it in array C.*/
/* Data Structures Using C by UDIT AGARWAL */

#include <stdio.h>
#include <conio.h>
#define max 50
void main ( )
{
clrscr();
int A[max], B[max], C[max], i,j,n;
printf ("\n Enter the value of n:");
scanf ("%d", &n);
for (i=0;i<=n-1; i++)
scanf ("%d", &A[i]);
j=n-1;
for (i=0;i<=n-1; i++)
{
B[j] = A[i];
j=j-1;
}
printf("\nElements in Array B is :\n");
for (i=0;i<=n-1; i++)
printf("%d ", B[i]);

printf("\nElements of array C(sum of A+B):\n");
for (i=0;i<=n-1; i++)
{
C[i]= A[i]+B[i];
printf ("%d ", C[i]);
}
getch ( );
}
