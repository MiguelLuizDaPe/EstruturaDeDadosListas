#ifndef INCLUDE_LISTAS_H_
#define INCLUDE_LISTAS_H_

#include <iostream>

namespace Lista {

// Lista estatica
template<typename T, int MAX>
struct Estatica {
	T elementos[MAX];
	int tamanho;
	void insert(int pos, T dado){
		if(pos > this->tamanho || pos < 0){
			throw "Erro de Indice(insert estatica)";
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
			throw "Erro de Indice(remove estatica)";
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
			throw "Erro de Indice(at estatica)";
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

	Estatica(){
		this->tamanho = 0;
	}

	void print(int pos = 0) {
		if(tamanho == 0){
			throw "Lista vazia(estatica)";
		}
		if(pos == 0){
			for (int i = 0; i < this->tamanho; i++) {
				std::cout << this->elementos[i].nome << " " << this->elementos[i].pontuacao << std::endl;
			}
		}
		else{
			for (int i = 0; i < pos; i++) {
				std::cout << " " << this->elementos[i].nome << " " << this->elementos[i].pontuacao << std::endl;
			}
		}
		
	}
};

// Lista Encadeada
template<class T>
struct Node {
	T data;
	Node<T> *next;

	Node(){ this->next = nullptr; }
};

template<class T>
struct Encadeada {
	Node<T> *head;
	void insert(int pos, T data){
		Node<T> *el = new Node<T>;
		el->data = data;
		if(pos == 0){
			el->next = this->head;
			this->head = el;
		}
		else{
			Node<T> *nav = this->head;
			Node<T> *prev_nav = this->head;
			int counter = 0;
			while(nav->next != nullptr && counter < pos){
				prev_nav = nav;  //vai pra posição atual do nav
				nav = nav->next; //vai nav um pra frente
				counter++;
			}
			if(counter == pos){
				el->next = nav;
				prev_nav->next = el;
			}
			else if(counter + 1 == pos){
				prev_nav = nav;
				nav = nav->next;
				el->next = nav;
				prev_nav->next = el;
			}
			else{
				throw "Erro de indice(insert escadeada simples)";
			}
		}

	} // melhor: insert(int pos, const T& data)
	void remove(int pos){
		if(pos == 0){
			Node<T> *del = head;
			head = del->next;
			delete del;
		}
		else{
			Node<T> *nav = this->head;
			Node<T> *prev_nav = this->head;
			int counter = 0;
			while(nav->next != nullptr && counter < pos){
				prev_nav = nav;
				nav = nav->next;
				counter++;
			}
			if(counter == pos){
				Node<T> *del = nav;
				prev_nav->next = nav->next;
				delete del;
			}
			else{
				throw "Erro de indice(remove encadeada simples)";
			}
		}
	}
	T& at(int pos){
		Node<T> *nav = this->head;
		int counter = 0;
		while(nav->next != nullptr && counter < pos){
			nav = nav->next;
			counter++;
		}
		if(counter == pos){
			return nav->data;
		}
		else{
			throw "Erro de indice(at encadeada simples)";
		}
	}
	T& operator[](int pos){
		return this->at(pos);
	}
	bool contains(T data){
		Node<T> *nav = this->head;
		while(nav->next != nullptr){
			if(nav->data == data){
				return true;
			}
			nav = nav->next;
		}
		return nav->data == data;
	}
	int find(T data){
		Node<T> *nav = this->head;
		int counter = 0;
		while(nav->next != nullptr){
			if(nav->data == data){
				break;
			}
			nav = nav->next;
			counter++;
		}
		if(nav->data == data){
			return counter;
		}
		else{
			return -1;
		}
		// se nao tiver o elemento :
		// return not_found;
	}
	int size(){
		auto nav = this->head;
		int n = 0;
		if(this->head == nullptr){
			return 0;
		}
		while(nav->next != nullptr){
			nav = nav->next;
			n++;
		}
		return n + 1;
	}
	void print(int pos = 0){
		if(this->head == nullptr) {
			std::cout << "Lista vazia(encadeada simples)" << std::endl;
		}
		else if(pos == 0){
			auto nav = this->head;
			while(nav->next != nullptr){
				std::cout << nav->data.nome << " " << nav->data.pontuacao << std::endl;
				nav = nav->next;
			}
			std::cout << nav->data.nome << " " << nav->data.pontuacao << std::endl;//pois ele n imprime o ultimo no loop
		}
		else{
			auto nav = this->head;
			int counter = 0;
			while(nav->next != nullptr && counter < pos){
				std::cout << nav->data.nome << " " << nav->data.pontuacao << std::endl;
				nav = nav->next;
				counter++;
			}
		}
	}

	Encadeada(){ this->head = nullptr; }
};
// Encadeada Dupla

template<class T>
struct Node2 {
	T data;
	Node2<T> *next;

	Node2(){ this->next = nullptr; }
};

template<class T>
struct Encadeada2 {
	Node2<T> *head;
	void insert(int pos, T data){
		Node2<T> *el = new Node2<T>;
		el->data = data;
		if(pos == 0){
			el->next = this->head;
			this->head = el;
		}
		else{
			Node2<T> *nav = this->head;
			Node2<T> *prev_nav = this->head;
			int counter = 0;
			while(nav->next != nullptr && counter < pos){
				prev_nav = nav;  //vai pra posição atual do nav
				nav = nav->next; //vai nav um pra frente
				counter++;
			}
			if(counter == pos){
				el->next = nav;
				prev_nav->next = el;
			}
			else if(counter + 1 == pos){
				prev_nav = nav;
				nav = nav->next;
				el->next = nav;
				prev_nav->next = el;
			}
			else{
				throw "Erro de indice(insert encadeada dupla)";
			}
		}

	} // melhor: insert(int pos, const T& data)
	void remove(int pos){
		if(pos == 0){
			Node2<T> *del = head;
			head = del->next;
			delete del;
		}
		else{
			Node2<T> *nav = this->head;
			Node2<T> *prev_nav = this->head;
			int counter = 0;
			while(nav->next != nullptr && counter < pos){
				prev_nav = nav;
				nav = nav->next;
				counter++;
			}
			if(counter == pos){
				Node2<T> *del = nav;
				prev_nav->next = nav->next;
				delete del;
			}
			else{
				throw "Erro de indice(remove encadeada dupla)";
			}
		}
	}
	T& at(int pos){
		Node2<T> *nav = this->head;
		int counter = 0;
		while(nav->next != nullptr && counter < pos){
			nav = nav->next;
			counter++;
		}
		if(counter == pos){
			return nav->data;
		}
		else{
			throw "Erro de indice(at encadeada dupla)";
		}
	}
	T& operator[](int pos){
		return this->at(pos);
	}
	bool contains(T data){
		Node2<T> *nav = this->head;
		while(nav->next != nullptr){
			if(nav->data == data){
				return true;
			}
			nav = nav->next;
		}
		return nav->data == data;
	}
	int find(T data){
		Node2<T> *nav = this->head;
		int counter = 0;
		while(nav->next != nullptr){
			if(nav->data == data){
				break;
			}
			nav = nav->next;
			counter++;
		}
		if(nav->data == data){
			return counter;
		}
		else{
			return -1;
		}
		// se nao tiver o elemento :
		// return not_found;
	}
	int size(){
		auto nav = this->head;
		int n = 0;
		if(this->head == nullptr){
			return 0;
		}
		while(nav->next != nullptr){
			nav = nav->next;
			n++;
		}
		return n + 1;
	}
	void print(int pos = 0){
		if(this->head == nullptr) {
			std::cout << "Lista vazia(encadeada dupla)" << std::endl;
		}
		else if(pos == 0){
			auto nav = this->head;
			while(nav->next != nullptr){
				std::cout << nav->data.nome << " " << nav->data.pontuacao << std::endl;
				nav = nav->next;
			}
			std::cout << nav->data.nome << " " << nav->data.pontuacao << std::endl;//pois ele n imprime o ultimo no loop
		}
		else{
			auto nav = this->head;
			int counter = 0;
			while(nav->next != nullptr && counter < pos){
				std::cout << nav->data.nome << " " << nav->data.pontuacao << std::endl;
				nav = nav->next;
				counter++;
			}
		}
	}

	Encadeada2(){ this->head = nullptr; }
};

} // namespace List

#endif // INCLUDE_LISTAS_H_
