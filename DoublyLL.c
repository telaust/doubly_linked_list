#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct Node
{
	int data; // uint8
	struct Node* next;
	struct Node* prev;
}node_t;


node_t*
alloc() // Allocate memory for node
{
	return (node_t*) malloc( sizeof( node_t* ) );
}

node_t*
init(int val)
{
	node_t* node = alloc();

	node->data = val;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

int
size(node_t* list)
{
	int c = 0;
	while (list->next != NULL)
	{
		c++;
		list = list->next;
	}
	return c;
}

node_t*
add_node(node_t* list, int ival)
{
	if (list == NULL)
	{
		list = alloc();
		list->data   =   ival;
		list->prev   =   NULL;
		list->next   =   NULL;
	}
	else
	{
		node_t* tmp = list;

		while (tmp->next != NULL)
			tmp = tmp->next;
		

		node_t* p = alloc();
		p->data   = ival;
		tmp->next = p;
		p->prev   = tmp;
		p->next   = NULL;
	}

	return list;
}

void 
free_node(node_t* node)
{
	//free(&(node->data));
	realloc(&(node->data), 0);
	realloc(node, 0);
}

void
free_list(node_t* &head)
{
	// do {

	// 	free(&head->data);
	
	// 	free(head);

	// } while (head != NULL);
	int n = size(head);
	// node_t* all = (node_t*)malloc(n * sizeof(node_t*));
	// free(all);

	free( head );
}

node_t*
copy_node(node_t* head, int val)
{
	node_t* node = alloc();	

	node_t* ref = head;

	while (ref != NULL)
	{
		if (ref->data == val)
		{
			node->data = val;
			node->prev = ref->prev;
			node->next = ref->next;

			break;
		}
		ref = ref->next;
	}

	return node;
}

/* printing */
void
print_disordered(node_t* head)
{
	
	printf("---------------- Print in disorder -------------------------\n");

	while (head->next != NULL)
		head = head->next;

	while (head->prev != NULL)
	{
		printf("%d\n", head->data);
		head = head->prev;
	}

	printf("\n");

}

void
print_ordered(node_t* head)
{
	printf("---------------- Print in order -------------------------\n");

	if (head->next != NULL) head = head->next;	

	do {
		printf("%d\n", head->data);
		head = head->next;
	} while (head != NULL);

	printf("\n");
}

void 
reversedLinkedList(node_t* head)
{
    if(head == NULL) return;

    node_t* prev = NULL;
    node_t* current = NULL;
    node_t* next = NULL;
    
    current = head;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // now let the head point at the last node (prev)
    head = prev;
}


int main()
{

	node_t* list = alloc();
	

	list = add_node(list, 13);
	list = add_node(list, 21);


	// print_disordered(list);
	
	print_ordered(list);
	// free_node(list);

	print_ordered(list);

	reversedLinkedList(list);
	print_ordered(list);


	return 0;
}