#include <iostream>
#include <cmath>
using namespace std;
void printCharacter(char, int);
void iterar(char, int);
void piramide(char, char);
int main()
{

    //Primera parte del segundo punto
    char letra;
    int times = 0;
    cout << "-------- Primera parte del segundo punto--------" << endl;
    cout << "Letra que se va imprimir en pantalla: " << endl;
    cin >> letra;
    cout << "Numero de veces que se va mostrar en pantalla, digitalicelo porfavor: " << endl;
    cin >> times;
    printCharacter(letra, times);

    //Segunda Parte del sgundo punto: "cree un métodoque itere hasta 20 para crear la siguiente salida enconsola"
    char A = 'a';
    cout << "-------- Segunda parte del segundo punto--------" << endl;
    iterar(A, 1);

    //Tercer punto
    cout << "----Tercer Punto----" << endl;
    char primerchar, segundochar;
    piramide('m', 'a');

    return 0;
}
void printCharacter(char letra, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << letra;
    }
    cout<<endl;
}
void iterar(char A, int iteraciones)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < iteraciones; j++)
        {
            cout << A;
        }
        cout << endl;
        iteraciones++;
    }
}
void piramide(char primerchar, char segundochar)
{
    for (int i = 0; 10 >= i; i++)
    {
        for (int j = 9; j >= i; j--)
        {
            cout << primerchar;
        }
        if (i == 0)
        {
            cout << segundochar;
        }
        for (int k = 1; 2 * i >= k; k++)
        {
            cout << segundochar;
        }
        if (i == 0)
        {
            for (int j = 8; j >= i; j--)
            {
                cout << primerchar;
            }
            cout << endl;
        }
        else
        {
            for (int j = 9; j >= i; j--)
            {
                cout << primerchar;
            }
            cout << endl;
        }
    }
}
