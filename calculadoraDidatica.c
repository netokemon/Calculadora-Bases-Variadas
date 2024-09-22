#include <stdio.h>

int valorInput = 0.0;
int valorBinario[32];
char valorHexa[32];

void converterBinario(int num){
    int contador = 0;
    while(num > 0){
        valorBinario[contador] = num % 2;
        num = num/2;
        contador++;
    }

    for(int i = contador - 1; i >= 0; i--){
        printf("Seu numero em binario eh: %d", valorBinario[i]);
    }
}

void converterHexa(int num){
    int contador = 0;

    while (num > 0){
        int resto = num % 16;
        if (resto < 10){
            valorHexa[contador] = resto + '0';
        } 
        else{
            valorHexa[contador] = resto - 10 + 'A';
        }
        num = num / 16;
        contador++;
    }
    for(int i = contador-1; i >= 0; i--){
        printf("Seu numero em hexadecimal eh: %c", valorHexa[i]);
    }

}
int main(){

    printf("Bem-vindo a calculadora didatica! primeiramente insira o valor a ser convertido.\n");
    scanf("%d", &valorInput);
    converterBinario(valorInput);

    return 0;
}