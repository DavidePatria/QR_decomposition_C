#include <stdio.h>
#include <math.h>

static inline int QR_dec( double *A, double *Q, double *R, int rows, int cols) {
	double T[3][3];
	double S[3][3];
	float norm;

	int i,ii, j, jj, k, kk;
	
	for (i=0; i<cols; i++) {
		
		//copy column
		for(ii=0; ii<rows; ii++) {
			//A[ii][i] = Q[ii][i];
			Q[ii*3 +i] = A[ii*3 + i] ;
		}


		for(j=0; j<i; j++) {
			for(jj=0; jj<i; jj++) {
				T[jj][0] = Q[3*jj + j];
				S[jj][0] = A[3*jj + j];
			}
			float r = 0;
			for(k=0; k<rows; k++) {
				r += T[k][0] * S[k][0];
				//r += T[3*k + 0] * S[3*k + 0];
			}
			R[3*j + i] = r;

			// is ok to reuse kk?
			for(k=0; k<rows; k++) {
				T[k][0] *= r;
				Q[3*k + i] += -T[k][0];
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
			Q[3*k + i] /= R[3*i + i];
		}

	}

}




		//for(kk=0; kk<jj; kk++) {
void main() {
	double A[3][3] = {{1.f,2,3},{4,5,6},{7,8,9}};
	double Q[3][3];
	double R[3][3];
	int col = 3;
	int row = 3;

	int i,jj;

	//printf("Q before trans = \n");
	//for (i=0; i<3; i++) {
	//	printf("\n");
	//	for (jj=0; jj<3; jj++) {
	//		printf("%f ", Q[i][jj]);
	//	}
	//}

	printf("\n");

	QR_dec(A,Q,R,3,3);

	printf("A = \n");
	for (i=0; i<3; i++) {
		printf("\n");
		for (jj=0; jj<3; jj++) {
			printf("%f ", A[i][jj]);
		}
	}
	printf("\n");

	printf("Q = \n");
	for (i=0; i<3; i++) {
		printf("\n");
		for (jj=0; jj<3; jj++) {
			printf("%f ", Q[i][jj]);
		}
	}

	printf("\n");

	printf("R = \n");
	for (i=0; i<3; i++) {
		printf("\n");
		for (jj=0; jj<3; jj++) {
			printf("%f ", R[i][jj]);
		}
	}

	printf("\n");
}






