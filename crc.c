#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[128],cs[128],g[]="10001000000100001";
int a, e,c,b;
void xor()
{
for(c=1;c<N;c++)
cs[c]=((cs[c]==g[c])?'0':'1');
}
void crc()
{
for(e=0;e<N;e++)
cs[e]=t[e];
do
{
if(cs[0]=='1');
xor();
for(c=0;c<N-1;c++)
{
cs[c]=cs[c+1];
}
cs[c]=t[e++];
}
while(e<=a+N-1);
}
void main()
{
printf("\n enter data t:");
scanf("%s",t);
printf("\n predefined generator polynomial is :%s",g);
a=strlen(t);
for(e=a;e<a+N-1;e++)
t[e]='0';
printf("\n modified t[u] is:%s",t);
crc();
printf("\n checksum is :%s",cs);
for(e=a;e<a+N-1;e++)
t[e]=cs[e-a];
printf("\n final codeword is :%s",t);
printf("\n\n test error detection 1(yes)0(no)?:");
scanf("%d",&b);
if(b==1)
{
printf("\n enter position where error is to inserted:");
scanf("%d",&e);
t[e]=(t[e]=='0')?'1':'0';
printf("errorneous data:%s\n",t);
}
crc();
for(e=0;(e<N-1)&&(cs[e]!='1');e++);
if(e<N-1)
printf("error detected");
else
printf("error detected.");
}

