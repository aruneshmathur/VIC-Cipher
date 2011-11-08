#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <unistd.h>   
#include "operations.h"
#include "args.h"

int main(int argc, char **argv) {

	int i, j, count = 0, encode_result_length, first_num, second_num, elecount, rows, personal_number = DEFAULT_PERSONAL_NUMBER, c;
	int date_len;
	char t;

	int *date = DEFAULT_DATE;
	int *random_ig = DEFAULT_RANDOM;

	/*Initialize the pointers that we'll need later */
	int *temp, *first_app_res, *assign_res, *header_checker, *first, *second;
	int *encode_result, *transpose_select, *new_header, *chain_res, *append_res, *sub_result;
	int **pseudo_random, **transpose_res, **second_num_trans, **final_res, **inter_trans, **message_matrix;

	char *key_phrase = DEFAULT_KEYPHRASE;
	char *message = DEFAULT_MESSAGE;


	while ((c = getopt_long(argc, argv, "d:p:k:m:", longopts, NULL)) != -1)
        	switch (c) {
			case 'd':
				date_len = strlen(optarg);
				date = malloc(sizeof(int) * date_len);
				i = 0;
				while(i < strlen(optarg)) {
					t = optarg[i];
					if(t == 0) {
						fprintf (stderr, "--date must be in the form DDMMYYYY.\n");
						return -1;
					}
					date[i++] = atoi(&t);
				}

			break;

		        case 'p':
				personal_number = atoi(optarg);

				if(personal_number > 16) {
					fprintf (stderr, "--personal must be < 16 strictly.\n");
					return -1;
				}
		        break;
	
			case 'k':
				key_phrase = optarg;
				if(strlen(key_phrase) != 20) fprintf (stderr, "--personal must be < 16 strictly.\n");
			break;

			case 'm':
				message = optarg;
			break;

	                case '?':
             			if (optopt == 'k' || optopt == 'm' || optopt == 'd' || optopt == 'p')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			        else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
             			else
			                fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                                return -1;
			default:
				abort();
				return -1;
        }



	sub_result = modular_subtraction_digit(random_ig, date, 5);

	first = assign_char(key_phrase, 0, 10, 65); 
	second = assign_char(key_phrase, 10, 10, 65); 

	chain_res = chain_addition(sub_result, 5);

	append_res = join(sub_result, 5, chain_res, 5);
	
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

	first_num = personal_number + pseudo_random[4][8];
	second_num = personal_number + pseudo_random[4][9];
	
	transpose_res = transpose(assign_res, pseudo_random, 10, 5);
	free(temp);
	
	transpose_select = malloc(sizeof(int) * (first_num + second_num));

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 5; j++) {
			transpose_select[count++] = transpose_res[i][j];
			if (count == (first_num + second_num)) break;
		}
			if (count == (first_num + second_num)) break;
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

	date[5] = (date[5] == 0) ? 10: date[5];
	
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
