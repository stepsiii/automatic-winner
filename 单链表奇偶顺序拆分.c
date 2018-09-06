#include<stdlib.h>
#include<stdio.h>
typedef struct node{
	int data;
	struct node *next;
}node;

int main(){
	//函数申明
	
	node *fun(int a[],int n);
	void display(node *head);
	//变量定义
	int a[]={1,2,4,3,5,6,10,8,9,7};
	int i,n=10;
	node *head;

	//函数调用	
 	head = fun(a,n);
	display(head);
}

node *fun(int a[],int n){
node* lastNode(node *head,int length);
	int i;
	int length=0;
	node *head;
	node *rear;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	rear = head;
	for(i=0;i<n;i++){
		if(a[i]%2 != 0){  //奇数，头插入法
		node *s;
		s = (node*)malloc(sizeof(node));
		s->data=a[i];
		s->next=head->next;
		head->next=s;
		rear=lastNode(head,length);
		}
		else{  //偶数，尾插入法
		rear=lastNode(head,length);
		node *s;
		s = (node*)malloc(sizeof(node));
		s->data=a[i];
		rear->next=s;
		rear=s;
		rear->next=NULL;
		}
		length++;
	}
	return head;
}
//追踪单链表的尾指针
node* lastNode(node *head,int length){
	//在单链表中不断加入新的结点时，如何找到终端结点的指针，思考并写出对应的代码
int i=0;
node *p=head; 
for(i=0;i<length;i++){
	while(p->next!=NULL)
	p=p->next;
	return p;
}

}
//输出带头结点的单链表的各个结点的值
void display(node *head){
	node *p=head->next;
	if(p==NULL)
		printf("该链表为空");
	while(p!=NULL)
	{
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
}
