#include <iostream>
#include <stack>
 
using namespace std;
 
int postfix( char *str )
{
    stack< int > s;
    int x;
 
    for ( int i = 0; str[ i ]; ++i )
    {
        if ( str[ i ] >= '0' && str[ i ] <= '9' )
        {
            x = str[ i ] - '0';
            while ( str[ i + 1 ] >= '0' && str[ i + 1 ] <= '9' )
                x = x * 10 + str[ ++i ] - '0';
            s.push( x );
        }
        else if ( str[ i ] == '+' && s.size() >= 2 )
        {
            x = s.top(); s.pop();
            x += s.top(); s.pop();
            s.push( x );
        }
        else if ( str[ i ] == '-' && s.size() >= 2 )
        {
            x = s.top(); s.pop();
            x = s.top() - x; s.pop();
            s.push( x );
        }
        else if ( str[ i ] == '*' && s.size() >= 2 )
        {
            x = s.top(); s.pop();
            x *= s.top(); s.pop();
            s.push( x );
        }
        else if ( str[ i ] == '/' && s.size() >= 2 && s.top() != 0 )
        {
            x = s.top(); s.pop();
            x = s.top() / x; s.pop();
            s.push( x );
        }
    }
 
    if ( !s.empty() )
        return s.top();
 return 0;
}
 
int main()
{
    char str[ 100 ];
 
    cin.getline( str, 100);
    cout << postfix( str ) << endl;
 
    return 0;
}
