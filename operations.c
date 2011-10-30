#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "checkerboard.h"
#include "operations.h"

int* encode(char* message, int* header, int length) {
	int i, t, count;
	int *result = malloc(sizeof(int) * length * 2); 
	count = 0;
	init_checkerboard(header, 10);
	
	for(i = 0; i < length; i++) {
		if(message[i] == ' ') continue;
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

	result[count] = -1;

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
		result[i] = code[input[i] - 1];
	}

	return result;
}

int* modular_subtraction_digit(int *a, int *b, int size) {
	int* new_arr = malloc(sizeof(int) * size), i;
	for(i = 0; i < size; i++) {
		new_arr[i] = (a[i] - b[i] + 10) % 10;
	}
		
	return new_arr;

}

int* modular_addition_digit(int *a, int *b, int size) {

	int* new_arr = malloc(sizeof(int) * size), i;
	for(i = 0; i < size; i++) {
		new_arr[i] = (a[i] + b[i]) % 10;
	}
		
	return new_arr;
}

int* assign_char(char* arr, int start, int size, int b) {

 	int hash[26], base, i, diff;
	int* new_arr = malloc(sizeof(arr));

	memset(hash, 0, sizeof(hash));

	base = b;
	diff = (b == 65) ? 0 : 1;

	for(i = start; i < start + size; i++) {
		hash[arr[i]-base]++;
	}
	
	cumulative_sum(hash, 26);

	for(i = start + size - 1; i >= start; i--) {
		new_arr[i - start] = (hash[arr[i] - base] - diff) % 10;
		hash[arr[i]-base]--;
	}

	return new_arr;
}

int* assign_int(int* arr, int start, int size) {

 	int hash[26], i, diff;
	int* new_arr = malloc(sizeof(arr));

	memset(hash, 0, sizeof(hash));

	diff = 1;

	for(i = start; i < start + size; i++) {
		hash[arr[i]]++;
	}
	
	cumulative_sum(hash, 26);

	for(i = start + size - 1; i >= start; i--) {
		new_arr[i - start] = (hash[arr[i]] - diff) % 10;
		hash[arr[i]]--;
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

int* join(int* a, int sa, int *b, int sb) {
	int total = sa + sb, i;
	int* res = malloc(sizeof(int) * total);
	
	for(i = 0; i < sa; i++) {
		res[i] = a[i];
	}

	for(; i < sa + sb; i++) {
		res[i] = b[i - sa];
	}
	return res;
}

int** get_matrix(int* array, int size, int columns) {
	
	int temp = 5 - (size % 5), rows, i, j, left = size % columns, count = 0, lim, newsize;
	newsize = size + temp;
	rows = newsize / columns;

	if(left != 0) rows = rows + 1;
	int** result = malloc(sizeof(int*) * rows);

	for(i = 0; i < rows; i++) {
		result[i] = malloc(sizeof(int) * columns);
		memset(result[i], -1, columns * sizeof(int));
	}
	
	for(i = 0; i < rows; i++) {
		lim = (((i == rows - 1) && (left != 0))? left + newsize - size : columns);
		for(j = 0; j < lim; j++) {
			result[i][j] = (count >= size) ? 9 : array[count++];
		}
	}
	
	return result; 
}

int get_encode_message_length(int* array) {
	int length = 0;
	while(*array++ != -1) {
		length++;
	}

	return length;
}

int* copy(int* arr, int start, int end) {
	int* res = malloc(sizeof(int) * (end - start)), i;
	
	for(i = start; i < end; i++) {
		res[i - start] = arr[i];
	}

	return res;
}	

int find_location(int* arr, int* marked, int size, int ele) {
	int i;
	
	for(i = 0; i < size; i++) {
		if(arr[i] == ele && marked[i] != 1) {
			marked[i] = 1;
			return i;
		}
	}

	return -1;
}


int** get_matrix_filled(int** from, int rows, int cols, int ele_count, int* header, int size) {
	
	int left = ele_count % size, res_rows = 0, i, j, k, m, n, p;

	change(header, size, 0, 10);	

	res_rows = ele_count / size;
	
	if(left != 0) res_rows = res_rows + 1;

	int** res = malloc(sizeof(int*) * res_rows);
	int* marked = malloc(sizeof(int) * size);

	for(i = 0; i < res_rows; i++) {
		res[i] = malloc(sizeof(int) * size);
	}

	i = j = k = p = 0;
	m = 1; n = -1;
	for(i = 0; i < res_rows; i++) {
		if((n == -1) && (n = find_location(header, marked, size, m)) == -1) {
			i--; m++;
			continue;
		}
		for(j = 0; j < n; j++) {
			if(from[k][p] != -1) res[i][j] = from[k][p];
			else if(j != 0) j--;
			p++;
			if(p == cols) {
				k++; p = 0; 
			}
		}
		n++;
		if(n > size) {
			n = -1;
		}
	}
	
	change(header, size, 10, 0);	

	return res;
	
}
