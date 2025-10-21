#include <ostream>

template <typename T> 
class Node {
    public:
	    T data;
	    Node<T>* next;
	    Node(T data, Node<T>* next){
		    this->data=data;
		    this->next=next;
	     }
	    Node(T data){
		    this->data=data;
		    this->next=nullptr;
	    }
	    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;  // Solo imprime el atributo data
        return out;
    }
        // miembros públicos
    
};
