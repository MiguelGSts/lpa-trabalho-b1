#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include "entrega.h"

#define taxaDist 1.2
#define valProt 7.5
#define entAdic 4

int main(){
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);

    //Variáveis 
    float distKM, peso, subTot, total;
    int mod, opProt, opc;
    int c;
    //============================

    title();
    printf("Informe a distância da entrega: ");
    scanf("%f", &distKM);
    while((c = getchar()) != '\n' && c != EOF); //Limpeza do buffer
    distKM = valiDist(distKM, c);




    return 0;
}