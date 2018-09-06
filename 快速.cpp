#include<iostream>
using namespace std;
int Partition(int *r,int first,int end)
{
	int i,j,temp;
	i=first;j=end;	
	while(i<j)
	{
		while(i<j&&r[i]<=r[j])j--;
		if(i<j){
			temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i++;
		}
		while(i<j&&r[i]<=r[j])i++;
		if(i<j){
			temp=r[j];
			r[j]=r[i];
			r[i]=temp;
			j--;
		} 
	}
	return i;
}
void QuickSort(int *r,int first,int end)
{
	if(first<end)
	{
		int pivot=Partition(r,first,end);
		QuickSort(r,first,pivot-1);
		QuickSort(r,pivot+1,end);
	}	
}
int main()
{
	int r[]={1,2,4,8,6,9,3,5,7,10};
	int first,end;
	QuickSort(r,first,end);
	for(int i=0;i<10;i++)
	cout<<r[i]<<endl;
	return 0;
}