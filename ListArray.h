#include <ostream>
#include "List.h"
#include <algorithm>
#include <stdexcept>

template <typename T> 
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* newArr = new T[new_size];
        std::copy(arr, arr + n, newArr);
        delete[] arr;
        arr = newArr;
        max = new_size;
    }

public:
    ListArray() {
        arr = new T[MINSIZE];
        n = 0;
        max = MINSIZE;
    }

    ~ListArray() {
        delete[] arr;
        arr = nullptr;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango\n");

        if (n >= max)
            resize(2 * max);

        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        if (n >= max)
            resize(2 * max);
        arr[n++] = e;
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango\n");

        T eliminado = arr[pos];
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;
        return eliminado;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango\n");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e)
                return i;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T& operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");
        return arr[pos];
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ListArray<U>& list);
};

// Operador <<
template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
    out << "[";
    for (int i = 0; i < list.n; i++) {
        out << list.arr[i];
        if (i < list.n - 1)
            out << ", ";
    }
    out << "]";
    return out;
}

