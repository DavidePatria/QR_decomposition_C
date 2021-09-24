#include "QR_decomp_as_py.h"


void main() {
	const int ROW = 4;
	const int COL = 3;

	//double A[3][4] = {{0.9284,-1,0,-1},{1.9823,2.02,-1,-1},{-1,1.0,-5.09,1.1}};
	//double Q[3][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0}}; 
	//double R[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	double A[4][3] = {{0.928,-1,0,-1},{1.9823,2.02,-1,-1},{-1,1.0,-5.09,1.1}};
	double Q[4][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0}}; 
	double R[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

	QR_dec(A,Q,R,ROW,COL);
	//int i,jj;

	//printf("Q before trans = \n");
	//for (i=0; i<3; i++) {
	//	printf("\n");
	//	for (jj=0; jj<3; jj++) {
	//		printf("%f ", Q[i][jj]);
	//	}
	//}

	//printf("A = \n");
	//for (i=0; i<ROW; i++) {
	//	printf("\n");
	//	for (jj=0; jj<COL; jj++) {
	//		printf("%f ", A[i][jj]);
	//	}
	//}
	//printf("\n\n");


	printf("\n");


	//printf("A = \n");
	//for (i=0; i<ROW; i++) {
	//	printf("\n");
	//	for (jj=0; jj<COL; jj++) {
	//		printf("%f ", A[i][jj]);
	//	}
	//}
	//printf("\n\n");

	//printf("Q = np.array([ \n");
	//for (i=0; i<ROW; i++) {
	//	printf("[");
	//	for (jj=0; jj<COL; jj++) {
	//		printf("%f ,", Q[i][jj]);
	//	}
	//	printf("],\n");
	//}
	//printf("])");

	//printf("\n\n");

	//printf("R = np.array([ \n");
	//for (i=0; i<COL; i++) {
	//	printf("[");
	//	for (jj=0; jj<COL; jj++) {
	//		printf("%f ,", R[i][jj]);
	//	}
	//	printf("], \n");
	//}
	//printf("])");

	//printf("\n\n");


	//int k, l,  j;

	//float res[4];

	//for(j=0; j<COL; j++) {
	//	for(i=0; i<ROW; i++) {
	//		res[j] = Q[0][i]*R[i][j]; 
	//	}
	//}

	//for(i=0; i<COL; i++) {
	//	printf(" %f ", res[i]);
	//}


	//res[0] = Q[0][0]*R[0][0] + Q[0][1]*R[1][0] + Q[0][2]*R[2][0];
	//res[1] = Q[0][0]*R[0][1] + Q[0][1]*R[1][1] + Q[0][2]*R[2][1];
	//res[2] = Q[0][0]*R[0][2] + Q[0][1]*R[1][2] + Q[0][2]*R[2][2];
 
	//res[3] = Q[1][0]*R[0][0] + Q[1][1]*R[1][0] + Q[1][2]*R[2][0];
	//res[4] = Q[1][0]*R[0][1] + Q[1][1]*R[1][1] + Q[1][2]*R[2][1];
	//res[5] = Q[1][0]*R[0][2] + Q[1][1]*R[1][2] + Q[1][2]*R[2][2];

	//res[6] = Q[2][0]*R[0][0] + Q[2][1]*R[1][0] + Q[2][2]*R[2][0];
	//res[7] = Q[2][0]*R[0][1] + Q[2][1]*R[1][1] + Q[2][2]*R[2][1];
	//res[8] = Q[2][0]*R[0][2] + Q[2][1]*R[1][2] + Q[2][2]*R[2][2];

	//for (i=0; i<9; i++) {
	//	printf(" %f\n", res[i]);
	//}




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



