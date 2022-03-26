#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ringinfo{
    size_t size;
    void* (*plus)(void*, void*);
    void* (*mult)(void*, void*);
    void* zero;
};

matrix* creatematrix(){
    matrix* mat =calloc(1, sizeof(matrix));
    mat->elem = NULL;
    mat->n = 0;
    mat->m = 0;
    mat->ringinfo = NULL;
    return mat;
}
typedef struct data{
    double real;
    double complex;
}data;
matrix* enterint(matrix* a) {
    if(a->elem != NULL){
        free(a->elem);
    }
    printf("Write height and width\n");
    scanf("%d", &(a->m));
    scanf("%d", &(a->n));
    a->elem = calloc(a->n* a->m, a->ringinfo->size );
    for (int i = 0; i < a->m; i++) {
        for (int j = 0; j <a->n; j++) {
            scanf("%d",(int*)(a->elem+ (i * a->n + j) * a->ringinfo->size));
        }
    }
    return a;
}
matrix* enterdouble(matrix* a) {
    if(a->elem != NULL){
        free(a->elem);
    }
    printf("Write height and width\n");
    scanf("%d", &(a->m));
    scanf("%d", &(a->n));
    a->elem = calloc(a->n* a->m, a->ringinfo->size);
    for (int i = 0; i < a->m; i++) {
        for (int j = 0; j <a->n; j++) {
            scanf("%lf",(double*)(a->elem + (i * a->n + j) * a->ringinfo->size));
        }
    }
    return a;
}
matrix* entercomplex(matrix* a){
    if(a->elem != NULL){
        free(a->elem);
    }
    printf("Write height and width\n");
    scanf("%d", &(a->m));
    scanf("%d", &(a->n));
    a->elem = calloc(a->n* a->m, a->ringinfo->size);
    for (int i = 0; i < a->m; i++) {
        for (int j = 0; j <a->n; j++) {
            printf("Write <real part>_<complex part>\n");
            scanf("%lf", &((data*) (a->elem + (i * a->n + j) * a->ringinfo->size))->real);
            scanf("%lf", &((data*) (a->elem + (i * a->n + j) * a->ringinfo->size))->complex);
        }
    }
    return a;
}
void printint(matrix* a) {
    if(a->elem) {
        for (int i = 0; i < a->m; i++) {
            for (int j = 0; j < a->n; j++) {
                printf("%d ", *(int*)(a->elem + (i * a->n + j) * a->ringinfo->size));
            }
            printf("\n ");
        }
        printf("\n ");
    }
}
void printdouble(matrix* a) {
    if(a->elem) {
        for (int i = 0; i < a->m; i++) {
            for (int j = 0; j < a->n; j++) {
                printf("%lf ", *(double*)(a->elem + (i * a->n + j) * a->ringinfo->size));
            }
            printf("\n ");
        }
        printf("\n ");
    }
}
void printcomplex(matrix* a) {
    if(a->elem) {
        for (int i = 0; i < a->m; i++) {
            for (int j = 0; j < a->n; j++) {
                if (((data*)(a->elem+ (i * a->n + j) * a->ringinfo->size))->complex >=0){
                    printf("%.2lf+%.2lfi ", ((data*)(a->elem + (i * a->n + j) * a->ringinfo->size))->real,((data*)(a->elem + (i * a->n + j) * a->ringinfo->size))->complex);
                }
                else{
                    printf("%.2lf%.2lfi ", ((data*)(a->elem + (i * a->n + j) * a->ringinfo->size))->real,((data*)(a->elem + (i * a->n + j) * a->ringinfo->size))->complex);
                }
            }
            printf("\n ");
        }
        printf("\n ");
    }
}
matrix* plus(matrix* a, matrix* b){
    if (a->n == b->n && a->m == b->m) {
        matrix *res = creatematrix();
        res->n = a->n;
        res->m = a->m;
        res->ringinfo = a->ringinfo;
        res->elem = calloc(a->n*a->m,res->ringinfo->size);
        res->elem = res->ringinfo->plus(a->elem, b->elem);
        void *m;
        m = res->elem;
        for (int i = 0; i < (a->m); i++) {
            for (int j = 0; j < a->n; j++) {
                m = res->ringinfo->plus(a->elem + (i * a->n + j) * a->ringinfo->size,
                                        b->elem + (i * b->n + j) * b->ringinfo->size);
                memcpy((void *) (res->elem + (i * a->n + j) * a->ringinfo->size), m, res->ringinfo->size);
            }
        }
        return res;
    }
    else {
        printf("error\n");
        return NULL;
    }
}
matrix* mult (matrix* a, matrix* b){
    if(a->n == b->m){
        matrix* c = creatematrix();
        c->n = a->m;
        c->m = b->n;
        c->ringinfo = a->ringinfo;
        c->elem = calloc(a->n*b->m,c->ringinfo->size);
        void* m;
        m = c->elem;
        for (int i = 0; i < a->m; i++){
            for (int j = 0; j < b->n; j++) {
                for (int k = 0; k < a->n; k++){
                    m =c->ringinfo->plus(m, c->ringinfo->mult(a->elem+(i*a->n+k)*c->ringinfo->size, b->elem+(j+k*a->m)*c->ringinfo->size));
                }
                memcpy((void*) c->elem + (i*a->m+j)* c->ringinfo->size, m, c->ringinfo->size);
                m = creatematrix();
            }
        }
        return c;
    }
    else{
        printf("error\n");
        matrix* y = creatematrix();
        return y;
    }
}
matrix* lk(matrix* a){
    int lambada, g1, g2;
    printf("Write lambada\n");
    scanf("%d", &lambada);
    printf("Now write the string which programm should mult with lambada and the string you want plus current combination\n");
    scanf("%d", &g1);
    scanf("%d", &g2);
    if(g2 > a->m+1 || g1>a->m+1 || lambada == 0 || g2 <= 0 || g1 <= 0){
        printf ("error\n");
        return NULL;
    }
    void* m;
    for (int i = 0; i < a->m; i++) {
        for (int j = 0; j < a->n; j++) {
            if (i == g2-1){
                m = a->elem+ ((g2-1)*a->m+j)*a->ringinfo->size;
                for(int r = 0; r < lambada; r++){
                    m =a->ringinfo->plus(a->elem + ((g1-1)*a->m+j)*a->ringinfo->size, m);
                }
                memcpy(a->elem+(i*a->m+j)*a->ringinfo->size,m,a->ringinfo->size);
            }
        }
    }
    return a;
}
matrix* transpon(matrix* a){
    matrix* b = creatematrix();
    b->elem = calloc(a->n * a->m, a->ringinfo->size);
    b->ringinfo = a->ringinfo;
    b->n = a->m;
    b->m = a->n;
    void* m;
    for (int i = 0; i < a->m; i++) {
        for (int j = 0; j < a->n; j++) {
            m = a->elem + (i * a->n + j)*a->ringinfo->size;
            memcpy(b->elem + (j * a->m + i)*a->ringinfo->size, m, b->ringinfo->size);
            m = creatematrix();
        }
    }
    return b;
}
void freematrix(matrix* mat){
    if (mat->elem){
        free(mat->elem);
    }
    free(mat);
}