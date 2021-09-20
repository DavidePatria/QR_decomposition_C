#include <stdio.h>
#include <math.h>

static inline int QR_dec( double *A, double *Q, double *R, int rows, int cols) {
	//vectors for internal coputations
	double T[3];
	double S[3];
	//double T[3][3];
	//double S[3][3];
	float norm;
	int i,ii, j, jj, k, kk;
	float r;
	
	for (i=0; i<cols; i++) {
		printf("\n");
		printf("outer cycle n = %d\n", i);
		
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

			//R[3*j + i] = r;
			R[3*i + j] = r;

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




		//for(kk=0; kk<jj; kk++) {
void main() {
	double A[3][3] = {{12,-51,4},{6,167,-68},{-4,24,-41}};
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
	printf("\n\n");

	printf("Q = \n");
	for (i=0; i<3; i++) {
		printf("\n");
		for (jj=0; jj<3; jj++) {
			printf("%f ", Q[i][jj]);
		}
	}

	printf("\n\n");

	printf("R = \n");
	for (i=0; i<3; i++) {
		printf("\n");
		for (jj=0; jj<3; jj++) {
			printf("%f ", R[i][jj]);
		}
	}

	printf("\n\n");

	float res[9];

	int k, l;


	res[0] = Q[0][0]*R[0][0] + Q[0][1]*R[1][0] + Q[0][2]*R[2][0];
	res[1] = Q[0][0]*R[0][1] + Q[0][1]*R[1][1] + Q[0][2]*R[2][1];
	res[2] = Q[0][0]*R[0][2] + Q[0][1]*R[1][2] + Q[0][2]*R[2][2];
 
	res[3] = Q[1][0]*R[0][0] + Q[1][1]*R[1][0] + Q[1][2]*R[2][0];
	res[4] = Q[1][0]*R[0][1] + Q[1][1]*R[1][1] + Q[1][2]*R[2][1];
	res[5] = Q[1][0]*R[0][2] + Q[1][1]*R[1][2] + Q[1][2]*R[2][2];

	res[6] = Q[2][0]*R[0][0] + Q[2][1]*R[1][0] + Q[2][2]*R[2][0];
	res[7] = Q[2][0]*R[0][1] + Q[2][1]*R[1][1] + Q[2][2]*R[2][1];
	res[8] = Q[2][0]*R[0][2] + Q[2][1]*R[1][2] + Q[2][2]*R[2][2];

	//res6 = Q[2][0]*R[0][2] + Q[2][1]*R[1][2] + Q[2][2]*R[2][2];

	for (i=0; i<9; i++) {
		printf(" %f\n", res[i]);
	}
	//printf("res2 = %f\n", res2);
	//
	//printf("Q*R = \n");
	//for (i=0; i<3; i++) {
	//	printf("\n");
	//	for (j=0; j<3; j++) {
	//		P[i][j] =  0
	//		for(k = 0; k < 3; k++){
	//			for(l = 0; l < 3; l++){
	//				P[i][j] += Q[k][l] * R[l][k]
	//			}
	//		}
	//	}
	

	printf("\n");

}


