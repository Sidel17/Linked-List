typedef int ElementType; 

#ifndef _List_H 
#define _List_H

struct Node;						 
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List Construct(List L);		       //fungsi untuk membuat list (header L)
void Insert(ElementType X, List L, Position P ); //fungsi untuk insersi elemen

Position Header(List L);         //fungsi untuk menset L sebagai Header

Position Advance(Position P);    /*fungsi untuk memajukan pointer Posisi ke node elemen selanjutnya */
											 
Position Find(ElementType X, List L); // pencarian berdasarkan nilai elemen

void Update(ElementType X, Position P); // peng-updatean nilai elemen

Position FindPrevious(ElementType X,List L); //mencari simpul pendahulu

void Delete(ElementType X, List L); 

void DeleteList(List L);
								
ElementType Retrieve(Position P);   
int IsLast( Position P, List L );
int IsFirst( Position P, List L );
int IsEmpty(List L);
ElementType count (List L, Position P);
ElementType sum (List L, Position P);
double average(List L, Position P);
#endif  //Akhir dari _List_H 
