#include <ostream>
#include "List.h"
#include <algorithm>
#include <stdexcept>
using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
	T* arr;
	int max;
	int n;
	static const int MINSIZE=2;
	void resize(int new_size){
		T* newArr = new T[new_size];
		copy(arr, arr+max, newArr);
		delete[] arr;
		arr=newArr;
		max=new_size;
	}
        // miembros privados

    public:
	void insert(int pos, T e) override {
		if(pos<0 || pos >= n){
			throw out_of_range("Posición fuera de rango\n");
		}else{
			n++;
			if(n>max){
				resize(2*max);
			}
			int aux1, aux2;
			aux1=arr[pos];
			for(int i=pos+1; i<n; i++){
				aux2=arr[i];
				arr[i]=aux1;
				aux1=aux2;
			}
		}

	}
	void append(T e) override {
		n++;
		if(n>max){
			resize(2*max);
		}
		arr[n-1]=e;
        }
	void prepend(T e) override {
		n++;
                if(n>max){
                	resize(2*max);
		}
                arr[0]=e;
        }
	T remove(int pos) override {
		if(pos<0 || pos>=n){
			throw out_of_range("Posición fuera de rango\n");
		}else{
			for(int i=pos; i<n; i++){
				arr[i]=arr[i+1];
			}
			n--;
		}

        }
	T get(int pos) override {
		if(pos<0 || pos>=n){
			throw out_of_range("Posición fuera de rango\n");
		}else{
			return arr[pos];
		}
        }
	int search(T e) override {
		for(int i=0; i<n; i++){
			if(arr[i]==e){
				return i;
			}
		}
		return -1;
        }
	bool empty() override {
		if(n==0){
			return true;
		}else{
			return false;
		}
        }
	int size() override {
		return n;
        }
	ListArray(){
		arr=new T[MINSIZE];
		n=0;
		max=MINSIZE;
	}
	~ListArray(){
		delete[] arr;
		arr=nullptr;
	}	
	T& operator[](int pos) {
        	if (pos < 0 || pos >= n)
            		throw out_of_range("Posición fuera de rango");
        	return arr[pos];
    	}
	friend ostream& operator<< <T>(ostream& out, const ListArray<T>& list);
        // miembros públicos, incluidos los heredados de List<T>
    
};
