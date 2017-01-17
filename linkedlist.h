#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
typedef struct Node Node;
struct List
{
	Node* head;
};
typedef struct List List_t;


/*		// Takes &l as param where l is ptr
void insert(List_t **l, int data);
void disp ( List_t** l);

*/

/*		// Takes l as param where l is ptr 

void insert(List_t *l, int data);
void disp ( List_t* l);

*/


		// Takes &l as param where l is not ptr 

void insert(List_t *l, int data);
void del(List_t* l, int data);
void disp ( List_t* l);
