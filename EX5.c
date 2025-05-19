#include <stdio.h>
#define TAM 100

typedef struct {
    int dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == TAM - 1;
}

void push(Pilha *p, int valor) {
    if (!cheia(p)) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

int pop(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[p->topo--];
    }
    return -1; 
}

int topo(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[p->topo];
    }
    return -1;
}

void ordenarPilha(Pilha *orig) {
    Pilha aux;
    inicializar(&aux);

    while (!vazia(orig)) {
        int temp = pop(orig);

        while (!vazia(&aux) && topo(&aux) > temp) {
            push(orig, pop(&aux));
        }

        push(&aux, temp);
    }

 
    while (!vazia(&aux)) {
        push(orig, pop(&aux));
    }
}

void mostrar(Pilha *p) {
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar(&p);

  
    push(&p, 3);
    push(&p, 1);
    push(&p, 4);
    push(&p, 2);
    push(&p, 5);

    printf("Pilha original:\n");
    mostrar(&p);

    ordenarPilha(&p);

    printf("Pilha ordenada (crescente):\n");
    mostrar(&p);

    return 0;
}
