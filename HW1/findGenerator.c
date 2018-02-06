#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findGenerator(int a);

void main(){
    
    int p;
    printf("Enter a prime number:");
    scanf("%d", &p);
    findGenerator(p);    

}

void findGenerator(int p ){
    for (int g = 2; g < p; g++){
       int num = 0;
       for (int r = 1; r < p-1; r++){
           if ((int)pow(g,r) % p != 1)
           {
               num++;               
           }
       }
       if (num == (p-2)){
           printf("%d is a generator of Z_%d.\n",g,p);
           break;
       }
   }
}
