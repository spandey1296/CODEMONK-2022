#include<stdio.h>
int main()
{
   int a,b,temp;
   printf("Enter the First Number : ");
   scanf("%d",&a);
   printf("Enter the Second Number : ");
   scanf("%d",&b);
   temp=a;
   a=b;
   b=temp;
   printf("\n**********************************After Swap************************************");
   printf("\n\n First Number : %d",a);
    printf("\n Second Number : %d",b);
}