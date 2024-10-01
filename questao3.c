#include <stdio.h>

//Aguinaldo Anselmo da Costa Neto => Arquitetura de Computadores:

void converteBase16Bits(short num) {
    // Verifica se o número é negativo ou positivo
    if (num < 0) {
        // Quando o número é negativo, converte para o complemento de dois
        printf("Número em complemento de dois de 16 bits (Hexadecimal): %04X\n", (unsigned short)num);
    } else {
        // Quando o número é positivo, apenas imprime o valor diretamente
        printf("Número em complemento de dois de 16 bits (Hexadecimal): %04X\n", (unsigned short)num);
    }
}

int main() {
    short numero;

    //Entrada do usuário:
    printf("Digite um número inteiro em base 10 (-32768 a 32767): ");
    scanf("%hd", &numero);

    //Roda a função com o input do usuário
    converteBase16Bits(numero);

    return 0;
}
