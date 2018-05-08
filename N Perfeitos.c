#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define LIM 1000000

int main(void){
    setlocale(LC_ALL,"");

    int soma;

    for(int i=2; i <= LIM; i++){
        for(int k=1; k < i; k++){
            if(i%k == 0)
                soma += k;
        }
        if(soma == i)
            printf("O n�mero %d � perfeito!\n", i);
        soma = 0;

        if(i == LIM)
            break;
    }

    printf("Esses s�o todos os n�mero perfeitos no intervalo [2~1000000]");

    system("pause");

    return 0;
}
