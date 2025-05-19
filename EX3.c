#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {
    char dados[TAM][50];
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

void copiarString(char *destino, const char *origem) {
    int i = 0;
    while (origem[i] != '\0' && i < 49) {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

void push(Pilha *p, char *valor) {
    if (!cheia(p)) {
        p->topo++;
        copiarString(p->dados[p->topo], valor);
    }
}

char* pop(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[p->topo--];
    }
    return NULL;
}

int main() {
    Pilha undo, redo;
    char comando[50], texto[50], atual[50] = "";
    inicializar(&undo);
    inicializar(&redo);

    while (1) {
        printf("Digite comando (digitar, undo, redo, mostrar, sair): ");
        scanf("%s", comando);

        if (strcmp(comando, "digitar") == 0) {
            printf("Digite texto: ");
            scanf(" %[^\n]", texto);
            push(&undo, atual);
            copiarString(atual, texto);
            inicializar(&redo);
        } else if (strcmp(comando, "undo") == 0) {
            if (!vazia(&undo)) {
                push(&redo, atual);
                copiarString(atual, pop(&undo));
            } else {
                printf("Nada para desfazer.\n");
            }
        } else if (strcmp(comando, "redo") == 0) {
            if (!vazia(&redo)) {
                push(&undo, atual);
                copiarString(atual, pop(&redo));
            } else {
                printf("Nada para refazer.\n");
            }
        } else if (strcmp(comando, "mostrar") == 0) {
            printf("Texto atual: %s\n", atual);
        } else if (strcmp(comando, "sair") == 0) {
            break;
        } else {
            printf("Comando inválido.\n");
        }
    }
    return 0;
}
