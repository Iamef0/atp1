#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL,"");

    int n, multi=1;

    printf("Insira um n�mero inteiro positivo: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        multi *= i;
    }

    printf("\n%d! � igual a %d\n", n, multi);

    system("pause");

    return 0;

}
