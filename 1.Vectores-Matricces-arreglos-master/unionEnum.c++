/*
comienza en 0 y 1, 
cada número subsiguiente es la suma de los dos números anteriores de la serie.
*/
using namespace std;
#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
    union char_int
    {
        int num;
        char character;
    } x;

    x = {'a'};

    cout << "x num: " << x.num << endl;
    cout << "x char: " << x.character << endl;

    enum color
    {
        red = 1,
        yellow,
        green = 20,
        blue
    };
    color col = red;
    int n = blue;
    cout << col;
}
