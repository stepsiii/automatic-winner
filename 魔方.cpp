#include<stdio.h>
int main(){
int n=3,t,i1,j1; 
int a[3][3]={{}};
	if (n%2==0)   
		printf("n应为奇数！");
	else{
		printf("执行中。。。\n");
		int i=0;
		int j=((n+1)/2)-1;
		a[i][j]=1;
			for(t=2;t<=n*n;t++)
			{
			if(i==0)
				i1=n-1;
			else
				i1=i-1;
			if(j==0)
				j1=n-1;
			else
				j1=j-1;
			if(a[i1][j1]!=0)
				{a[i+1][j]=t;
				i+=1;}
			else
				{a[i1][j1]=t;
				i=i1;
				j=j1;}
			}
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
					printf("%d\t",a[i][j]);
			}
			printf("\n");
			printf("\n");
		}
		printf("%d",t);
	}
}
	