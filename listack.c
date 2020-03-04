#include <stdio.h>
typedef struct node{
	char ch;
	struct node *next;
}Node;

typedef struct LinkStack{
	Node* top;
	int count;
}linkstack;
