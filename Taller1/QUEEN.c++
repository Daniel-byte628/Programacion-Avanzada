#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string ANAGRAMA = "12345678";
const int BOARD_SIZE = 8;

void printBoard(string anagrama)
{
    int row1[] = {0, 0, 0, 0, 0, 0, 0, 1};
    int row2[] = {0, 0, 0, 0, 0, 0, 1, 0};
    int row3[] = {0, 0, 0, 0, 0, 1, 0, 0};
    int row4[] = {0, 0, 0, 0, 1, 0, 0, 0};
    int row5[] = {0, 0, 0, 1, 0, 0, 0, 0};
    int row6[] = {0, 0, 1, 0, 0, 0, 0, 0};
    int row7[] = {0, 1, 0, 0, 0, 0, 0, 0};
    int row8[] = {1, 0, 0, 0, 0, 0, 0, 0};

    int board[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        switch (anagrama[i])
        {
        case '1':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row1[j];
            }
            break;
        case '2':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row2[j];
            }
            break;
        case '3':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row3[j];
            }
            break;
        case '4':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row4[j];
            }
            break;
        case '5':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row5[j];
            }
            break;
        case '6':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row6[j];
            }
            break;
        case '7':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row7[j];
            }
            break;
        case '8':
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = row8[j];
            }
            break;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkContinued(string anagrama)
{
    bool result = true;

    for (int i = 0; i < BOARD_SIZE - 1; i++)
    {
        int currenNumber = (int)anagrama[i] - 48;
        int nextNumber = (int)anagrama[i + 1] - 48;
        if (currenNumber + 1 == nextNumber)
        {
            result = false;
        }
    }

    return result;
}
bool inverse(string anagrama)
{
    bool result = true;
    for (int i = 0; i < BOARD_SIZE - 1; i++)
    {
        int currenNumber = (int)anagrama[i] - 48;
        int nextNumber = (int)anagrama[i + 1] - 48;
        if (currenNumber == nextNumber+1)
        {
            result = false;
        }
    }
    return result;
}
bool cadados(string anagrama)
{
    bool result = true;

    for (int i = 0; i < BOARD_SIZE - 2; i++)
    {
        int currenNumber = (int)anagrama[i] - 48;
        int num1 = currenNumber % 2;
        int nextNumber = (int)anagrama[i + 2] - 48;
        int num2 = nextNumber % 2;
        if (num2 == num1)
        {
            result = false;
        }
    }

    return result;
}
bool cuatro(string anagrama)
{
    bool result = true;
    for (int i = 0; i < BOARD_SIZE - 5; i++)
    {
        int currenNumber = (int)anagrama[i] - 48;
        int num1=currenNumber%2;
        int nextNumber = (int)anagrama[i + 5] - 48;
        int num2=nextNumber%2;
        if (num1==num2)
        {
            result = false;
        }
    }
    return result;
}
bool seis(string anagrama)
{
    bool result = true;
    for (int i = 0; i < BOARD_SIZE - 6; i++)
    {
        int currenNumber = (int)anagrama[i] - 48;
        int num1=currenNumber%2;
        int nextNumber = (int)anagrama[i + 6] - 48;
        int num2=nextNumber%2;
        if (num1==num2)
        {
            result = false;
        }
    }
    return result;
}
bool ocho(string anagrama)
{
    bool result = true;
        int currenNumber = (int)anagrama[0] - 48;
        int nextNumber = (int)anagrama[7] - 48;
        if (currenNumber == 1 && nextNumber == 8||currenNumber==8 &&nextNumber==1)
        {
            result = false;
        }
    return result;
}
void permute(string select, string remain, int *ptrMove)
{
    if (remain == "" && checkContinued(select) && cadados(select) && cuatro(select)  && inverse(select) &&seis(select) &&ocho(select))
    {
        cout << "**********************" << endl;
        cout << "movimiento ->" << *ptrMove << endl;
        cout << select << endl;

        // printBoard(select);
        cout << "**********************" << endl;
        *ptrMove = *ptrMove + 1;
        return;
    }

    for (int i = 0; remain[i]; ++i)
    {
        string wk(remain);
        permute(select + remain[i], wk.erase(i, 1), ptrMove);
    }
}

int main()
{
    int move = 0;
    int *ptrMove = &move;

    // string anagrama = ANAGRAMA;
    // sort(anagrama.begin(), anagrama.end());
    // permute("", anagrama, ptrMove);
    string string="42736851";
    if (checkContinued(string) && cadados(string) && cuatro(string)  && inverse(string) &&seis(string) &&ocho(string))
    {
       cout<<"true";
    }
    cout<<"false";
    return 0;
}