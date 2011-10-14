#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cumulative_sum(int *a, int size) {
	int i;
	for(i = 1; i < size; i++) {
		a[i] = a[i] + a[i-1];
	}
}

int** transpose(int* header, int **array, int header_columns, int array_rows) {
	int hash[10], i, j;
	int** m;

	memset(hash, 0, sizeof(hash));

	for(i = 0; i < header_columns; i++) {
		hash[header[i]]++;
	}

	cumulative_sum(hash, 10);

	m = malloc(sizeof(int) * header_columns * array_rows);
	

	
	return NULL;
}

int* map_change(int* code, int *input, int size) {

	int* result = malloc(sizeof(int) * size), i;
	
	for(i = 0; i < size; i++) {
		result[i] = code[input[i]];
	}

	return result;
}

int* modular_addition_digit(int *a, int *b, int size) {

	int* new_arr = malloc(sizeof(int) * size), i;
	for(i = 0; i < size; i++) {
		new_arr[i] = (a[i] + b[i]) % 10;
	}
		
	return new_arr;
}

int* assign(char* arr, int size, int b) {

 	int hash[26], base, i, diff;
	memset(hash, 0, sizeof(hash));

	int* new_arr = malloc(sizeof(arr));

	base = b;
	diff = (b == 65) ? 0 : 1;

	for(i = 0; i < size; i++) {
		hash[arr[i]-base]++;
	}
	
	cumulative_sum(hash, 26);

	for(i = size - 1; i >= 0; i--) {
		new_arr[i] = (hash[arr[i]-base] - diff) % 10;
		hash[arr[i]-base]--;
	}

	return new_arr;
}
		

int* chain_addition(int *arr, int size) {
	int *new_arr = malloc(size * sizeof(int)), i;

	for(i = 0; i < size - 1; i++) {
		new_arr[i] = (arr[i] + arr[i+1]) % 10;
	}

	new_arr[i] = (arr[size - 1] + new_arr[0]) % 10;

	return new_arr;
}

int main() {

	/*char array[10] = {  '1', '2', '0', '4', '3', '3', '9', '6', '6', '9' }; 
	int* res = assign(array, 10, 48), i;
	for(i=0;i<10;i++) printf("%d ", res[i]);*/

	int a[14] = {3,6,5,3,4,6,9,3,2,3,3,9,2,8};
	transpose(a, NULL, 14);

	return 0;
}
