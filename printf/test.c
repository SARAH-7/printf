#include <stdio.h>



void foo(int *x)
{
    *x += 3;
    printf("inside the function [%d]\n", *x);
    
    // (*s)++;
    // (*s)++;
    // printf("inside the function [%s]\n", *s);
}

int main(void)
{
    // char *s = "hello";
    // foo(&s);
    int x = 5;

    foo(&x);
    printf("outside the function [%d]\n", x);
    // printf("outside the function [%s]\n", s);
    // printf("%s\n", s);
}