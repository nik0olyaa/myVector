#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector {
    template <T> friend Vector<T> operator+(Vector<T>& v1, Vector<T>& v2);
    template <T> friend int operator+(Vector<T>& v, T element);
    template <T> friend int operator+(T element, Vector<T>& v);

    template <T> friend Vector<T> operator-(Vector<T>& v1, Vector<T>& v2);
    template <T> friend int operator-(Vector<T>& v, int index);

    template <T> friend Vector<T> operator*(Vector<T>& v1, Vector<T>& v2);
    template <T> friend int operator*(Vector<T>& v, T element);
    template <T> friend int operator*(T element, Vector<T>& v);

    template <T> friend Vector<T> operator/(Vector<T>& v1, Vector<T>& v2);

    template <T> friend ostream& operator <<(ostream& out, Vector<T>& v);
    template <T> friend istream& operator >>(istream& in, Vector<T>& v);
private:
    T* vectorPtr;
    int size;
public:
    Vector(int size);
    Vector(Vector& a);

    int getSize();
    int setSize(int newSize);
    T getElement(int index);
    T* getPtr();
    int setPtr(T* newPtr);

    int add(T element);
    int remove(int indexDel);
    int mult(T element);

    Vector& operator=(const Vector& v);
    bool operator==(Vector& v);

    ~Vector();
};


#endif // VECTOR_H_INCLUDED
