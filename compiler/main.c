#include <stdio.h>
#include "helpers/vector.h" 
#include "helpers/buffer.h"
#include "test.h"



int main() {
    print_brazil_flag();

    printf("╔════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                        ║\n");
    printf("║  Compiladores - TURMA B - GRUPO 2                                      ║\n");
    printf("║                                                                        ║\n");

    // Criação do vetor
    printf("║  Criando o vetor...                                                    ║\n");
    Vector vec = vector_create();
    printf("║  Vetor criado com sucesso!                                             ║\n");
    printf("║                                                                        ║\n");

    // Adição de elementos
    printf("║  Adicionando elementos ao vetor...                                     ║\n");
    vector_push(&vec, 10);
    printf("║  Valor 10 adicionado.                                                  ║\n");
    vector_push(&vec, 20);
    printf("║  Valor 20 adicionado.                                                  ║\n");
    vector_push(&vec, 30);
    printf("║  Valor 30 adicionado.                                                  ║\n");
    printf("║                                                                        ║\n");

    // Consultando o topo do vetor
    printf("║  Valor no topo do vetor (peek): %d                                     ║\n", vector_peek(&vec));
    printf("║                                                                        ║\n");

    // Mudando o ponteiro peek
    printf("║  Mudando o ponteiro peek para o índice 1...                            ║\n");
    vector_set_peek_pointer(&vec, 1);
    printf("║  Ponteiro peek alterado.                                               ║\n");
    printf("║                                                                        ║\n");

    // Consultando o novo topo
    printf("║  Valor no topo do vetor após mudança do ponteiro (peek): %d            ║\n", vector_peek(&vec));
    printf("║                                                                        ║\n");

    // Removendo elementos
    printf("║  Removendo elementos do vetor...                                       ║\n");
    printf("║  Valor removido do vetor (pop): %d                                     ║\n", vector_pop(&vec));
    printf("║  Valor removido do vetor (pop): %d                                     ║\n", vector_pop(&vec));
    printf("║  Valor removido do vetor (pop): %d                                     ║\n", vector_pop(&vec));
    printf("║                                                                        ║\n");

    printf("╚════════════════════════════════════════════════════════════════════════╝\n");
    return 0;
}

/*
int main() {
    printf("Compiladores - TURMA B - GRUPO 2\n");

    // Teste das funções do vetor
    Vector vec = vector_create();
    vector_push(&vec, 10);
    vector_push(&vec, 20);
    vector_push(&vec, 30);

    printf("Valor no topo do vetor (peek): %d\n", vector_peek(&vec));  // Saída: 10

    vector_set_peek_pointer(&vec, 1);
    printf("Valor no topo após mudança do ponteiro (peek): %d\n", vector_peek(&vec));  // Saída: 20

    printf("Valor removido do vetor (pop): %d\n", vector_pop(&vec));  // Saída: 30
    printf("Valor removido do vetor (pop): %d\n", vector_pop(&vec));  // Saída: 20
    printf("Valor removido do vetor (pop): %d\n", vector_pop(&vec));  // Saída: 10

    return 0;
}
*/