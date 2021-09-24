#include <stdio.h>
#include <math.h>

void QR_dec( double *A, double *Q, double *R, int rows, int cols) {
	//vectors for internal coputations
	double T[rows];
	double S[rows];
	//double T[3][3];
	//double S[3][3];
	float norm;
	int i,ii, j, jj, k, kk;
	float r;

	//for(i=0; i<rows*cols; i++) {
	//	printf("%f  ", A[i]);
	//}
	
	for (i=0; i<cols; i++) {
		printf("\n");
		//printf("outer cycle n = %d\n", i);
		
		//copy column
		for(ii=0; ii<cols; ii++) {
			//A[ii][i] = Q[ii][i];
			//printf("inside ii cycle at number %d\n", ii);
			Q[ii*cols +i] = A[ii*cols + i] ;

			// printing A every cycle to check if it gets modified
			//printf("A = \n");
			//for (kk=0; kk<rows; kk++) {
			//	printf("\n");
			//	for (jj=0; jj<cols; jj++) {
			//		printf("%f ", A[kk + 3*jj]);
			//	}
			//}
			//printf("\n\n");

		}

		for(j=0; j<i; j++) {

			for(jj=0; jj<rows; jj++) {
				//T[jj][0] = Q[3*jj + j];
				//S[jj][0] = A[3*jj + j];
				T[jj] = Q[cols*jj + j];
				S[jj] = A[cols*jj + i];
				//printf("T[jj] = %f, S[jj] = %f\n", T[jj], S[jj]);
			}
		
			r = 0;
			for(k=0; k<rows; k++) {
				r += T[k] * S[k];
				//printf("k = %d, T[k] = %f, S[k] = %f, T[k]*S[k] = %f\n", k, T[k], S[k], T[k]*S[k]);
				//printf("r = %f\n", r);
				//r += T[3*k + 0] * S[3*k + 0];
				//r += T[k] * S[k];
			}

			R[cols*j + i] = r;
			//R[3*i + j] = r;

			for(kk=0; kk<rows; kk++) {
				// multiply vector T by r
				T[kk] *= r;
				// subtract T[kk] from Q column-wise
				Q[cols*kk + i] -= T[kk];
			}
		}

		// rezeroing at each cycle
		norm = 0;
		// norm of the i-th column
		for(k=0; k<rows; k++) {
			norm += Q[cols*k + i]*Q[cols*k + i];
		}
		norm = sqrt(norm);

		R[cols*i + i] = norm;

		for(k=0; k<rows; k++) {
			Q[cols*k + i] = Q[cols*k + i]/R[cols*i + i];
			//Q[3*k + i] /= R[3*i + i];
		}
	}
}


