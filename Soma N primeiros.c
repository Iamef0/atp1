#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(void){

    int n, soma=0;

    setlocale(LC_ALL,"");

    printf("Insira a quantidade de n�meros a serem somados: ");
    scanf("%d", &n);

    for(int i=1; i <= n; i++){
        soma += i;
    }

    printf("A soma dos %d primeiros n�meros inteiros positivos � %d !", n, soma);

    system("pause");

    return 0;
}
