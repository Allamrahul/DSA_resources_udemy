#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void fun_head_recursion(int n){
	
	if(n > 0){
		fun_head_recursion(n-1);
		printf("%d ", n);
		
	}

}


int fun1_tail_recirsion(int n ){
	static int x = 0;
	if(n>0){
		x++;
		return fun1_tail_recirsion(n-1) + x;
	}
	return 0;
}

int fun1_tree_recirsion(int n ){
	
	if(n>0){
		printf("%d", n);
		fun1_tree_recirsion(n-1);
		fun1_tree_recirsion(n-1);		
	}
	return 0;
}


void funB_indir_recur(int n); // prototype


void funA_indir_recur(int n){

	if(n>0){
		
		printf("%d", n);
		funB_indir_recur(n-1);
	}

}


void funB_indir_recur(int n){

	if(n>0){
		
		printf("%d", n);
		funA_indir_recur(n/2);
	}

}

int fun_nested_recur(int n) {
	
	if(n>100)
		return n-10;
	return fun_nested_recur(fun_nested_recur(n+11)); 
}


int sum_of_N_natural_nubers_recur(int N) {
	if(N == 0)
		return 0;

	return N + sum_of_N_natural_nubers_recur(N-1);

}

int fact_of_N_natural_nubers_recur(int N) {
	if(N == 0)
		return 1;

	return N * fact_of_N_natural_nubers_recur(N-1);

}


int power_recur(int num, int exp){
	
	if(exp == 0){
		return 1;
	} 
	
	return num * power_recur(num, exp-1);
	
	
}


int power_recur_fast(int num, int exp){
	
	if(exp == 0){
		return 1;
	} 
	
	if(exp%2 == 0){
		
		return power_recur_fast(num * num, exp/2);
	}
	else {
		return num * power_recur_fast(num* num, (exp-1)/2);
	}
	
	
}

double Taylor_Series_recur(int x, int n) {
	
	static double p = 1, f = 1;
	double r;
	
	if(n == 0) 
		return 1;
	
	
	r = Taylor_Series_recur(x, n-1);

	p = p * x;
	f = f * n;

	return r + p/f;
	
}

double Taylor_Series_hornerrule_recur(int x, int n) {
	
	static double s = 1;
	
	if(n == 0) 
		return s;
	
	
	s = 1 + (x*s/n);
	

	return Taylor_Series_hornerrule_recur(x, n-1);
	
}



double Taylor_Series_loop(int x, int n) {
	
	double s = 1;
	int i;
	double num = 1; 
	double den = 1;
	
	for(i=1; i < n; i++){
		
		num = num * x;
		den = den * i;
		s += num/den;
	}
	return s;
	
}


int fibonacci(int n) {
	
	int t_0 = 0;
	int t_1 = 1;
	int sum = 0;
	
	if(n <= 1) return n;
	
	for(int i = 2; i <= n; i++){
		
		sum = t_0 + t_1;
		t_0 = t_1;
		t_1 = sum;
	}
	
	return sum;
	
}

int fibonacci_recursion(int n) {
	
	if(n <= 1) return n;
	
	return fibonacci_recursion(n-2) + fibonacci_recursion(n-1);
	
}

int F[10];

int fibonacci_recursion_memoization(int n) {
	
	if(n <= 1) {
		F[n] = n;
		return n;
	}
	
	if(F[n-2] == -1) {
		F[n-2] = fibonacci_recursion_memoization(n-2);
	} 
	
	if(F[n-1] == -1) {
		F[n-1] = fibonacci_recursion_memoization(n-1);
	}
	
	F[n] = F[n-1] + F[n-2];
	
	return F[n-2] + F[n-1];
	
}

int combination(int n, int r) {
	
	return fact_of_N_natural_nubers_recur(n)/(fact_of_N_natural_nubers_recur(n-r) * fact_of_N_natural_nubers_recur(r));
	
}


int combination_recursion(int n, int r) {
	
	if(r == 0 || n == r) return 1;
	
	return combination_recursion(n-1, r-1) + combination_recursion(n-1, r);
}


void TowerOfHanoi(int nDisks, int T1, int T2, int T3) {
	
	if(nDisks > 0) {
		TowerOfHanoi(nDisks-1, T1, T3, T2);
		printf("moving from %d to %d \n", T1, T3);
		TowerOfHanoi(nDisks-1, T2, T1, T3);
	}
}


int f(int n)

{

	static int i = 1;
	
	if (n>=5)return n;
	
	n = n+i;
	
	i++;
	
return f(n);

}

void foo (int n, int sum)

{

int k = 0, j = 0;

if (n == 0) return;

k = n % 10;

j = n/10;

sum = sum + k;

foo (j, sum);

printf("%d", k);

}


int f11(int &x, int c) 

{

	c = c - 1; 
	
	if (c == 0) return 1; 
	
	x = x + 1; 
	
	return f11(x,c) * x;

}

int fun (int n)

{ 

int x=1, k; 

if(n==1) return x; 

for (k=1; k<n; ++k) 

	x=x + fun (k) * fun (n - k); 

return x; 

}

struct Array_ptr {
	
	int *A;
	int size;
	int length;
};

struct Array {
	
	int A[15];
	int size;
	int length;
};

void Display(struct Array arr){
	
	printf("\nElements are\n");
	
	for(int i = 0; i < arr.length; i++){
		printf("%d ", arr.A[i]);
	}
}


void Append(struct Array *arr, int x) {
	
	if(arr->length < arr->size){
		arr->A[arr->length] = x;
		arr->length++;
	}
}

void Insert(struct Array *arr, int x, int index){
	
	if(index >= 0 && arr->length < arr->size && index <= arr->length){
	
		for(int i = arr->length; i > index; i--) {
			arr->A[i] = arr->A[i-1];	
		}
		arr->A[index] = x;
		arr->length++;
	
	}
	
}

int Delete(struct Array *arr, int index){
	
	if(index < arr->length && index >= 0){
		int x;
		x = arr->A[index];
		
		for(int i = index; i < arr->length-1; i++){
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
		return x;
	}
	return 0;
	
}

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int linearSearch(struct Array *arr, int key){
	
	for(int i = 0; i < arr->length; i++){
		
		if(key == arr->A[i]){
			
			//return i; normal execution
			
			 
			//swap(&arr->A[i-1], &arr->A[i]);
			//return i-1; // shift the element with previous element to increase the speed - Transposition
			
			//swap(&arr->A[0], &arr->A[i]);
			//return 0; // shift with element at beginning to increase the speed - shift to head
			
		}
	}
	return -1;
}

int BinarySearch(struct Array *arr, int low, int high, int key) {
	
	while(low <= high) {
		
		int mid = (low + high)/2;
		
		if(arr->A[mid] == key) {
			return mid;
		}
		
		else if(arr->A[mid] > key) {
			high = mid - 1;
			
		}
		
		else {
			low = mid + 1;
		}
		
		//BinarySearch(&arr, low, high, mid);
	}
	return -1;
	
}

int Recursion_BinarySearch(int *arr, int low, int high, int key) { // good one
	
	while(low <= high) {
		
		int mid = (low + high)/2;
		
		if(arr[mid] == key) {
			return mid;
		}
		
		else if(arr[mid] > key) {
			high = mid - 1;
			
		}
		
		else {
			low = mid + 1;
		}
		
		return Recursion_BinarySearch(arr, low, high, key);
	}
	return -1;
	
}

int Get(struct Array *arr, int index){
	
	if(index >= 0 && index < arr->length){
		return arr->A[index];
	}
	return -1;
}

void Set(struct Array *arr, int index, int value) {
	if(index >= 0 && index < arr->length){
		arr->A[index] = value;
	}
}


int Max(struct Array arr) {
	int max = arr.A[0];
	
	for(int i = 1; i < arr.length; i++){
		if(arr.A[i] > max) {
			max = arr.A[i];
		}
	}
	return max;
}

int Min(struct Array arr) {
	int min = arr.A[0];
	
	for(int i = 1; i < arr.length; i++){
		if(arr.A[i] < min) {
			min = arr.A[i];
		}
	}
	return min;
}

int Sum(struct Array *arr) {
	
	int sum = 0;
	for(int i = 0; i < arr->length; i++){
		sum = sum + arr->A[i];
	}
	return sum;
}

int Recur_Sum(struct Array *arr, int n) {// good one
	
	if(n < 0) return 0;
	
	return arr->A[n] + Recur_Sum(arr, n-1);
}

float Avg(struct Array *arr) {
	//cout << "Avg op " << Sum(arr)/arr->length;
	return (float)Sum(arr)/arr->length;
} 

void Reverse(struct Array *arr){
	
	int *B;
	int i,j;
	
	B = (int *)malloc(arr->length * sizeof(int));
	
	for(i = (arr->length)-1, j = 0; i >= 0; i--, j++) {
		
		B[j] = arr->A[i];
		
	}
	
	for(i = 0; i < arr->length; i++){
		arr->A[i] = B[i];
	}
	free(B);
	
}

void Reverse_2(struct Array *arr){
	
	int *B;
	int i = 0;
	int j = arr->length-1;
	int temp;
	while(i < j){
		temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
		i++;
		j--;
	}
	
}

void left_shift(struct Array *arr){
	for(int i = 0; i< arr->length-1; i++){
		arr->A[i] = arr->A[i+1];
	}
	arr->A[arr->length-1] = 0;
}

void left_rotate(struct Array *arr){
	int temp = arr->A[0];
	for(int i = 0; i< arr->length-1; i++){
		arr->A[i] = arr->A[i+1];
	}
	arr->A[arr->length-1] = temp;
}


void insert_sorted(struct Array *arr, int key){
	arr->length++;
	for(int i = 0; i< arr->length; i++){
		
		if(key < arr->A[i]){
			
			for(int j = arr->length; j > i; j--){
				arr->A[j] = arr->A[j-1];
			}
			arr->A[i] = key;
			break;
		}
	}
}

void insert_sorted_while(struct Array *arr, int key){ // good one
	
	
	int i = arr->length-1;
	if(arr->size == arr->length){
		return;
	}
	while(i>=0 && key < arr->A[i]){
		arr->A[i+1] = arr->A[i];
		i--;	
	}
	arr->A[i+1] = key;
	arr->length++;
	
}

bool check_if_list_sorted(struct Array *arr){
	int i = 0;
	
	while(i < arr->length-1){
		if(arr->A[i] > arr->A[i+1]){
			return 0;
		}
		i++;
	} 
	return 1;
	
}

void negative_left_positive_right(struct Array *arr) { // good one
	
	int i = 0;
	int j = arr->length-1;
	
	while(i <= j){
		while(arr->A[i] < 0){
			i++;
		}
	
		while(arr->A[j] >= 0){
			j--;
		}
		if(i < j) {
			swap(&arr->A[i], &arr->A[j]);
		}
	}
	
	
}

int* merge_sorted_arr(struct Array *arr_A, struct Array *arr_B){ // my implementation
	
	int *c;
	c = (int *)malloc((arr_A->length + arr_B->length) * sizeof(int));
	
	int i = 0; int j = 0; int k = 0;
	
	while(i < arr_A->length && j < arr_B->length) {
		
		if(arr_A->A[i] < arr_B->A[j]){
			
			c[k] = arr_A->A[i];
			i++;
			k++;
		}
		
		else if (arr_A->A[i] > arr_B->A[j]){
			
			c[k] = arr_B->A[j];
			j++;
			k++;
		}
	}
		
	while(i < arr_A->length){
			
		c[k] = arr_A->A[i];
		i++;
		k++;
	}
	
	while(j < arr_B->length){
			
		c[k] = arr_B->A[j];
		j++;
		k++;
	}	
	return c;
		
	}
	
struct Array* merge(struct Array *arr1, struct Array *arr2){
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	
	while(i < arr1->length && j < arr2->length){
		
		if(arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++]; 
		else
			arr3->A[k++] = arr2->A[j++];
	}
	
	for(;i < arr1->length;i++)
		arr3->A[k++] = arr1->A[i];
		
	for(;j < arr2->length;j++)
		arr3->A[k++] = arr2->A[j];
	
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	
	return arr3;
		
}

struct Array* union_sorted(struct Array *arr1, struct Array *arr2){
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	
	while(i < arr1->length && j < arr2->length){
		
		if(arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++]; 
		else if(arr1->A[i] == arr2->A[j]){
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
		else
			arr3->A[k++] = arr2->A[j++];
	}
	
	for(;i < arr1->length;i++)
		arr3->A[k++] = arr1->A[i];
		
	for(;j < arr2->length;j++)
		arr3->A[k++] = arr2->A[j];
	
	arr3->length = k ;
	arr3->size = 10;
	
	return arr3;
		
}


struct Array* intersection_sorted(struct Array *arr1, struct Array *arr2){
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	
	while(i < arr1->length && j < arr2->length){
		
		if(arr1->A[i] < arr2->A[j]) 
			i++;
		else if(arr1->A[i] == arr2->A[j]){
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
		else
			j++;
	}
	
	arr3->length = k ;
	arr3->size = 10;
	
	return arr3;
		
}


struct Array* difference_sorted(struct Array *arr1, struct Array *arr2){
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	
	while(i < arr1->length && j < arr2->length){
		
		if(arr1->A[i] < arr2->A[j]) 
			arr3->A[k++] = arr1->A[i++];
			
		else if(arr1->A[i] == arr2->A[j]){
			i++;
			j++;
		}
		else
			j++;
	}
	
	for(;i < arr1->length;i++)
		arr3->A[k++] = arr1->A[i];
	
	arr3->length = k;
	arr3->size = 10;
	
	return arr3;
		
}	
	
void print_missing_elem(struct Array* arr){
	
	int diff = arr->A[0] - 0;
	
	for(int i = 0; i < arr->length; i++){
		
		if(arr->A[i]- i != diff){
			int k = i;
			for(int j = arr->A[i]-i-1; j >= diff; j--){
				printf("%d \n", k + diff);
				k++;
			}
			diff = arr->A[i] - i;
		}
	}
}

void find_duplicate_sorted_arr(struct Array* arr){
	
	int last_dup = 0;
	
	for(int i = 0; i < arr->length; i++){
		int j = i;
		if(arr->A[j] == arr->A[j+1]){
			if(last_dup != arr->A[j])
				printf("%d", arr->A[j]);
				
			last_dup = arr->A[j];
			
		}
	}
}
	
void count_duplicate_sorted_arr(struct Array* arr){ // could not solve this. IMP review
	
	int j;
	
	for(int i = 0; i < arr->length; i++){
		if(arr->A[i] == arr->A[i+1]){
			j = i+1;
			while(arr->A[j] == arr->A[i]) j++;
			printf("%d is appearing %d times \n",arr->A[i], j-i);
			i = j - 1;	
		}	
	}	
}


void count_duplicates(struct Array* arr){ // wrote by myself next day, with pure logic
	int j;
	for(int i = 0; i < arr->length; i++){
		
		j = i+1;
		if(arr->A[i] == arr->A[i+1]){
			while(arr->A[i] == arr->A[j]) j++;
			printf("%d is seen %d times", arr->A[i], j-i);
			i = j-1;
		}
	}
	
}

void count_duplicates_unsorted(struct Array* arr){ // my impl
	int count = 1;
	
	for(int i = 0; i < arr->length-1; i++){
		if(arr->A[i] != -1){
			for(int j = i+1;j < arr->length; j++){
				if(arr->A[j] != -1 && arr->A[i] == arr->A[j]){
					count++;
					arr->A[j] = -1;
				}
					
			}
		}	
		if(count > 1) printf("Count of %d is %d \n", arr->A[i], count);
		count = 1;
	}
	
}

void pair_with_sum_k_sorted_array(struct Array* arr, int k){ // my impl
	int i = 0;
	int j = arr->length-1;
	while(i < j){
		if(arr->A[i] + arr->A[j] == k) {
			printf("(%d, %d) \n", arr->A[i], arr->A[j]);
			j--;
			i++;
		}
		else if(arr->A[i] + arr->A[j] > k) j--;
		else i++;
	}
	
}

void min_max_in_one_scan(struct Array* arr){
	int min, max;
	min = max = arr->A[0];
	
	for(int i = 1; i < arr->length; i++){
		if(arr->A[i] >= max) max = arr->A[i];
		else min = arr->A[i];
	}
	
	printf("(max, min) = (%d, %d)", max, min);
}

int main(int argc, char** argv) {
	
	// Array LL
	
	struct Array arr = {{-1,3,4,5,6,8,9,10,12,14},15,10}; 
	min_max_in_one_scan(&arr);
	//pair_with_sum_k_sorted_array(&arr, 11);
	//count_duplicates_unsorted(&arr);
	//count_duplicates(&arr);
	//find_duplicate_sorted_arr(&arr);
	//print_missing_elem(&arr);
	
	/*
	int ch, x, index;
	
	struct array arr1;
	printf("ENter sixe of array");
	scanf("%d", &arr1.size);
	arr1.A = (int *)malloc(srr1.size * sizeof(int));
	arr1.length = 0;
	
	do
	 {
	 printf("\n\nMenu\n");
	 printf("1. Insert\n");
	 printf("2. Delete\n");
	 printf("3. Search\n");
	 printf("4. Sum\n");
	 printf("5. Display\n");
	 printf("6.Exit\n");
	
	 printf("enter you choice ");
	 scanf("%d",&ch);
	
	switch(ch)
 	{
		 case 1: printf("Enter an element and index
		");
		 scanf("%d%d",&x,&index);
		 Insert(&arr1,index,x);
		 break;
		 case 2: printf("Enter index ");
		 scanf("%d",&index);
		 x=Delete(&arr1,index);
		 printf("Deleted Element is %d\n",x);
		 break;
		 case 3:printf("Enter element to search ");
		 scanf("%d",&x);
		 index=LinearSearch(&arr1,x);
		 printf("Element index %d",index);
		 break;
		 case 4:printf("Sum is %d\n",Sum(arr1));
		 break;
		 case 5:Display(arr1);
	
	 }
	 }while(ch<6);


	
	
	
	struct Array arr = {{2,6,10,15,25}, 10, 5};
	struct Array arr_2 = {{2,6,10,14,25}, 10, 5};
	
	Append(&arr, 10);
	Insert(&arr, 11, 4);
	printf("Element with value %d deleted \n", Delete(&arr, 3));
	
	printf("Element found/unfound %d \n", linearSearch(&arr, 4));
	
	printf("Element found/unfound %d \n", Recursion_BinarySearch(arr.A, 0, arr.length, 25));
	
	printf("%d \n", Get(&arr,5));
	Set(&arr, 5, 100);
	printf("%d \n", Max(arr));
	printf("%d \n", Min(arr));
	printf("Sum = %d \n", Recur_Sum(&arr, arr.length-1));
	printf("Sum = %d \n", Sum(&arr));
	printf("Avg = %f \n", Avg(&arr));
	
	Reverse_2(&arr);
	
	left_shift(&arr);
	
	left_rotate(&arr);
	
	insert_sorted(&arr, 0);
	
	insert_sorted_while(&arr, 10);
	
	printf("%d \n", check_if_list_sorted(&arr));
	
	negative_left_positive_right(&arr);
	
	
	///**** my impl - merge
	int *p = merge_sorted_arr(&arr, &arr_2);
	for(int i = 0; i < arr.length + arr_2.length; i++){
		printf("%d ", p[i]);
	}
	///***
	
	//other impl
	struct Array *arr3;
	
	arr3 = merge(&arr, &arr_2);
	
	struct Array *arr3;
	//arr3 = union_sorted(&arr, &arr_2);
	//arr3 = intersection_sorted(&arr, &arr_2);

	arr3 = difference_sorted(&arr, &arr_2);
	*/
	//menu driven prog
	
	
	
	//Display(*arr3);
	
	
	
	/*
	struct Array arr;
	int n;
	printf("Enter size of array");
	scanf("%d", &arr.size);
	arr.A = (int *) malloc(arr.size * sizeof(int));
	arr.length = 0;
	
	printf("Enter how many numbers");
	scanf("%d", &n);
	
	printf("Enter all elements \n");
	for(int i=0; i< n; i++) {
		scanf("%d", &arr.A[i]);
	}
	
	arr.length = n;
	
	Display(arr);
	
	free(arr.A)
	
	*/
	/*
	unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; 
	printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
	*/
	/*
	
	//2D array 
	// completely in stack
	
	int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3,5,7}}; // stack
	
	// Partially in stack and heap
	
	int *B[3]; // stack
	B[0] = (int *)malloc(4 * sizeof(int));
	B[1] = (int *)malloc(4 * sizeof(int));
	B[2] = (int *)malloc(4 * sizeof(int)); // heap
	
	// completely in heap
	
	int **C;
	
	C = (int **)malloc(3 * sizeof(int *));
	C[0] = (int *)malloc(4 * sizeof(int));
	C[1] = (int *)malloc(4 * sizeof(int));
	C[2] = (int *)malloc(4 * sizeof(int));
	
	
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
	
	free(C); free(B[0]);*/
	//Transferring elements from one heap array to another
	/*
	
	int *p, *q;
	p = (int *)malloc(5 * sizeof(int));
	p[0] = 3;
	p[1] = 6;
	p[2] = 9;
	p[3] = 12;
	p[4] = 15;
	
	q = (int *)malloc(10 * sizeof(int));
	
	for(int i = 0; i < 5; i++){
		q[i] = p[i];
	}
	free(p);
	p = q;
	q = NULL;
	
	for(int i = 0; i < 5; i++){
		printf("%d ", p[i]);
	}
	*/
	/*
	int A[10] = {2,4,6,8,10};
	int *p;
	p = (int *)malloc(5 * sizeof(int));
	p[0] = 3;
	p[1] = 6;
	p[2] = 9;
	p[3] = 12;
	p[4] = 15;
	
	for(int i = 0; i < 5; i++){
		printf("%d ", A[i]);
	}
	
	for(int i = 0; i < 5; i++){
		printf("%d ", p[i]);
	}
	
	free(p);
	*/
	/*
	int A[5];
	
	for(int i = 0; i < 5; i++) {
		printf("%u \n", &A[i]); // %u is for address
	}
	*/
	
	/*
	int a = 5;
	
	int x,y,z,w;
	
	x = a++;
	printf("%d %d \n", x, a);
	y= ++a;
	printf("%d %d \n", y, a);
	
	for(int i = 0; i < 5; i++){
		printf("%d post\n", ++i);
	}
	
	for(int j = 0; j < 5; ++j){
		printf("%d pre\n", j++);
	}
	*/
	//int p = 5;
	//printf("%d", fun(4));
	
	/*
	int a = 2048, sum = 0;

	foo (a, sum);

	printf("%d \n", sum);
	*/
	
	//TowerOfHanoi(3, 1, 2, 3);
	//printf("%d",f(1));
	
	//printf("%d", combination(4,2));
	//printf("%d", combination_recursion(4,2));
	
	/*
	for(int i = 0; i < 10; i++){
		F[i] = -1;
	}
	*/
	//printf("%d", fibonacci(5));
	//printf("%d", fibonacci_recursion(5));
	//printf("%d", fibonacci_recursion_memoization(5));
	
	/*
	printf("%d", sum_of_N_natural_nubers_recur(10));
	printf("%d", fact_of_N_natural_nubers_recur(5));
	printf("%d", power_recur(2, 6));
	printf("%d", power_recur_fast(2, 8));
	
	printf("%lf \n", Taylor_Series_recur(3, 10));
	printf("%lf \n", Taylor_Series_hornerrule_recur(3, 10));
	printf("%lf \n", Taylor_Series_loop(3, 10));
	*/
	/*
	int r;
	r = fun_nested_recur(95);
	printf("%d\n", r);
	*/
	//funA_indir_recur(20);
	//fun1_tree_recirsion(4);
	/*
	int r;
	r = fun1(5);
	printf("%d", r);
	*/
	
	/*
	int x = 3;
	fun(x);
	*/
	
	/*
	int sum = 0;
	int A[] = {1,2,3,4,5};
	
	for(auto x:A){
		sum = sum + x;
	}
	cout <<sum;
	*/
	return 0;
}
