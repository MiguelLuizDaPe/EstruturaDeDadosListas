#ifndef LISTA_ESTATICA_
#define LISTA_ESTATICA_
// #include "structs.h"
#include <iostream>

using namespace std;

template<typename T>
struct Elemento {
	T dado;
};

template<typename T, int MAX>
struct ListaE {
	Elemento<T> elementos[MAX];
	int tamanho;
};

template <typename T,int MAX>
ostream& operator<<(ostream& os, const ListaE<T, MAX> &list) {
    if(list.len == 0) {
        os << "Lista vazia" << endl;
    } else {
        for(int i = 0; i < list.tamanho; i++) {
            os << "Lista[" << i << "]: " << list.dado.nome << "" << list.dado.pontuacao << endl;
        }
    }
    return os;
}

template<typename T, int MAX>
void inicializarE(ListaE<T, MAX>& lista) {
	lista.tamanho = 0;
}

template<typename T, int MAX>//Juntei tudo as função pra ser um só inserir
void inserirE(ListaE<T, MAX>& lista, T dado, int pos){
    if(pos > lista.tamanho || pos < 0){
        throw "Posição inválida";
    }
    else if(lista.tamanho == pos){
        lista.elementos[lista.tamanho].dado = dado;
	    lista.tamanho++;
    }
    else{
        for (int i = lista.tamanho; i > pos; i--) {
		    lista.elementos[i].dado = lista.elementos[i - 1].dado;
	    }
	    lista.elementos[pos].dado = dado;
	    lista.tamanho++;
    }
}


// template<typename T, int MAX>
// void inserir_finalE(Lista<T, MAX>& lista, T dado) {
// 	lista.elementos[lista.tamanho].dado = dado;
// 	lista.tamanho++;
// }

// template<typename T, int MAX>
// void inserir_posicaoE(Lista<T, MAX>& lista, T dado, int pos) {
// 	for (int i = lista.tamanho; i > pos; i--) {
// 		lista.elementos[i].dado = lista.elementos[i - 1].dado;
// 	}
// 	lista.elementos[pos].dado = dado;
// 	lista.tamanho++;
// }

// template<typename T, int MAX>
// void inserir_inicioE(Lista<T, MAX>& lista, T dado){
// 	inserir_posicaoE(lista, dado, 0);
// }


template<typename T, int MAX>//Juntei tudo as função pra fazer um só que é remover
void removerE(ListaE<T, MAX>& lista, int pos){
    if(pos > lista.tamanho || pos < 0){
        throw "Posição inválida";
    }
    else if(pos == lista.tamanho){
        lista.tamanho--;
    }
    else{
        for (int i = pos; i < lista.tamanho; i++) {
		    lista.elementos[i].dado = lista.elementos[i + 1].dado;
	    }
	    lista.tamanho--;
    }
}


// template<typename T, int MAX>
// void remover_finalE(Lista<T, MAX>& lista) {
// 	lista.tamanho--;
// }

// template<typename T, int MAX>
// void remover_posicaoE(Lista<T, MAX>& lista, int pos) {
// 	for (int i = pos; i < lista.tamanho; i++) {
// 		lista.elementos[i].dado = lista.elementos[i + 1].dado;
// 	}
// 	lista.tamanho--;
// }

// template<typename T, int MAX>
// void remover_inicioE(Lista<T, MAX>& lista) {
// 	for (int i = 0; i < lista.tamanho; i++) {
// 		lista.elementos[i].dado = lista.elementos[i + 1].dado;
// 	}
// 	lista.tamanho--;
// }


template<typename T, int MAX>
T obter_itemE(ListaE<T, MAX>& lista, int pos) {
    if(pos > lista.tamanho || pos < 0){
        throw "Posição inválida";
    }
    else{
        return lista.elementos[pos].dado;
    }
}

template<typename T, int MAX>
bool contemE(ListaE<T, MAX>& lista, T dado) {
	for (int i = 0; i < lista.tamanho; i++) {
		if (lista.elementos[i].dado == dado) {
			return true;
		}
	}
	return false;
}

template<typename T, int MAX>
T obter_posicaoE(ListaE<T, MAX>& lista, T dado) {
	for (int i = 0; i < lista.tamanho; i++) {
		if (lista.elementos[i].dado == dado) {
			return i;
		}
	}
	return -1;
}

template<typename T, int MAX>
void imprimirE(ListaE<T, MAX>& lista) {
	for (int i = 0; i < lista.tamanho; i++) {
		cout << " " << lista.elementos << endl;
	}
}

#endif
