#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// O objetivo é permitir o cadastro de cartas, a escolha de atributos para comparação e a execução de comparações entre duas cartas escolhidas.

typedef struct {
    // Estrutura que representa uma carta com informações sobre a cidade
    char codigo_cidade[4]; // Código único da cidade
    char nome[50], uf[3]; // Nome e UF da cidade
    int populacao, numero_pontos_turisticos; // População e número de pontos turísticos
    float area, PIB, densidade, PIB_CAP, super_poder; // Atributos numéricos da cidade
} Carta;

typedef struct {
    // Estrutura para armazenar o atributo selecionado para a comparação
    int atributo;
} Atributos;

// Função para exibir as informações de uma carta
void printcarta(Carta carta) {
    // Exibe todos os dados da carta
    printf("Código da Cidade: %.3s\n", carta.codigo_cidade);
    printf("Nome da cidade: %s\n", carta.nome);
    printf("População da cidade: %d habitantes\n", carta.populacao);
    printf("Número de pontos turísticos: %d\n", carta.numero_pontos_turisticos);
    printf("Área: %.2f m²\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Densidade Populacional: %.2f\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.PIB_CAP);
    printf("Super Poder: %.2f\n\n", carta.super_poder);
}

// Função para cadastrar uma nova carta de cidade
Carta cadastrar_carta() {
    Carta carta;
    
    // Solicita ao usuário os dados da carta
    printf("Insira o código da cidade: ");
    scanf("%s", carta.codigo_cidade);

    printf("Insira o nome da cidade: ");
    scanf("%s", carta.nome);

    printf("Insira a UF: ");
    scanf("%s", carta.uf);

    printf("Insira a população: ");
    scanf("%d", &carta.populacao);

    printf("Insira o número de pontos turísticos: ");
    scanf("%d", &carta.numero_pontos_turisticos);

    printf("Insira a área: ");
    scanf("%f", &carta.area);

    printf("Insira o PIB: ");
    scanf("%f", &carta.PIB);

    // Calcula a densidade populacional e o PIB per capita
    carta.densidade = (float) carta.populacao / carta.area;
    carta.PIB_CAP = (float) carta.PIB / carta.populacao;

    // Calcula o valor do Super Poder, que é uma soma de vários atributos
    carta.super_poder = carta.populacao + carta.numero_pontos_turisticos + carta.area + carta.PIB + carta.densidade + carta.PIB_CAP;
    
    return carta;
}

// Função para exibir o menu de atributos e retornar a escolha do usuário
Atributos menuAtributo(int d){
    Atributos atributo;
    
    // Exibe o menu de atributos disponíveis para comparação
    printf(">>>>> Atributos <<<<<\n");
    printf("[1] População da cidade\n");
    printf("[2] Número de pontos turísticos\n");
    printf("[3] Área\n");
    printf("[4] PIB\n");
    printf("[5] Densidade Populacional\n");
    printf("[6] PIB per capita\n");
    printf("[7] Super Poder\n");
    
    // Solicita ao usuário que escolha um atributo
    printf("Escolha o %dº atributo: ", d+1);
    scanf("%d", &atributo.atributo);
    
    return atributo;
}

// Função principal
int main() {
    // Variáveis principais
    int num_cartas;
    
    // Solicita o número de cartas a serem cadastradas
    printf("Digite quantas cartas deseja cadastrar: ");
    scanf("%d", &num_cartas);

    // Verifica se a quantidade de cartas é válida
    if (num_cartas <= 1) {
        printf("##### Quantidade Invalida! #####\n");
        return 0;
    }
    
    // Cria um vetor de cartas
    Carta cartas[num_cartas];
    
    // Loop para cadastrar todas as cartas
    for (size_t i = 0; i < num_cartas; i++) {
        cartas[i] = cadastrar_carta();
        printf("\nA carta %ld foi cadastrada com sucesso.\n\n", i+1);
        printcarta(cartas[i]);
    }
    
    // Comparação de Cartas
    int cartaPrimeira, cartaSegunda, quantAtributos;
    int pontosPrimeira = 0, pontosSegunda = 0;

    // Solicita a quantidade de atributos a serem comparados
    printf("\nDigite quantos atributos gostaria de comparar: ");
    scanf("%d", &quantAtributos);

    // Cria um vetor de atributos selecionados
    Atributos atributos[quantAtributos];
    
    // Loop para o usuário selecionar os atributos para comparação
    for (size_t i = 0; i < quantAtributos; i++) {
        atributos[i] = menuAtributo(i);
    }

    // Exibe as cartas disponíveis para comparação
    printf("*** Selecione as cartas para comparar ***\n");
    for (size_t i = 0; i < num_cartas; i++) {
        printf("[%ld] %s\n", i+1, cartas[i].nome);
    }
    
    // Solicita as cartas a serem comparadas
    printf("\nDigite a primeira carta: ");
    scanf("%d", &cartaPrimeira);
    printf("\nDigite a segunda carta: ");
    scanf("%d", &cartaSegunda);  
    
    // Exibe a comparação entre as duas cartas selecionadas
    printf("\nComparação entre %s e %s\n", cartas[cartaPrimeira-1].nome, cartas[cartaSegunda-1].nome);
    
    // Loop para comparar os atributos selecionados
    for (size_t i = 0; i < quantAtributos; i++) {
       switch (atributos[i].atributo) {
        case 1: // Comparação da população
            if (cartas[cartaPrimeira-1].populacao > cartas[cartaSegunda-1].populacao) {
                printf("População: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].populacao < cartas[cartaSegunda-1].populacao) {
                printf("População: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("População: Empate\n");
            break;
        case 2: // Comparação do número de pontos turísticos
            if (cartas[cartaPrimeira-1].numero_pontos_turisticos > cartas[cartaSegunda-1].numero_pontos_turisticos) {
                printf("Número de Pontos Turísticos: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].numero_pontos_turisticos < cartas[cartaSegunda-1].numero_pontos_turisticos) {
                printf("Número de Pontos Turísticos: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("Número de Pontos Turísticos: Empate\n");
            break;
        case 3: // Comparação da área
            if (cartas[cartaPrimeira-1].area > cartas[cartaSegunda-1].area) {
                printf("Área: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].area < cartas[cartaSegunda-1].area) {
                printf("Área: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("Área: Empate\n");
            break;
        case 4: // Comparação do PIB
            if (cartas[cartaPrimeira-1].PIB > cartas[cartaSegunda-1].PIB) {
                printf("PIB: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].PIB < cartas[cartaSegunda-1].PIB) {
                printf("PIB: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("PIB: Empate\n");
            break;
        case 5: // Comparação da densidade populacional
            if (cartas[cartaPrimeira-1].densidade < cartas[cartaSegunda-1].densidade) {
                printf("Densidade Populacional: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].densidade > cartas[cartaSegunda-1].densidade) {
                printf("Densidade Populacional: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("Densidade Populacional: Empate\n");
            break;
        case 6: // Comparação do PIB per capita
            if (cartas[cartaPrimeira-1].PIB_CAP > cartas[cartaSegunda-1].PIB_CAP) {
                printf("PIB per Capita: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].PIB_CAP < cartas[cartaSegunda-1].PIB_CAP) {
                printf("PIB per Capita: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("PIB per Capita: Empate\n");
            break;
        case 7: // Comparação do Super Poder
            if (cartas[cartaPrimeira-1].super_poder > cartas[cartaSegunda-1].super_poder) {
                printf("Super Poder: %s vence\n", cartas[cartaPrimeira-1].nome);
                pontosPrimeira++;
            }
            else if (cartas[cartaPrimeira-1].super_poder < cartas[cartaSegunda-1].super_poder) {
                printf("Super Poder: %s vence\n", cartas[cartaSegunda-1].nome);
                pontosSegunda++;
            }
            else
                printf("Super Poder: Empate\n");
            break;
        default:
            break;
       }
    }

    // Exibe o vencedor final
    if (pontosPrimeira > pontosSegunda)
        printf("\nA carta da cidade de %s venceu a comparação!\n", cartas[cartaPrimeira-1].nome);
    else if (pontosPrimeira < pontosSegunda)
        printf("\nA carta da cidade de %s venceu a comparação!\n", cartas[cartaSegunda-1].nome);
    else
        printf("\nA comparação terminou em empate!\n");
    
    return 0;
}
