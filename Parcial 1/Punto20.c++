#include <iostream>
using namespace std;
const int tam = 10;
void imprimir(int arreglo[])
{
    for (int i = 0; i < tam; i++)
    {
        int num = arreglo[i];
        int *ptr = &num;
        if (*ptr % 2 == 0)
        {
            cout << *ptr << " - " << ptr << endl;
        }
    }
}
void add(int arreglo[])
{
    int contador = 0, num = 0, di = 10,dom=2;
    int *tam = &num;
    int *diez = &di;
    int *dos=&dom;
    while (contador<10)
    {
        if (arreglo[contador] % 2 == 1)
        {
            arreglo[contador] = arreglo[contador] + 2;
        }
        contador++;
    }
}
int main()
{
    int arreglo[tam] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    imprimir(arreglo);
    add(arreglo);
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo[i] << endl;
    }
    return 0;
}