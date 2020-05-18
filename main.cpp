#include <iostream>
#include "Vector.cpp"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(0,"");
    Vector<int> A(3);
    Vector<int> B(3);
    Vector<int> C(3);
    int a;
    cout << "A= ";
    cin >> A;
    cout <<"B= ";
    cin >> B;
    cout << "A= " << A <<endl;
    cout << "B= " << B <<endl;

    C=A+B;
    cout << "Додавання: " << C << endl;
    C=A-B;
    cout << "Вiднiмання: " << C << endl;
    C=A*B;
    cout << "Множення: " << C << endl;
    C=A/B;
    cout << "Дiлення: " << C << endl;
    cout<<"Додавання елемента: "<<endl;
    cin>>a;
    A+a;
    cout<<A<<endl;
    cout<<"Видалення елемента: "<<endl;
    cin>>a;
    A-a;
    cout<<A<<endl;
    cout<<"Множення на число: "<<endl;
    cin>>a;
    A*a;
    cout<<A<<endl;

    return 0;
}
