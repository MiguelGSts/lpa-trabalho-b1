#include <stdio.h>

void title(){
    printf("==============\n");
    printf(" ENTREGAS BSB \n");
    printf("==============\n\n");
}
float valiDist(float dist, int c){
    if(dist <= 0){
        while(dist <= 0){
            printf("[VALOR INVÁLIDO]\n");
            printf("Informe novamente a distância da entrega: ");
            scanf("%f", &dist);
            while((c = getchar()) != '\n' && c != EOF);
        }
        return dist;
    }else{
        return dist;
    }
}