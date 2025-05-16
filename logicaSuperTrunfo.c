#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

#include <string.h>  // Adicionada para usar strcmp()

// Função para exibir o menu e capturar uma escolha válida
int escolherAtributo(int jaEscolhido) {
    int opcao;
    while (1) {
        printf("\nEscolha um atributo para comparar:\n");
        if (jaEscolhido != 1) printf("1 - População\n");
        if (jaEscolhido != 2) printf("2 - Área\n");
        if (jaEscolhido != 3) printf("3 - PIB\n");
        if (jaEscolhido != 4) printf("4 - Pontos Turísticos\n");
        if (jaEscolhido != 5) printf("5 - Densidade Demográfica\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5 && opcao != jaEscolhido)
            return opcao;
        else
            printf("Opção inválida. Tente novamente.\n");
    }
}

int main() {
    // Dados das cartas
    char pais1[] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 2200.0; // em bilhões
    int pontos1 = 25;

    char pais2[] = "Argentina";
    int populacao2 = 45000000;
    float area2 = 2780400.0;
    float pib2 = 500.0;
    int pontos2 = 18;

    // Densidade demográfica (calculada)
    float dens1 = populacao1 / area1;
    float dens2 = populacao2 / area2;

    // Escolha de atributos
    printf("=== SUPER TRUNFO: COMPARAÇÃO MULTI-ATRIBUTOS ===\n");
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);

    // Variáveis para somar os valores comparados
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    // Comparação do primeiro atributo
    printf("\n--- Comparação do 1º Atributo ---\n");
    switch (atributo1) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d | %s: %d\n", pais1, populacao1, pais2, populacao2);
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km² | %s: %.2f km²\n", pais1, area1, pais2, area2);
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bi USD | %s: %.2f bi USD\n", pais1, pib1, pais2, pib2);
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d | %s: %d\n", pais1, pontos1, pais2, pontos2);
            valor1_carta1 = pontos1;
            valor1_carta2 = pontos2;
            break;
        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.6f hab/km² | %s: %.6f hab/km²\n", pais1, dens1, pais2, dens2);
            valor1_carta1 = dens1;
            valor1_carta2 = dens2;
            break;
    }

    // Comparação do segundo atributo
    printf("\n--- Comparação do 2º Atributo ---\n");
    switch (atributo2) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d | %s: %d\n", pais1, populacao1, pais2, populacao2);
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km² | %s: %.2f km²\n", pais1, area1, pais2, area2);
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bi USD | %s: %.2f bi USD\n", pais1, pib1, pais2, pib2);
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d | %s: %d\n", pais1, pontos1, pais2, pontos2);
            valor2_carta1 = pontos1;
            valor2_carta2 = pontos2;
            break;
        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.6f hab/km² | %s: %.6f hab/km²\n", pais1, dens1, pais2, dens2);
            valor2_carta1 = dens1;
            valor2_carta2 = dens2;
            break;
    }

    // Ajuste de lógica para densidade (onde o menor valor vence)
    float ajuste1 = (atributo1 == 5) ? -valor1_carta1 : valor1_carta1;
    float ajuste2 = (atributo1 == 5) ? -valor1_carta2 : valor1_carta2;
    float ajuste3 = (atributo2 == 5) ? -valor2_carta1 : valor2_carta1;
    float ajuste4 = (atributo2 == 5) ? -valor2_carta2 : valor2_carta2;

    // Soma dos atributos para decidir vencedor
    float soma1 = ajuste1 + ajuste3;
    float soma2 = ajuste2 + ajuste4;

    printf("\n--- Resultado Final ---\n");
    printf("%s (Total): %.2f\n", pais1, soma1);
    printf("%s (Total): %.2f\n", pais2, soma2);

    printf("Vencedor: ");
    (soma1 > soma2) ? printf("%s\n", pais1) :
    (soma2 > soma1) ? printf("%s\n", pais2) :
                      printf("Empate!\n");

    return 0;
}
