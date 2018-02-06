#include <stdio.h>
#include <stdlib.h>

void isCoprime(int a, int b);
int gcd(int a, int b);

void main() {

    int a;
    int b;
    printf("Enter the first numer:");
    scanf("%d", &a);
    printf("Enter the second number:");
    scanf("%d", &b);
    isCoprime(a,b);

}

int gcd(int a, int b){

    if (b==0){
        return a;
    }
    else{
        return gcd(b,a % b);
    }

}

void isCoprime(int a, int b){
    if (gcd(a,b) == 1){
        printf("%d and %d are coprime.\n",a,b);
    }
    else{
        printf("%d and %d are not coprime.\n",a,b);
    }
}
