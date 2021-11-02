#include <iostream>
#include <string>
using namespace std;
//Funcion
int palindromo(string texto)
{
    int aux = 0, igual = 0;
    cout << endl
         << "ingrese la palabra a evaluar: ";
    getline(cin, texto);
    for (int i = texto.length() - 1; i >= 0; --i)
    {
        if (texto[i] == texto[aux])
        {
            ++igual;
        }
        ++aux;
    }
    if (texto.length() == igual)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}
int main()
{
    string texto;
    int num = 0;
    num = palindromo(texto);
    if (num == 0)
    {
        cout << "No se palindromo";
    }
    else
    {
        cout << "Es palindromo";
    }
    return 0;
}
