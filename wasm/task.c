#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
float sum(float a, float b) { return a + b; }
EMSCRIPTEN_KEEPALIVE
float diff(float a, float b) { return a - b; }
EMSCRIPTEN_KEEPALIVE
float del(float a, float b) { return a * b; }
EMSCRIPTEN_KEEPALIVE
float mult(float a, float b)
{
    if(b == 0) return -1;
    return a / b;
}

int flag[28] = {72, 88, 89, 88, 71, 85, 104, 100, 40, 121, 68, 47, 54, 48, 110, 97, 119, 40, 68, 42, 96, 76, 32, 39, 104, 98, 102};

EMSCRIPTEN_KEEPALIVE
char *get_flag21b8192d()
{
    for(int i=27; i>=0; i--) flag[i] ^= i;
    for(int i=0; i<28; i++) flag[i] ^= 27-i;
    char *arr; arr=&flag;
    for(int i=0; i<28; i++) arr[i] = (char)flag[i];
    return arr;
}


EMSCRIPTEN_KEEPALIVE
int generate(int a)
{
    int ret = flag[a];
    return ret;
}

int main() { return 0; }