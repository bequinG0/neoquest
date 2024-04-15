#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *code = (char *)malloc(96800);
    FILE *file = fopen("encode.c", "rb");
    int len = fread(code, sizeof(char), 96800, file);
    printf("[");
    for(int i=0; i<len; i++) printf("%d, ", code[i]);
    printf("]\n");
}