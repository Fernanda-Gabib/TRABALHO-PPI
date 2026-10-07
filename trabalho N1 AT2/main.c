#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main (){
    setlocale(LC_ALL, "pt-br.UTF-8"); 
    system("chcp 65001 > nul"); 
    //quant = quantidade. 

    int quantEquipe, quantJogos, opcao = 1, quantVitorias, quantDerrotas, quantEmpates ; 


    do{
        printf("Por favor, Digite a quantidade de equipes (entre 3 e 10):");
        scanf("%d", &quantEquipe); 
        if(quantEquipe < 3 || quantEquipe > 10  ){
            printf("Número inválido, por favor, digite um número entre 3 e 10. \n"); 
        }
    } while (quantEquipe < 3 || quantEquipe > 10 ); 
    do{
        printf("Por favor, Digite a quantidade de jogos disputados pelas equipes (entre 1 e 10):");
        scanf("%d", &quantJogos); 
        if(quantJogos < 1 || quantJogos > 10 ){
            printf("Número inválido, por favor, digite um número entre 3 e 10. \n"); 
        }
    } while(quantJogos < 1 || quantJogos > 10); 

    while(opcao != 5){
        printf("\n\n1 - Registrar resultados do campeonato.");
        printf("\n2 - Mostrar resumo do campeonato.");
        printf("\n3 - Mostrar regulamento.");
        printf("\n4 - Simular campanha de uma equipe.");
        printf("\n5 - Encerra sistema.");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                for(int i = 1; i <= quantEquipe; i++){
                    do{
                    printf("\nEQUIPE %d", i);
                    printf("\n\nDigite a quantidade de vitórias: ");
                    scanf("%d", &quantVitorias);
                    printf("\nDigite a quantidade de derrotas: ");
                    scanf("%d", &quantDerrotas);
                    printf("\nDigite a quantidade de empates: ");
                    scanf("%d", &quantEmpates);

                    if(quantVitorias + quantDerrotas + quantEmpates != quantJogos){
                        printf("\n\nA quantidade digitada supera a quantidade de jogos disputados.\nDigite novamente.\n");
                    }
                    } while(quantVitorias + quantDerrotas + quantEmpates != quantJogos);
                }
            break;
            case 2: 

            break;
            case 3: 

            break;
            case 4: 

            break;

            case 5:
                printf("Encerrando...");
            break;
            default:
                printf("Opção inválida.");
            break; 
        }
    }

    return 0; 
}