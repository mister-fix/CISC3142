#include <iostream>

using namespace std;

template <typename T> class Simple {
    public:
        Simple(T n) {
            val = n;
        }

        void setVal(T a);

        void print();
        
        T getVal() { return val; }

    private:
        T val;
};

template <typename T> void Simple<T>::setVal(T n) {
    val = n;
}

template <typename T> void Simple<T>::print() {
    cout << val;
}