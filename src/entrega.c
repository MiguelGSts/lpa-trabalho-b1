#include <stdio.h>

void title(){
    printf("==============\n");
    printf(" ENTREGAS BSB \n");
    printf("==============\n\n");
}

float validaVal(float valor){
    int c;
    
    while(valor <= 0){
        printf("[VALOR INVÁLIDO]\n");
        printf("Informe o valor novamente: ");
        scanf("%f", &valor);
        while((c = getchar()) != '\n' && c != EOF);}
    return valor;
}
