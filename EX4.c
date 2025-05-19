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

void removerPares(Pilha *original) {
    Pilha temp;
    inicializar(&temp);

    while (!vazia(original)) {
        int valor = pop(original);
        if (valor % 2 != 0) {
            push(&temp, valor);
        }
    }

 
    while (!vazia(&temp)) {
        push(original, pop(&temp));
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

    push(&p, 2);
    push(&p, 5);
    push(&p, 8);
    push(&p, 3);
    push(&p, 6);
    push(&p, 7);

    printf("Pilha original:\n");
    mostrar(&p);

    removerPares(&p);

    printf("Pilha após remover os pares:\n");
    mostrar(&p);

    return 0;
}
