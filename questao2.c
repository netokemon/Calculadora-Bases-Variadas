#include <stdio.h>
#include <stdint.h>

void printBits(size_t size, void *ptr) {
    unsigned char *b = (unsigned char*) ptr;
    int i, j;
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            printf("%u", (b[i] >> j) & 1);
        }
    }
    printf("\n");
}

void desmembrarFloat(float numero) {
    uint32_t bits;
    *((float*)&bits) = numero;

    int sinal = (bits >> 31) & 1;
    int expoente = (bits >> 23) & 0xFF;
    int expoenteComVies = expoente - 127;
    int fracao = bits & 0x7FFFFF; 

    printf("Número em float: %.6f\n", numero);
    printf("Bits: ");
    printBits(sizeof(float), &numero);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d (Sem viés)\n", expoente);
    printf("Expoente com viés: %d\n", expoenteComVies);
    printf("Fração: 0x%x\n\n", fracao);
}


void desmembrarDouble(double numero) {
    uint64_t bits;
    *((double*)&bits) = numero;

    int sinal = (bits >> 63) & 1;
    int expoente = (bits >> 52) & 0x7FF;
    int expoenteComVies = expoente - 1023; 
    uint64_t fracao = bits & 0xFFFFFFFFFFFFF; 

    printf("Número em double: %.6lf\n", numero);
    printf("Bits: ");
    printBits(sizeof(double), &numero);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d (Sem viés)\n", expoente);
    printf("Expoente com viés: %d\n", expoenteComVies);
    printf("Fração: 0x%llx\n", fracao);
}

int main() {
    float numeroFloat;
    double numeroDouble;

    printf("Digite um número decimal para float: ");
    scanf("%f", &numeroFloat);
    desmembrarFloat(numeroFloat);

    printf("Digite um número decimal para double: ");
    scanf("%lf", &numeroDouble);
    desmembrarDouble(numeroDouble);

    return 0;
}