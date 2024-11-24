#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, answer, score = 0;
    char operation;
    
    srand(time(NULL));
    
    printf("Bem-vindo ao jogo de tabuada!\n");
    printf("Você terá que adivinhar qual operação resulta no valor dado.\n");
    
    while (1) {
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;
        result = num1 * num2;
        
        printf("\n%d %c %d = ?\n", num1, '*', num2);
        printf("Qual é o resultado? (Digite -1 para sair) ");
        scanf("%d", &answer);
        
        if (answer == -1) {
            printf("Obrigado por jogar! Sua pontuação final é %d.\n", score);
            break;
        }
        
        if (answer == result) {
            printf("Resposta correta!\n");
            score++;
        } else {
            printf("Resposta incorreta. A resposta correta é %d.\n", result);
        }
    }
    
    return 0;
}

