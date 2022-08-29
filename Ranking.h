#ifndef RANKING
#define RANKING

#include <iostream>
#include "Listas.h"

struct Jogador {
    std::string nome;
    int pontuacao;
    bool operator==(const Jogador &temp){
        return (this->nome == temp.nome && this->pontuacao == temp.pontuacao);
    }
    bool operator!=(const Jogador &temp){
        return !(this->nome == temp.nome && this->pontuacao == temp.pontuacao);
    }
};

Jogador criar_jogador() {

    Jogador jogador;
    std::string silabas[75] = { "a", "ti", "si", "cu", "ta", "ca", "tu", "na", "ri", "ma", "mi", "o", "ni", "da", "la", "de", "te", "to"
    , "e", "co", "ru", "fi", "i", "pi", "pa", "bi", "nu", "mu", "ba", "zi", "ga", "es", "se", "sa", "me", "mo", "lo", "no", "pe"
    , "lu", "po", "ar", "dor", "su", "vas", "vi", "le", "ro", "fla", "ne", "va", "fa", "bu", "tri", "so", "do", "bo", "cra", "gu"
    , "gra", "tra", "do", "fo", "pu", "us", "bro", "les", "fo", "fa", "gus", "vo", "go", "fu", "pro", "pre" };

    int numSílabas = rand() % 3;
    jogador.nome = silabas[rand() % 75] + silabas[rand() % 75];
    for (int j = 0; j < numSílabas; j++) {
        jogador.nome += silabas[rand() % 75];
    }
    jogador.pontuacao = rand() % 10001;
    return jogador;
}

Lista::Estatica<Jogador, 10> OsTop(Lista::Encadeada<Jogador> ListEncSimp, int pos){
    Lista::Estatica<Jogador, 10> ListEst;
    Lista::Node<Jogador> *nav = ListEncSimp.head;
    if(nav == nullptr){
        throw "Lista vazia(ostop encadeada simples)";
    }
	int counter = 0;
	while(nav->next != nullptr && counter < pos){
        ListEst[counter] = ListEncSimp[counter];
        ListEst.tamanho++;
		nav = nav->next;
		counter++;
	}
    return ListEst;
}

Lista::Estatica<Jogador, 10> OsTop(Lista::Encadeada2<Jogador> ListEncDup, int pos){
    Lista::Estatica<Jogador, 10> ListEst;
    Lista::Node2<Jogador> *nav = ListEncDup.head;
    if(nav == nullptr){
        throw "Lista vazia(ostop encadeada dupla)";
    }
	int counter = 0;
	while(nav->next != nullptr && counter < pos){
        ListEst[counter] = ListEncDup[counter];
        ListEst.tamanho++; 
		nav = nav->next;
		counter++;
	}
    return ListEst;
}

void Round(Lista::Encadeada<Jogador> &l){
	Lista::Node<Jogador> *nav = l.head;
    if(nav == nullptr){
        throw "Lista vazia(rounds encadeada simples)";
    }
    int pontAle = 0;
    int counter = 0;
    int pos = 10; // pq vai variar entre os 10 primeiros
    while(nav->next != nullptr && counter < pos){
        pontAle = (rand() % 101) + 100; //pra gerar um numero entre 100 e 200
        l[counter].pontuacao += pontAle;
        nav = nav->next;
        counter++;
    }
    pos = l.size(); // pra variar no resto
    while(nav->next != nullptr && counter < pos){
        pontAle = (rand() % 501) + 500; //pra gerar um numero entre 500 e 1000
        l[counter].pontuacao += pontAle;
        nav = nav->next;
        counter++;
    }
    pontAle = (rand() % 501) + 500; //pra gerar um numero entre 500 e 1000
    l[counter].pontuacao += pontAle;
}

void Round(Lista::Encadeada2<Jogador> &l){
	Lista::Node2<Jogador> *nav = l.head;
    if(nav == nullptr){
        throw "Lista vazia(rounds encadeada dupla)";
    }
    int pontAle = 0;
    int counter = 0;
    int pos = 10; // pq vai variar entre os 10 primeiros
    while(nav->next != nullptr && counter < pos){
        pontAle = (rand() % 101) + 100; //pra gerar um numero entre 100 e 200
        l[counter].pontuacao += pontAle;
        nav = nav->next;
        counter++;
    }
    pos = l.size(); // pra variar no resto
    while(nav->next != nullptr && counter < pos){
        pontAle = (rand() % 501) + 500; //pra gerar um numero entre 500 e 1000
        l[counter].pontuacao += pontAle;
        nav = nav->next;
        counter++;
    }
    pontAle = (rand() % 501) + 500;
    l[counter].pontuacao += pontAle;
}

#endif
