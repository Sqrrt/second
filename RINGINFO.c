#include "RINGINFO.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct matrix matrix;
typedef struct ringinfo info;
void* plusint(void* a,void* b){
    int* a1 = (int*) a;
    int* b1 = (int*) b;
    int* res = malloc(sizeof(int));
    *res = *a1+ *b1;
    return res;
}
void* plusdouble(void* a,void* b){
    double* a1 = (double*) a;
    double* b1 = (double*) b;
    double* res = malloc(sizeof(double));
    *res = *a1+ *b1;
    return res;
}
void* pluscomplex(void* a,void* b){
    data* c = (data*) a;
    data* d = (data*) b;
    data* res = malloc(sizeof(data));
    ((data*)res)->real = c->real + d->real;
    ((data*)res)->complex = c->complex + d->complex;
    return res;
}
void* multint(void*a, void* b){
    int* a1 = (int*) a;
    int* b1 = (int*) b;
    int* res = malloc(sizeof(int));
    *res = (*a1) * (*b1);
    return res;
}
void* multdouble(void*a, void* b){
    double* a1 = (double*) a;
    double* b1 = (double*) b;
    double* res = malloc(sizeof(double));
    *res = (*a1) * (*b1);
    return res;
}
void* multcomplex(void* a,void* b){
    data* c = (data*) a;
    data* d = (data*) b;
    data* res = malloc(sizeof(data));
    res->real = (c->real) * (d->real) - (c->complex) * (d->complex);
    res->complex = (c->real) * (d->complex) + (d->real) * (c->complex);
    return res;
}
void* zeroint(void*a){
    *(int*) a = 0;
    return a;
}
void* zerodouble(void*a){
    *(double*) a = 0.0;
    return a;
}
void* zerocomplex(void* a){
    ((data*) a)->real = 0.0;
    ((data*) a)->complex = 0.0;
    return a;
}
info* ringinfocreate(
        void*(*plus)(void*, void*),
        size_t size,
        void*(*mult)(void*, void*),
        void (*zero)(void*)){
    info* ringinfo = malloc (sizeof(info));
    ringinfo->size = size;
    ringinfo->plus = plus;
    ringinfo->mult = mult;
    ringinfo->zero = zero;
    return ringinfo;
}
