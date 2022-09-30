/*Copy string in other string*/
/* Data Structures Using C by UDIT AGARWAL */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main ( )
{
int i=0;
char *c1, str1[10], str2[10];
clrscr ( );
printf ("\nEnter the string to be copied:\n");
scanf ("%s", str1);
c1=str1;
while(*c1!='\0')
{
str2[i]=*c1;
c1=c1+1;
i=i+1;
}
str2[i]='\0';
printf ("\nCopied string in other string is %s", str2);
getch ();
}
