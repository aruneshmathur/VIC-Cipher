#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* assign(int *arr, int size, char type) {

 	int hash[26], base, i;
	memset(hash, 0, sizeof(hash));

	switch(type) {
		case 'a': base = 97; 
			break;	
		case 'A': base = 65;
			break;
		
		case 'n':
		case 'N':
			base = 48;
		default:
			return NULL;
	}

	for(i = 0; i < size; i++) {
		hash[arr[i]-base]++;
	}
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

	return 0;
}
