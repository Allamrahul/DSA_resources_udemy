#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int len_of_str(char* p){
	
	int i = 0;
	
	//printf("%c \n", p[0]);
	while(p[i] != '\0') i++;
	
	return i;
	
}

void upper_case_to_lower(char* p){
	int i = 0;
	while(p[i] != '\0') {
		p[i] = p[i]+32; i++;
	}
}

void Reverse_str(char* p){
	char temp;
	
	int len = len_of_str(p);
	
	int j = 0;
	int k = len - 1;
	
	while(j < k){
		temp = p[j];
		p[j] = p[k];
		p[k] = temp;
		j++;
		k--;
	} 
	
}

int isPalin_str(char p[]){
	
	int i = 0;
	int j = strlen(p) - 1;
	
	while(i < j){
		if(p[i++] != p[j--]) return 0;
		
	}
	
	return 1;
}

char* dup_in_str(char p[]){ // developed by myself. Special becuase I used malloc effectively
	
	char* count = (char *)malloc(128 * sizeof(char));
	int j,i;
	for(i = 0; i < 128; i++) count[i] = 0;
	
	for(j = 0; p[j] != '\0'; j++){
		count[p[j]]++;
	}
	return count;
}

void is_str_duplicate(char p[]){ // bitset method - good one to understand for bitwise operations.
	
	long int H = 0, x = 0;
	int i;
	for(i = 0; p[i] != '\0'; i++){
		x = 1;
		x = x << p[i]-97;
		
		if(x&H) printf("%c is dup \n", p[i]);
		else H = H | x;  
	}
}

void swap(char* p, int a, int b){
	char temp;
	
	temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}

void permutation_swap(char s[], int l, int h){ // a tricky one. But good for recursion.
	int i;
	if(l == h) printf("%s \n", s);
	
	else {
	
		for(i = l; i <= h; i++){
			swap(s, i, l);	
			permutation_swap(s, l+1, h);
			swap(s, i, l);
		}
	}
}

void permutation_str(char s[], int k){
	
	static int A[10] = {0};
	static char Res[10];
	int i;
	
	if(s[k] == '\0'){
		Res[k] = '\0';
		printf("%s \n", Res);
	}
	
	else{
		for(i = 0; s[i] != '\0'; i++){
			
			if(A[i] == 0){
				A[i] = 1;
				
				Res[k] = s[i];
				permutation_str(s, k+1);
				A[i] = 0;
			}
		}
	}
	
}


// MATRICES//

struct Matrix
{
	 int A[10];
	 int n;
};

void Set(struct Matrix *m,int i,int j,int x)
{
 	if(i==j)
 		m->A[i-1]=x;

}
int Get(struct Matrix m,int i,int j)
{
 	if(i==j)
 		return m.A[i-1];
 	else
 		return 0;
}
void Display(struct Matrix m)
{
 int i,j;
 for(i=0;i<m.n;i++)
 {
 	for(j=0;j<m.n;j++)
 	{
 		if(i==j)
		 	printf("%d ",m.A[i]);
		else
			printf("0 ");
	}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	//permutation("ABC", 0, 2);
	//char s[] = "ABC";
	//permutation_swap(s, 0, 2);
	//permutation_str(s, 0);
	
	/*
	is_str_duplicate("ssrssrk");
	
	char* c = dup_in_str("ssrssrk");
	int i;
	for(i = 0; i < 128; i++){
		if(c[i] > 1){
			printf("(char, count) = (%c,%d) \n", i, c[i]);
		}
	}
	free(c);
	
	
	printf("%d",isPalin_str("abbaa"));
	
	char p[] = "WELLEW";
	
	char q[100];
	
	int j = 0;
	
	while(p[j] != '\0') {
		q[j] = p[j];
		j++;
	}
	
	Reverse_str(&p);
	printf("%s %s \n", p, q);
	int k = 1;
	int m = 0;
	while(p[m] != '\0') {
		if(p[m] != q[m]) {
			printf("Not palindrome");
			k = 0;
		}
		m++;
	}
	if(k == 1) printf("Palindrome");
	*/
	//else printf("Not palindrome");
	
	//Reverse_str(&p);
	//printf("%s \n", p);
	//char *p = "welcome";
	//printf("%d \n", len_of_str(p));
	/*
	char p[] = "WELCOME";
	upper_case_to_lower(&p);
	printf("%s", p);
	*/
	return 0;
}
