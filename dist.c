#include<stdio.h>
#include<stdlib.h>
int main()
{
int d[10][10],t[10][10],a[10][10],i,j,n,k,count,via,Distance;
printf("enter the number of nodes\n");
scanf("%d",&n);
printf("enter the initial cost matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		scanf("%d",&d[i][j]);
		d[i][i]=0;
		t[i][j]=d[i][j];
		a[i][j]=j;
		}
	}
do
{
count=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(t[i][j]>(d[i][k]+t[k][j]))
				{
				t[i][j]=(t[i][k]+t[k][j]);
				a[i][j]=k;
				count++;
				}
			}
		}
	}
}while(count!=0);
for(i=1;i<=n;i++)
{
	printf("\n\n For router%d\n",i);
	for(j=1;j<=n;j++)
	{
	printf("\t\nto node%d,via%d,Distance->%d",j,a[i][j],t[i][j]);
	}
}
printf("\n\n");
return 0;
} 
