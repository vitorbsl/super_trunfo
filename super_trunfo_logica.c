#include <stdio.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    char estado[3];
    int codigo;

    unsigned long int populacao; // tipo alterado
    float area;
    float pib;
    int pontos_turisticos;

    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// Funções auxiliares
void calcular_atributos(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;

    // Super Poder: soma dos atributos conforme enunciado
    // Importante: conversões para evitar truncamento
    carta->super_poder = (float)carta->populacao +
                         carta->area +
                         carta->pib +
                         carta->pontos_turisticos +
                         carta->pib_per_capita +
                         (1 / carta->densidade); // inverso da densidade
}

void ler_carta(Carta *carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("Estado (sigla): ");
    scanf("%s", carta->estado);

    printf("Código: ");
    scanf("%d", &carta->codigo);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    calcular_atributos(carta);
}

void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade < c2.densidade); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

// Função principal
int main() {
    Carta carta1, carta2;

    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);

    comparar_cartas(carta1, carta2);

    return 0;
}
