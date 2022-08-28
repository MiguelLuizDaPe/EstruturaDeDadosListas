#include <iostream>
#include "ListaEstatica.h"
// #include "structs.h"
#include "ListaEncadeadaDupla.h"
#include "ListaEncadeada.h"
#include "Ranking.h"


int main()
{
    srand(time(NULL));
    int num_de_jogadores = rand() % 51;

    Lista2::List<Jogador> l;

    for (int i = 0; i < num_de_jogadores; i++) {
        try{
            l.insert(i, criar_jogador());
        }
        catch(char const* x){
            std::cout << x << std::endl;
        }
    }
    l.print();
}
