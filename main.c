#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "checkerboard.h"

int* encode(char* message, int* header, int length) {
	int i, t, count;
	int *result = malloc(sizeof(int) * length * 2); 
	count = 0;
	init_checkerboard(header, 10);
	
	for(i = 0; i < length; i++) {
		t = get_val(message[i]);

		if(t < 0) {
			t+=10; 
			t=-t;
			result[count++] = 0;
			result[count++] = t;

		} else if(t >=0 && t <=9) {
			result[count++] = t;
		} else {
			result[count++] = 8;
			result[count++] = t % 10;
		}
	}
	result[count] = NULL;

	free_checkerboard();
	return result;
}

void change(int *arr, int size, int from, int to) {

	int i;
	for(i = 0; i < size; i++) {
		if(arr[i] == from) arr[i] = to;
	}
}

void cumulative_sum(int *a, int size) {
	int i;
	for(i = 1; i < size; i++) {
		a[i] = a[i] + a[i-1];
	}
}

int** transpose(int* header, int **array, int header_columns, int array_rows) {
	int hash[11], i, j;
	int **m;
	
	change(header, header_columns, 0, 10);

	memset(hash, 0, sizeof(hash));

	for(i = 0; i < header_columns; i++) {
		hash[header[i]]++;
	}

	cumulative_sum(hash, 11);
	
	m = malloc(sizeof(int*) * header_columns);
	for(i = 0; i < header_columns; i++)
		m[i] = malloc(sizeof(int) * array_rows);

	
	for(j = header_columns - 1; j >= 0; j--) {

		hash[header[j]]--;

		for(i = 0; i < array_rows; i++) {
			m[hash[header[j]]][i] = array[i][j];
		}
	}


	change(header, header_columns, 10, 0);

	return m;
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
	int* new_arr = malloc(sizeof(arr));

	memset(hash, 0, sizeof(hash));

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

	/*int a[10] = {0, 2, 2, 1, 2, 1, 5, 8, 3, 1};
	int **b, *c;
	b= malloc(sizeof(int*) *5);
	c=a;
	int i, j;
	
	for(i=0;i<5;i++) {
		c=chain_addition(c,10);
		b[i]=c;
	
	}
		
 	transpose(a, b, 10, 5);*/

	int a[10] = {1, 2, 0, 5, 3, 4, 8, 6, 7, 9}, i;
	char *b = "WE ARE PLEASED TO HEAR OF YOUR SUCCESS IN ESTABLISHING YOUR FALSE IDENTITY YOU WILL BE SENT SOME MONEY TO COVER EXPENSES WITHIN A MONTH";

	int* d = encode(b, a, 135);

	i=0;
	/*while(d[i]!=NULL) {
		printf("%d", d[i]);
	}*/

	printf("\n");
	
	return 0;
}
