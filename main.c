//
// Created by olegg on 24.03.2022.
//

#include <stdio.h>
#include "RINGINFO.h"
#include "matrix.h"
int menuint(){
    int ii, f, ff, fff;
    matrix* a = creatematrix();
    matrix* b = creatematrix();
    matrix* c = creatematrix();
    matrix* d = creatematrix();
    info* ringinfo = ringinfocreate(
            (void*)plusint,
            sizeof(int),
            (void*)multint,
            (void*)zeroint);
    a->ringinfo = ringinfo;
    b->ringinfo = ringinfo;
    c->ringinfo = ringinfo;
    while(1) {
        printf("what do you want?\n 1)create 1st matrix\n 2)create 2nd matrix\n 3)plusmatrix (1st + 2nd)\n 4)mult (1st * 2nd)\n 5)transpon\n 6)plus lk\n 7)print\n 8)change 1st and 2nd\n 9)exit\n");
        scanf("%d", &ii);
        switch (ii) {
            case 1:
                a = enterint(a);
                break;
            case 2:
                b = enterint(b);
                break;
            case 3:
                c = plus(a, b);
                break;
            case 4:
                c = mult(a, b);
                break;
            case 5:
                printf("What matrix?\n 1)first\n 2) second\n 3) resulted\n");
                scanf("%d", &f);
                switch (f) {
                    case 1:
                        a = transpon(a);
                        break;
                    case 2:
                        b = transpon(b);
                        break;
                    case 3:
                        c = transpon(c);
                        break;
                }
                break;
            case 6:
                printf("What matrix?\n 1)first\n 2)second\n 3)result\n" );
                scanf("%d", &fff);
                switch (fff) {
                    case 1:
                        a = lk(a);
                        break;
                    case 2:
                        b = lk(b);
                        break;
                    case 3:
                        c = lk(c);
                        break;
                }
                break;
            case 7:
                printf("What matrix do you want to print?\n 1)a\n 2)b\n 3)result\n ");
                scanf("%d", &ff);
                switch (ff) {
                    case 1:
                        printint(a);
                        break;
                    case 2:
                        printint(b);
                        break;
                    case 3:
                        printint(c);
                        break;
                }
                break;
            case 8:
                d = a;
                a = b;
                b = d;
                break;
            case 9:
                freematrix(a);
                freematrix(b);
                freematrix(c);
                return 0;
        }
    }
}
int menudouble(){
    int kk,f,ff,fff;
    matrix* b = creatematrix();
    matrix* a = creatematrix();
    matrix* c = creatematrix();
    matrix* d = creatematrix();
    info* ringinfo = ringinfocreate(
            (void*)plusdouble,
            sizeof(double),
            (void*)multdouble,
            (void*)zerodouble);
    a->ringinfo = ringinfo;
    b->ringinfo = ringinfo;
    c->ringinfo = ringinfo;
    while (1) {
        printf("what do you want?\n 1)create 1st matrix\n 2)create 2nd matrix\n 3)plusmatrix (1st + 2nd)\n 4)mult (1st * 2nd)\n 5)transpon\n 6)plus lk\n 7)print\n 8)change 1st and 2nd\n 9)exit\n");
        scanf("%d", &kk);
        switch (kk) {
            case 1:
                a = enterdouble(a);
                break;
            case 2:
                b = enterdouble(b);
                break;
            case 3:
                c = plus(a, b);
                break;
            case 4:
                c = mult(a, b);
                break;
            case 5:
                printf("What matrix?\n 1)first\n 2) second\n 3) resulted\n");
                scanf("%d", &f);
                switch (f) {
                    case 1:
                        a = transpon(a);
                        break;
                    case 2:
                        b = transpon(b);
                        break;
                    case 3:
                        c = transpon(c);
                        break;
                }
            case 6:
                printf("What matrix?\n 1)first\n 2)second\n 3)result\n" );
                scanf("%d", &fff);
                switch (fff) {
                    case 1:
                        a = lk(a);
                        break;
                    case 2:
                        b = lk(b);
                        break;
                    case 3:
                        c = lk(c);
                        break;
                }
                break;
            case 7:
                printf("What matrix do you want to print?\n 1)a\n 2)b\n 3)result\n ");
                scanf("%d", &ff);
                switch (ff) {
                    case 1:
                        printdouble(a);
                        break;
                    case 2:
                        printdouble(b);
                        break;
                    case 3:
                        printdouble(c);
                        break;
                }
                break;
            case 8:
                d = a;
                a = b;
                b = d;
                break;
            case 9:
                freematrix(a);
                freematrix(b);
                freematrix(c);
                return 0;
        }
    }
}
int menucomplex(){
    int cc, f, ff, fff;
    matrix* b = creatematrix();
    matrix* a = creatematrix();
    matrix* c = creatematrix();
    matrix* d = creatematrix();
    info* ringinfo = ringinfocreate(
            (void*)pluscomplex,
            sizeof(data),
            (void*)multcomplex,
            (void*)zerocomplex);
    a->ringinfo = ringinfo;
    b->ringinfo = ringinfo;
    c->ringinfo = ringinfo;
    while(1) {
        printf("what do you want?\n 1)create 1st matrix\n 2)create 2nd matrix\n 3)plusmatrix (1st + 2nd)\n 4)mult (1st * 2nd)\n 5)transpon\n 6)plus lk\n 7)print\n 8)change 1st and 2nd\n 9)exit");
        scanf("%d", &cc);
        switch (cc) {
            case 1:
                a = entercomplex(a);
                break;
            case 2:
                b = entercomplex(b);
                break;
            case 3:
                c = plus(a, b);
                break;
            case 4:
                c = mult(a, b);
                break;
            case 5:
                printf("What matrix?\n 1)first\n 2) second\n 3) resulted\n");
                scanf("%d", &f);
                switch (f) {
                    case 1:
                        a = transpon(a);
                        break;
                    case 2:
                        b = transpon(b);
                        break;
                    case 3:
                        c = transpon(c);
                        break;
                }
                break;
            case 6:
                printf("What matrix?\n 1)first\n 2)second\n 3)result\n" );
                scanf("%d", &fff);
                switch (fff) {
                    case 1:
                        a = lk(a);
                        break;
                    case 2:
                        b = lk(b);
                        break;
                    case 3:
                        c = lk(c);
                        break;
                }
                break;
            case 7:
                printf("What matrix do you want to print?\n 1)a\n 2)b\n 3)result\n ");
                scanf("%d", &ff);
                switch (ff) {
                    case 1:
                        printcomplex(a);
                        break;
                    case 2:
                        printcomplex(b);
                        break;
                    case 3:
                        printcomplex(c);
                        break;
                }
                break;
            case 8:
                d = a;
                a = b;
                b = d;
                break;
            case 9:
                freematrix(a);
                freematrix(b);
                freematrix(c);
                return 0;
        }
    }
}
int main() {
    int ll;
    while(1) {
        printf("Enter what kind of data you use:\n1)int\n2)double\n3)complex\n4)exit\n");
        scanf("%d", &ll);
        switch (ll) {
            case 1:
                menuint();
                break;
            case 2:
                menudouble();
                break;
            case 3:
                menucomplex();
                break;
            case 4:
                return 0;
        }
    }
}