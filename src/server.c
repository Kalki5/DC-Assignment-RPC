#include "common/calculator.h"

int isprime(int a) {
    int i;
    for(i=2; i <= a/2; i++) {
        if(a % i == 0) {
            break;
        }
    }

    if(i == a / 2 + 1) {
        return 1;
    } else {
        return 0;
    }
}

int isBothOddOrEven(int x, int y) {
    return !((x & 1) ^ (y & 1));
}

int *calc_1_svc(variable *argp, struct svc_req *rqstp) {
    static int result;
    switch(argp->choice) {
        case 1: {
            result = (argp->x) + (argp->y);
            break;
        }
        case 2: {
            result = (argp->x) * (argp->y);
            break;
        }
        case 3: {
            result = (argp->x) - (argp->y);
            break;
        }
        case 4: {
            result = (argp->x) / (argp->y);
            break;
        }
        case 5: {
            result = (argp->x) % (argp->y);
            break;
        }
        case 6: {
            result = isprime(argp->x);
            break;
        }
        case 7: {
            result = isBothOddOrEven(argp->x, argp->y);
            break;
        }
    }
    return &result;
}