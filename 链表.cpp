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

LinkList::LinkList()//�޲����Ĺ��캯��������һ��������
{
	first = new LinkNode;
	first->next = NULL;
}
LinkList::LinkList(int a[], int n)//�в����Ĺ��캯��������һ�������ݵ����� 
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
void LinkList::LinkList_t(int a[], int n)//�в����Ĺ��캯��������һ�������ݵ�����
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
int LinkList::Get(int n)//���ҵ�nλ������
{
	LinkNode *s;
	s = first->next;
	for (int i = 1; i < n; i++)
	{
		s = s->next;
	}
	return s->data;
}
void LinkList::Get_c(int data) //��������
{
	LinkNode *s;
	int finded;
	s = first->next;
	int count = 1;
	while(s!=NULL){
		if (s->data == data) {
			finded = count;
			cout << "�ҵ�" << data << ",�ڵ�" << finded << "���ڵ���" << endl;
			count++;
			s = s->next;
		}
		else {
			count++;
			s = s->next;
		}
	}
}
void LinkList::Insert(int data, int n)//��������
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
	cout << "1.��������" << endl;
	cout << "2.��λ����" << endl;
	cout << "3.���ݲ���" << endl;
	cout << "4.��������" << endl;
	cout << "5.ɾ������" << endl;
	cout << "6.�˳�����" ;
}
int main()
{
	menu();
	int a[1000];
	int ch;
	LinkList L1;
	f1:ch = 0;
	cout << "\n\n\nѡ�����" << endl; cin >> ch;
	switch (ch)
	{
	case 1: {
		system("cls");
		int t;
		cout << "��������ֵ����:"; cin >> t;
		while (t > 1000) {
			cout << "��ֵ�������������롣" << endl;
			cout << "��������ֵ����:"; cin >> t;
		}
		for (int i = 0; i < t; i++) {
			cout << "�����" << i + 1 << "������"; cin >> a[i];
		}
		L1.LinkList_t(a, t);
		system("cls"); cout << "����ɹ�" << endl; menu(); goto f1;
	}
	case 2: {
		system("cls");
		int t = 0;
		cout << "��Ҫ�ڼ�λ������"; cin >> t;
		system("cls");
		cout << L1.Get(t) << endl;
		menu();
		goto f1;
	}
	case 3: {
		system("cls");
		int data;
		cout << "����Ҫ���ҵ����ݣ�"; cin >> data;
		system("cls"); menu(); cout << endl;
		L1.Get_c(data); goto f1;
	}
	case 4: {
		system("cls");
		int data;
		int n;
		cout << "����Ҫ�����λ�ã�"; cin >> n;
		cout << "����Ҫ��������ݣ�"; cin >> data;
		L1.Insert(data, n);
		system("cls"); menu(); cout << "\n����ɹ���"; goto f1;
	}
	case 5: {
		system("cls");
		int n;
		cout << "��Ҫɾ���ĸ����ݣ�"; cin >> n;
		L1.Del(n);
		system("cls"); menu(); cout << "\nɾ���ɹ���"; goto f1;
	}
	default:break;
	}
	return 0;
}
