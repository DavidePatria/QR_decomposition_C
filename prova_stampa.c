#include <stdio.h>

static inline int prova_stampa( double *A, int j) {
	int i;
	for (i=0;i<3;i++){
		printf("%f ", A[3*i + j-1]);
	}
}

void main() {
	double A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int i;

	for (i=0;i<3;i++){
		printf("%f ", A[i][0]);
	}

	// stampa una colonna
	prova_stampa(A,1);
}
