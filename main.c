#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <unistd.h>   
#include "operations.h"
#include "args.h"

int main(int argc, char **argv) {

	int i, j, count = 0, encode_result_length, first_num, second_num, elecount, rows, personal_number = DEFAULT_PERSONAL_NUMBER, c;
	int date_len, verbose = 0;
	char t;

	int *date = DEFAULT_DATE;
	date_len = 6;
	int *random_ig = DEFAULT_RANDOM;


	/*Initialize the pointers that we'll need later */
	int *temp, *first_app_res, *assign_res, *header_checker, *first, *second;
	int *encode_result, *transpose_select, *new_header, *chain_res, *append_res, *sub_result;
	int **pseudo_random, **transpose_res, **second_num_trans, **final_res, **inter_trans, **message_matrix;

	char *key_phrase = DEFAULT_KEYPHRASE;
	char *message = DEFAULT_MESSAGE;


	while ((c = getopt_long(argc, argv, "d:p:k:m:v", longopts, NULL)) != -1)
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
				if(strlen(key_phrase) < 20) fprintf (stderr, "--personal must be < 16 strictly.\n");
			break;

			case 'm':
				message = optarg;
			break;

			case 'v':
				verbose = 1;
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

	if(verbose == 1) {

		printf("\n1. Subtraction result:\n");

		for(i = 0; i < 5; i++) 
			printf("%d ", sub_result[i]);

		printf("\n \n");

	}

	first = assign_char(key_phrase, 0, 10, 65); 
	second = assign_char(key_phrase, 10, 10, 65); 


	if(verbose == 1) {

		printf("2. First character assigned result:\n");

		for(i = 0; i < 10; i++) 
			printf("%d ", first[i]);

		printf("\n\n");


		printf("3. Second character assigned result:\n");

		for(i = 0; i < 10; i++) 
			printf("%d ", second[i]);

		printf("\n\n");

	}

	chain_res = chain_addition(sub_result, 5);

	if(verbose == 1) {

		printf("4. Chain addition result for the subtraction performed earlier:\n");

		for(i = 0; i < 5; i++) 
			printf("%d ", chain_res[i]);

		printf("\n\n");

	}

	append_res = join(sub_result, 5, chain_res, 5);

	if(verbose == 1) {

		printf("5. Joining both 1 and 4, we get:\n");

		for(i = 0; i < 10; i++) 
			printf("%d ", append_res[i]);

		printf("\n\n");

	}
	
	free(sub_result);
	free(chain_res);
	
	first_app_res = modular_addition_digit(first, append_res, 10);

	if(verbose == 1) {

		printf("6. Adding 2 and 5 modularly, we get:\n");

		for(i = 0; i < 10; i++) 
			printf("%d ", first_app_res[i]);

		printf("\n\n");

	}	

	assign_res = map_change(second, first_app_res, 10);

	if(verbose == 1) {

		printf("7. Mapping 6 according to 3, we get:\n");

		for(i = 0; i < 10; i++) 
			printf("%d ", assign_res[i]);

		printf("\n\n");

	}	


	free(first_app_res);
	
	pseudo_random = malloc(sizeof(int*) * 5);

	temp = assign_res;
	for(i = 0; i < 5; i++) {
		temp=chain_addition(temp,10);
		pseudo_random[i]=temp;
	}

	if(verbose == 1) {

		printf("8. Performing chain addition on 7, we get:\n");

		for(i = 0; i < 5; i++) {
			for(j = 0; j <10; j++) {
				printf("%d ", pseudo_random[i][j]);
			}
			printf("\n");
		}

		printf("\n");
	}
	

	header_checker = assign_int(pseudo_random[4], 0, 10);

	if(verbose == 1) {

		printf("8. The header for our checkerboard that we use is:\n");

		for(i = 0; i < 10; i++) {
			printf("%d ", header_checker[i]);
		}

		printf("\n\n");
	}

	encode_result = encode(message, header_checker, strlen(message));

	encode_result_length = get_encode_message_length(encode_result);

	if(verbose == 1) {

		printf("8. The encoded message is:\n");

		for(i = 0; i < encode_result_length; i++) {
			printf("%d ", encode_result[i]);
		}

		printf("\n\n");

		printf("9. The message's length is: %d\n", encode_result_length);

		printf("\n\n");

	}

	first_num = personal_number + pseudo_random[4][8];
	second_num = personal_number + pseudo_random[4][9];

	if(verbose == 1) {

		printf("10. The first and second number are: %d %d\n", first_num, second_num);

		printf("\n\n");

	}
	
	transpose_res = transpose(assign_res, pseudo_random, 10, 5);

	if(verbose == 1) {

		printf("11. The transpose of 8 wrt 7 is:\n");

		for(i = 0; i < 10; i++) {
			for(j = 0; j < 5; j++) 
				printf("%d ", transpose_res[i][j]);
			printf("\n");
		}

		printf("\n\n");

	}
	
	free(temp);
	
	transpose_select = malloc(sizeof(int) * (first_num + second_num));

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 5; j++) {
			transpose_select[count++] = transpose_res[i][j];
			if (count == (first_num + second_num)) break;
		}
			if (count == (first_num + second_num)) break;
	}


	if(verbose == 1) {

		printf("12. The %d elements of 11 are:\n", first_num + second_num);

		for(i = 0; i < first_num + second_num; i++) {
			printf("%d ", transpose_select[i]);
		}

		printf("\n\n");

	}
	
	message_matrix = get_matrix(encode_result, encode_result_length, first_num);
	free(encode_result);

	elecount = encode_result_length + ((5 - (encode_result_length % 5)) % 5);
	rows = elecount / first_num;
	if(encode_result_length % first_num !=  0) rows =rows + 1;


	if(verbose == 1) {

		printf("13. Our message in 8 as a matrix is:\n");

		for(i = 0; i < rows; i++) {
			for(j = 0; j < first_num; j++) 
				printf("%d ", message_matrix[i][j]);
			printf("\n");
		}

		printf("\n\n");

	}
	

	
	inter_trans = transpose(transpose_select, message_matrix, first_num, rows);

	if(verbose == 1) {

		printf("14. Transpose of 13 using the first %d elements of 12 is:\n", first_num);

		for(i = 0; i < first_num; i++) {
			for(j = 0; j < rows; j++) 
				printf("%d ", inter_trans[i][j]);
			printf("\n");
		}

		printf("\n\n");

	}

	new_header = copy(transpose_select, first_num, first_num + second_num);

	if(verbose == 1) {

		printf("15. The last %d elements of 12 are:\n", second_num);

		for(i = first_num; i < first_num + second_num; i++) {
			printf("%d ", transpose_select[i]);
		}

		printf("\n\n");

	}

	second_num_trans = get_matrix_filled(inter_trans, first_num, rows, elecount, new_header, second_num);


	rows = elecount / second_num;
	if(encode_result_length % second_num !=  0) rows =rows + 1;

	if(verbose == 1) {

		printf("14. Filling in the matrix using the %d elements of 15 is:\n", second_num);

		for(i = 0; i < rows; i++) {
			for(j = 0; j < second_num; j++) 
				printf("%d ", second_num_trans[i][j]);
			printf("\n");
		}

		printf("\n\n");

	}


	final_res = transpose(new_header, second_num_trans, second_num, rows);
	free(new_header);
	
	elecount = 1;

	date[date_len - 1] = (date[date_len - 1] == 0) ? 10: date[date_len - 1];

	if(verbose == 1) {

		printf("16. The result is:\n");

	}
	
	for(i = 0; i < second_num; i++) {
		for(j = 0; j < rows; j++) {
			if(final_res[i][j] != -1) {
				printf("%d ", final_res[i][j]); 
				elecount++;	
				if(((elecount) % date[date_len - 1]) == 0) {
					elecount = 1; 
					printf("\n");
				}				
			}
		}
	}

	printf("\n");

	return 0;
}
