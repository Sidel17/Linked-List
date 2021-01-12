#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void PrintList(const List L);
void PrintList(const List L)
{
	Position P = Header(L);
   	if(IsLast(P,L)){
		printf("\n\nMemory Kosong karena telah dihapus ");
	}
	else{
		printf("\n");
	do{
		P=Advance(P);
		printf("%d\t",Retrieve (P));
	}while(!IsLast(P,L));
	}
}

int main(int argc, char *argv[])
{
	int x=0;
	List L = NULL;
	Position P = NULL;
	
	L = Construct(L); 
	P = Header(L);    

	Insert(10, L, P); 
	PrintList(L);
	
	P = Advance(P);       
	Insert(70, L, P); 
	PrintList(L);
	
	P = Advance(P);      
	Insert(11, L, P); 
	PrintList(L);	
	
	P = Advance(P);      
	Insert(3, L, P); 
	PrintList(L);
	
	P = Advance(P);       
	Insert(99, L, P); 
	PrintList(L);
	
	printf("\nPencarian Nilai Sebelum\n");
	if((P=FindPrevious(11,L))!=NULL)
	{	printf("Cari elemen Dengan Nilai =11");
		FindPrevious(11,L);
		printf("\nPencarian berhasil, Nilai sebelum 11 adalah %d\n\n",Retrieve(P));
		PrintList(L);
	}
	printf("\nPencarian dan Peng-Updatetan\n");
	if((P=Find(11,L))!=NULL)
	{
		printf("\nPencarian berhasil, Nilai %d ditemukan \n\n",Retrieve(P));
		Update(50,P);
		printf("Elemen dengan nilai 11 telah diupdate menjadi 50\n");
		PrintList(L);
	}
	printf("\n");
	printf("nilai rata - rata = %f",average(L,P));
	//printf("\nDelete elemen	dengan nilai = 500\n");
	//Delete(500,L);
	//PrintList(L);
	
	//DeleteList(L);
	
	return 0;
}
