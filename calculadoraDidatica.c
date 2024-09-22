#include <stdio.h>

int valorInput = 0.0;
int valorBinario[32];
char valorHexa[32];
int valorOcta[32];

void converterParaBinario(int numero) {
    int binario[32];
    int i = 0;


    while (numero > 0) {
        binario[i] = numero % 2; 
        numero = numero / 2;
        i++;
    }

    printf("O número em binário é: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
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
    printf("\n");

}
void converterOcta(int num){
    int contador = 0;

    while(num > 0){
        valorOcta[contador] = num % 8;
        num = num / 8;
        contador++;
    }

    for(int i = contador-1; i >= 0; i--){
        printf("Seu numero em base 8 eh: %d", valorOcta[i]);
    }
    printf("\n");


}

void converterParaBCD(int numero) {
    int digito;

    printf("O número em BCD é: ");


    int potenciaDeDez = 1;
    while (numero / potenciaDeDez > 0) {
        potenciaDeDez *= 10;
    }
    potenciaDeDez /= 10;

    while (potenciaDeDez > 0) {
        digito = numero / potenciaDeDez; 
        numero = numero % potenciaDeDez; 
        potenciaDeDez /= 10;


        switch(digito) {
            case 0: printf("0000 "); break;
            case 1: printf("0001 "); break;
            case 2: printf("0010 "); break;
            case 3: printf("0011 "); break;
            case 4: printf("0100 "); break;
            case 5: printf("0101 "); break;
            case 6: printf("0110 "); break;
            case 7: printf("0111 "); break;
            case 8: printf("1000 "); break;
            case 9: printf("1001 "); break;
        }
    }
    printf("\n");
}


int main(){

    printf("Bem-vindo a calculadora didatica! primeiramente insira o valor a ser convertido.\n");
    scanf("%d", &valorInput);
    converterParaBinario(valorInput);
    converterHexa(valorInput);
    converterOcta(valorInput);
    converterParaBCD(valorInput);


    return 0;
}