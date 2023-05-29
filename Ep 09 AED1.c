#include <stdio.h>

#define MAX_ALTURA 100
#define MAX_LARGURA 100

char verificar_mapa(char mapa[MAX_ALTURA][MAX_LARGURA], int largura, int altura) {
    int pos_x = 0, pos_y = 0;
    char direcao = '>';

    while (1) {
        if (direcao == '>')
            pos_x++;
        else if (direcao == '<')
            pos_x--;
        else if (direcao == 'v')
            pos_y++;
        else if (direcao == '^')
            pos_y--;

        if (pos_x >= largura || pos_y >= altura || pos_x < 0 || pos_y < 0)
            return '!';

        char ponto_atual = mapa[pos_y][pos_x];

        if (ponto_atual == '*')
            return '*';
        else if (ponto_atual == '>')
            direcao = '>';
        else if (ponto_atual == '<')
            direcao = '<';
        else if (ponto_atual == 'v')
            direcao = 'v';
        else if (ponto_atual == '^')
            direcao = '^';

        mapa[pos_y][pos_x] = '.';
    }

    return '!';
}

int main() {
    int largura, altura;
    char mapa[MAX_ALTURA][MAX_LARGURA];

    scanf("%d%d", &largura, &altura);

    for (int i = 0; i < altura; i++)
        scanf("%s", mapa[i]);

    char resultado = verificar_mapa(mapa, largura, altura);

    printf("%c\n", resultado);

    return 0;
}
