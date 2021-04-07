#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





struct Node_sparsemt {
    
    int col;
    int val;
    struct Node_sparsemt *next;
    
};

void display_sparsemat(struct Node_sparsemt **A, int m, int n) {
    
    int i;
    int j;
    struct Node_sparsemt *head;
    
    for(i = 0; i < m; i++) {
        head = A[i];
        for(j = 0; j < n; j++)
        {
            if(j == head->col) {
                printf("IN");
                printf("%d ", head->val);
                head = head->next;
            }
            else
                printf("0 ");
            
        }
        printf("\n");
    }
    
}

void Display_sparse(struct Node_sparsemt **t) {
    
    int i = 0;
    struct Node_sparsemt **head = t;
    for(; i < 2; i++) {
        head = t[i];
        while(head != NULL){
            printf("%d ", (*head)->val);
            head = (*head)->next;
        }
    }
}

int main(){
	

    int m = 0;
    int n = 0;
    int i = 0;
    int cols;
    int data;
    int nz;
    struct Node_sparsemt *last, *new;
    printf("Enter size of mtx: ");
    scanf("%d %d", &m, &n);
    
    //create an array of given size.
    
    struct Node_sparsemt *A[m];
    
    
    for(i = 0; i < m; i++) {
        
        printf("Enter no. of non zer elem in row %d: \n", i);
        scanf("%d", &nz);
    
        while(nz--) {
            printf("Enter non zer elem: ");
            scanf("%d %d", &cols, &data);
            if(A[i] == NULL) {
                A[i] = (struct Node_sparsemt*)malloc(sizeof(struct Node_sparsemt));
                A[i]->col = cols;
                A[i]->val = data;
                A[i]->next = NULL;
                last = A[i];
            } else {
                
                new = (struct Node_sparsemt*)malloc(sizeof(struct Node_sparsemt));
                new->col = cols;
                new->val = data;
                new->next = NULL;
                last->next = new;
                last = new;
            }
        }
    }
    
    //Display_sparse(A);
    
	display_sparsemat(A,m,n);
	
	for(i = 0; i < m; i++)
	    free(A[i]);
	
	return 0;
} 










