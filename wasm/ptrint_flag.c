#include <stdio.h>

int flag[28] = {72, 88, 89, 88, 71, 85, 104, 100, 40, 121, 68, 47, 54, 48, 110, 97, 119, 40, 68, 42, 96, 76, 32, 39, 104, 98, 102};

//EMSCRIPTEN_KEEPALIVE
char *get_flag21b8192d()
{
    for(int i=27; i>=0; i--) flag[i] ^= i;
    for(int i=0; i<28; i++) flag[i] ^= 27-i;
    char *arr; arr=&flag;
    for(int i=0; i<28; i++) arr[i] = (char)flag[i];
    return arr;
}

int main()
{
    printf("%s\n", get_flag21b8192d());
}