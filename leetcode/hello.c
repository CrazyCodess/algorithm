#include<stdio.h>  
int main(){  
    int a,b,c,d;
    printf("please enter a,b:");
    scanf("%d,%d",&a, &b);
    c = a+b;
    d = a*b;
    printf("a + b = %d\n", c);
    printf("a * b = %d\n", d);
    return 0;
}