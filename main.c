#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "operations.h"
#include "args.h"

int main() {

	int i, j, count = 0, encode_result_length, first_num, second_num, elecount, rows;

	int *date = DEFAULT_DATE;
	int *random_ig = DEFAULT_RANDOM;

	/*Initialize the pointers that we'll need later */
	int *temp, *first_app_res, *assign_res, *header_checker;
	int *encode_result, *transpose_select, *new_header;
	int **pseudo_random, **transpose_res, **second_num_trans, **final_res, **inter_trans, **message_matrix;

	int* sub_result = modular_subtraction_digit(random_ig, date, 5);
	char* key_phrase = "IDREAMOFJEANNIEWITHT";
	char* message = DEFAULT_MESSAGE;

	int* first = assign_char(key_phrase, 0, 10, 65); 
	int* second = assign_char(key_phrase, 10, 10, 65); 

	int* chain_res = chain_addition(sub_result, 5);

	int* append_res = join(sub_result, 5, chain_res, 5);
	
	free(sub_result);
	free(chain_res);
	
	first_app_res = modular_addition_digit(first, append_res, 10);
	
	assign_res = map_change(second, first_app_res, 10);
	free(first_app_res);
	
	pseudo_random = malloc(sizeof(int*) * 5);

	temp = assign_res;
	for(i = 0; i < 5; i++) {
		temp=chain_addition(temp,10);
		pseudo_random[i]=temp;
	}
	
	header_checker = assign_int(pseudo_random[4], 0, 10);

	encode_result = encode(message, header_checker, strlen(message));

	encode_result_length = get_encode_message_length(encode_result);

	first_num = 8 + pseudo_random[4][8];
	second_num = 8 + pseudo_random[4][9];

	transpose_res = transpose(assign_res, pseudo_random, 10, 5);
	free(temp);
	
	transpose_select = malloc(sizeof(int) * first_num + second_num);

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 5; j++) {
			transpose_select[count++] = transpose_res[i][j];
			if (count == 31) break;
		}
			if (count == 31) break;
	}

	message_matrix = get_matrix(encode_result, encode_result_length, first_num);
	free(encode_result);

	elecount = (encode_result_length + 5 - (encode_result_length % 5));
	rows = elecount / first_num;
	if(encode_result_length % first_num !=  0) rows =rows + 1;

	inter_trans = transpose(transpose_select, message_matrix, first_num, rows);

	new_header = copy(transpose_select, first_num, first_num + second_num);

	second_num_trans = get_matrix_filled(inter_trans, first_num, rows, elecount, new_header, second_num);

	rows = elecount / second_num;
	if(encode_result_length % second_num !=  0) rows =rows + 1;
	final_res = transpose(new_header, second_num_trans, second_num, rows);
	free(new_header);
	
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
