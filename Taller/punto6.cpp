#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
const int Maxusuarios = 100;
//ESTRUCTURAS
struct User
{
    int id;
    string name;
    string lastname;
    int edad;
}; //arreglo de almacenamiento de base de datos

//PROTOTIPOS
void limpiar_buffer();
void consultarusuario(User usuarios[], int);
void agefrecuency(User usuarios[], int);
void adduser(User usuarios[], int &);
void removeuser(User usuarios[], int &);
void imprimirlistado(User usuarios[], int);
void archivo(User usuarios[], int);
void instrucciones(int);

int main()
{
    User usuarios[Maxusuarios];
    bool salir = false;
    int opcion;
    int newusers = 0;
    do
    {
        //MENU
        cout << "-------------------MENU--------------------" << endl;
        // a. Consultar un usuario con un identificador especifico.
        cout << "1. Hacer Consultas De Usuarios" << endl;
        // b. Consultar la frecuencia de edades
        cout << "2. Hacer consultas De Frecuencias De Edades" << endl;
        // c. Agregar un nuevo usuario
        cout << "3. Agregar usuario" << endl;
        // d. Eliminar un usuario dado un identificador
        cout << "4. Eliminar usuario" << endl;
        // e. Imprimir el listado de todos lo usuarios existentes y almacenar un archivo usuarios.bat
        cout << "5. Imprimir Listado De Usuarios Existentes" << endl;
        // f. Por cada acción que ejecute el programa. Se debe almacenar la instrucción realizada en un archivo log.bat
        cout << "6. Terminar la Aplicación" << endl;
        cin >> opcion;
        limpiar_buffer();

        switch (opcion)
        {
        case 1:
            cout << "Has seleccionado: Hacer Consultas De Usuarios" << endl;
            consultarusuario(usuarios, newusers);
            instrucciones(1);
            break;
        case 2:
            cout << "Has seleccionado: Hacer consultas De Frecuencias De Edades" << endl;
            agefrecuency(usuarios, newusers);
            instrucciones(2);
            break;
        case 3:
            cout << "Has seleccionado: Agregar usuario" << endl;
            adduser(usuarios, newusers);
            instrucciones(3);
            break;
        case 4:
            cout << "Has seleccionado: Eliminar usuario" << endl;
            removeuser(usuarios, newusers);
            instrucciones(4);
            break;
        case 5:
            cout << "Has seleccionado: Imprimir Listado De Usuarios Existentes" << endl;
            imprimirlistado(usuarios, newusers);
            break;
        case 6:
            cout << "Has seleccionado: Terminar la Aplicación" << endl;
            cout << "Hasta pronto" << endl;
            instrucciones(7);
            salir = true;
            break;
        default:
            cout << "La opción ingresada es incorrecta. Vuelva a intentarlo" << endl;
            break;
        }
    } while (!salir);

    return 0;
}
//FUNCIONES
void consultarusuario(User usuarios[], int tamano)
{
    bool exit = false;
    char opv = 'n';
    do
    {
        int id = 0;
        cout << "Indiqueme el Id que desea buscar: " << endl;
        cin >> id;
        if (id < tamano)
        {
            cout << "--------INFORMACION DEL USUARIO--------" << endl;
            cout << usuarios[id].id << "  " << usuarios[id].name << "  " << usuarios[id].lastname << "  " << usuarios[id].edad << endl;
        }
        else
        {
            cout << "Valor no encontrado, intente nuevamente " << endl;
        }
        cout << "Desea salir (s/n)" << endl;
        cin >> opv;
        if (opv == 's')
        {
            exit = true;
        }
    } while (!exit);
}
void limpiar_buffer()
{
    cin.clear();
    cin.ignore(10000, '\n');
}
void agefrecuency(User usuarios[], int tamano)
{
    int contador1 = 0, contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0, contador6 = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (usuarios[i].edad > 0 && usuarios[i].edad <= 17)
        {
            contador1++;
        }
        else if (usuarios[i].edad > 17 && usuarios[i].edad <= 30)
        {
            contador2++;
        }
        else if (usuarios[i].edad > 30 && usuarios[i].edad <= 50)
        {
            contador3++;
        }
        else if (usuarios[i].edad > 50 && usuarios[i].edad <= 75)
        {
            contador4++;
        }
        else if (usuarios[i].edad > 75)
        {
            contador5++;
        }
    }
    cout << "-----Tabla de Frecuencia de edades-----" << endl;
    cout << "            0-17    " << contador1 << endl;
    cout << "            18-30   " << contador2 << endl;
    cout << "            30-50   " << contador3 << endl;
    cout << "            50-75   " << contador4 << endl;
    cout << "            >75     " << contador5 << endl;
}
void adduser(User usuarios[], int &tamano)
{
    cout << "Usuario Nuevo" << endl;
    cout << "ID:       " << endl;
    usuarios[tamano].id = tamano;
    cout << usuarios[tamano].id << endl;
    cout << "Nombre:   " << endl;
    cin >> usuarios[tamano].name;
    cout << "Appelido: " << endl;
    cin >> usuarios[tamano].lastname;
    cout << "Edad:     " << endl;
    cin >> usuarios[tamano].edad;
    tamano++;
}
void removeuser(User usuarios[], int &tamano)
{
    int id;
    cout << "Id del usuario que va a quitar: " << endl;
    cin >> id;
    tamano--;
    for (int i = 0; i < tamano; i++)
    {
        usuarios[i].id = usuarios[i + 1].id;
        usuarios[i].id--;
        usuarios[i].name = usuarios[i + 1].name;
        usuarios[i].lastname = usuarios[i + 1].lastname;
        usuarios[i].edad = usuarios[i + 1].edad;
    }
}
void imprimirlistado(User usuarios[], int tamano) //No terminado
{
    for (int i = 0; i < tamano; i++)
    {
        cout << usuarios[i].id << " ";
        cout << usuarios[i].name;
        cout << " ";
        cout << usuarios[i].lastname;
        cout << " " << usuarios[i].edad << endl;
    }
    instrucciones(5);
    char opv = 'n';
    cout << "Los valores en pantalla son correctos, desea guardarlo (s/n)" << endl;
    cin >> opv;
    if (opv == 's')
    {
        instrucciones(6);
        archivo(usuarios, tamano);
    }
}
void archivo(User arreglo[], int tamano)
{
    ofstream archivo;
    archivo.open("usuarios.txt", ios::out);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    for (int i = 0; i < tamano; i++)
    {
        archivo << arreglo[i].id << " ";
        archivo << arreglo[i].name;
        archivo << " ";
        archivo << arreglo[i].lastname;
        archivo << " " << arreglo[i].edad << endl;
    }
    archivo.close();
}
void instrucciones(int numero)
{
    ofstream archivo;
    archivo.open("log.txt", ios::app);

    switch (numero)
    {
    case 1:
        archivo << "Consulto los usuarios" << endl;
        break;
    case 2:
        archivo << "Consulto las frecuencias de edades" << endl;
        break;
    case 3:
        archivo << "Añadio un nuevo usuario" << endl;
        break;
    case 4:
        archivo << "Elimino un usuario" << endl;
        break;
    case 5:
        archivo << "Imprimio el listado de usuarios existentes" << endl;
        break;
    case 6:
        archivo << "Almaceno el listado de usuarios en un archivo .txt" << endl;
        break;
    case 7:
        archivo << "Salio de la apliciacion" << endl
                << endl;
        break;
    default:
        break;
    }
    archivo.close();
}
