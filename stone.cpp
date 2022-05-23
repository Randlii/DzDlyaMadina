
#include <iostream>
#include <fstream>

using namespace std;


int max(int a, int b)
{
    if (a > b)
        return a;
    else return b;
}

void showTable(int **T,int *P, int WMAX, int NStones)
{
    int i, w=0;
    cout << "   ";
    for (w = 0; w <= WMAX; w++) 
    {
        cout.width(3);
        printf("%d", w);
    }
    cout << endl;
    cout << "---";
    for (i = 0; i <= WMAX; i++) cout << "---";
    cout << endl;
    for (i = 1; i <= NStones-1; i++) {
        cout.width(2);
        printf("%d:", P[i]);
        for (w = 0; w <= WMAX; w++) {
            cout.width(3);
            printf("%d:", T[i][w]);
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int w, i, w0, t0, t1,WMAX, NStones;
    int* P;
    int** T;
    ifstream F;
    F.open("TextFile2.txt");
    F >> NStones;
    F >> WMAX;
    P = new int[NStones + 1];
    for (int i = 0; i <= NStones; i++)
        F >> P[i];
    F.close();
    T = new int*[NStones + 1];
    for (i = 0; i <= NStones+1; i++)
        T[i] = new int[NStones +1];
    for (i = 0; i <= NStones; i++)
        for (w = 0; w <= WMAX; w++)
            T[i][w] = 0;
    for (i = 1; i <= NStones; i++)
        T[i][0] = 0;
    for (w = P[1]; w <= WMAX; w++)
        T[1][w] = P[1];

    for (i = 2; i <= NStones; i++)
        for (w = 1; w <= WMAX; w++) {
            t0 = T[i - 1][w];
            if (w >= P[i]) {
                t1 = T[i - 1][w - P[i]] + P[i];
                T[i][w] = max(t0, t1);
            }
            else T[i][w] = t0;
        }

    showTable(T, P, WMAX, NStones);


    cout << "Оптимальное решение: w = ";
    printf("%d\n", T[NStones][WMAX]);
    cout << "Берем камни: \n";
    i = NStones;
    w = WMAX;
    w0 = T[NStones][WMAX];
    while (w0 > 0) {
        while (i > 0 && T[i][w] == w0)
            i--;
        if (i == 0) {
            printf("%d", w0);
            break;
        }
        printf("%d ", P[i+1]);
        w0 = w0 - P[i + 1];
        w = w0;
    }
}
