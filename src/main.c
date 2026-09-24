#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include "entrega.h"


int main(){
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);

    //Variáveis 
    float distKM, peso, subTot, total;
    float taxaPeso, taxaMod;
    int mod, opProt, opc;
    int c;
    //============================

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

    return 0;
}