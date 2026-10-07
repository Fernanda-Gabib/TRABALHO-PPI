#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main (){
    setlocale(LC_ALL, "pt-br.UTF-8"); 
    system("chcp 65001 > nul"); 
    //quant = quantidade. 

    int quantEquipe, quantJogos; 
    do{
        printf("Por favor, Digite a quantidade de equipes (entre 3 e 10):\t");
        scanf("%d", &quantEquipe); 
        if(quantEquipe < 3 || quantEquipe > 10  ){
            printf("Número inválido, por favor, digite um número entre 3 e 10. \n"); 
        }
    } while (quantEquipe < 3 || quantEquipe > 10 ); 
    do{
        printf("Por favor, Digite a quantidade de jogos disputados pelas equipes (entre 1 e 10):\t");
        scanf("%d", &quantJogos); 
        if(quantJogos < 1 || quantJogos > 10 ){
            printf("Número inválido, por favor, digite um número entre 3 e 10. \n"); 
        }
    } while(quantJogos < 1 || quantJogos > 10); 

    
    
    

    return 0; 
}