#include<stdlib.h>
#include<stdio.h>
typedef struct node{
	int data;
	struct node *next;
}node;

int main(){
	//��������
	
	node *fun(int a[],int n);
	void display(node *head);
	//��������
	int a[]={1,2,4,3,5,6,10,8,9,7};
	int i,n=10;
	node *head;

	//��������	
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
		if(a[i]%2 != 0){  //������ͷ���뷨
		node *s;
		s = (node*)malloc(sizeof(node));
		s->data=a[i];
		s->next=head->next;
		head->next=s;
		rear=lastNode(head,length);
		}
		else{  //ż����β���뷨
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
//׷�ٵ������βָ��
node* lastNode(node *head,int length){
	//�ڵ������в��ϼ����µĽ��ʱ������ҵ��ն˽���ָ�룬˼����д����Ӧ�Ĵ���
int i=0;
node *p=head; 
for(i=0;i<length;i++){
	while(p->next!=NULL)
	p=p->next;
	return p;
}

}
//�����ͷ���ĵ�����ĸ�������ֵ
void display(node *head){
	node *p=head->next;
	if(p==NULL)
		printf("������Ϊ��");
	while(p!=NULL)
	{
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
}
