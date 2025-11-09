#include <ostream>
#include "List.h"
#include "Node.h"
//#include "ListArray.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	Node<T>* first;
	int n;
	
    public:

     void insert(int pos, T e) override {
    if (pos < 0 || pos > n)
        throw std::out_of_range("Posición fuera de rango\n");

    // Caso: insertar al principio
    if (pos == 0) {
        first = new Node<T>(e, first);
    } else {
        // Avanza hasta el nodo anterior a la posición
        Node<T>* prev = first;
        for (int i = 0; i < pos - 1; i++)
            prev = prev->next;

        // Inserta el nuevo nodo
        prev->next = new Node<T>(e, prev->next);
    }
    n++;
}

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
   insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango\n");

        Node<T>* eliminado;
        T valor;

        // Caso: eliminar el primero
        if (pos == 0) {
            eliminado = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            eliminado = prev->next;
            prev->next = eliminado->next;
        }

        valor = eliminado->data;
        delete eliminado;
        n--;

        return valor;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango\n");
        Node<T>* current=first;
	for(int i=0; i<pos; i++){
		current=current->next;
	}
	return current->data;
    }

    int search(T e) override{
	    Node<T>* current=first;
        for (int i = 0; i < n; i++) {
                if (current->data == e)
                     return i;
		current=current->next;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    ListLinked (){
	    first=nullptr;
	    n=0;
    }
    ~ListLinked() {
    Node<T>* aux = first;  // aux apunta al primer nodo

    while (aux != nullptr) {
        Node<T>* temp = aux->next;  // Guarda el siguiente nodo
        delete aux;  // Elimina el nodo actual
        aux = temp;  // Avanza al siguiente nodo
    }

    first = nullptr;  // Finalmente, aseguramos que `first` sea nullptr
    n = 0;  // También aseguramos que el contador de elementos sea 0
}

    T operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posicion fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;  // Devuelve una copia del dato
    }
    
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr)
                out << ", ";
            current = current->next;
        }
        out << "]";
        return out;
    }
};



