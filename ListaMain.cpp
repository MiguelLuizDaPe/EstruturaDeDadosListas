#include <iostream>
#include "Listas.h"
#include "Ordenar.h"
#include "Ranking.h"
#define MAX_JOGADORES 200

#ifdef _WIN32
#define PAUSE(msg) system("pause")
#define CLEAR() system("cls")
#else
#define PAUSE(msg) system("echo " msg " ; read _")
#define CLEAR() system("clear")
#endif

enum TipoLista{ ENCS, ENCD };

int main()
{
    srand(time(NULL));

    TipoLista tipo_lista = ENCD;//variavel que funciona como menu
    int top = 5;                //variavel que funciona como o top N
    int rodadas = 5;               

    if(tipo_lista == ENCS){
        Lista::Encadeada<Jogador> l;
        int num_de_jogadores = (rand() % MAX_JOGADORES) + 20;

        for (int i = 0; i < num_de_jogadores; i++) {
            try{
                l.insert(i, criar_jogador());
            }
            catch(char const* x){
                std::cout << x << std::endl;
            }
        }
        for(int i = 0; i < rodadas; i++){
            bubble_sort(l);
            l.print();
            std::cout << "--------------------" << std::endl;
            try{
                Lista::Estatica<Jogador, 10> listaTop = OsTop(l, top);
                listaTop.print();    
            }
            catch(const char *x){
                std::cout << x << std::endl;
            }
            Round(l);
            PAUSE("Pressione qualquer tecla para continuar...");
        }
        
    }
    if(tipo_lista == ENCD){
        Lista::Encadeada2<Jogador> l;
        int num_de_jogadores = (rand() % MAX_JOGADORES) + 20;

        for (int i = 0; i < num_de_jogadores; i++) {
            try{
                l.insert(i, criar_jogador());
            }
            catch(char const* x){
                std::cout << x << std::endl;
            }
        }
        for(int i = 0; i < rodadas; i++){
            bubble_sort(l);
            l.print();
            std::cout << "--------------------" << std::endl;
            try{
                Lista::Estatica<Jogador, 10> listaTop = OsTop(l, top);
                listaTop.print();    
            }
            catch(const char *x){
                std::cout << x << std::endl;
            }
            Round(l);
            PAUSE("Pressione qualquer tecla para continuar...");
        }

    }
}
