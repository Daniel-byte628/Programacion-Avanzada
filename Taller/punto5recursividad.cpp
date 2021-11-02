#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <chrono>
#include <sys/time.h>

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

using namespace std;
//PROTOTIPOS
int lanzamientodado();
void frecuencia(int, int[]);
void imprimir(int[]);
void beginnew(int[]);
int main()
{
    int arreglo[6] = {0, 0, 0, 0, 0, 0};

    frecuencia(10, arreglo);
    imprimir(arreglo);
    beginnew(arreglo);
    frecuencia(100, arreglo);
    imprimir(arreglo);
    beginnew(arreglo);
    frecuencia(500, arreglo);
    imprimir(arreglo);
    beginnew(arreglo);
    frecuencia(1000, arreglo);
    imprimir(arreglo);
    beginnew(arreglo);
    frecuencia(10000, arreglo);
    imprimir(arreglo);
    beginnew(arreglo);
    return 0;
}

//FUNCIONES
int lanzamientodado()
{
    auto millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    srand(millisec_since_epoch);
    int num = 1 + rand() % 6;
    return num;
}
void frecuencia(int repeticiones, int arreglo[])
{
    int repetitivenumber = 0;
    repetitivenumber = lanzamientodado();
    arreglo[repetitivenumber - 1]++;

    if (repeticiones > 1)
    {
        frecuencia(repeticiones - 1, arreglo);
    }
}
void imprimir(int arreglo[])
{
    cout << "Frecuencia del '1': " << arreglo[0] << endl;
    cout << "Frecuencia del '2': " << arreglo[1] << endl;
    cout << "Frecuencia del '3': " << arreglo[2] << endl;
    cout << "Frecuencia del '4': " << arreglo[3] << endl;
    cout << "Frecuencia del '5': " << arreglo[4] << endl;
    cout << "Frecuencia del '6': " << arreglo[5] << endl
         << endl;
}
void beginnew(int arreglo[])
{
    for (int i = 0; i < 6; i++)
    {
        arreglo[i] = 0;
    }
}