#include <stdio.h>

// Protótipos das funções
float mediaTurma(int alunos[], int tamanho);
float mediaEscola(int turmas);

// Função principal (main)
int main() {
    int turmas;

    // Solicitar ao usuário o número de turmas
    printf("Digite o número de turmas: ");
    scanf("%d", &turmas);

    // Chamar a função para calcular a média geral da escola
    float media_geral = mediaEscola(turmas);

    // Exibir a média geral da escola
    printf("A média geral das turmas é: %.2f\n", media_geral);

    return 0;
}

// Função para calcular a média dos alunos de uma turma
float mediaTurma(int alunos[], int tamanho) {
    int total = 0;
    
    // Somar a quantidade de alunos da turma
    for (int i = 0; i < tamanho; i++) {
        total += alunos[i];
    }

    // Retornar a média da turma
    return (float) total / tamanho;
}

// Função para calcular a média de todas as turmas da escola
float mediaEscola(int turmas) {
    int alunos[100];  // Vetor para armazenar a quantidade de alunos por turma
    float media_geral = 0;

    // Para cada turma, solicitar o número de alunos e calcular a média de cada turma
    for (int i = 0; i < turmas; i++) {
        int tamanho_turma;
        
        // Solicitar o número de alunos da turma
        printf("Digite o número de alunos da turma %d: ", i + 1);
        scanf("%d", &tamanho_turma);

        // Solicitar as notas dos alunos para calcular a média da turma
        printf("Digite as notas dos %d alunos da turma %d:\n", tamanho_turma, i + 1);
        for (int j = 0; j < tamanho_turma; j++) {
            printf("Nota do aluno %d: ", j + 1);
            scanf("%d", &alunos[j]);
        }

        // Calcular a média da turma usando a função mediaTurma
        float media_turma = mediaTurma(alunos, tamanho_turma);
        printf("A média da turma %d é: %.2f\n", i + 1, media_turma);

        // Somar a média de cada turma para calcular a média geral
        media_geral += media_turma;
    }

    // Retornar a média geral das turmas (dividido pelo número de turmas)
    return media_geral / turmas;
}
