#include <stdio.h>
#include <stdlib.h>

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

int modMenu(){
    printf("\n=== Modalidade ===\n");
    printf("[1] Econômica\n");
    printf("[2] Expressa\n");
    printf("[3] Prioritária\n");
    printf("\nInsira a modadlidade de entrega: ");
}

int validaMod(int mod){
    int c;
    while(scanf("%d", &mod) != 1 || mod<1 || mod>3){
        while((c = getchar()) != '\n' && c != EOF);
        printf("\n[OPÇÃO INVÁLIDA]\n");
        printf("Informe novamente a modadelidade entrega: ");
    }
    return mod;
}

float adicMod(float subtotal, int opMod){
    float adic;
    if(opMod == 1){
        adic = 0.0;
    }else if(opMod == 2){
        adic = 0.15;
    }else{
        adic = 0.30;
    }

    return subtotal * adic;
}
void limpar_tela() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

int protecMenu(){
    printf("\n=== Serviço Adicional de Proteção ===\n");
    printf("Adicione um serviço de proteção adicional para sua entrega!\nValor: R$7,50\n");
    printf("[1] Contratar serviço\n");
    printf("[0] Não contratar\n");
    printf("Insira a opção desejada: ");
}

int validaProtec(int opProt){
    int c;
    while(scanf("%d", &opProt) != 1 || opProt<0 || opProt>1){
        while((c = getchar()) != '\n' && c != EOF);
        printf("\n[OPÇÃO INVÁLIDA]\n");
        printf("Insira sua opção novamente: ");
    }
}