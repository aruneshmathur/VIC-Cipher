#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "operations.h"

int main() {

	int i;
	int date[5] = {7, 4, 1, 7, 7};
	int random_ig[5] = {7, 7, 6, 5, 1};
	int* temp;

	int* sub_result = modular_subtraction_digit(random_ig, date, 5);
	char* key_phrase = "IDREAMOFJEANNIEWITHT";

	int* first = assign_char(key_phrase, 0, 10, 65); 
	int* second = assign_char(key_phrase, 10, 10, 65); 

	int* chain_res = chain_addition(sub_result, 5);

	int* append_res = join(sub_result, 5, chain_res, 5);
	
	free(sub_result);
	free(chain_res);
	
	int* first_app_res = modular_addition_digit(first, append_res, 10);
	
	int* assign_res = map_change(second, first_app_res, 10);
	
	int** pseudo_random = malloc(sizeof(int*) * 5);

	temp = assign_res;
	for(i=0;i<5;i++) {
		temp=chain_addition(temp,10);
		pseudo_random[i]=temp;
	}

	int** trans_res = transpose(assign_res, pseudo_random, 10, 5);

	int* header_checker = assign_int(pseudo_random[4], 0, 10);
	for(i = 0; i < 10; i++) {
		printf("%d ", header_checker[i]);
	}
	/*int a[10] = {0, 2, 2, 1, 2, 1, 5, 8, 3, 1};
	int **b, *c, *d; int i, first, second;
	char *e;
	b= malloc(sizeof(int*) *5);
	c=a;
	
	for(i=0;i<5;i++) {
		c=chain_addition(c,10);
		b[i]=c;
	
	}
		
 	transpose(a, b, 10, 5);

	first = b[4][8];
	second = b[4][9];

	printf("%d %d\n", first, second);

	e = "WE ARE PLEASED TO HEAR OF YOUR SUCCESS IN ESTABLISHING YOUR FALSE IDENTITY YOU WILL BE SENT SOME MONEY TO COVER EXPENSES WITHIN A MONTH";

	d = encode(e, a, 135);

	i=0;

	while(d[i] != -1) {
		printf("%d ", d[i]);
		i++;
	}

	

	printf("\n");*/
	
	return 0;
}
