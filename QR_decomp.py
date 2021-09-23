import numpy as np

A = np.array([[12,-51,4,-2, 0],[6,16,-68,-1,2],[-4,24,-41,5,-7]]);

righe = A.shape[0]
colonne = A.shape[1]

Q = np.zeros([righe,colonne])
R = np.zeros([colonne,colonne])



for i in np.arange(0,A.shape[1],1):
    Q[:,i] = A[:,i]

    for j in range(i):
        R[j,i] = np.dot(Q[:,j],A[:,i])
        #print("R[j,i] =", R[j,i])
        Q[:,i] = Q[:,i] - np.dot(R[j,i],Q[:,j])
    R[i,i] = np.linalg.norm(Q[:,i])
    Q[:,i] = Q[:,i] / R[i,i]

    #for j in range

Res = np.dot(Q,R)

print("Q=", Q.round(4))
print("\nR=", R.round(4))

print("\nmultiplication=\n", Res)
print("\nA = \n", A)
