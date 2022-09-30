/* Concatenation*/
/* Data Structures Using C by UDIT AGARWAL */

#include <stdio.h>
#include <conio.h>
void main ( )
{
int a[5],b[5],c[10],i,j ;
clrscr ( );
printf ("\n Enter five elements of first array:\n");
for (i=0; i<=4; i++)
scanf ("%d", &a[i]);
printf ("\n Enter five elements of second array:\n");
for (i=0; i<=4; i++)
{
scanf ("%d", &b[i]);
}
for (i=0; i<=4; i++)
c[i] = a[i];
for (j=0; j<=4; j++)
c[i++] = b[j];
j = i;
printf ("\n After concatenation :");
for (i=0; i<j; i++)
{
printf ("%d,", c[i]);
}
getch ( );
}