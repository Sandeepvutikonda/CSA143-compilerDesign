#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
 int i=0,j=0,k=0,n;
 void *p;
 //void *add[5];
 char ch,b[15],d[15],c;
 printf("Expression terminated by $:");
 while((c=getchar())!='$')
 {
  b[i]=c;
  i++;
 }
 n=i-1;
 printf("Given Expression:");
 i=0;
 while(i<=n)
 {
  printf("%c",b[i]);
  i++;
 }
 printf("\n Symbol Table\n");
 printf("Symbol \t addr \t type");
 while(j<=n)
 {
  c=b[j];
  if(isalpha(toascii(c)))
  {
   p=malloc(c);
   //add[k]=p;
   //d[k]=c;
   printf("\n%c \t %d \t identifier\n",c,p);
   //k++;
   j++;
  }
  else
  {
   ch=c;
   if(ch=='+'||ch=='-'||ch=='*'||ch=='=')
   {
    p=malloc(ch);
    //add[k]=p;
    //d[k]=ch;
    printf("\n %c \t %d \t operator\n",ch,p);
    //k++;
    j++;
   }
   }
   }
   }
