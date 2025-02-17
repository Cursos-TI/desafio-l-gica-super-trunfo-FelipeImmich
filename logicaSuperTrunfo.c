#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.


typedef struct {
    char codigo_cidade[4];
    char nome[50], uf[3];
    int populacao, numero_pontos_turisticos;
    float area, PIB, densidade, PIB_CAP, super_poder;
} Carta;

typedef struct{
    int atributo;
} Atributos;

// Função de exibir a carta
void printcarta(Carta carta){
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

// Função para cadastrar a carta
Carta cadastrar_carta() {
    Carta carta;
    
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

    // Calculando densidade populacional e PIB per capita
    carta.densidade = (float) carta.populacao / carta.area;
    carta.PIB_CAP = (float) carta.PIB / carta.populacao;

    // Calculando o Super Poder
    carta.super_poder = carta.populacao + carta.numero_pontos_turisticos + carta.area + carta.PIB + carta.densidade + carta.PIB_CAP;
    
    return carta;
}

Atributos menuAtributo(int d){
    Atributos atributo;
    printf(">>>>> Atributos <<<<<\n");
    printf("[1] População da cidade\n");
    printf("[2] Número de pontos turísticos\n");
    printf("[3] Área\n");
    printf("[4] PIB\n");
    printf("[5] Densidade Populacional\n");
    printf("[6] PIB per capita\n");
    printf("[7] Super Poder\n");
    printf("Escolha o %dº atributo: ", d+1);
    scanf("%d", &atributo.atributo);
    return atributo;
}

    // Inicio
int main() {
    //Quantidade de cartas
    int num_cartas;
    printf("Digite quantas cartas deseja cadastrar: ");
    scanf("%d", &num_cartas);

    //verificando se entrada valida
    if (num_cartas <= 1)
    {
        printf("##### Quantidade Invalida! #####\n");
        return 0;
    }
    
    //iniciando as cartas
    Carta cartas[num_cartas];
    
    //Loop para cadastrar todas
    for (size_t i = 0; i < num_cartas; i++){
        cartas[i] = cadastrar_carta();
        printf("\nA carta %ld foi cadastrada com sucesso.\n\n", i+1);
        printcarta(cartas[i]);
    
    }
    
    // Comparação de Cartas:
    int cartaPrimeira, cartaSegunda, quantAtributos;

    printf("\nDigite quantos atributos gostaria de comparar: ");
    scanf("%d", &quantAtributos);

    Atributos atributos[quantAtributos];
    for (size_t i = 0; i < quantAtributos; i++)
    {
        atributos[i] = menuAtributo(i);
    };

    printf("*** Selecione as cartas para comparar ***\n");
    for (size_t i = 0; i < num_cartas; i++)
    {
        printf("[%ld] %s\n",i+1,cartas[i].nome);
    }
    
    printf("\nDigite a primeira carta: ");
    scanf("%d", &cartaPrimeira);
    printf("\nDigite a segunda carta: ");
    scanf("%d", &cartaSegunda);  
    
    // Comparando
    

    printf("\nComparação entre %s e %s\n", cartas[cartaPrimeira-1].nome, cartas[cartaSegunda-1].nome);
    for (size_t i = 0; i < quantAtributos; i++)
    {
       switch (atributos[i].atributo)
       {
        case 1: //populacao
            if (cartas[cartaPrimeira-1].populacao > cartas[cartaSegunda-1].populacao)
                printf("População: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].populacao < cartas[cartaSegunda-1].populacao)
                printf("População: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("População: Empate\n");
            break;
        case 2: //numero de pontos turisticos
            if (cartas[cartaPrimeira-1].numero_pontos_turisticos > cartas[cartaSegunda-1].numero_pontos_turisticos)
                printf("Número de Pontos Turísticos: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].numero_pontos_turisticos < cartas[cartaSegunda-1].numero_pontos_turisticos)
                printf("Número de Pontos Turísticos: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("Número de Pontos Turísticos: Empate\n");
            break;
        case 3: // area
            if (cartas[cartaPrimeira-1].area > cartas[cartaSegunda-1].area)
                printf("Área: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].area < cartas[cartaSegunda-1].area)
                printf("Área: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("Área: Empate\n");
            break;
        case 4: //pib
            if (cartas[cartaPrimeira-1].PIB > cartas[cartaSegunda-1].PIB)
                printf("PIB: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].PIB < cartas[cartaSegunda-1].PIB)
                printf("PIB: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("PIB: Empate\n");
            break;
        case 5: //densidade
            if (cartas[cartaPrimeira-1].densidade < cartas[cartaSegunda-1].densidade)
                printf("Densidade Populacional: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].densidade > cartas[cartaSegunda-1].densidade)
                printf("Densidade Populacional: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("Densidade Populacional: Empate\n");
            break;
        case 6: //PIB PER CAPITA
            if (cartas[cartaPrimeira-1].PIB_CAP > cartas[cartaSegunda-1].PIB_CAP)
                printf("PIB per Capita: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].PIB_CAP < cartas[cartaSegunda-1].PIB_CAP)
                printf("PIB per Capita: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("PIB per Capita: Empate\n");
            break;
        case 7: //SUPER PODER
            if (cartas[cartaPrimeira-1].super_poder > cartas[cartaSegunda-1].super_poder)
                    printf("Super Poder: %s vence\n", cartas[cartaPrimeira-1].nome);
            else if (cartas[cartaPrimeira-1].super_poder < cartas[cartaSegunda-1].super_poder)
                printf("Super Poder: %s vence\n", cartas[cartaSegunda-1].nome);
            else
                printf("Super Poder: Empate\n");
            break;
        default:
            break;
       }
    }
    return 0;
}
