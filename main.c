#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cumulate(int *a, int size) {
	int i;
	for(i = 1; i < size; i++) {
		a[i] = a[i] + a[i-1];
	}
}

int* assign(char *arr, int size, char type) {

 	int hash[26], base, i;
	memset(hash, 0, sizeof(hash));

	int* new_arr = malloc(sizeof(arr));

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
	
	cumulate(hash, 26);

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
	int* res = assign(array, 10, 'A'), i;
	for(i=0;i<10;i++) printf("%d ", res[i]);

	return 0;
}
