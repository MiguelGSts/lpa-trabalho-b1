#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include "entrega.h"
#include <stdlib.h>

int main(){
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);

    float distKM, peso, subTot, total;
    float taxaPeso, taxaMod;
    int mod, opProt, opc;
    int c;
    const float taxaProtec = 7.5;

    title();
    printf("Informe a distância da entrega: ");
    scanf("%f", &distKM);
    while((c = getchar()) != '\n' && c != EOF); //Limpeza do buffer
    distKM = validaVal(distKM);
    subTot = valKM(distKM);
    
    printf("Informe o peso da carga de entrega: ");
    scanf("%f", &peso);
    while((c = getchar()) != '\n' && c != EOF);
    peso = validaVal(peso);
    taxaPeso = adicPeso(subTot, peso);

    modMenu();
    scanf("%d", &mod);
    while(mod<1 || mod>3){
        printf("\n[OPÇÃO INVÁLIDA]\n");
        printf("Informe novamente a modadelidade entrega: ");
        scanf("%d", &mod);
    }
    taxaMod = adicMod(subTot, mod);

    protecMenu();
    while(scanf("%d", &opProt) != 1 || opProt<0 || opProt>1){
        while((c = getchar()) != '\n' && c != EOF);
        printf("\n[OPÇÃO INVÁLIDA]\n");
        printf("Insira sua opção novamente: ");
    }
    if(opProt == 1){
        subTot += taxaProtec;
    }
    

    /*Método de Verificação (RETIRA-LO AO FINAL PARA ENTREGA)
    printf("Distância: %.2f; Peso: %.2f; Modalidade: %d\n", distKM, peso, mod);
    printf("Subtotal: %.2f\n", subTot);
    printf("Taxa por peso: %.2f; Taxa por modalidade: %.2f\n", taxaPeso, taxaMod);
    */
    return 0;
}