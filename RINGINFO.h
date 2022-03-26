#ifndef OLEGG_RINGINFO_H
#define OLEGG_RINGINFO_H
#include "string.h"
typedef struct matrix matrix;
typedef struct ringinfo info;
typedef struct data data;
struct ringinfo{
    size_t size;
    void* (*plus)(void*, void*);
    void* (*mult)(void*, void*);
    void(*zero)(void*);
};
struct data{
    double real;
    double complex;
};

info* ringinfocreate(
        void* (*plus)(void*, void*),
        size_t size,
        void* (*mult)(void*, void*),
        void (*zero)(void*));
void* plusint(void* a,void* b);
void* plusdouble(void* a,void* b);
void* pluscomplex(void* a,void* b);
void* multint(void*a, void* b);
void* multdouble(void*a, void* b);
void* multcomplex(void*a, void* b);
void* zeroint(void* a);
void* zerodouble(void* a);
void* zerocomplex(void* a);

#endif //OLEGG_RINGINFO_H