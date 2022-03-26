
#ifndef OLEGG_MATRIX_H
#define OLEGG_MATRIX_H
typedef struct matrix matrix;
typedef struct ringinfo info;
typedef struct data data;
typedef struct matrix{
    void* elem;
    int n;
    int m;
    info* ringinfo;
}matrix;
matrix* creatematrix();
void printcomplex(matrix* a);
void printdouble(matrix* a);
void printint(matrix* a);
matrix* enterdouble(matrix* a);
matrix* enterint(matrix* a);
matrix* entercomplex(matrix* a);
matrix* zero(info* ringinfo);
matrix* plus(matrix* a, matrix* b);
matrix* mult(matrix* a, matrix* b);
matrix* transpon(matrix* a);
matrix* lk(matrix* a);
void freematrix(matrix* a);
#endif //OLEGG_MATRIX_H
