#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo   = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo       = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: lista vazia ou posicao invalida\n");
        return;
    }
    q        = p->Prox;
    *Item    = q->Item;
    p->Prox  = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *Item) {
    TipoApontador p = Lista->Primeiro;
    if(Vazia(*Lista)){
        return;
    }
    while(p->Prox != Lista->Ultimo){
        p = p->Prox;
    }
    *Item = Lista->Ultimo->Item;
    free(Lista->Ultimo);
    Lista->Ultimo = p;
    p->Prox = NULL;
}

void InsereInicio(TipoItem x, TipoLista *Lista) {
    TipoApontador ins;
    ins = (TipoApontador)malloc(sizeof(TipoCelula));
    ins->Item = x;
    ins->Prox = Lista->Primeiro->Prox;
    Lista->Primeiro->Prox = ins;
    if(Lista->Ultimo == Lista->Primeiro){
        Lista->Ultimo = ins;
    }
}

void Inverte(TipoLista *Lista) {
    TipoApontador ant = NULL;
    TipoApontador atual = Lista->Primeiro->Prox;
    TipoApontador prox;
    if(atual == NULL){
        return;
    }
    Lista->Ultimo = atual;
    while(atual != NULL){
        prox = atual->Prox;
        atual->Prox = ant;
        ant = atual;
        atual = prox;
    }
    Lista->Primeiro->Prox = ant;
}

int Tamanho(TipoLista *Lista) {
    int tam = 0;
    TipoApontador p = Lista->Primeiro->Prox;
    while(p != NULL){
        tam++;
        p = p->Prox;
    }
    return tam;
}
