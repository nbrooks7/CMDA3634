#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void isPrime(int a);

void main(){
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    isPrime(a);

}

void isPrime(int a){
    for (int i = 2; i <= sqrt(a); i++){
        if ((a % i) == 0){
            printf("%d is not prime.\n", a);
            return;
        }
    }
    printf("%d is prime.\n",a);
        



}
