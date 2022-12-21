#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void init(Node*& head)
{
	head = NULL;
}

Node* createNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}

Node* search(Node* head, int data)
{
	if (head != NULL)
	{
		Node* p = head;
		while (p != NULL)
		{
			if (p->data == data)
			{
				return p;
			}else
				p = p->next;
		}
		return NULL;
	}
	else
		std::cout << "Linked list is empty\n";
}

void addFirst(Node*& head, int data)
{
	Node* p = createNode(data);
	p->next = head;
	head = p;
}

void addLast(Node*& head, int data)
{
	Node* p = createNode(data);

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		Node* last = head;
		//Tim last
		/*while (last != NULL)
		{
			if (last->next == NULL)
			{
				last->next = p;
				break;
			}
			last = last->next;
		}*/
		while (last->next != NULL)
		{
			last = last->next;
		}
		//Chen vao cuoi
		last->next = p;
	}
}

void addBehind(Node*& head, int insertData, int data)
{
	Node* p = head;
	Node* insertNode = createNode(insertData);
	while (p != NULL && p->data != data)
	{
			p = p->next;
	}
	if (p != NULL) //Kiem tra xem co phan tu muon tim ko
	{
		insertNode->next = p->next;
		p->next = insertNode;
	}else
		std::cout << "Khong co phan tu muon tim!\n";
}

void addFront(Node*& head, int insertData, int data)
{
	if (search(head, data) != NULL)
	{
		Node* p = head;
		Node* previous = NULL;
		Node* insertNode = createNode(insertData);
		while (p->data != data)
		{
			previous = p;
			p = p->next;
		}
		previous->next = insertNode;
		insertNode->next = p;
	}
}

void deleteFirst(Node*& head)
{
	if (head != NULL)
	{
		Node* p = head;
		head = p->next;
		p->next = NULL;
		delete p;
	}else
		std::cout << "Linked list is NULL\n";
}

void deleteLast(Node*& head)
{
	if (head != NULL)
	{
		Node* last = head; 
		Node* previous = NULL;
		while (last->next != NULL)
		{
			previous = last;
			last = last->next;
		}
		if (previous == NULL)
		{
			deleteFirst(head);
		}
		else
		{
			previous->next = NULL;
			delete last;
		}
	}else 
		std::cout << "Linked list is NULL\n";
}

void deleteMember(Node*& head, int data)
{
	if (search(head, data) != NULL)
	{
		Node* member = head;
		Node* previos = NULL;
		while (member->data != data)
		{
			previos = member;
			member = member->next;
		}
		if (previos == NULL)
		{
			deleteFirst(head);
		}
		else
		{
			previos->next = member->next;
			member->next = NULL;
			delete member;
		}
	}
	else
		std::cout << data << " is not in linked list\n";
}

void output(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		std::cout << p->data << "\n";
		p = p->next;
	}
}

void clean(Node*& head)
{
	while (head != NULL)
	{
		deleteFirst(head);
	}
}

int main()
{
	Node* head;
	init(head);
	//addLast(head, 99);
	addFirst(head, 10);
	addFirst(head, 15);
	addFirst(head, 9);
	//addLast(head, 5);
	//addBehind(head, 0, 15);
	/*deletefirst(head);
	deletelast(head);*/

	//deleteMember(head, 15);

	addFront(head, 100, 15);
	clean(head);

	output(head);

	return 0;
}