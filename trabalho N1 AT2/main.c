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

    do
    {
        printf("Por favor, Digite a quantidade de equipes (entre 3 e 10):");
        scanf("%d", &quantEquipe);
        if (quantEquipe < 3 || quantEquipe > 10)
        {
            printf("Número inválido, por favor, digite um número entre 3 e 10. \n");
        }
    } while (quantEquipe < 3 || quantEquipe > 10);

    do
    {
        printf("Por favor, Digite a quantidade de jogos disputados pelas equipes (entre 1 e 10):");
        scanf("%d", &quantJogos);
        if (quantJogos < 1 || quantJogos > 10)
        {
            printf("Número inválido, por favor, digite um número entre 1 e 10. \n");
        }
    } while (quantJogos < 1 || quantJogos > 10);

    while (opcao != 5)
    {
        printf("\n\n1 - Registrar resultados do campeonato.");
        printf("\n2 - Mostrar resumo do campeonato.");
        printf("\n3 - Mostrar regulamento.");
        printf("\n4 - Simular campanha de uma equipe.");
        printf("\n5 - Encerra sistema.");

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

            for (int i = 1; i <= quantEquipe; i++)
            {
                do
                {
                    printf("\nEQUIPE %d", i);
                    printf("\n\nDigite a quantidade de vitórias: ");
                    scanf("%d", &quantVitorias);
                    printf("\nDigite a quantidade de derrotas: ");
                    scanf("%d", &quantDerrotas);
                    printf("\nDigite a quantidade de empates: ");
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

                printf("Jogos disputados pelas equipes: %d", quantJogos);
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
            }

            printf("\nMaior pontuação: %d pontos (primeira equipe: %d).", maiorPontuacao, equipeMaior);
            printf("\nEquipes empatadas na maior pontuação: %d.", empatesMaior);
            printf("\nMenor pontuação: %d pontos (primeira equipe: %d).", menorPontuacao, equipeMenor);
            printf("\nEquipes empatadas na menor pontuação: %d.\n", empatesMenor);
            registroConcluido = 1;
            break;

        case 2:
            printf("\nResumo do campeonato:\n");
            if (registroConcluido == 0)
            {
                printf("Nenhum registro de resultados foi feito ainda.\n");
            }
            else
            {
                printf("Quantidade de equipes: %d\n", quantEquipe);
                printf("Quantidade de jogos disputados pelas equipes: %d\n", quantJogos);
                printf("A soma dos pontos de todas as equipes foi: %d\n", somaPontos);
                printf("A média de pontos por equipe foi: %.2f\n", (float)somaPontos / quantEquipe);
                printf("Quantidade de equipes com campanha excelente no campeonato foi: %d\n", quantExcelente);
                printf("Quantidade de equipes com campanha boa no campeonato foi: %d\n", quantBoa);
                printf("Quantidade de equipes com campanha regular no campeonato foi: %d\n", quantRegular);
                printf("Quantidade de equipes com campanha ruim no campeonato foi: %d\n", quantRuim);
                printf("A equipe %d obteve a maior pontuação com %d pontos.\n", equipeMaior, maiorPontuacao);
                printf("A equipe %d obteve a menor pontuação com %d pontos.\n", equipeMenor, menorPontuacao);
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
            printf("Simulação de campanha ainda não implementada.\n");
            break;

        case 5:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
        }
    }

    return 0;
}