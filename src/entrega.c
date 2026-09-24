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

float valKM(float dist){
    const float taxaKM = 1.2;
    int valParcela;

    if(dist<=5.0){
        valParcela = 8;
    }else if(dist<=15.0){
        valParcela = 12;
    }else if(dist<=30.0){
        valParcela = 18;
    }else{
        valParcela = 25;
    }
    return valParcela + (dist * taxaKM);
}

float adicPeso(float subtotal, float peso){
    float adic;
    
    if(peso <= 2){
        adic = 0;
    }else if(peso <= 5){
        adic = 0.05;
    }else if(peso <= 10){
        adic = 0.10;
    }else{
        adic = 0.20; 
    }
    return subtotal * adic;
}