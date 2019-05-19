#include <iostream>
#include <cstdio>
#include <cstring> 
 

using namespace std;


int N, x;

struct node 
{
   int data;
   node* next;
   node* prev;
};  

bool isEmpty(node *head)
{
	if(head == NULL)
		return 1;
	else
		return 0;
}

void insertAsFirst(node *&head, node *&last, int number)
{
	node *temp = new node;
	temp->data = number;
	temp->next = NULL;
	temp->prev = NULL;

	head = temp;
	last = temp;

}

void insertAsLast(node *&head, node *&last, int number)
{
	node *temp = new node;
	temp->data = number;
	temp->next = head; //zhongyao
	last->next = temp;
	temp->prev = last;
	last = temp;
	head->prev = last;

}

void insert(node *&head, node *&last, int number)
{
	if(isEmpty(head)) insertAsFirst(head, last, number);
	else
	{
		node *temp = new node;
		temp->data = number;
		temp->next = NULL;
		last->next = temp;
		temp->prev = last;
		last = temp;
	}
}

void remove(node *&head, node *&last)
{
	if(isEmpty(head))
		cout << "The list is empty" << endl;
}

void showlist(node *head, node *current)
{
	if(isEmpty(current)) cout << "The list is empty" << endl;
	else
	{
		cout << "The list contains: \n";
		bool b = 1;
		while(head != current || b)
		{
			b = 0;
			cout << current->data << endl;
			current = current->next;
		}
	}

}


int main()
{
	freopen("1038_2.in", "r", stdin);
	freopen("1038_2.out", "w", stdout);

//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	node *head = NULL;
	node *last = NULL;

	int number, T, bs;
	cin >> T;
	cin >> bs;
	bs = bs % T;
	if(!bs) bs = T;

	
	insertAsFirst(head, last, 1);
	for(int i = 2; i <= T - 1; i++)
	{
		insert(head, last, i);
	}
	insertAsLast(head, last, T);

	
	node *p = head;
	int cnt = 0;
	
	while(head != last)
	{
		cnt++;
		
		if(cnt == bs)
		{
			cnt = 0;
			node *temp = p;
			T--;
			p = p->next;
			if(temp == head)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				head = temp->next;  
				delete temp;
				//showlist(head, head);
			}
			else if(temp == last)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				last = temp->prev;  
				delete temp;
				//showlist(head, head);
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				//showlist(head, head);
			}
			cin >> bs;
			bs = bs % T;
			if(!bs) bs = T;
			continue;
		}
		p = p->next;
	}
	cout << head->data;




	return 0;
}
