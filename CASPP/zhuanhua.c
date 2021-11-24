#include <stdio.h>
int main()
{
    int x = 4294967295;
    int y;
    printf("%d\n", &x);
    if(y = (int)((float)x))printf("%d", &y);
    else puts("no");
}