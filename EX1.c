#include <stdio.h>
#define TAM 5

typedef struct {
    int dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int cheia(Pilha *p) {
    return p->topo == TAM - 1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, int valor) {
    if (!cheia(p)) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

int pop(Pilha *p) {
    if (!vazia(p)) {
        int valor = p->dados[p->topo];
        p->topo--;
        return valor;
    }
    return -1;
}

int main() {
    int vetor[TAM], i;
    Pilha pilha;
    
    inicializar(&pilha);
    
    printf("Digite %d números:\n", TAM);
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
    }
    
    for (i = 0; i < TAM; i++) {
        push(&pilha, vetor[i]);
    }
    
    for (i = 0; i < TAM; i++) {
        vetor[i] = pop(&pilha);
    }
    
    printf("Vetor invertido:\n");
    for (i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}
