#define TYPE double
#define FLAG "%7.3f"

typedef struct {
	TYPE **array;    /* Pointer to an array of type TYPE */
	int rows;       /* Number of rows */
	int cols;       /* Number of columns */
} matrix;

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



/* Decomposes the matrix A into QR */
void QRdecompose(matrix *A, matrix *Q, matrix *R) {

	/* Using the Gram-Schmidt process */
	
	/* Temporary vector T and S used in calculations */
	matrix *T = create_matrix(A->rows, 1);
	matrix *S = create_matrix(A->rows, 1);
	
	for (int i = 0; i < A->cols; i++) {
	
		//Qi = Ui
		matrix_copy_column(A,i,Q,i);
		
		for (int j = 0; j < i; j++) {
		
			//r[j,i] = Qj^T * Ui
			matrix_copy_column(Q,j,T,0);
			matrix_copy_column(A,i,S,0);
			TYPE r = 0;
			for (int k=0; k<A->rows; k++) {
			  r += T->array[k][0] * S->array[k][0];
			}
			
			R->array[j][i] = r;
			// subtract works subtracting the the second argument to the first
			// mutiply in this case is the 0-th column of T multiplied by r
			matrix_column_subtract(Q,i,matrix_column_multiply(T,0,r),0);
		
		}
		
		//r[i,i] = ||Qi||
		R->array[i][i] = vector_length(Q,i);
		//Qi = Qi/r[i,i]
		// divide the i-th element od Q by the third argument
		matrix_column_divide(Q,i,R->array[i][i]);
	
	
	}
	
	//free_matrix(T);
	//free_matrix(S);

}

