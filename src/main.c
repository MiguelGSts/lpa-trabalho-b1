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
    float totFinal = 0, maiorValor = 0, menorValor = 0;
    int mod, opProt, tentEntrega;
    int qntEntrega = 0, opProcess, qntEco = 0, qntExpres = 0, qntPriori = 0;
    int c;
    const float taxaProtec = 7.5;
    const float valorTenta = 4.0;

    do{
        title();
        printf("Informe a distância da entrega: ");
        distKM = validaVal();
        subTot = valKM(distKM);
        
        printf("Informe o peso da carga de entrega: ");
        peso = validaVal();
        taxaPeso = adicPeso(subTot, peso);

        modMenu();
        mod = validaMod();
        if(mod == 1){
            qntEco++;
        }else if(mod == 2){
            qntExpres++;
        }else{
            qntPriori++;
        }
        taxaMod = adicMod(subTot, mod);

        protecMenu();
        opProt = validaProtec();
        if(opProt == 1){
            subTot += taxaProtec;
        }
        
        tentaAdic();
        tentEntrega = validaTenta();
        subTot += (tentEntrega * valorTenta);

        limpar_tela();
        total = subTot + taxaPeso + taxaMod;
        printf("Total do valor da entrega: R$%.2f\n", total);
        
        qntEntrega++;
        totFinal += total;
        if(total>maiorValor){
            maiorValor = total;
        }else if(total<menorValor){
            menorValor = total;
        }
        title();
        printf("Deseja processar outra entrega?\n([1] para Sim e [0] para Não): ");
        opProcess = processValida();
        limpar_tela();

    }while(opProcess != 0);

    title();

    printf("=== Resumo dos Processamentos ===\n");
    printf("-> Quantidade de entregas processadas: %d\n", qntEntrega);
    printf("-> Valor total de todos os processamentos: R$%.2f\n", totFinal);
    printf("-> Valor médio das entregas: R$%.2f\n", totFinal/qntEntrega);
    printf("-> Quantidade de entregas Econômicas: %d\n", qntEco);
    printf("-> Quantidade de entregas Expressas: %d\n", qntExpres);
    printf("-> Quantidade de entregas Prioritárias: %d\n", qntPriori);
    printf("-> Maior valor de entrega encontrado: R$%.2f\n", maiorValor);
    printf("-> Menor valor de entrega encontrado: R$%.2f\n", menorValor);
    /*Método de Verificação (RETIRA-LO AO FINAL PARA ENTREGA)
    printf("Distância: %.2f; Peso: %.2f; Modalidade: %d\n", distKM, peso, mod);
    printf("Subtotal: %.2f\n", subTot);
    printf("Taxa por peso: %.2f; Taxa por modalidade: %.2f\n", taxaPeso, taxaMod);
    */
    return 0;
}