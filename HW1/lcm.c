#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b);
int lcm(int a, int b);

void main() {

    int a;
    int b;
    printf("Enter the first numer:");
    scanf("%d", &a);
    printf("Enter the second number:");
    scanf("%d", &b);
    printf("The least common multiple of %d and %d is %d.\n", a, b, lcm(a, b));


}

int gcd(int a, int b){

    if (b==0){
        return a;
    }
    else{
        return gcd(b,a % b);
    }

}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
