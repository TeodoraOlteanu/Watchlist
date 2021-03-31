#include <algorithm>
#include "ValidationClass.h"

bool ValidationClass::check_string(string str)
{
    for(int i=0;i<str.length();i++)
        if(isdigit(str[i]) == true)
            return false;
    return true;
}

bool ValidationClass::check_number(int number)
{
    int aux;
    aux = number;
    while(aux!=0)
    {
        if(isdigit(number%10) == true)
            return false;
        aux=aux/10;
    }
    return true;
}



