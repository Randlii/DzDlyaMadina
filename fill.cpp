#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
typedef struct {
       int x, y;
     } TPoint;   
     
TPoint Point( int x, int y )
{
  TPoint P;      
  P.x = x; P.y = y;
  return P;
}

void ShowMatrix( int **A, int XMAX, int YMAX )
{
  int i, j;
  cout << "--------------------\n";
  for ( i=0; i<YMAX; i++ ) {
    for ( j=0; j<XMAX; j++ ) {
      cout.width(3);  
      cout << A[i][j];
      }
    cout << endl;;
    }
  cout << "--------------------\n";
}
void ochered(queue<TPoint> Q, TPoint pt, int XMAX, int YMAX, int color, int NEW_COLOR, int **A)
{
   while ( ! Q.empty() ) {
    pt = Q.front(); Q.pop();
    if ( A[pt.y][pt.x] == color ) {
      A[pt.y][pt.x] = NEW_COLOR;
      if ( pt.x > 0 ) Q.push ( Point(pt.x-1,pt.y));
      if ( pt.y > 0 ) Q.push ( Point(pt.x,pt.y-1));
      if ( pt.x < XMAX-1 ) Q.push ( Point(pt.x+1,pt.y) );
      if ( pt.y < YMAX-1 ) Q.push ( Point(pt.x,pt.y+1) );
      }
    }
}
int main ()
{  
  int i, j, x0, y0, color;
  TPoint pt;
  queue<TPoint> Q;
  ifstream F;
  int **A;
  int YMAX = -1, XMAX = -1;
  F.open ( "fill.dat" );
  F >> YMAX;
  F >> XMAX;
  A=new int*[XMAX];
    for(int i=0;i<=XMAX;i++)
   {
        A[i]=new int [YMAX];
   }
  for ( i=0; i<YMAX; i++ ) 
    for ( j=0; j<XMAX; j++ )
      F >> A[i][j];
  F.close();

  std::cout << "Исходная матрица ";
  ShowMatrix(A,XMAX,YMAX);
  
  std::cout << "Введите у: ";
  std::cin >> y0;
  std::cout << "Введите х: ";
  std::cin >> x0;
  if(x0 > XMAX || y0 > YMAX)
  {
    std::cout << "Неверные координаты";
    exit(0);
  }
  x0--;
  y0--;
  color = A[y0][x0];
  Q.push ( Point(x0,y0) );
  int NEW_COLOR;
  std::cout << "Введите новый цвет: ";
  std::cin >> NEW_COLOR;

  ochered(Q, pt, XMAX, YMAX, color, NEW_COLOR, A);

   std::cout << "Матрица после заливки ";
  ShowMatrix ( A,XMAX,YMAX );

  cin.get(); 
}
