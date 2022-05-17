#include <iostream>
using namespace std;

const int INF = 30000;

typedef int* pInt;
pInt* W;
int N;

void ReadMatrix()
{
    setlocale(LC_ALL, "rus");
    int i, j;

    N = 6; 
    W = new pInt[N];
    for (i = 0; i < N; i++)
        W[i] = new int[N];
    cout << "Введите матрицу 6х6 \n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    cout << "Весовая матрица графа: \n";
    cout << "  ";
    for (j = 0; j < N; j++) {
        cout.width(4);
        cout << (char)(j+65);
    }
    cout << endl;
    for (i = 0; i < N; i++) {
        cout.width(2);
        cout << (char)(i + 65);
        for (j = 0; j < N; j++) {
            if (W[i][j] < 0) {
                W[i][j] = INF;
                cout << "   .";
            }
            else {
                cout.width(4);
                cout << W[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;;
}

int main()
{
    int i, j, k, minDist, kMin;
    bool* active;
    int* R, * P;

    ReadMatrix();
    active = (bool*)calloc(N, sizeof(bool));
    R = (int*)calloc(N, sizeof(int));
    P = (int*)calloc(N, sizeof(int));

    for (i = 0; i < N; i++) {
        active[i] = true;
        R[i] = W[0][i];
        P[i] = 0;
    }
    active[0] = false;
    P[0] = -1;

    for (i = 0; i < N - 1; i++) {
        minDist = INF + 100;
        for (j = 0; j < N; j++)
            if (active[j] && R[j] < minDist) {
                minDist = R[j];
                kMin = j;
            }
        active[kMin] = false;
        for (j = 0; j < N; j++)
            if (R[kMin] + W[kMin][j] < R[j]) {
                R[j] = R[kMin] + W[kMin][j];
                P[j] = kMin;
            }
    }

    cout << "Вспом. массив:\n";
    cout << " ";
    for (i = 0; i < N; i++) {
        cout.width(5);
        cout << (char)(i + 65);
    }
    cout << "\n";
    cout << "R";
    for (i = 0; i < N; i++) {
        cout.width(5);
        cout << R[i];
    }
    cout << "\n";
    cout << "P";
    for (i = 0; i < N; i++) {
        cout.width(5);
        if (P[i] < 0)
            cout << '.';
        else
            cout << (char)(P[i]+65);
    }
    int l = -1;
    cout << "\nвведите начальную вершину цифрой:";
    cin >> l;
    cout << "\nвведите конечную вершину цифрой:";
    cin >> N;
    cout << "Самый короткий маршрут из " << (char)(l + 65 - 1) << " в " << (char)(N+65-1) << "\n";
    i = N -1;
    l--;
    while (i != l-1) {
        cout.width(2);
        cout << (char)(i + 65);
        if (i != 0)
            cout << "<";
        i = P[i];
    }
}
