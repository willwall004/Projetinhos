#include <stdio.h>
int main()
{
    int i;
    int v[4];
    for(i=0;i<4;i++)
    {
        scanf("%d", &v[i]);
    }
    for(i=0;i<4;i++)
    {
        printf("%d\n", v[i]);
    }
    return 0;
}
