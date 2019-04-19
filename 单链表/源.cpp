#include <iostream>
#include <string>
using namespace std;


struct Node
{
	int  data;
	Node *next;
};


class LinkList {
private:
	Node *first;
public:
	LinkList(); //ͷ�彨��

	~LinkList();
	void Creat(int n);     //����
	void PrintList();       //����
	void Change();        //����
	void Delte();        //ɾ��ż��Ԫ�ؽڵ�
	void Insert(int x);    //��������
	void And(LinkList&);  //��������
	void Reverse();

};


LinkList::LinkList()
{
	first = new Node;
	first->next = NULL;

}

void LinkList::Creat(int  n)
{
	int a[100];
	for (int i = 0; i < n; i++)
	{

		Node *s = new Node;
		cin >> a[i];
		s->data = a[i];
		s->next = first->next;
		first->next = s;
	}
}

void LinkList::PrintList()
{
	Node *p = first->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


LinkList::~LinkList()
{
	while (first != NULL)
	{
		Node *q = first;
		first = first->next;
		delete q;
	}
}


void LinkList::Change()
{
	Node *i = first->next, *j = first->next;
	j = j->next;
	i->next = NULL;
	i = j;
	while (i != NULL)
	{
		j = j->next;
		i->next = first->next;
		first->next = i;
		i = j;
	}
}
void LinkList::Delte()
{
	Node *s, *q, *p;
	q = first;
	p = q->next;

	while (p != NULL)
	{
		if ((p->data) % 2 == 0)
		{
			s = p->next;
			q->next = s;
		}
		else {
			q = q->next;
		}
		p = p->next;
	}
}

void LinkList::Insert(int n)
{
	Node* p = first;
	Node* s = new Node;
	s->data = n;

	if (first->next == NULL)  //��˳���ʱ
	{
		s->next = NULL;
		first->next = s;
		return;
	}

	if (p->next->data>n&&first->next != NULL)  //С�ڵ�һ��Ԫ��ʱ
	{
		s->next = first->next;
		first->next = s;
		return;
	}

	p = first->next;
	while (p->next != NULL)  //���ڵ�һ��Ԫ�أ���С�����һ��Ԫ��ʱ
	{
		if ((p->data <= n) && (p->next->data>n))
		{
			s->next = p->next;
			p->next = s;
			return;
		}
		else {
			p = p->next;
		}
	}

	if (p->data <= n)  //�������һ��Ԫ��ʱ
	{
		s->next = NULL;
		p->next = s;
		return;
	}
}

void LinkList::And(LinkList& a)
{
	Node* p = first->next;
	while (p != NULL)
	{
		a.Insert(p->data);
		p = p->next;
	}
	a.Reverse();
}
void LinkList::Reverse()
{
	Node *p = first->next, *q = first->next;
	q = q->next;
	p->next = NULL;
	p = q;
	while (p != NULL)
	{
		q = q->next;
		p->next = first->next;
		first->next = p;
		p = q;
	}
}


int main()
{
	LinkList a;
	cout << "ͷ�巨��������������������:" << endl;
	a.Creat(6);

	cout << "������"<<endl;
	a.PrintList();

	cout << "���ú�"<<endl;
	a.Reverse();
	a.PrintList();


	cout << "ɾ��ż���ڵ��"<<endl;
	a.Delte();
	a.PrintList();

	cout << "����Ԫ��6 ������Ϊ��"<<endl;
	a.Insert(6);
	a.PrintList();

	LinkList b;
	b.Insert(7);
	b.Insert(15);
	b.Insert(65);
	b.Insert(31);
	b.Insert(12);
	b.Insert(20);
	cout << "����һ��������a1:" << endl;
	b.PrintList();

	LinkList c;
	c.Insert(5);
	c.Insert(17);
	c.Insert(26);
	c.Insert(46); 
	c.Insert(31); 
	c.Insert(59);
	cout << "����һ��������a2:" << endl;
	c.PrintList();

	cout << "�����ǵݼ���������ϲ���ķǵ���������Ϊ��"<<endl;
	b.And(c);
	c.PrintList();

	return 0;
}









