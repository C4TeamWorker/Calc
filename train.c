#include <stdio.h>
#include <stdlib.h>

typedef struct Carriage{
	char ch;
	struct Carriage *next;
}carriage;

typedef struct Train{
	carriage* passenger;
	int line;
	struct Train* next;
}train;

void getCarriage(carriage *L, char &str[]){
	carriage *p = L->next;
	int i = 0;
	while(p != NULL){
		str[i] = p->ch;
		p = p->next;
	}
}

int carriageLength(carriage *s){
	int i = 0;
	carriage *p = s;
    while(p->next != NULL){
		i++;
		p = p->next;
	}
	return(i);
}

int trainLength(train *s){
	int i = 0;
	train *p = s;
	while(p->next != NULL){
		i++;
		p = p->next;
	}
	return(i);
}

void initTrain(train *&s){
	s = (train *)malloc(sizeof(train));
	s->passenger = NULL;
	s->line = 0;
	s->next = NULL;
}

void destroyTrain(train *&s){
	train *p = s->next;
	while(p!=NULL){
		carriage *tmp = p->passenger->next;
		while(tmp!=NULL){
			free(p->passenger);
			p->passenger = tmp;
			tmp = tmp->next;
		}
		free(p->passenger);
		free(s);
		s = p;
		p = p->next;
	}
	free(s);
}
