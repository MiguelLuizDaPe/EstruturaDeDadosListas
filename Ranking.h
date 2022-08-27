#ifndef RANKING
#define RANKING

#include <iostream>

struct Jogador {
    std::string nome;
    int pontuacao;
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



#endif
