#ifndef INCLUDE_DOUBLE_LINKED_LIST_HH_
#define INCLUDE_DOUBLE_LINKED_LIST_HH_


#include <cstddef>
#include <iterator>
#include <iostream>

namespace Lista2 {

	// constexpr int not_found = ~0; // MAX_INT

	template<class T>
	struct Node {
		T data;
		Node<T> *next;
		Node<T> *prev;

		Node() {
			this->next = nullptr;
			this->prev = nullptr;
		}

	};

	template<class T>
	struct List {
		Node<T> *head;
		Node<T> *tail;
		void insert(int pos, T data) {
			if (pos == 0) {
				if (this->head == nullptr) { // quando for lista vazia
					Node<T> *el = new Node<T>;
					el->data = data;
					el->next = this->head;
					el->prev = this->tail;
					this->head = el;
					this->tail = el;
				}
				else {
					Node<T> *el = new Node<T>;
					el->data = data;
					el->next = this->head;
					this->head = el;
				}
			}
			else {
				Node<T> *nav = this->head;
				Node<T> *prev_nav = this->head;
				int counter = 0;
				while (nav->next != nullptr && counter < pos) {
					prev_nav = nav;                         //vai pra posição atual do nav
					nav = nav->next;                        //vai nav um pra frente
					counter++;
				}
				if (counter == pos) {
					Node<T> *el = new Node<T>;
					el->data = data;
					el->next = nav;
					prev_nav->next = el;
					el->prev = prev_nav;
					nav->prev = el;
				}
				else if (counter + 1 == pos) {
					prev_nav = nav;
					nav = nav->next;
					Node<T> *el = new Node<T>;
					el->data = data;
					el->next = nav;
					prev_nav->next = el;
					el->prev = prev_nav;
					nav->prev = el;
					this->tail = el;
				}
				else {
					throw "Erro de indice";
				}
			}

		} // melhor: insert(int pos, const T& data)
		void remove(int pos) {
			if (pos == 0) {
				if (this->head->next == nullptr) { // quando for uma lista com um elemento
					Node<T> *del = head;
					this->head = nullptr;
					this->tail = nullptr;
					delete del;
				}
				else {
					Node<T> *del = this->head;
					this->head = del->next;
					delete del;
				}
			}
			else {
				Node<T> *nav = this->head;
				Node<T> *prev_nav = this->head;
				Node<T> *next_nav = this->head->next;
				int counter = 0;
				while (nav->next != nullptr && counter < pos) {
					prev_nav = nav;
					nav = next_nav;
					next_nav = next_nav->next;
					counter++;
				}
				if (counter == pos) {
					if (next_nav == nullptr) {
						Node<T> *del = nav;
						prev_nav->next = nullptr;
						this->tail = prev_nav;
						delete del;
					}
					else {
						Node<T> *del = nav;
						prev_nav->next = next_nav;
						next_nav->prev = prev_nav;
						delete del;
					}
				}
				else {
					throw "Erro de indice";
				}
			}
		}
		T& at(int pos) {
			Node<T> *nav = this->head;
			int counter = 0;
			while (nav->next != nullptr && counter < pos) {
				nav = nav->next;
				counter++;
			}
			if (counter == pos) {
				return nav->data;
			}
			else {
				throw "Erro de indice";
			}
		}
		T& operator[](int pos) {
			return this->at(pos);
		}
		bool contains(T data) {
			Node<T> *nav = this->head;
			while (nav->next != nullptr) {
				if (nav->data == data) {
					return true;
				}
				nav = nav->next;
			}
			return nav->data == data;
		}
		int find(T data) {
			Node<T> *nav = this->head;
			int counter = 0;
			while (nav->next != nullptr) {
				if (nav->data == data) {
					break;
				}
				nav = nav->next;
				counter++;
			}
			if (nav->data == data) {
				return counter;
			}
			else {
				return -1;
			}
			// se nao tiver o elemento :
			// return not_found;
		}
		int size() {
			Node<T> *nav = this->head;
			int n = 0;
			if (this->head == nullptr) {
				return 0;
			}
			while (nav->next != nullptr) {
				nav = nav->next;
				n++;
			}
			return n + 1;
		}

		List() {
			this->head = nullptr;
			this->tail = nullptr;
		}

	};

	template <class T>
	std::ostream& operator<<(std::ostream& os, const Lista2::List<T> &list) {
		if (list.head == nullptr) {
			os << "Lista vazia" << std::endl;
		}
		else {
			auto nav = list.head;
			while (nav->next != nullptr) {
				os << nav->data.nome << " " << nav->data.pontuacao << " ";
				nav = nav->next;
			}
			os << nav->data.nome << " " << nav->data.pontuacao;
			os << std::endl;
		}
		return os;
	}

}

#endif
