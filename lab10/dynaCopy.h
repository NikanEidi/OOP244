
//Nikan Eidi
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include <iostream>

namespace seneca {

    // Two-Argument dynaCopy
    template <typename T>
    T* dynaCopy(const T* src, int size) {
        T* dest = new T[size];
        for (int i = 0; i < size; i++) {
            dest[i] = src[i];
        }
        return dest;
    }

    // Three-Argument dynaCopy 
    template <typename T>
    T* dynaCopy(T*& dest, const T* src, int size) {
        delete[] dest;
        dest = new T[size];
        for (int i = 0; i < size; i++) {
            dest[i] = src[i];
        }
        return dest;
    }

    // prnArray
    template <typename T>
    void prnArray(const T* arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

} // namespace seneca

#endif // !SENECA_DYNACOPY_H
