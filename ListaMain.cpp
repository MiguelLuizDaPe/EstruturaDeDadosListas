#include <iostream>
#include "ListaEstatica.h"
#include "Ordenar.h"
#include "ListaEncadeadaDupla.h"
#include "ListaEncadeada.h"
#include "Ranking.h"
#define MAX_JOGADORES 200

int main()
{
    srand(time(NULL));
    int num_de_jogadores = rand() % MAX_JOGADORES;

    // Lista::List<Jogador> l;
    ListaE<Jogador, 20000> l;


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
