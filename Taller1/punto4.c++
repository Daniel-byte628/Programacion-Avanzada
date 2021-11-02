/*  INSTRUCCIONES
1. Crear el tablero de ajedrez
2. Colocar una reyna por columna en el tablero
3. Comprabar haber que ninguna reyna se mate entre ella
4. Mostrar el tablero e intentar recrear el siguiente juego: https://elpais.com/elpais/2017/09/04/ciencia/1504535610_082169.html
El 4 paso de recrear se hace porque el enunciado dice que:
Resuelva  el  ejercicio de  las  ocho  reinas, 
describa  el  algoritmo  que  plantea  para encontrar la solución al problema.
Es decir una sola solucion, y nunca dice: De cuantas maneras diferentes se puede hacer. */

/* Explicacion algoritmo
Colocar una reyna en la primera columna, y 7 fila
Colocar la siguiente reyna utilizando el movimiento del caballo
En el momento de que una reyna no puede colocarse porque se matan entre ellas,
Se devuelve a la anterior reyna y se mueve una fila, y si no se puede colocar
se repite el proceso.En el momento de que haya la posibilidad de colocarse,
se mueve utilizando el movimiento del caballo(asi sucesivamente). */

#include <iostream>
using namespace std;
const int numchess = 8;
void mostrar(int chesstable[numchess][numchess])
{
    for (int i = 0; i < numchess; i++)
    {
        for (int j = 0; j < numchess; j++)
        {
            cout << chesstable[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void create(int chesstable[][numchess])
{
    for (int i = 0; i < numchess; i++)
    {
        for (int j = 0; j < numchess; j++)
        {
            chesstable[i][j] = 0;
        }
    }
}

void horse(int &columna, int &fila)
{
    columna++;
    fila = fila - 2;
    if (columna > 7)
    {
        columna = (columna % 8);
    }
    else if (columna < 0)
    {
        columna = (columna + 7) + 1;
    }
    if (fila > 7)
    {
        fila = (fila % 8);
    }
    else if (fila < 0)
    {
        fila = (fila + 7) + 1;
    }
}
bool verificarcolum(int chesstable[][numchess], int fila, int columna)
{
    //Fila una unica reyna
    //Columna solo una reyna
    bool isvalid = true;
    for (int i = 0; i < numchess; i++)
    {
        if (chesstable[i][columna] == 1 && i != fila)
        {
            isvalid = false;
        }
    }
    return isvalid;
}
bool verificarrow(int chesstable[][numchess], int fila, int columna)
{
    //Fila una unica reyna
    //Columna solo una reyna
    bool isvalid = true;
    for (int i = 0; i < numchess; i++)
    {
        if (chesstable[fila][i] == 1 && i != columna)
        {
            isvalid = false;
        }
    }
    return isvalid;
}
bool diagonal(int chesstable[][numchess], int fila, int columna)
{
    int temfila = fila, temcolum = columna;
    //Diagonal solo una reyna
    //   izquierda arriba
    while (columna > 0 && fila > 0)
    {
        columna--;
        fila--;
        if (chesstable[fila][columna] == 1 && columna > 0 && fila > 0)
        {
            return false;
        }
    }
    //   izquierda abajo
    fila = temfila, columna = temcolum;
    while (columna > 0 && fila < 8)
    {
        columna--;
        fila++;
        if (chesstable[fila][columna] == 1 && columna > 0 && fila < 8)
        {
            return false;
        }
    }
    return true;
}
void simulation(int chesstable[numchess][numchess])
{
    int fila = 6, columna = 0, reynascolocadas = 1, intentos = 0;
    //Colocar una reyna en la primera fila
    chesstable[fila][columna] = 1;
    bool completestep = true;
    do
    {
        //Caballo movimiento
        horse(columna, fila);
        chesstable[fila][columna] = 1;
        reynascolocadas++;
        do
        {
            if (intentos == 8)
            {
                chesstable[fila][columna] = 0;
                mostrar(chesstable);
                columna--;
                fila = fila + 2;
                if (fila > 7)
                {
                    fila = (fila % 8);
                }
                chesstable[fila][columna] = 0;
                reynascolocadas--;
                intentos = 1;
                fila--;
                if (fila < 0)
                {
                    fila = fila + 8;
                }
            }
            else if (verificarcolum(chesstable, fila, columna) == true && verificarrow(chesstable, fila, columna) == true && diagonal(chesstable, fila, columna) == true)
            {
                completestep = false;
            }
            else
            {
                chesstable[fila][columna] = 0;
                fila--;
                if (fila < 0)
                {
                    fila = (fila + 7) + 1;
                }
                chesstable[fila][columna] = 1;
                intentos++;
            }
        } while (completestep == true);
        completestep = true;
        intentos = 0;
    } while (reynascolocadas < 8);
}
int main()
{
    int chesstable[numchess][numchess];
    create(chesstable);
    simulation(chesstable);
    mostrar(chesstable);
    return 0;
}