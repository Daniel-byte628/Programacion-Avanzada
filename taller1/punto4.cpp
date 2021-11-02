#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#define GetSize(array_enteros) (sizeof(array_enteros) / sizeof(*(array_enteros)))
using namespace std;

//PROTOTIPOS
void arregloaleatorio(int[]);
void mostrararreglo(int[]);
long sumadeenteros(int[], int);
void actualizar(int, int, int[]);
void imprimirpares(int[], int);

int main()
{

    //  a. Iniciar aleatoriamente un arreglo de enteros 10 posiciones.
    // Nota: enteros cualquiera, no dice explicitamente desde aqui a esto, es decir, no hay un rango de numeros.
    int arrayaleatorio[10];
    int tamano = sizeof(arrayaleatorio) / sizeof(arrayaleatorio[0]);
    //se puede colocar el tamaño del arreglo pues es nueve, sin embargo, para que sea mas sofisticado la otra funcion y sea generalizada
    arregloaleatorio(arrayaleatorio);
    mostrararreglo(arrayaleatorio);

    // b. Declare una función que recorra el arreglo y calcule la suma de cada uno de sus elementos
    long resultadosuma;
    resultadosuma = sumadeenteros(arrayaleatorio, tamano);
    cout << "El resultado es: " << resultadosuma << endl;

    // c. Un método que reciba la posición del arreglo y el nuevo valor, para actualizar este dato.
    int valor, posicion;
    cout << "Posicion que desea cambiar:" << endl;
    cin >> posicion;
    cout << "Nuevo valor: " << endl;
    cin >> valor;
    actualizar(posicion, valor, arrayaleatorio);

    // d. Un método que imprima todos los valores pares que pertenecen al arreglo
    mostrararreglo(arrayaleatorio);
    imprimirpares(arrayaleatorio, tamano);
    return 0;
}

//FUNCIONES
void arregloaleatorio(int arregloaleatorio[])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int num = rand();
        arregloaleatorio[i] = num;
    }
}
void mostrararreglo(int arreglo[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << arreglo[i] << endl;
    }
}
long sumadeenteros(int arreglo[], int tamano)
{
    long suma = 0;
    for (int i = 0; i < tamano; i++)
    {
        suma += arreglo[i];
    }
    return suma;
}
void actualizar(int posicion, int valor, int arreglo[])
{
    arreglo[posicion] = valor; // como es un array este va pasar por referencia &
    cout << endl;
}
void imprimirpares(int arreglo[], int tamano)
{
    cout << "Los numeros pares del arreglo son: ";
    for (int i = 0; i < tamano; i++)
    {
        int numero = arreglo[i];
        if (numero % 2 == 0)
        {
            cout << numero << " ";
        }
    }
    cout << endl;
}
