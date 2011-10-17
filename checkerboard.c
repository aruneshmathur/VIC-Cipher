#include "checkerboard.h"
#include<stdlib.h>

int *header = NULL;
int **list;

int init_checkerboard(int *arr, int size) {
	int i;

	if(size != 10) return 0;	
	header = arr;
	
	list = malloc(sizeof(int*) * 26);

	for(i = 0; i < 26; i++) {
		list[i] = malloc(sizeof(int));
	}

	*list['A' - 65] = arr[0]; 
	*list['T' - 65] = arr[1];
	*list['O' - 65] = arr[3];
	*list['N' - 65] = arr[4];
	*list['E' - 65] = arr[5];
	*list['S' - 65] = arr[7];
	*list['I' - 65] = arr[8];
	*list['R' - 65] = arr[9];

	*list['B' - 65] = -10 - arr[0];
	*list['C' - 65] = -10 - arr[1];
	*list['D' - 65] = -10 - arr[2];
	*list['F' - 65] = -10 - arr[3];
	*list['G' - 65] = -10 - arr[4];
	*list['H' - 65] = -10 - arr[5];
	*list['J' - 65] = -10 - arr[6];
	*list['K' - 65] = -10 - arr[7];
	*list['L' - 65] = -10 - arr[8];
	*list['M' - 65] = -10 - arr[9];

	*list['P' - 65] = 80 + arr[0];
	*list['Q' - 65] = 80 + arr[1];
	*list['U' - 65] = 80 + arr[2];
	*list['V' - 65] = 80 + arr[3];
	*list['W' - 65] = 80 + arr[4];
	*list['X' - 65] = 80 + arr[5];
	*list['Y' - 65] = 80 + arr[6];
	*list['Z' - 65] = 80 + arr[7];
	
	return 1;
}

int get_val(char c) {
	int b;
	if(header == NULL) return -1;
	b = (c - 65);

	return *list[b];	
}

void free_checkerboard() {
	int i;
	for(i = 0; i < 26; i++) {
		free(list[i]);
	}
	free(list);

	list = NULL;
}

