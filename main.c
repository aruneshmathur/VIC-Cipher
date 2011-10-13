#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void cumulative_sum(int *a, int size) {
	int i;
	for(i = 1; i < size; i++) {
		a[i] = a[i] + a[i-1];
	}
}

int* assign(char *arr, int size, int b) {

 	int hash[26], base, i;
	memset(hash, 0, sizeof(hash));

	int* new_arr = malloc(sizeof(arr));

	base = b;

	for(i = 0; i < size; i++) {
		hash[arr[i]-base]++;
	}
	
	cumulative_sum(hash, 26);

	for(i = size - 1; i >= 0; i--) {
		new_arr[i] = (hash[arr[i]-base]--) % 10;
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

	char array[10] = { 'A', 'N', 'N', 'I', 'E', 'W', 'I', 'T', 'H', 'T'}; 
	int* res = assign(array, 10, 65), i;
	for(i=0;i<10;i++) printf("%d ", res[i]);

	return 0;
}
