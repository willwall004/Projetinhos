#include <stdio.h>
int contachar(char c, char* s)
{
    int cont=0;
    int i;
    for(i=0; s[i]<'\0'; i++);
    {
        if(s[i]=c)
        {
            cont++;
        }
    }
    return cont;
}
