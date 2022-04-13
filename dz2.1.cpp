#include <iostream>
int main()
{
    std::string str;
    std::cin >> str;
    int i = 0;
    int l;
    int c = 0;
    while(str[i] != '\0') {
        if (str[i] == ')' || str[i] == '}' || str[i] == ']' || str[i] == '>') {
            std::cout << i+1;
            exit(0);
        }
        if (str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<') {
            l = str[i];
            c = i;
            i++;
            while (str[i] != '\0') {
                if (str[i] == ')' || str[i] == '}' || str[i] == ']' || str[i] == '>') {
                    if(str[i] == l +1 || str[i] == l +2)
                        break;
                    else
                    {
                        std::cout << c+1;
                        exit(0);
                        
                    }
                }
           
                if (str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<' || str[i +1] == '\0')  {
                    std::cout << c+1;
                    exit(0);
                    
                }
                i++;
            }
        }
        i++;
    }
std::cout << "ошибок нет";
}
