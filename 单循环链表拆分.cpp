#include<stdlib.h>
#include<stdio.h>
typedef int dataType;
typedef struct node{
	dataType data;
	struct node *next;
}node;

int main(){
	node *inition();
	//新建链表 
	void build(node *L1,dataType a[],int n);
	//链表赋值 
	void display(node *L1);
	//链表输出 
	void marge(node *L2,node *L1);
	//链表拆分 
	dataType a[10]={1,2,3,4,5,6,7,8,9,10};
	//数组定义 
	node *L1=inition();
	node *L2=inition();
	build(L1,a,10);
	display(L1);
	marge(L2,L1);	
	display(L1);
	display(L2);
	return 0;
}
node *inition(){
	node *L1;
	L1=(node*)malloc(sizeof(node));
	L1->next=L1;
	return L1;
}

//链表空间开辟与指针定义 
void display(node *L1){
	node *p=L1->next;
	while(p!=L1)
	{
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
}
//顺序输出链表中的值 
void build(node *L1,dataType a[],int n){
	node *rear;
	rear=L1;
	int i;
	for(i=0;i<n;i++)
	{
		node *s;
		s=(node*)malloc(sizeof(node));
		s->data=a[i];
		rear->next=s;
		rear=s;
	}
	rear->next=L1;
}
//将数组中的值赋值链表 
void marge(node *L2,node *L1)
{
	node *p;
	node *q;
	p=L1;
	q=L1->next;
	int i=1;
	while(q!=L1)
	{
		if(i%2==1){
			node *u;
			u=q->next;p->next=q;p=q;p->next=L1;
			q=u;i++;
		}
		else{
			node *u;
			u=q->next;q->next=L2->next;L2->next=q;
			q=u;i++;
		}
	}
}
//链表拆分，按照下标分组 