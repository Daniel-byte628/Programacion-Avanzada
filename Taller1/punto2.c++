#include <iostream>
#include <vector>
using namespace std;
void ordenamiento_seleccion(vector<int> &vector, int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        int min = i;
        for (int j = i + 1; j < tamano; j++)
        {
            if (vector[j] < vector[min])
            {
                min = j;
            }
        }
        int aux = vector[i];
        vector[i] = vector[min];
        vector[min] = aux;
    }
}
void agregar(vector<int> &sort)
{
    bool exit = true;
    char siono;
    do
    {
        cout << "Valor añadir" << endl;
        int valor = 0;
        cin >> valor;
        sort.push_back(valor);
        cout << "¿Desea agregar otro valor? (s/n)" << endl;
        cin >> siono;
        if (siono == 'n')
        {
            exit = false;
        }
    } while (exit);
}

int main()
{
    vector<int> sort(0);
    agregar(sort);
    int tamano = sort.size();
    ordenamiento_seleccion(sort, tamano);
    int *apun = &sort[0];
    for (int i = 0; i <= tamano - 1; i++)
    {
        cout << apun << " " << *apun << endl;
        apun++;
    }
}