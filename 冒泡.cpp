#include <iostream>
using namespace std;
void BubbleSort(int *r,int n)
{
	int exchange=n;
	int bound;
	int temp;
	while(exchange!=0)
	{
		bound=exchange;exchange=0;
		for(int j=1;j<bound;j++)
		if(r[j]>r[j+1]){
			temp=r[j];
			r[j]=r[j+1];
			r[j+1]=temp;
			exchange=j;

		}
	}
} 
int main()
{
	int r[]={1,2,3,4,65,8,4,9,14,3};
	BubbleSort(r,10);
	for(int i=0;i<10;i++)
	cout<<r[i]<<endl;
	return 0;
}
