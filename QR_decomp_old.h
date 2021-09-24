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
	double T[rows];
	double S[rows];
	//double T[3][3];
	//double S[3][3];
	float norm;
	int i,ii, j, jj, k, kk;
	float r;
	
	for (i=0; i<cols; i++) {
		//printf("\n");
		//printf("outer cycle n = %d\n", i);
		
		//copy column
		for(ii=0; ii<rows; ii++) {
			//A[ii][i] = Q[ii][i];
			Q[ii*3 +i] = A[ii*3 + i] ;
		}

		for(j=0; j<i; j++) {
			for(jj=0; jj<rows; jj++) {
				//T[jj][0] = Q[3*jj + j];
				//S[jj][0] = A[3*jj + j];
				T[jj] = Q[3*jj + j];
				S[jj] = A[3*jj + i];
				//printf("T[jj] = %f, S[jj] = %f\n", T[jj], S[jj]);
			}
		
			r = 0;
			for(k=0; k<rows; k++) {
				r += T[k] * S[k];
				printf("k = %d, T[k] = %f, S[k] = %f, T[k]*S[k] = %f\n", k, T[k], S[k], T[k]*S[k]);
				printf("r = %f\n", r);
				//r += T[3*k + 0] * S[3*k + 0];
			}

			R[3*j + i] = r;
			//R[3*i + j] = r;

			for(kk=0; kk<rows; kk++) {
				// multiply vector T by r
				T[kk] *= r;
				// subtract T[kk] from Q column-wise
				Q[3*kk + i] -= T[kk];
			}
		}

		// rezeroing at each cycle
		norm = 0;
		// norm of the i-th column
		for(k=0; k<rows; k++) {
			norm += Q[3*k + i]*Q[3*k + i];
		}
		norm = sqrt(norm);

		R[3*i + i] = norm;

		for(k=0; k<rows; k++) {
			Q[3*k + i] = Q[3*k + i]/R[3*i + i];
			//Q[3*k + i] /= R[3*i + i];
		}

	}

}
