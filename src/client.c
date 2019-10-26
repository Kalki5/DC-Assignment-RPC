#include "common/calculator.h"

void calc_prg_1(char *host) {
    CLIENT *clnt;
    int *result_1;
    variable calc_1_arg;

    clnt = clnt_create(host, calc_prg, calc_version, "udp");

    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }

    printf("\nOperations:\n1. Addition\n2. Multiplication\n3. Subtraction\n4. Division\n5. Remainder \n6. Is first number prime\n7. Check if both are Odd or Even\n\nEnter choice (1-7): ");
    if (!scanf("%d", &calc_1_arg.choice) && calc_1_arg.choice < 1 && calc_1_arg.choice > 7) {
        printf("Error: Invalid choice\n");
        exit(1);
    }

    printf("Enter values (X Y): ");
    if (!scanf("%d %d", &calc_1_arg.x, &calc_1_arg.y)) {
        printf("Error: Invalid values\n");
        exit(1);
    }

    result_1 = calc_1(&calc_1_arg, clnt);

    if (result_1 == (int *) NULL) {
        clnt_perror(clnt, "RPC Call Failed");
    }

    if(calc_1_arg.choice != 6 && calc_1_arg.choice != 7) {
        printf("Your result: %d\n", *result_1);
    } else if (calc_1_arg.choice == 6) {
        if (*result_1 == 1) {
            printf("YES, It is a Prime number\n");
        } else {
            printf("NO, It is not a Prime number\n");
        }
    } else if (calc_1_arg.choice == 7) {
        if (*result_1 == 1) {
            printf("YES, Both numbers are either even or odd\n");
        } else {
            printf("NO, One number is even and the other one is odd\n");
        }
    }

    clnt_destroy(clnt);
}

int main(int argc, char *argv[]) {
    char *host;
    if (argc < 2) {
        printf("Usage: %s server_host\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    calc_prg_1(host);
    exit(0);
}