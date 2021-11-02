#include <iostream>
#include <cmath>
using namespace std;
//Prototipos funciones
float hipotenusa(float, float);
int menornumero(int, int, int);
void imprimir(int);

//Main
int main()
{

    //Primer punto de calcular hipotenusa
    float cateto1 = 0, cateto2 = 0, resultado = 0;
    cout << "--------Punto a--------" << endl;
    resultado = hipotenusa(cateto1, cateto2);
    cout << "Su hipotenusa es:" << resultado << endl
         << endl;

    //Segundo punto
    int one = 0, two = 0, three = 0, answer = 0;
    cout << "--------Punto b--------" << endl;
    answer = menornumero(one, two, three);
    cout << "El menor numero de los tres que ingreso es: " << answer << endl;

    //Tercer punto
    int numero = 0;
    cout << "--------Punto c--------" << endl;
    imprimir(numero);

    return 0;
}

//Funciones
float hipotenusa(float cateto1, float cateto2)
{
    float hipot;
    cout << "Digite el cateto1: " << endl;
    cin >> cateto1;
    cout << "Digite el cateto2: " << endl;
    cin >> cateto2;
    return hipot = sqrt((cateto1 * cateto1) + (cateto2 * cateto2)); //sqrt sirve para sacar la raiz cuadrada de dicho numero
}
int menornumero(int one, int two, int three)
{
    cout << "Ingrese su primer numero" << endl;
    cin >> one;
    cout << "Ingrese su segundo numero" << endl;
    cin >> two;
    cout << "Ingrese su tercer numero" << endl;
    cin >> three;
    int numeromenor = 0;
    if (one < two && one < three)
    {
        numeromenor = one;
    }
    else if (two < three && two < one)
    {
        numeromenor = two;
    }
    else
    {
        numeromenor = three;
    }
    return numeromenor;
}

void imprimir(int numero)
{
    int millares = 0, centenas = 0, decenas = 0, unidades = 0;
    cout << "Digiteme el numero de 4 cifras" << endl;
    cin >> numero;
    unidades = numero % 10;
    cout << unidades << " unidades" << endl;
    numero = numero / 10;
    decenas = numero % 10;
    cout << decenas << " decenas" << endl;
    numero = numero / 10;
    centenas = numero % 10;
    cout << centenas << " centenas" << endl;
    numero = numero / 10;
    millares = numero % 10;
    cout << millares << " millares" << endl;
}
