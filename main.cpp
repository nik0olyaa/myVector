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
    cout << "���������: " << C << endl;
    C=A-B;
    cout << "�i��i�����: " << C << endl;
    C=A*B;
    cout << "��������: " << C << endl;
    C=A/B;
    cout << "�i�����: " << C << endl;
    cout<<"��������� ��������: "<<endl;
    cin>>a;
    A+a;
    cout<<A<<endl;
    cout<<"��������� ��������: "<<endl;
    cin>>a;
    A-a;
    cout<<A<<endl;
    cout<<"�������� �� �����: "<<endl;
    cin>>a;
    A*a;
    cout<<A<<endl;

    return 0;
}
