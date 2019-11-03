

/* ****************************************************************************
			        (MAIN PROGRAM FILE)

        JACOBI METHOD TO FIND ALL EIGEN VALUES OF A REAL SYMMETRIC MATRIX
	Author- SHIBA BISWAS
	Designation- M.Sc (Mathematics) Student at University of North Bengal
	gmail- shibabiswas1@gmail.com
	INDIA

***************************************************************************** */

#include<stdio.h>
#include<math.h>
#include"Function.h"
void main()
{
	int i,j,k,n,p,q,M;
	float a[10][10],b[10][10],r[10][10],A,B,C,S,big,t;
	printline(60);
	printf("Enter The order of the non-singular symmetric matrix : ");
	scanf("%d",&n);
	printline(60);
	read(a,n);
	printline(60);
	printf("The given non-singular symmetric matrix is :\n");
	write(a,n);
	printline(60);
	printf("Enter the number of iteration : ");
	scanf("%d",&M);
	for(k=1;k<=M;k++)
	{
		big=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i<j)
				{
					if(fabs(a[i][j])>big)
					{
						big=fabs(a[i][j]);
						p=i;
						q=j;
					}
				}
			}
		}
		if(a[p][p]<a[q][q])
		{
			t=-1;
		}
		else
		{
			t=1;
		}
		A=2*a[p][q]*t;
		B=fabs(a[p][p]-a[q][q]);
		C=pow(0.5*(1+(B/pow(A*A+B*B,0.5))),0.5);
		S=A/(2*C*pow(A*A+B*B,0.5));
		cons(C,S,n,p,q,b);
		STAS(b,a,n,r);
		fun(r,b,n,a);
	}
	printline(60);
	printf("The required eigen values are :\n");
	for(i=1;i<=n;i++)
	{
		printf("a%d%d = %f.\n",i,i,a[i][i]);
	}
	printline(60);
}

