#ifndef ORDENAR_
#define ORDENAR_

#include <iostream>
#include "Ranking.h"
#include "ListaEstatica.h"
#include "EncadeadaDupla.h"
#include "EncadeadaSimples.h"

template<typename T, int MAX>
void bubble_sort_estatica(ListaE<Jogador, MAX>& l) {
    int i, j;
    Jogador temp;
    for (i = 0; i < l.tamanho; i++) {
        for (j = i + 1; j < l.tamanho; j++)
        {
            if (l[j].pontuacao > l[i].pontuacao) {
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }
}

void bubble_sort_encadeada_simples(Lista::List<Jogador>& l) {
    int i, j;
    Jogador temp;
    for (i = 0; i < l.size(); i++) {
        for (j = i + 1; j < l.size(); j++)
        {
            if (l[j].pontuacao > l[i].pontuacao) {
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }
}

void bubble_sort_encadeada_dupla(Lista2::List<Jogador>& l) {
    int i, j;
    Jogador temp;
    for (i = 0; i < l.size(); i++) {
        for (j = i + 1; j < l.size(); j++)
        {
            if (l[j].pontuacao > l[i].pontuacao) {
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }
}

#endif