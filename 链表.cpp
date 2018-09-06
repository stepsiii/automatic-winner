#include<iostream>
using namespace std;
class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n); 
	void LinkList_t(int a[], int n);
	void PutList();
	int Get(int n);
	void Get_c(int data);
	void Insert(int data, int n);
	void Del(int n);
	void Remove(int n, int data);
private:
	class LinkNode 
	{
	public:
		int data;
		LinkNode *next;
	};
	LinkNode *first;
};

LinkList::LinkList()//无参数的构造函数，建立一个空链表
{
	first = new LinkNode;
	first->next = NULL;
}
LinkList::LinkList(int a[], int n)//有参数的构造函数，建立一个有数据的链表 
{
	first = new LinkNode;
	first->next = NULL;
	LinkNode *s, *r;
	r = first;
	for (int i = 0; i < n; i++)
	{
		s = new LinkNode; s->data = a[i];
		r->next = s; r = s;
	}
	r->next = NULL;
}
void LinkList::LinkList_t(int a[], int n)//有参数的构造函数，建立一个有数据的链表
{
	first = new LinkNode;
	first->next = NULL;
	LinkNode *s, *r;
	r = first;
	for (int i = 0; i < n; i++)
	{
		s = new LinkNode; s->data = a[i];
		r->next = s; r = s;
	}
	r->next = NULL;
}
int LinkList::Get(int n)//查找第n位的数据
{
	LinkNode *s;
	s = first->next;
	for (int i = 1; i < n; i++)
	{
		s = s->next;
	}
	return s->data;
}
void LinkList::Get_c(int data) //查找数据
{
	LinkNode *s;
	int finded;
	s = first->next;
	int count = 1;
	while(s!=NULL){
		if (s->data == data) {
			finded = count;
			cout << "找到" << data << ",在第" << finded << "个节点中" << endl;
			count++;
			s = s->next;
		}
		else {
			count++;
			s = s->next;
		}
	}
}
void LinkList::Insert(int data, int n)//插入数据
{
	LinkNode *r, *s;
	s = first;
	r = new LinkNode;
	r->data = data;
	for (int i = 1; i < n; i++)
	{
		s = s->next;
	}
	r->next = s->next;
	s->next = r;
}
void LinkList::Del(int n)
{
	LinkNode *s;
	s = first;
	for (int i = 1; i < n; i++)
	{
		s = s->next;
	}
	s->next = s->next->next;
}
void menu()
{
	cout << "1.建立链表" << endl;
	cout << "2.按位查找" << endl;
	cout << "3.数据查找" << endl;
	cout << "4.插入数据" << endl;
	cout << "5.删除数据" << endl;
	cout << "6.退出程序" ;
}
int main()
{
	menu();
	int a[1000];
	int ch;
	LinkList L1;
	f1:ch = 0;
	cout << "\n\n\n选择操作" << endl; cin >> ch;
	switch (ch)
	{
	case 1: {
		system("cls");
		int t;
		cout << "请输入数值个数:"; cin >> t;
		while (t > 1000) {
			cout << "数值过大，请重新输入。" << endl;
			cout << "请输入数值个数:"; cin >> t;
		}
		for (int i = 0; i < t; i++) {
			cout << "输入第" << i + 1 << "个数："; cin >> a[i];
		}
		L1.LinkList_t(a, t);
		system("cls"); cout << "输入成功" << endl; menu(); goto f1;
	}
	case 2: {
		system("cls");
		int t = 0;
		cout << "想要第几位的数？"; cin >> t;
		system("cls");
		cout << L1.Get(t) << endl;
		menu();
		goto f1;
	}
	case 3: {
		system("cls");
		int data;
		cout << "输入要查找的数据："; cin >> data;
		system("cls"); menu(); cout << endl;
		L1.Get_c(data); goto f1;
	}
	case 4: {
		system("cls");
		int data;
		int n;
		cout << "输入要插入的位置："; cin >> n;
		cout << "输入要插入的数据："; cin >> data;
		L1.Insert(data, n);
		system("cls"); menu(); cout << "\n插入成功！"; goto f1;
	}
	case 5: {
		system("cls");
		int n;
		cout << "想要删除哪个数据？"; cin >> n;
		L1.Del(n);
		system("cls"); menu(); cout << "\n删除成功！"; goto f1;
	}
	default:break;
	}
	return 0;
}
