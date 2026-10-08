#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "pt-BR.UTF-8");
    system("chcp 65001 > nul");

    int quantEquipe, quantJogos, opcao = 1, quantVitorias, quantDerrotas, quantEmpates;
    int somaPontos = 0;
    int quantExcelente = 0, quantBoa = 0, quantRegular = 0, quantRuim = 0;
    int maiorPontuacao = -1, equipeMaior = 0, empatesMaior = 0;
    int menorPontuacao = 9999, equipeMenor = 0, empatesMenor = 0;
    int registroConcluido = 0;
    int totalVitorias = 0, totalDerrotas = 0, totalEmpates = 0;

    printf("--- SISTEMA DE REGISTRO DE RESULTADOS ---\n");
    
    do
    {
        printf("\nPor favor, Digite a quantidade de equipes (entre 3 e 10):");
        scanf("%d", &quantEquipe);
        if (quantEquipe < 3 || quantEquipe > 10)
        {
            printf("\nNúmero inválido, por favor, digite um número entre 3 e 10. \n");
        }
    } while (quantEquipe < 3 || quantEquipe > 10);

    do
    {
        printf("Por favor, Digite a quantidade de jogos disputados pelas equipes (entre 1 e 10):");
        scanf("%d", &quantJogos);
        if (quantJogos < 1 || quantJogos > 10)
        {
            printf("\nNúmero inválido, por favor, digite um número entre 1 e 10. \n");
        }
    } while (quantJogos < 1 || quantJogos > 10);

    while (opcao != 5)
    {
        printf("\n\n--- MENU ---");
        printf("\n1 - Registrar resultados do campeonato.");
        printf("\n2 - Mostrar resumo do campeonato.");
        printf("\n3 - Mostrar regulamento.");
        printf("\n4 - Simular campanha de uma equipe.");
        printf("\n5 - Encerrar o sistema.");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            somaPontos = 0;
            quantExcelente = 0;
            quantBoa = 0;
            quantRegular = 0;
            quantRuim = 0;
            maiorPontuacao = -1;
            menorPontuacao = 9999;
            equipeMaior = 0;
            equipeMenor = 0;
            empatesMaior = 0;
            empatesMenor = 0;
            totalVitorias = 0;
            totalDerrotas = 0;
            totalEmpates = 0;

            printf("\n--- REGISTRO DE RESULTADOS ---\n");

            for (int i = 1; i <= quantEquipe; i++)
            {
                do
                {
                    printf("\nEQUIPE %d", i);
                    printf("\n\nDigite a quantidade de vitórias: ");
                    scanf("%d", &quantVitorias);
                    printf("Digite a quantidade de derrotas: ");
                    scanf("%d", &quantDerrotas);
                    printf("Digite a quantidade de empates: ");
                    scanf("%d", &quantEmpates);

                    if (quantVitorias + quantDerrotas + quantEmpates != quantJogos)
                    {
                        printf("\n\nA quantidade digitada não corresponde à quantidade de jogos disputados.\nDigite novamente.\n");
                    }
                    else if (quantVitorias < 0 || quantDerrotas < 0 || quantEmpates < 0)
                    {
                        printf("Erro: Nenhum resultado pode ser negativo.\n");
                    }
                } while ((quantVitorias < 0 || quantDerrotas < 0 || quantEmpates < 0) ||
                         (quantVitorias + quantDerrotas + quantEmpates != quantJogos));

                printf("\n\nJogos disputados pelas equipes: %d", quantJogos);
                printf("\nEquipe %d - Vitórias: %d, Derrotas: %d, Empates: %d", i, quantVitorias, quantDerrotas, quantEmpates);

                int pontos = (quantVitorias * 3) + quantEmpates;
                printf("\nPontuação: %d pontos\n", pontos);
                somaPontos += pontos;

                if (pontos > maiorPontuacao)
                {
                    maiorPontuacao = pontos;
                    equipeMaior = i;
                    empatesMaior = 1;
                }
                else if (pontos == maiorPontuacao)
                {
                    empatesMaior++;
                }

                if (pontos < menorPontuacao)
                {
                    menorPontuacao = pontos;
                    equipeMenor = i;
                    empatesMenor = 1;
                }
                else if (pontos == menorPontuacao)
                {
                    empatesMenor++;
                }

                if (pontos >= 15)
                {
                    printf("Situação: Excelente campanha\n");
                    quantExcelente++;
                }
                else if (pontos >= 10)
                {
                    printf("Situação: Boa campanha\n");
                    quantBoa++;
                }
                else if (pontos >= 5)
                {
                    printf("Situação: Campanha regular\n");
                    quantRegular++;
                }
                else
                {
                    printf("Situação: Campanha ruim\n");
                    quantRuim++;
                }

                totalVitorias += quantVitorias;
                totalDerrotas += quantDerrotas;
                totalEmpates += quantEmpates;
            }

            printf("\n\nMaior pontuação: %d pontos (equipe: %d).", maiorPontuacao, equipeMaior);
            printf("\nEquipes empatadas na maior pontuação: %d.", empatesMaior);
            printf("\nMenor pontuação: %d pontos (equipe: %d).", menorPontuacao, equipeMenor);
            printf("\nEquipes empatadas na menor pontuação: %d.\n", empatesMenor);
            registroConcluido = 1;
            break;

        case 2:
            printf("\n--- RESUMO DO CAMPEONATO ---\n");
            if (registroConcluido == 0)
            {
                printf("Nenhum registro de resultados foi feito ainda.\n");
            }
            else
            {
                printf("Quantidade de equipes: %d\n", quantEquipe);
                printf("Quantidade de jogos disputados pelas equipes: %d\n", quantJogos);
                printf("Quantidade de vitórias total: %d\n", totalVitorias);
                printf("Quantidade de derrotas total: %d\n", totalDerrotas);
                printf("Quantidade de empates total: %d\n", totalEmpates);
                printf("A soma dos pontos de todas as equipes foi: %d\n", somaPontos);
                printf("A média de pontos por equipe foi: %.2f\n", (float)somaPontos / quantEquipe);
                printf("Quantidade de equipes com campanha excelente no campeonato foi: %d\n", quantExcelente);
                printf("Quantidade de equipes com campanha boa no campeonato foi: %d\n", quantBoa);
                printf("Quantidade de equipes com campanha regular no campeonato foi: %d\n", quantRegular);
                printf("Quantidade de equipes com campanha ruim no campeonato foi: %d\n", quantRuim);
                if(maiorPontuacao == menorPontuacao){
                    printf("Todas as equipes obtiveram a mesma pontuação de %d pontos.\n", maiorPontuacao);
                }
                else{
                    printf("A equipe %d obteve a maior pontuação com %d pontos.\n", equipeMaior, maiorPontuacao);
                    printf("A equipe %d obteve a menor pontuação com %d pontos.\n", equipeMenor, menorPontuacao);
                }
                    printf("A quantidade de equipes empatadas na maior pontuação foi: %d\n", empatesMaior);
                    printf("A quantidade de equipes empatadas na menor pontuação foi: %d\n", empatesMenor);
                
            }
            break;

        case 3:
            printf("\n--- REGULAMENTO ---\n");
            printf("Cada vitória equivale a 3 pontos.\n");
            printf("Cada empate equivale a 1 ponto.\n");
            printf("Cada derrota equivale a 0 pontos.\n");
            printf("15 ou mais pontos: campanha excelente.\n");
            printf("Entre 10 e 14 pontos: campanha boa.\n");
            printf("Entre 5 e 9 pontos: campanha regular.\n");
            printf("Menos de 5 pontos: campanha ruim.\n");
            printf("Você pode registrar de 3 a 10 equipes e de 1 a 10 jogos por equipe.\n");
            break;

        case 4:
            int quantSimulacoes, quantVitoriasSim, quantDerrotasSim, quantEmpatesSim, quantJogosSim, quantPontosSim = 0, somaPontosSim = 0;

            printf("\n--- SIMULAÇÃO DE CAMPANHA ---\n");

            do{
                printf("Digite a quantidade de simulações que deseja realizar(entre 1 e 5): ");
            scanf("%d", &quantSimulacoes);
            }while(quantSimulacoes < 1 || quantSimulacoes > 5);

            do{
                printf("Digite a quantidade de jogos que deseja simular(entre 1 e 10): ");
                scanf("%d", &quantJogosSim);
            }while(quantJogosSim < 1 || quantJogosSim > 10);

            for(int i = 1; i <= quantSimulacoes; i++){
                do{
                printf("\nSimulação %d:\n", i);
                printf("Digite a quantidade de vitórias: ");
                scanf("%d", &quantVitoriasSim);
                printf("Digite a quantidade de derrotas: ");
                scanf("%d", &quantDerrotasSim);
                printf("Digite a quantidade de empates: ");
                scanf("%d", &quantEmpatesSim);

                    if(quantVitoriasSim + quantDerrotasSim + quantEmpatesSim != quantJogosSim){
                        
                        printf("\n\nA quantidade digitada não corresponde à quantidade de jogos disputados.\nDigite novamente.\n");
                    }
                    else if(quantVitoriasSim < 0 || quantDerrotasSim < 0 || quantEmpatesSim < 0){
                        printf("Erro: Nenhum resultado pode ser negativo.\n");
                    }

                }while((quantVitoriasSim < 0 || quantDerrotasSim < 0 || quantEmpatesSim < 0) ||
                         (quantVitoriasSim + quantDerrotasSim + quantEmpatesSim != quantJogosSim));

                printf("\nJogos disputados na %d simulação: %d", i, quantJogosSim);
                printf("\nSimulação %d - Vitórias: %d, Derrotas: %d, Empates: %d", i, quantVitoriasSim, quantDerrotasSim, quantEmpatesSim);

                quantPontosSim = (quantVitoriasSim * 3) + quantEmpatesSim;
                printf("\nPontuação: %d pontos\n", quantPontosSim);
                somaPontosSim += quantPontosSim;

                if (quantPontosSim >= 15)
                {
                    printf("Situação: Excelente campanha\n");
                }
                else if (quantPontosSim >= 10)
                {
                    printf("Situação: Boa campanha\n");
                }
                else if (quantPontosSim >= 5)
                {
                    printf("Situação: Campanha regular\n");
                }
                else
                {
                    printf("Situação: Campanha ruim\n");
                }
            }
            
            break;

        case 5:
            printf("\n\nSistema encerrado com sucesso.\nObrigado por utilizar o sistema.\n");
            break;

        default:
            printf("Opção inválida, tente novamente.\n");
            break;
        }
    }

    return 0;
}