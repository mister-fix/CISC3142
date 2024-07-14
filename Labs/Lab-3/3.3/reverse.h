#include <iostream>

using namespace std;

// Reverse function
template <typename T> void reverse(T arr[], int size) {
    for(int i = 0, j = size - 1; i < size / 2; i++,j--) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Print function
template <typename T> void print(T arr[], int size) {
	cout << "{";

    for(int i = 0; i < size; i++) {
        std::cout << arr[i];

        if(i != size - 1) cout << ", ";
    }

    cout << "}";
};
