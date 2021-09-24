#include <stdio.h>
#include <math.h>

void QR_dec( double *A, double *Q, double *R, int rows, int cols) {
	// the functions decomposes the input matrix A in the matrices Q and R, one simmetric one orthonormal and one upper triangular, by using the Gram-Schmidt method.
	// the input matrice A is defined as A[3][3], so are the output matrices Q and R.
	// this function is meant to be used in the polar decomposition algorithm and has been tested with 3x3 input matrices.
	// for tests for the standalone function please refer to the original github repo this has been developed in. 
	// https://github.com/DavidePatria/QR_decomposition_C/blob/main/README.md
	
	// as already mentioned in the README the matrices orders are: A mxn => Q mxn , R nxn and rank(A) must be n

	//vectors for internal coputations
	double norm; 
	//double product1;
	double product[3];
	double product2;
	double tmp;

	int i,ii, j, jj, k, kk;
	//double r;
	//double Q_fake[3][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	for (i=0; i<cols; i++) {
		//printf("\n");
		//printf("outer cycle n = %d\n", i);
		
		//printf("printing A inside the function\n");
		//for(ii=0; ii<rows*cols; ii++) {
		//	printf( "%f ", A[ii]);
		//}
		//printf("\n");
		
		//copy column
		//Q[:,i] = A[:,i]
		//printf("col Q[:,i] ");
		
		for(ii=0; ii<rows; ii++) {
			if(A[ii*cols + i] == INFINITY) {
				printf("problems here\n");
			}
		}

		for(ii=0; ii<rows; ii++) {
			//Q[ii*cols+i] = A[ii*cols+i];
			//Q_fake[i][ii] = A[ii*cols+i];
			Q[ii*cols+i] = A[ii*cols+i];
			
			//printf("%f ", Q[ii*cols+i]);
		}

		printf("\n\n");

		printf("i = %d\n", i);

		printf("A =");
		for(ii=0; ii<rows*cols; ii++) {
			if( ii % cols == 0) {
				printf("\n");
			}
			printf( "%f ", A[ii]);
		}

		printf("\n\n");

		printf("Q =\n");
		for(ii=0; ii<rows; ii++) {
			for(jj=0; jj<cols; jj++) {
				printf( "%f ", Q[jj*cols+i]);
			}
			printf("\n");
		}

		//printf("Q =");
		//for(ii=0; ii<rows*cols; ii++) {
		//	if( ii % cols == 0) {
		//		printf("\n");
		//	}
		//	printf( "%f ", Q[ii]);
		//}

		// zeroing the product every cycle
		

		for(j=0; j<i; j++) {

			//product1 = 0;
			//product2 = 0;

			//R[j,i] = np.dot(Q[:,j],A[:,i])
			for(jj=0; jj<rows; jj++) {
				//printf("j = %d\n", j);
				//printf("Q = %f, A = %f\n", Q[cols*jj+j],A[cols*jj+i]);
				
				//product1 += Q[cols*jj+j]*A[cols*jj+i];

				printf("moltiplicandi = %f, %f", Q[cols*jj+j] , A[cols*jj+i]);
				printf("\n");
				
				product[jj] = Q[cols*jj+j]*A[cols*jj+i];
				//product12 = Q[cols*jj+j]*A[cols*jj+i];
				//product13 = Q[cols*jj+j]*A[cols*jj+i];

				//if ( Q[cols*jj+j] == INFINITY ) {
				//	printf("diverged at: %d,%d\n", j, jj);
				//}

			}
			printf("product[0]: %f\n", product[0]);
			printf("product[1]: %f\n", product[1]);
			printf("product[2]: %f\n", product[2]);
			return;
			//R[3*i+j] = product1;

			//printf("R[3*i+j: %f\n", product1);

			//np.dot(R[j,i],Q[:,j])
			//for(jj=0; jj<rows; jj++) {
			//	product2 += R[3*j+i] * Q[3*jj+j];
			//}
			
			//Q[:,i] = Q[:,i] - np.dot(R[j,i],Q[:,j])
			printf("col subtracted Q[:,i] ");
			for(jj=0; jj<rows; jj++) {
				Q[cols*jj+i] = Q[cols*jj+i] - R[cols*j+i] * Q[cols*jj+j];
				printf("%f ", Q[cols*jj+i]);
			}
			printf("\n\n");

		}

		//R[i,i] = np.linalg.norm(Q[:,i])
		for (jj=0; jj<rows; jj++) {
			norm = 0;
			for (ii=0; ii<rows; ii++) {
				norm += Q[cols*ii+jj] * Q[cols*ii+jj];
			}
			R[3*jj+jj] = sqrt(norm);
		}

		for (jj=0; jj<rows; jj++) {
			Q[cols*jj+i] /= R[cols*jj+jj];
		}
	}

		
	printf("Q=\n");
	for(ii=0; ii<rows*cols; ii++) {
		if( ii % cols == 0) {
			printf("\n");
		}
		printf( "%f ", Q[ii]);
	}

}
