#include <iostream>
#include "Listas.h"
#include "Ordenar.h"
#include "Ranking.h"
#define MAX_JOGADORES 200

enum TipoLista{ EST, ENCS, ENCD};

int main() //criar um gerador de listas
{
    srand(time(NULL));

    TipoLista tl = EST;

    if(tl == EST){
        Lista::Estatica<Jogador, 20000> l;
        int num_de_jogadores = rand() % MAX_JOGADORES;

        for (int i = 0; i < num_de_jogadores; i++) {
            try{
                l.insert(i, criar_jogador());
            }
            catch(char const* x){
                std::cout << x << std::endl;
            }
        }
        bubble_sort<Jogador, 20000>(l);
        l.print();
    }
    if(tl == ENCS){
        Lista::Encadeada<Jogador> l;
        int num_de_jogadores = rand() % MAX_JOGADORES;

        for (int i = 0; i < num_de_jogadores; i++) {
            try{
                l.insert(i, criar_jogador());
            }
            catch(char const* x){
                std::cout << x << std::endl;
            }
        }
        bubble_sort(l);
        l.print();
    }
    if(tl == ENCD){
        Lista::Encadeada2<Jogador> l;
        int num_de_jogadores = rand() % MAX_JOGADORES;

        for (int i = 0; i < num_de_jogadores; i++) {
            try{
                l.insert(i, criar_jogador());
            }
            catch(char const* x){
                std::cout << x << std::endl;
            }
        }
        bubble_sort(l);
        l.print();
    }

    // Lista::List<Jogador> l;
    
}
