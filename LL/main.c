/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct Node 
{
	int data;
	struct Node* next;
}*first;


void insert_ele(int elem){
	
	
	struct Node* new;
	struct Node* temp= first;
	
	if(first == NULL){
	    
	    new = (struct Node*) malloc(sizeof(struct Node)); // create a node
	    new->data = elem;
	    new->next = NULL;
	    first = new;
	 
	    
	} 
	else {
	    temp = first;
	    while(temp->next != NULL) temp = temp->next;
	    new = (struct Node*) malloc(sizeof(struct Node)); // create a node
	    temp->next = new;
	    new->data = elem;
	    new->next = NULL;
	   
	}
}


int main(){
	
	int A[] = {3,5,7,10,15};
	first = NULL;
	int i;
	
	for(i = 0; i< 5; i++)
	    insert_ele(A[i]);
	    
	struct Node* t2 = first;
	while(t2 != NULL){
		printf("%d ->", t2->data);
		t2 = t2->next; 
	}
	 
	return 0;
} 
