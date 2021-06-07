#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DeNode{
	int key;
	struct DeNode * next;
	struct DeNode * prev;
}DeNode;

typedef struct Deck{
	DeNode * head;
	DeNode * tail;
	int n;
}Deck;


Deck * D_Init();
void D_PushFront(Deck * d, int x);
void D_PushBack(Deck *d, int x);
int D_Insert(Deck * d, int i, int x);
unsigned int D_PopFront(Deck * d);
int D_PopBack(Deck * d);
int D_Pull(Deck * d, int x);
void D_Print(Deck * d);
int D_Empty(Deck * d);
int D_Search(Deck * d, int i);
void D_Swap(Deck * d, int i);
void D_Bubble(Deck * d);


int main(){
	Deck * d;
	d=D_Init();
	int i;
	printf("%d\n", D_PopFront(d));
	for(i=9; i>=0; i--){
		D_PushBack(d, i);
	}
	D_Print(d);
	//printf("%d", D_Search(d, 5));
	D_Bubble(d);
	D_Print(d);
	return 0;
}


Deck * D_Init(){
	Deck * result=(Deck *)malloc(sizeof(Deck));
	result->head=NULL;
	result->tail=NULL;
	result->n=0;
	return result;
}

void D_PushFront(Deck * d, int x){
		DeNode * tmp=(DeNode *)malloc(sizeof(DeNode));
		tmp->next=NULL;
		tmp->prev=NULL;
		tmp->key=x;
	
		if(d->n==0){
			d->head=tmp;
			d->tail=tmp;
			d->n=1;
			return;
		}
		else{
			d->head->prev=tmp;
			tmp->next=d->head;
			d->head=tmp;
			d->n++;
			return;
		}
}

void D_PushBack(Deck *d, int x){
	DeNode * tmp=(DeNode *)malloc(sizeof(DeNode));
	tmp->next=NULL;
	tmp->prev=NULL;
	tmp->key=x;
	
	if(d->n==0){
	d->head=tmp;
	d->tail=tmp;
	d->n=1;
	return;
	}
	else{
		tmp->prev=d->tail;
		d->tail->next=tmp;
		d->tail=tmp;
		d->n++;
		
		return;
	}
}

int D_Insert(Deck * d, int i, int x){
	if(i<0 || i>d->n) return 0;
	
	DeNode * tmp=(DeNode *)malloc(sizeof(DeNode));
	tmp->next=NULL;
	tmp->prev=NULL;
	tmp->key=x;
	
	if(d->n==0) {
		D_PushFront(d, x);
		return 1;
	}
	if(i==d->n) {
		D_PushBack(d, x);
		return 1;
	}
	int j;
	if(i < d->n/2) {
		DeNode * p=d->head;
		for(j=0;j<i-1;j++){
			p=p->next;
		}
		tmp->next=p->next;
		tmp->prev=p;
		p->next->prev=tmp;
		p->next=tmp;
		d->n++;
		return 1;
	}
	else{
		DeNode * p=d->tail;
		for(j=d->n-1;j>i;j--){
			p=p->prev;
		}
		tmp->next=p;
		p->prev->next=tmp;
		tmp->prev=p->prev;
		p->prev=tmp;
		d->n++;
		return 1;
	}
}

unsigned int D_PopFront(Deck * d){
	if(d->n==0) return -1;
	
	int Result=d->head->key;
	
	if(d->n==1){
		free(d->head);
		d->head=NULL;
		d->tail=NULL;
		d->n=0;
		return Result;
	}
	else{
		DeNode * tmp=d->head->next;
		free(d->head);
		d->head=tmp;
		d->head->prev=NULL;
		d->n--;
		return Result;
	}
}

int D_PopBack(Deck * d){
	if(d->n==0) return -1;
	
	int Result=d->tail->key;
	
	if(d->n==1){
		free(d->head);
		d->head=NULL;
		d->tail=NULL;
		d->n=0;
		return Result;
	}
	else{
	
		DeNode * tmp=d->tail->prev;

		free(d->tail);
		d->tail=tmp;
		d->tail->next=NULL;
		d->n--;
		return Result;
	}
}

int D_Pull(Deck * d, int x){
	if(d->n==0) return -1;
	
	
	//проверка на 0<=x<=n-1;
	if(x<0 || x> d->n-1) return -1;
	else{
		if(x==0) return D_PopFront(d); 
		if(x==d->n-1) return D_PopBack(d);
		
		if(x < d->n/2){
			DeNode * tmp=d->head;
			int j;
			for(j=0; j<x; j++) tmp=tmp->next;
			int result=tmp->key;
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			d->n--;
			return result;
		}
		else{
			DeNode * tmp=d->tail;
			int j;
			for(j=d->n-1; j>x; j--) tmp=tmp->prev;
			int result=tmp->key;
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			d->n--;
			return result;
		}
		
	}
}

void D_Print(Deck * d){
	int i=0;
	DeNode * p = d->head;
	for(i=0; i < d->n; i++){
		printf("%d ", p->key);
		p=p->next;
	}
	printf("\n");
	return;
}

int D_Empty(Deck * d){
	if(d->n==0) return 1;// если пустой
	else return 0;
}

int D_Search(Deck * d, int i){
	if(i<0 || i>d->n-1) return -1;
	if(d->n==0) return -1;
	if(i<d->n/2){
		DeNode * tmp=d->head;
		int j;
		for(j=0; j<i;j++) tmp=tmp->next;
		
		return tmp->key;
	}
	else{
		DeNode * tmp=d->tail;
		int j;
		for(j=d->n-1; j>i;j--) tmp=tmp->prev;
		
		return tmp->key;
	}
}

void D_Swap(Deck * d, int i){
	if(i<0 || i>d->n-1) return;
	if(d->n==0) return;
	if(i==d->n-1){
		D_Insert(d, i-1, D_PopBack(d));
		return;
	}
	else{
		D_Insert(d, i+1, D_Pull(d, i));
		return;
	}
}

void D_Bubble(Deck * d){
	int i, j;
	for(i=0; i<d->n-1; i++){
		for(j=0; j<d->n-i-1; j++){
			if(D_Search(d, j)>D_Search(d, j+1)) D_Swap(d, j);
		}
	}
}
