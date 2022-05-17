#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int i, A, N;

    std::cout << "Введите А: \n";
    std::cin >> A;
    std::cout << "Введите В: \n";
    std::cin >> N;
    int* K = new int[N + 1];
    for (i = 0; i < A; i++)
        K[i] = 0;
    K[A] = 1;
    for (i = A + 1; i <= N; i++) {
        K[i] = K[i-1];
        if(i %2 == 0)
        K[i] = K[i] + K[i / 2];
        if (i % 3 == 0)
        K[i] = K[i] + K[i / 3];
    }
    cout << "Количество программ " << K[N];
}
