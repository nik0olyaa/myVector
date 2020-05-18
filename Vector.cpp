#include "Vector.h"
#include <string>
#include <sstream>

using namespace std;

template <typename T>
Vector<T>::Vector(int size) {
    if (size>0)
        this->size=size;
    else
        this->size=3;
    this->vectorPtr = new T[this->size];

    for (int i = 0; i < this->size; i++) {
        this->vectorPtr[i] = 0;
    }
}

template <typename T>
Vector<T>::Vector(Vector& v) {
    this->size = v.size;
    for (int i = 0; i < v.size; i++) {
        this->vectorPtr[i] = v.vectorPtr[i];
    }
}

template <typename T>
int Vector<T>::getSize() {
    return this->size;
}

template <typename T>
int Vector<T>::setSize(int newSize) {
    T* newVectorPtr = new T[newSize];
    for (int i = 0; i < newSize; i++) {
        newVectorPtr[i] = i > this->size ? 0 : vectorPtr[i];
    }
    this->size = newSize;
    this->vectorPtr = newVectorPtr;

    return 1;
}

template <typename T>
T Vector<T>::getElement(int index) {
    if (this->size < index) {
        return 0;
    }
    return this->vectorPtr[index];
}

template <typename T>
T* Vector<T>::getPtr() {
    return this->vectorPtr;
}

template <typename T>
int Vector<T>::setPtr(T* newPtr) {
    if (newPtr == nullptr) {
        return -1;
    }

    for (int i = 0; i < this->size; i++) {
        this->vectorPtr[i] = newPtr[i];
    }
    this->vectorPtr = newPtr;

    return 1;
}

template <typename T>
int Vector<T>::add(T element) {
    T* tmp = new T[this->size + 1];
    for (int i = 0; i < this->size; i++)
        tmp[i] = vectorPtr[i];

    tmp[this->size] = element;
    this->size += 1;

    delete this->vectorPtr;
    this->vectorPtr = tmp;

    return 1;
}

template <typename T>
int Vector<T>::remove(int indexDel) {
    if (this->size == 0 || this->size <= indexDel)
        return -1;

    T* tmp = new T[this->size - 1];
    if(tmp==nullptr)
        return 0;
    for (int i = 0; i < indexDel; i++)
        tmp[i] = vectorPtr[i];

    for (int i = indexDel + 1; i < this->size; i++)
        tmp[i-1] = vectorPtr[i];

    this->size -= 1;
    delete this->vectorPtr;
    this->vectorPtr = tmp;

    return 1;
}

template <typename T>
int Vector<T>::mult(T element) {
    T* tmp = new T[this->size];
    for (int i = 0; i < this->size; i++)
        tmp[i] = vectorPtr[i] * element;

    delete this->vectorPtr;
    this->vectorPtr = tmp;

    return 1;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v) {
    if (this == &v)
        return *this;

    this->size = v.size;

    for (int i = 0; i < v.size; i++)
        this->vectorPtr[i] = v.vectorPtr[i];

    return *this;
}

template <typename T>
bool Vector<T>::operator==(Vector& v) {
    if (this->vectorPtr == v.vectorPtr)
        return true;

    else if (this->size == v.size)
        for (int i = 0; i < v.size; i++)
            if (this->vectorPtr[i] != v.vectorPtr[i])
                return false;

     else
        return false;

    return true;
}

template <typename T>
Vector<T> operator +(Vector<T>& v1, Vector<T>& v2) {
    int newSize = min(v1.getSize(), v2.getSize());
    T *ptr = new T[newSize];

    for (int i = 0; i < newSize; i++)
                ptr[i] = v1.getElement(i) + v2.getElement(i);

    Vector<T> res(newSize);
    res.setPtr(ptr);

    return res;
}

template <typename T>
int operator +(T element, Vector<T>& v) {
    return v.add(element);
}

template <typename T>
int operator +(Vector<T>& v, T element) {
    return v.add(element);
}

template <typename T>
Vector<T> operator -(Vector<T>& v1, Vector<T>& v2) {
    int newSize =min(v1.getSize(), v2.getSize());
    T *ptr = new T[newSize];

    for (int i = 0; i < newSize; i++)
                ptr[i] = v1.getElement(i) - v2.getElement(i);

    Vector<T> res(newSize);
    res.setPtr(ptr);

    return res;
}

template <typename T>
int operator -(Vector<T>& v, int index) {
    return v.remove(index);
}

template <typename T>
Vector<T> operator *(Vector<T>& v1, Vector<T>& v2) {
    int newSize =min(v1.getSize(), v2.getSize());
    T *ptr = new T[newSize];
    for (int i = 0; i < newSize; i++) {
                ptr[i] = v1.getElement(i) * v2.getElement(i);
        }
    Vector<T> res(newSize);
    res.setPtr(ptr);
    return res;
}

template <typename T>
int operator *(T element, Vector<T>& v) {
    return v.mult(element);
}

template <typename T>
int operator *(Vector<T>& v, T element) {
    return v.mult(element);
}

template <typename T>
Vector<T> operator /(Vector<T>& v1, Vector<T>& v2) {
    int newSize =min(v1.getSize(), v2.getSize());
    T *ptr = new T[newSize];

    for (int i = 0; i < newSize; i++)
                ptr[i] = v1.getElement(i) / v2.getElement(i);

    Vector<T> res(newSize);
    res.setPtr(ptr);

    return res;
}

template <typename T>
ostream& operator <<(ostream& out, Vector<T>& v) {
    out << "[";
    for (int i = 0; i < v.getSize(); i++)
        out<<v.getElement(i) <<((i == v.getSize() - 1) ? "" : ", ");
    out<< "]";

    return out;
}

template <typename T>
istream& operator >>(istream& in, Vector<T>& v) {
    T* inputPtr = new T[v.getSize()];
    for (int i = 0; i < v.getSize(); i++)
        in >> inputPtr[i];

    v.setPtr(inputPtr);

    return in;
}

template <typename T>
Vector<T>::~Vector() {
    delete [] this->vectorPtr;
}
