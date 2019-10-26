#include "common/calculator.h"
#include "math.h"

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

int isInteger(int z) {
    return ceil(z) == floor(z);
}

response *calc_1_svc(request *argp, struct svc_req *rqstp) {
    static response result;
    result.code = 200;
    if (!isInteger(argp->x) || !isInteger(argp->y)) {
        result.code = 401;
        return &result;
    }
    switch(argp->choice) {
        case 1: {
            result.value = (argp->x) + (argp->y);
            break;
        }
        case 2: {
            result.value = (argp->x) * (argp->y);
            break;
        }
        case 3: {
            result.value = (argp->x) - (argp->y);
            break;
        }
        case 4: {
            result.value = (argp->x) / (argp->y);
            break;
        }
        case 5: {
            result.value = (argp->x) % (argp->y);
            break;
        }
        case 6: {
            result.value = isprime(argp->x);
            break;
        }
        case 7: {
            result.value = isBothOddOrEven(argp->x, argp->y);
            break;
        }
        default: {
            result.code = 400;
            printf("Server Error: Given choice does not exist");
        }
    }
    return &result;
}