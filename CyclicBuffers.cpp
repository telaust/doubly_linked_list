
#include <iostream>

using namespace std;


struct s_list
{
	int data;
	s_list* next;
};

s_list*
init(int val)
{
	s_list* l = new s_list; // dynamic allocation
	l->data = val;
	l->next = NULL;
	return l;
}

void
add_node(s_list* list, int val)
{
	if (list == NULL) 
	{
		list = init(val);
		exit(0);

	}
	
	s_list* newnode = new s_list;
	s_list* head = list;

	newnode->data = val;
	newnode->next = head;

	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = newnode;

	cout << val << " was added" << endl;

	
}

void
print_nodes(s_list* list)
{
	s_list* tmp = list;
	s_list* head = list;

	do {
		
		cout << head->data << endl;
		head = head->next;

	} while (head->next != tmp);
}

int main()
{
	s_list* l = new s_list;
	add_node(l, 12);
	add_node(l, 24);

	print_nodes(l);

	return 0;
}