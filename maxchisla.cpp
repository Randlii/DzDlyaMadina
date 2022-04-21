#include <iostream>
#include <fstream>
using namespace std;
int main ()
{  
  int N, i,c= 0,max = 0, j1,j2;
  ifstream F;
  int *A;
  F.open ( "queue.dat" );
  F >> N;
  if(N < 5)
    exit(0);
  A=new int[N];
  if(A == NULL)
    exit(0);
  for ( i=0; i<=N; i++ ) 
    F >> A[i];
  F.close();
  for ( i=0; i<=N; i++ )
  {
    c = 0;
    c = A[i] + A[i+5];
    if(c >= max)
    {
      max = c;
    }
  }
  std::cout << max;
}
