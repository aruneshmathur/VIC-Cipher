int *header = NULL;
int **list;

int init(int *arr, int size) {

	if(size != 10) return 0;	
	header = arr;

	list = malloc(sizeof(int*) * 26);
	return 1;
}

int get_val(char c) {
	if(header == NULL) return -1;

	return 0;	
}


