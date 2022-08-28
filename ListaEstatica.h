#ifndef LISTA_ESTATICA_
#define LISTA_ESTATICA_
#include <iostream>

using namespace std;

template<typename T, int MAX>
struct ListaE {
	T elementos[MAX];
	int tamanho;
	void insert(int pos, T dado){
		if(pos > this->tamanho || pos < 0){
			throw "Erro de Indice";
		}
		else if(this->tamanho == pos){
			this->elementos[this->tamanho] = dado;
			this->tamanho++;
		}
		else{
			for (int i = this->tamanho; i > pos; i--) {
				this->elementos[i] = this->elementos[i - 1];
			}
			this->elementos[pos] = dado;
			this->tamanho++;
		}
	}

	void remove(int pos){
		if(pos > this->tamanho || pos < 0){
			throw "Posição inválida";
		}
		else if(pos == this->tamanho){
			this->tamanho--;
		}
		else{
			for (int i = pos; i < this->tamanho; i++) {
			this->elementos[i] = this->elementos[i + 1];
		}
			this->tamanho--;
		}
	}

	T& at(int pos) {
		if(pos > this->tamanho || pos < 0){
			throw "Posição inválida";
		}
		else{
			return this->elementos[pos];
		}
	}

	T& operator[](int pos){
        return this->at(pos);
    }

	bool contains(T dado) {
		for (int i = 0; i < this->tamanho; i++) {
			if (this->elementos[i] == dado) {
				return true;
			}
		}
		return false;
	}

	int find(T dado) {
		for (int i = 0; i < this->tamanho; i++) {
			if (this->elementos[i] == dado) {
				return i;
			}
		}
		return -1;
	}

	ListaE(){
		this->tamanho = 0;
	}

	void print() {
		for (int i = 0; i < this->tamanho; i++) {
			cout << " " << this->elementos[i].nome << " " << this->elementos[i].pontuacao << endl;
		}
	}
};

#endif