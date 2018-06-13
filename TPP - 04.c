#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h> 
#include <math.h>

#define constE 2.71828182

short continua(void);
short primo(int num);
int main(void);
int menu(void);
double fat(int num);
void happy(int num);
void mersene(int num);
void sprimo(int num);
void gprimo(int a, int b);


//FUN��O MAIN
int main(void){	
	int operation = 0, a=0,b=0,i=0,j=0;
	setlocale(LC_ALL,"");
	
    do {
		operation = menu();
		system("cls");
		system("Pause"); 
		
	    switch(operation)  {
	    //OP��O GOLBACH
		case 1:
			printf("ENCONTRAR TODOS OS PARES DE N�MEROS PRIMOS CUJA SOMA SEJA IGUAL A N NO INTERVALO [4,1000].\n\n");
	        i = 4;
	        for(; i <= 1000; i++)
	        	sprimo(i);
	        printf("\n");
	        system("Pause");
	        break;	
	    //OP��O PRIMOS NO INTERVALO [A.B]
		case 2:			 
			printf("ENCONTRAR TODOS OS PRIMOS NO INTERVALO [A,B].\n\n");
			printf("Insira o intervalo [a, b]: ");
			scanf("%d %d", &a, &b);
			printf("Todos os n�meros no intervalo de [%d, %d] s�o: ",a,b);
			for(; a <= b; a++){
				if(primo(a))
					printf("%2.d ", a);
			}			 	
			printf("\n");
			system("pause");
	        break;	
	    //OP��O PRIMOS G�MEOS NO INTERVALO [A,B]
		case 3:
			printf("ENCONTRAR TODOS OS PRIMOS G�MEOS NO INTERVALO [A,B].\n\n");
			printf("Insira o intervalo [a, b]: ");
			scanf("%d %d", &a, &b);
			gprimo(a,b);			 	
			system("Pause");
			break;	
		//OP��O PRIMOS DE MERSENE
		case 4:
			j = 1;
			printf("ENCONTRAR TODOS OS PRIMOS DE MERSENE NO INTERVALO [1, 30].\n\n");			 
			for(; j <= 30; j++)
				mersene(j);
			printf("\n");
			system("pause");
			break;	
		//OP��O DE N�MEROS FELIZES
		case 5:
			i = 4;
			printf("ENCONTRAR TODOS OS N�MEROS FELIZES NO INTERVALO [4,1000].\n\n");
			printf("Os n�meros felizes no intervalo de [4,1000] s�o: ");
			for(; i <= 1000; i++)
				happy(i);
			printf("\n");
			system("pause");
			break;	
		//OP��O DE APROXIMA��O FATORIAL
		case 6:
			printf("CALCULAR A APROXIMA��O DO FATORIAL DE N.\n\n");
			printf("Insira um n�mero inteiro: ");
			scanf("%d", &a);
			printf("O fatorial aproximado de %d � %lf", a, fat(a));
			printf("\n");
			system("pause");
			break;
		//OP��O SAIR
		case 0:
			printf("\nDesenvolvido por: Murilo Rocha Pereira & Gustavo Marciel Pinheiro Oliveira\nRA: 181250934 & 181253828\nCurso: Ci�ncia da Computa��o\nSemestre: 1�\n");
			return 0;
		//OP��O INVALIDA
		default:
			printf("Insira uma op��o v�lida =].");
			printf("\n");
			system("pause");
			break;	
		}

  } while ( continua() );
  
  printf("\nDesenvolvido por: Murilo Rocha Pereira & Gustavo Marciel Pinheiro Oliveira\nRA: 181250934 & 181253828\nCurso: Ci�ncia da Computa��o\nSemestre: 1�\n");
  system("pause");
  return 0;
	
}

//SHORT PARA VERIFICAR SE O USU�RIO DESEJA REALIZAR UMA NOVA OPERA��O
short continua(void) {
	char ch;

    do{
		system("cls");
       	printf("\n\nDeseja realizar outro opera��o? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
  	}
  	while( (ch != 'S') && (ch != 'N') );

  	if(ch == 'S') 
	  return 1;
  	else 
	  return 0;
}

//FUN��O PARA CONSTRUIR O MENU E RETORNAR A OP��O ESCOLHIDA
int menu(void) {
  int opcao;

  system("CLS");
  printf("\n\t=====Trabalho pr�tico de programa��o - 04=====\n\n");
  printf("1. Encontrar todos os pares de n�meros primos cuja soma seja igual a n no intervalo [4,1000] \n");
  printf("2. Encontrar todos os primos no intervalo [a,b]\n");
  printf("3. Encontrar todos os primos g�meos no intervalo [a,b]\n");
  printf("4. Encontrar todos os primos de Mersene no intervalo [1, 30]\n");
  printf("5. Encontrar todos os n�meros felizes no intervalo [4,1000]\n");
  printf("6. Calcular a aproxima��o do fatorial de n, com 0 <= n <= 30\n");
  printf("0. Sair");
  
  
  printf("\n\nEscolha uma op��o dentre as listadas: ");
  scanf("%d", &opcao);
  
  return(opcao);
}

//FUN��O PARA VERIFICAR SE UM N�MERO � PRIMO
short primo(int num){
	if(num > 1){
        int i = 3;
           
        int exp1 = (int)sqrt((double)num)+1;
           
		if(num == 2)
			return 1;
		if(num%2 == 0)
			return 0;
		for (; i <= exp1; i+=2)
			if (num%i == 0)
				return(0);
		return 1;
    }
    else
    	return 0;
}

//FUN��O PARA ENCONTRAR OS N�MEROS FELIZES
void happy(int num){
	int numcopy = num, stop = 0, soma = 0;
	
	if(num >= 10){
		while(stop == 0){		
			if(num != 0){
				
				int aux = num%10;				
				num /= 10;								
				soma += aux * aux;								
				
			}	
			else{
				if(soma < 10){
					if(soma == 1){								
						printf("%3.d ", numcopy);
						break;
					}		
					else{						
						break;
					}				
				}					
				else{
					num = soma;
					soma = 0;	
				}					
			}		
		}
								
	}			 
}

//FUN��O PARA ENCONTRAR OS PRIMOS DE MERSENE
void mersene(int num){
	int m=0;	
	
	m = (pow((double)2, (double)num)) - 1;
	
	if(primo(m))
		printf("\n%d � um primo de Mersene!\nN� de Mersene correspondente: %d\n", num, m);	
}

//FUN��O PARA ENCONTRAR E RETORNAR A APROXIMA��O FATORIAL DE N
double fat(int num){
	double raiz = 0, frac = 0;
	
	raiz = sqrt(2*M_PI*num);
	frac = pow(num, num)/pow(constE, num);
	
	return raiz*frac;
}

//FUN��O PARA ENCONTRAR OS PRIMOS CUJA SOMA SEJA IGUAL A N
void sprimo(int num){
	if(num >= 4){
		int i = 0;
		int found = 0;
		printf("\nPrimos cuja soma seja igual a %d", num);
		for(; i <= (num/2) + 1; i++){
			if(primo(i)){
				int j = (num/2) + 1;
				for(; j < num; j++){
					if(primo(j)){
						if((j + i) == num){
							printf("\n(%d, %d)", i, j);
							found = 1;	
						}							
					}
				}
			}
		}
		if(!found)
			printf("\nN�o h� primos cuja a soma seja igual a %d", num);
	}
}

//fUN��O PARA ENCONTRAR OS PRIMOS G�MEOS
void gprimo(int a, int b){
	if(a < b){
		printf("S�o primos g�meos: \n");
		int n1 = 1, n2 = 1, linha = 0;
		for(; a <= b; a++){
			if(linha == 3){
				printf("\n");
				linha = 0;
			}				
			if(primo(a)){
				if(n2 >= n1){					
					n1 = a;						
				}	
				else{
					n2 = a;			
				}		
				if((n2 - n1) == 2){
					if(n1 < n2){
						printf("(%4.d, %4.d) ", n1, n2);
						linha++;
					}						
					else{
						printf("(%4.d, %4.d) ", n2, n1);	
						linha++;
					}						
				}
				if((n1 - n2) == 2){
					if(n1 < n2){
						printf("(%4.d, %4.d) ", n1, n2);	
						linha++;
					}						
					else{
						printf("(%4.d, %4.d) ", n2, n1);
						linha++;
					}						
				}	
			}								
		}
		printf("\n")	;
	}	
}
