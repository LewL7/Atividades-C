#include <stdio.h>
#include <stdlib.h>

main(void){

    int nmr1, nmr2, op;

    printf("Digite 1 para somar ou 2 para subtrair: \n");
    scanf("%d", &op);

    printf("Digite o primeiro numero: \n");
    scanf("%d", &nmr1);

    printf("Digite o segundo numero: \n");
    scanf("%d", &nmr2);

    if (op == 1){

        nmr1 = nmr1 + nmr2;

        printf("O resultado da soma é: %d", nmr1);
    
    }
    else{
        nrm1 = nmr1 = nmr2;

        printf("O resultado da subtração é: %d", nmr1)
    }

    return 0;
}