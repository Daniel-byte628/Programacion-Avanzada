#include <iostream>
using namespace std;
int main()
{
    long int valor1 = 200000, valor2 = 0;
    long int *ptr = &valor1;
    cout << *ptr << endl;
    cout << valor2 << endl;
    cout << &valor2 << endl;
    cout << &valor1 << endl;
    cout << ptr << endl;
    int num=0;
    num=*ptr+valor1;
    cout<<num<<endl;
}
