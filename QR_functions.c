/* Creates a matrix and returns a pointer to the struct */
matrix* create_matrix(int rows, int cols) {
	
	/* Allocate memory for the matrix struct */
	matrix *array = malloc(sizeof(matrix));
	
	array->rows = rows;
	array->cols = cols;
	
	/* Allocate enough memory for all the rows in the first matrix */
	array->array = calloc(rows, sizeof(TYPE*));
	
	/* Enough memory for all the columns */
	for (int i=0; i<rows; i++) {
		array->array[i] = calloc(cols,sizeof(TYPE));
	}
	
	return array;
}


/* Creates a matrix from a stack based array and returns a pointer to the struct */
matrix* create_matrix_from_array(int rows, int cols, TYPE m[][cols]) {

	/* Allocate memory for the matrix struct */
	matrix *array = malloc(sizeof(matrix));
	array->rows = rows;
	array->cols = cols;
	
	/* Allocate memory for the matrix */
	array->array = malloc(sizeof(TYPE*) * rows);
	
	/* Allocate memory for each array inside the matrix */
	for (int i=0; i<rows; i++) {
		array->array[i] = malloc(sizeof(TYPE) * cols);
	}
	
	/* Populate the matrix with m's values */
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			array->array[row][col] = m[row][col];
		}
	}
  return array;
}


/* Copies a matrix column from msrc at column col1 to mdst at column col2 */
void matrix_copy_column(matrix *msrc, int col1, matrix *mdst,int col2) {
	for (int i=0; i<msrc->rows; i++) {
		mdst->array[i][col2] = msrc->array[i][col1];
	}
}


/* Subtracts m2's column c2 from m1's column c1 */
matrix* matrix_column_subtract(matrix *m1, int c1, matrix *m2, int c2) {
	for (int i=0; i<m1->rows; i++) {
			m1->array[i][c1] -= m2->array[i][c2];
	}
	return m1;
}


/* Returns the length of the vector column in m */
double vector_length(matrix *m,int column) {
	double length = 0;
	for (int row=0; row<m->rows; row++) {
		length += m->array[row][column] * m->array[row][column];
	}
	return sqrt(length);
}


/* Divides the matrix column c in m by k */
matrix* matrix_column_divide(matrix *m, int c, TYPE k) {
	for (int i=0; i<m->rows; i++) {
		m->array[i][c] /= k;
	}
	return m;
}


/* Multiplies the matrix column c in m by k */
matrix* matrix_column_multiply(matrix *m, int c, TYPE k) {
	for (int i=0; i<m->rows; i++) {
		m->array[i][c] *= k;
	}
	return m;
}


/* Debugging purposes only */
void print_matrix(matrix *m) {
	for (int row = 0; row < m->rows; row++) {
		printf("[");
		for (int col = 0; col < m->cols - 1; col++) {
			printf(FLAG", ", m->array[row][col]);
		}
		printf(FLAG, m->array[row][m->cols-1]);
		printf("]\n");
	}
	printf("\n");
}
