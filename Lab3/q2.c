#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>

int opcount = 0;

void main()
{
	int i,j,k,n,m,flag=0;
	char t[100],p[30];
	printf("Enter text: ");
	fgets(t,100,stdin);
	printf("\nEnter pattern: ");
	fgets(p,30,stdin);
	n=strlen(t);
	m=strlen(p);
	for(i=0;i<=n-m;i++)
	{
		opcount++;
		j=0;
		while(j<m && p[j]==t[j+i])
		{
			j++;
			opcount++;
			if(j==m)
			{
				
				flag=1;
				k=i+1;
			}
			else flag=0;
		}
	}
	printf("\nOpcount: %d\n",opcount);

	if(flag==1)
	printf("\nPattern found at position: %d\n ",k);
	else
	printf("\nPattern not found in text \n");
	// getc();
}