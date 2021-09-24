# QR_decomposition_C

C implementation of the QR decomposition algorithm.

The code is an adaptation to the needs of the darktable project of the code found [here](https://stackoverflow.com/questions/35834294/implementing-qr-decomposition-in-c).

The Gram-Schmidt process is used, therefore the input matrice A (**m**x**n**) produces the **reduced** QR form, where Q is **m**x**n** and R is **n**x**n**. In order to apply this the rank of A has to be **n**.
