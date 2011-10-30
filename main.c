#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "operations.h"

int main() {

	int i, j, count = 0;
	int date[6] = {7, 4, 1, 7, 7, 6};
	int random_ig[5] = {7, 7, 6, 5, 1};
	int* temp;

	int* sub_result = modular_subtraction_digit(random_ig, date, 5);
	char* key_phrase = "IDREAMOFJEANNIEWITHT";
	char* message = "WE ARE PLEASED TO HEAR OF YOUR SUCCESS IN ESTABLISHING YOUR FALSE IDENTITY YOU WILL BE SENT SOME MONEY TO COVER EXPENSES WITHIN A MONTH";

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

	int* encode_result = encode(message, header_checker, strlen(message));
	int encode_result_length = get_encode_message_length(encode_result);

	int first_num = 8 + pseudo_random[4][8];
	int second_num = 8 + pseudo_random[4][9];

	int** transpose_res = transpose(assign_res, pseudo_random, 10, 5);
	
	int* transpose_select = malloc(sizeof(int) * first_num + second_num);

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 5; j++) {
			transpose_select[count++] = transpose_res[i][j];
			if (count == 31) break;
		}
			if (count == 31) break;
	}

	int** message_matrix = get_matrix(encode_result, encode_result_length, first_num);

	int elecount = (encode_result_length + 5 - (encode_result_length % 5));
	int rows = elecount / first_num;
	if(encode_result_length % first_num !=  0) rows =rows + 1;

	int** inter_trans = transpose(transpose_select, message_matrix, first_num, rows);

	int* new_header = copy(transpose_select, first_num, first_num + second_num);

	int** second_num_trans = get_matrix_filled(inter_trans, first_num, rows, elecount, new_header, second_num);

	rows = elecount / second_num;
	if(encode_result_length % second_num !=  0) rows =rows + 1;
	int** final_res = transpose(new_header, second_num_trans, second_num, rows);
	
	elecount = 1;
	
	for(i = 0; i < second_num; i++) {
		for(j = 0; j < rows; j++) {
			if(final_res[i][j] != -1) {
				printf("%d ", final_res[i][j]); 
				elecount++;	
				if(((elecount) % date[5]) == 0) {
					elecount = 1; 
					printf("\n");
				}				
			}
		}
	}

	return 0;
}
