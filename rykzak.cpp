#include <iostream>
using namespace std;
int max(int a, int b) 
{
    return (a > b) ? a : b;
}


void Print(int W, int wt[], int val[], int n)
{
    int i, w;
    int** K;
    K = new int* [n + 1];
    for (i = 0; i <= n + 1; i++)
        K[i] = new int[W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "Стоимость вещей в рюкзаке";
    int res = K[n][W];
    cout << res << endl;
    cout << "Вещи которые поместились: ";
    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        if (res == K[i - 1][w])
            continue;
        else {
            
            cout << " " << i - 1;
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    for (i = 0; i <= n + 1; i++)
        delete[] K[i];
}

int main()
{
    setlocale(LC_ALL, "rus");
    int val[] = { 60, 100, 120 };//цена
    int wt[] = { 10, 20, 30 };//вес
    int W = 50;//максвес
    int n = sizeof(val) / sizeof(val[0]);
    Print(W, wt, val, n);

    return 0;
}
