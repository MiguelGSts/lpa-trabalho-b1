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
    int mod, opProt, tentEntrega;
    int c;
    const float taxaProtec = 7.5;
    const float valorTenta = 4.0;

    title();
    printf("Informe a distância da entrega: ");
    while(scanf("%f", &distKM) != 1){
        while((c = getchar() != '\n' && c != EOF));
        printf("[VALOR INVÁLIDO]\n");
        printf("Insira a distância novamente: ");
    }
    while((c = getchar()) != '\n' && c != EOF); //Limpeza do buffer
    distKM = validaVal(distKM);
    subTot = valKM(distKM);
    
    printf("Informe o peso da carga de entrega: ");
    while(scanf("%f", &peso) != 1){
        while((c = getchar() != '\n' && c != EOF));
        printf("[VALOR INVÁLIDO]\n");
        printf("Insira a distância novamente: ");
    }
    while((c = getchar()) != '\n' && c != EOF);
    peso = validaVal(peso);
    taxaPeso = adicPeso(subTot, peso);

    mod = validaMod(modMenu());
    taxaMod = adicMod(subTot, mod);

    opProt = validaProtec(protecMenu());
    if(opProt == 1){
        subTot += taxaProtec;
    }
    
    tentaAdic();
    tentEntrega = validaTenta();
    subTot += (tentEntrega * valorTenta);

    /*Método de Verificação (RETIRA-LO AO FINAL PARA ENTREGA)
    printf("Distância: %.2f; Peso: %.2f; Modalidade: %d\n", distKM, peso, mod);
    printf("Subtotal: %.2f\n", subTot);
    printf("Taxa por peso: %.2f; Taxa por modalidade: %.2f\n", taxaPeso, taxaMod);
    */
    return 0;
}