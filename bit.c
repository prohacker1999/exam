#include<string.h>
#include<stdio.h>
main()
{
char a[20],fs[50]="",t[6],r[5];
int i,j,p=0,q=0;
printf("enter bit string:");
scanf("%s",a);
strcat(fs,"01111110");
if(strlen(a)<5)
{
strcat(fs,a);
}
else
{
for(i=0;i<strlen(a)-4;i++)
{
for(j=i;j<i+5;j++)
{
t[p++]=a[j];
}
t[p]='\0';
if(strcmp(t,"11111")==0)
{
strcat(fs,"111110");
i=j-1;
}
else
{
r[0]=a[i];
r[1]='\0';
strcat(fs,r);
}
p=0;
}
for(q=i;q<strlen(a);q++)
{
t[p++]=a[q];
}
t[p]='\0';
strcat(fs,t);
}
strcat(fs,"01111110");
printf("after stuffing:%s",fs);
}
