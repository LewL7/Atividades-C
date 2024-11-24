#include <stdio.h>

// Prot�tipos das fun��es
float mediaTurma(int alunos[], int tamanho);
float mediaEscola(int turmas);

// Fun��o principal (main)
int main() {
    int turmas;

    // Solicitar ao usu�rio o n�mero de turmas
    printf("Digite o n�mero de turmas: ");
    scanf("%d", &turmas);

    // Chamar a fun��o para calcular a m�dia geral da escola
    float media_geral = mediaEscola(turmas);

    // Exibir a m�dia geral da escola
    printf("A m�dia geral das turmas �: %.2f\n", media_geral);

    return 0;
}

// Fun��o para calcular a m�dia dos alunos de uma turma
float mediaTurma(int alunos[], int tamanho) {
    int total = 0;
    
    // Somar a quantidade de alunos da turma
    for (int i = 0; i < tamanho; i++) {
        total += alunos[i];
    }

    // Retornar a m�dia da turma
    return (float) total / tamanho;
}

// Fun��o para calcular a m�dia de todas as turmas da escola
float mediaEscola(int turmas) {
    int alunos[100];  // Vetor para armazenar a quantidade de alunos por turma
    float media_geral = 0;

    // Para cada turma, solicitar o n�mero de alunos e calcular a m�dia de cada turma
    for (int i = 0; i < turmas; i++) {
        int tamanho_turma;
        
        // Solicitar o n�mero de alunos da turma
        printf("Digite o n�mero de alunos da turma %d: ", i + 1);
        scanf("%d", &tamanho_turma);

        // Solicitar as notas dos alunos para calcular a m�dia da turma
        printf("Digite as notas dos %d alunos da turma %d:\n", tamanho_turma, i + 1);
        for (int j = 0; j < tamanho_turma; j++) {
            printf("Nota do aluno %d: ", j + 1);
            scanf("%d", &alunos[j]);
        }

        // Calcular a m�dia da turma usando a fun��o mediaTurma
        float media_turma = mediaTurma(alunos, tamanho_turma);
        printf("A m�dia da turma %d �: %.2f\n", i + 1, media_turma);

        // Somar a m�dia de cada turma para calcular a m�dia geral
        media_geral += media_turma;
    }

    // Retornar a m�dia geral das turmas (dividido pelo n�mero de turmas)
    return media_geral / turmas;
}
