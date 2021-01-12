#include <stdio.h>
#include <stdlib.h>
#include "List.h"  //interface disertakan

struct Node{
	ElementType Element;
	Position Next;
	Position Prev;
};

List Construct(List L){
	L = malloc(sizeof(struct Node));
	if(L == NULL) printf( "Memori Kosong dan Tidak Dapat Dialokasi!!!" );
	L->Next = NULL;
	L->Prev = NULL;
	return L;
}

Position Header(List L){
	return L;
}

void Insert(ElementType X, List L, Position P){
	Position TmpCell = NULL;;

	TmpCell = malloc(sizeof(struct Node));
	if( TmpCell == NULL ) 
	printf( "Memori Kosong dan Tidak Dapat Dialokasi!!!" );	
	
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P-> Next=TmpCell;
	TmpCell->Prev=P;
	
}


Position Find(ElementType X, List L)
{
	Position P=NULL;
	P=L->Next;
	while(P!=NULL && P->Element != X)
		P=P->Next;
	
	return P;
}

Position FindPrevious(ElementType X,List L)
{
	Position P=NULL;
	P=L;
	while(P->Next !=NULL && P->Next->Element != X)
		P=P->Next;
		
	return P;
}

void Update(ElementType X, Position P)
{
	P->Element=X;
}


void Delete(ElementType X,List L)
{
	Position P=NULL;
	P=Find(X,L);
	if(!IsLast(P,L))
	{
		(P->Prev)->Next=P->Next;
		(P->Next)->Prev=P->Prev;
		free(P);
	}
	else {
		(P->Prev)->Next=NULL;
	}
}

void DeleteList(List L)
{
	Position P,Tmp;
	P=L->Next;
	L->Next=NULL;
	while(P!=NULL)
	{
		Tmp=P->Next;
		free(P);
		P=Tmp;
	}
}

Position Advance(Position P){
	return P->Next;
}

Position AdvanceReverse(Position P){
	return P->Prev;
}

ElementType Retrieve(Position P){
	return P->Element;
}

int IsLast( Position P, List L ){
	return P->Next == NULL;
}

int IsFirst( Position P, List L ){
	return P->Prev == NULL;
}

int IsEmpty(List L)
{
	return L->Next==NULL;
}
ElementType count (List L, Position P){
	P = Header(L);
	int jumlah = 0;
	while (P->Next !=NULL)
	{
		if (P->Next != L)
		{
		jumlah++;
		P = P->Next;
		}
		else 
		{
			break;
		}
	}
	return jumlah;
}
ElementType sum (List L, Position P){
	ElementType total =0;
	P = Header(L);
	while (P->Next !=NULL){
		if (P->Next != L)
		{
		total+= P->Element;
		P = P->Next;
		}
		else
		{
			break;
		}
	}
	return total;	
}
double average(List L, Position P){
	return sum(L,P) / count(L,P);
}
