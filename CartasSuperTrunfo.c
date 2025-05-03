#include <stdio.h>

int main() {
    char estado;
    char codigo_carta[50];
    char nome_cidade[50];
    float populacao;
    float area;
    float PIB;
    int pontos_turisticos = 0;

    printf("Selecione um estado (A-H): ");
    scanf(" %c", &estado);

    printf("Selecione um codigo de caracteres (1-4): ");
    scanf("%s", codigo_carta);

    printf("Digite o nome da cidade: ");
    fscanf(stdin, " %[^\n]", nome_cidade);

    printf("Informe a população: ");
    scanf("%f", &populacao);

    printf("Informe a área (em Km²): ");
    scanf("%f", &area);

    printf("Informe o PIB: ");
    scanf("%f", &PIB);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos);

    printf("\nResumo:\n");
    // printf("Estado: %c\n", estado);
    // printf("Código da carta: %s\n", codigo_carta);
    printf("Código: %c0%s\n", estado, codigo_carta );
    printf("Cidade: %s\n", nome_cidade);
    printf("População: %.2f habitantes\n", populacao);
    printf("Área: %.2f Km²\n", area);
    printf("PIB: %.2f bilhões de reais \n", PIB);
    printf("Número de pontos turísticos: %d\n", pontos_turisticos);

    return 0;
}
