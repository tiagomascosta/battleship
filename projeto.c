/* 
PROJETO INTERMÉDIO DE PROGRAMAÇÃO 20/21
Docente: Nuno Horta
Desenvolvido por: Grupo 16
    -Duarte Domingues (99925)
    -Tiago Costa (100094)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void main_menu();
void modo_j0();
void modo_j1();
void modo_j2();
void instrucoes();
void modo_p1();
void modo_p2();
void modo_d1();
void modo_d2_3();
void print_tabu();
void print_logo();
void print_modo_x();
void print_pecas();
void print_dimensao();
int stringComp();

int modo_jogo = -1, modo_pos, modo_dis, dim_tabu_x, dim_tabu_y, peca_n[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, tentativa_j[3];
int novamente = 0;

char yx[17][26], p_yx[17][26], d_yx[17][26];

time_t t;

int main()
{
    memset(yx, ' ', sizeof(yx));
    memset(p_yx, ' ', sizeof(p_yx));
    memset(d_yx, ' ', sizeof(d_yx));
    main_menu();
    return (0);
}

void main_menu()
{
    srand((unsigned)time(&t));
    system("clear");
    print_logo();
    printf("\n                 Escolha uma opção de jogo:\n\n\n                  『0』 - Modo de Jogo 0\n\n                  『1』 - Modo de Jogo 1\n\n                  『2』 - Modo de jogo 2\n\n                  『3』 - Instruções\n\n");

    if (scanf("%d", &modo_jogo) != 1)
    {
        char erro;
        scanf("%c", &erro); // limpar caracters
        main_menu();
    }

    switch (modo_jogo)
    {
    case 0:
        modo_j0();
        break;

    case 1:
        modo_j1();
        break;

    case 2:
        modo_j2();
        break;

    case 3:
        instrucoes();
        break;

    default:
        main_menu();
    }
}

void modo_j0()
{
    int e, m, n;
    do
    {
        e = 0;
        system("clear");
        print_logo();
        printf("Escolha a dimensão do Tabuleiro?( Ex.: 9x9 (linhas x colunas) )\n");
        if (scanf("%dx%d", &dim_tabu_y, &dim_tabu_x) != 2)
        {
            char erro;
            scanf("%c", &erro); // limpar caracters
            e = 1;
        }
        else
        {
            if (dim_tabu_x % 3 || dim_tabu_x < 9 || dim_tabu_x > 24 || dim_tabu_y % 3 || dim_tabu_y < 9 || dim_tabu_y > 15)
            {
                e = 1;
            }
        }
    } while (e != 0);

    do
    {
        e = 0;
        system("clear");
        print_logo();
        printf("Escolha o modo de posicionamento que deseja, 1 ou 2?\n");
        if (scanf("%d", &modo_pos) != 1)
        {
            char erro;
            scanf("%c", &erro); // limpar caracters
            e = 1;
        }
        else
        {
            system("clear");
            print_logo();
            switch (modo_pos)
            {
            case 1:
                modo_p1();
                break;
            case 2:
                modo_p2();
                break;
            default:
                e = 1;
                break;
            }
            system("clear");
            print_logo();
            print_dimensao();
            print_pecas();
            for (m = 0; m <= 17; m++)
            {
                for (n = 0; n <= 26; n++)
                {
                    yx[m][n] = p_yx[m][n];
                }
            }
            print_tabu();
        }
    } while (e != 0);
}

void modo_j1()
{
    int e, m, n;
    do
    {
        e = 0;
        system("clear");
        print_logo();
        printf("Escolha a dimensão do Tabuleiro?( Ex.: 9x9 (linhas x colunas) )\n");
        if (scanf("%dx%d", &dim_tabu_y, &dim_tabu_x) != 2)
        {
            char erro;
            scanf("%c", &erro); // limpar caracters
            e = 1;
        }
        else
        {
            if (dim_tabu_x % 3 || dim_tabu_x < 9 || dim_tabu_x > 24 || dim_tabu_y % 3 || dim_tabu_y < 9 || dim_tabu_y > 15)
            {
                e = 1;
            }
        }
    } while (e != 0);

    do
    {
        e = 0;
        system("clear");
        print_logo();
        printf("Escolha o modo de posicionamento que deseja, 1 ou 2?\n");
        if (scanf("%d", &modo_pos) != 1)
        {
            char erro;
            scanf("%c", &erro); // limpar caracters
            e = 1;
        }
        else
        {
            system("clear");
            print_logo();
            switch (modo_pos)
            {
            case 1:
                modo_p1();
                break;
            case 2:
                modo_p2();
                break;
            default:
                e = 1;
                break;
            }
        }
    } while (e != 0);

    time_t time_i = time(NULL); // Guardar Contagem do tempo neste momento

    char char_x, resposta[256];
    int x, y = 0, t_pecas, erro = 0;
    t_pecas = peca_n[1] + peca_n[2] * 2 + peca_n[3] * 3 + peca_n[4] * 4 + peca_n[5] * 5 + peca_n[6] * 6 + peca_n[7] * 7 + peca_n[8] * 8;

    while (t_pecas != 0 || erro == 1)
    {
        system("clear");
        for (m = 0; m <= 17; m++)
        {
            for (n = 0; n <= 26; n++)
            {
                yx[m][n] = d_yx[m][n];
            }
        }
        print_logo();
        print_tabu();
        printf("Peças totais:");
        print_pecas();
        printf("\n");
        if (erro == 1)
        {
            printf("\n-1 : Coordenada inválida! Introduza novamente.\n\n");
        }
        erro = 0;
        printf("Escreva a coordenada de disparo ( Ex.: C2 )\n\n");
        scanf(" %s", resposta);
        if (stringComp(resposta) > 3 || stringComp(resposta) < 2)
        { // verificar se a resposta tem menos de 2 caracteres ou mais de 3
            erro = 1;
        }
        else
        {
            char_x = resposta[0];
            if (stringComp(resposta) == 2)
            {
                y = resposta[1] - 48;
            } // associara cordenada y a resposta se esta tiver 2 caracteres(y<9)
            if (stringComp(resposta) == 3)
            {
                y = (resposta[1] - 48) * 10 + (resposta[2] - 48);
            } // associara cordenada y a resposta se esta tiver 3 caracteres (y>9)
            if (char_x < 65 || (char_x > (dim_tabu_x + 64) && char_x < 96) || char_x > (dim_tabu_x + 96) || y <= 0 || y > dim_tabu_y)
            { // verificar se as coordenasdas introduzidas são invalidas
                erro = 1;
            }
        }
        if (erro == 0)
        {
            if (char_x <= dim_tabu_x + 64)
            {
                x = char_x - 64;
            }
            else
            {
                x = char_x - 96;
            }
            if (erro == 0)
            { // verificar se não houve erros ao inserir as coordenadas
                tentativa_j[1]++;
                if (p_yx[y][x] == ' ')
                {
                    d_yx[y][x] = '-';
                }
                else
                {
                    d_yx[y][x] = p_yx[y][x];
                }
                if (d_yx[y][x] != ' ')
                { // verificar se a coordenada ja tinha sido inserida
                    if (p_yx[y][x] != ' ')
                    {
                        t_pecas--;
                    } // verificar se existe peça
                }
            }
        }
    }

    time_t time_f = time(NULL);            // Guardar Contagem do tempo neste momento
    time_t time_spent = (time_f - time_i); // Calcular tempo decorrido ente as contagens do tempo guardadas

    system("clear");
    print_logo();
    for (m = 0; m <= 17; m++)
    {
        for (n = 0; n <= 26; n++)
        {
            yx[m][n] = p_yx[m][n];
        }
    }
    print_tabu();
    printf("Tentativas = %d\n", tentativa_j[1]);
    printf("Tempo de jogo = %ld\n", time_spent);
}

void modo_j2()
{
    int e, m, n;
    for (m = 0; m <= 17; m++)
    {
        for (n = 0; n <= 26; n++)
        {
            yx[m][n] = p_yx[m][n];
        }
    }

    do
    {
        e = 0;
        system("clear");
        print_logo();
        printf("Escolha a dimensão do Tabuleiro?( Ex.: 9x9 (linhas x colunas) )\n");
        if (scanf("%dx%d", &dim_tabu_y, &dim_tabu_x) != 2)
        {
            char erro;
            scanf("%c", &erro); // limpar caracters
            e = 1;
        }
        else
        {
            if (dim_tabu_x % 3 || dim_tabu_x < 9 || dim_tabu_x > 24 || dim_tabu_y % 3 || dim_tabu_y < 9 || dim_tabu_y > 15)
            {
                e = 1;
            }
        }
    } while (e != 0);

    int quantidade, erro, n_pecas_max, n_pecas_escolhidas;
    m = 1;
    n = 0;
    system("clear");
    print_logo();
    do
    {
        do
        {
            erro = 0;

            printf("Escolha a quantidade de peças do tipo %d: \n", m);
            if (scanf("%d", &quantidade) != 1)
            {
                char erro;
                scanf("%c", &erro);
                erro = 1;
                quantidade = 0;
                system("clear");
                print_logo();
                printf("Erro! Escolha novamente!\n\n");
            }
            else
            {
                n_pecas_max = ((dim_tabu_x * dim_tabu_y) / 9) / 2;
                peca_n[m] = quantidade;
                m = m + 1;
                n_pecas_escolhidas = peca_n[1] + peca_n[2] + peca_n[3] + peca_n[4] + peca_n[5] + peca_n[6] + peca_n[7] + peca_n[8];
            }
            if (n_pecas_max < n_pecas_escolhidas)
            {
                system("clear");
                print_logo();
                printf("Excedeu o número de peças\n\n");
                m = 1;
                for (m = 1; m <= 8; m++)
                {
                    peca_n[m] = 0;
                }
                m = 1;
                erro = 1;
            }
            if (peca_n[m - 2] < peca_n[m - 1] && m != 2)
            {
                system("clear");
                print_logo();
                printf("O número de peças de um tipo de maior dimensão é superior\n\n");
                m = 1;
                for (m = 1; m <= 8; m++)
                {
                    peca_n[m] = 0;
                }
                m = 1;
                erro = 1;
            }
        } while (erro != 0 || n_pecas_max < n_pecas_escolhidas);
    } while (n_pecas_escolhidas < n_pecas_max && m <= 8);
    if (m < 9)
    {
        printf("\nNúmero máximo de peças atingido!!!\n");
    }
    if (m == 9)
    {
        printf("\nTodos os tipos de peças defenidos!!!\n");
    }
    peca_n[0] = ((dim_tabu_x * dim_tabu_y) / 9) - n_pecas_escolhidas;

    do
    {
        e = 0;
        system("clear");
        print_logo();
        printf("Escolha o modo de disparo que deseja, 1 ou 2 ou 3?\n");
        if (scanf("%d", &modo_dis) != 1)
        {
            char erro;
            scanf("%c", &erro); // limpar caracters
            e = 1;
        }
        else
        {
            system("clear");
            print_logo();
            switch (modo_dis)
            {
            case 1:
                modo_d1();
                break;
            case 2:
                modo_d2_3();
                break;
            case 3:
                modo_d2_3();
                break;
            default:
                e = 1;
                break;
            }
            system("clear");
            print_logo();
            print_dimensao();
            print_pecas();
            print_tabu();
        }
    } while (e != 0);
}

void instrucoes()
{
    system("clear");
    print_logo();
    printf("Instruções:\n");
    printf(" 🔲 ..........\n");
    printf(" 🔲 ..........\n");
}

void modo_p1()
{ // Modo de Posicionamento 1
    int matriz_x, matriz_y = -1, x, y, peca, tentativa_v, e_v;

    do
    {
        matriz_x = -1;
        matriz_y++;
        y = dim_tabu_y - (matriz_y * 3);

        do
        {
            matriz_x++;
            x = 1 + (matriz_x * 3);
            tentativa_v = 1;

            do
            {
                e_v = 0;
                if (tentativa_v <= 3)
                { // verificar se as tentativas de colocar a peça < 3
                    peca = rand() % 43;
                    switch (peca)
                    { // cada "case" verificar se a peça gerada pode ser colocada, senão a flag "e_v" é ativa e incrementa-se o nº de tentativas
                    case 0:
                        peca_n[0]++;
                        break;
                    case 1:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ')
                        {
                            p_yx[y][x] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 2:
                        if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                        {
                            p_yx[y][x + 1] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 3:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                        {
                            p_yx[y][x + 2] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 4:
                        if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ')
                        {
                            p_yx[y - 1][x] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 5:
                        p_yx[y - 1][x + 1] = '1';
                        peca_n[1]++;
                        break;
                    case 6:
                        if (p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                        {
                            p_yx[y - 1][x + 2] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 7:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ')
                        {
                            p_yx[y - 2][x] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 8:
                        if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y - 2][x + 1] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 9:
                        if (p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                        {
                            p_yx[y - 2][x + 2] = '1';
                            peca_n[1]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 10:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                        {
                            p_yx[y][x] = '2';
                            p_yx[y][x + 1] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 11:
                        if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                        {
                            p_yx[y][x + 1] = '2';
                            p_yx[y][x + 2] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 12:
                        if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ')
                        {
                            p_yx[y - 1][x] = '2';
                            p_yx[y - 1][x + 1] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 13:
                        if (p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ')
                        {
                            p_yx[y - 1][x + 1] = '2';
                            p_yx[y - 1][x + 2] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 14:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y - 2][x] = '2';
                            p_yx[y - 2][x + 1] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 15:
                        if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                        {
                            p_yx[y - 2][x + 1] = '2';
                            p_yx[y - 2][x + 2] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 16:
                        if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ')
                        {
                            p_yx[y][x] = '2';
                            p_yx[y - 1][x] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 17:
                        if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ')
                        {
                            p_yx[y - 1][x] = '2';
                            p_yx[y - 2][x] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 18:
                        if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                        {
                            p_yx[y][x + 1] = '2';
                            p_yx[y - 1][x + 1] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 19:
                        if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y - 1][x + 1] = '2';
                            p_yx[y - 2][x + 1] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 20:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                        {
                            p_yx[y][x + 2] = '2';
                            p_yx[y - 1][x + 2] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 21:
                        if (p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ')
                        {
                            p_yx[y - 1][x + 2] = '2';
                            p_yx[y - 2][x + 2] = '2';
                            peca_n[2]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 22:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                        {
                            p_yx[y][x] = '3';
                            p_yx[y][x + 1] = '3';
                            p_yx[y][x + 2] = '3';
                            peca_n[3]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 23:
                        if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                        {
                            p_yx[y - 1][x] = '3';
                            p_yx[y - 1][x + 1] = '3';
                            p_yx[y - 1][x + 2] = '3';
                            peca_n[3]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 24:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                        {
                            p_yx[y - 2][x] = '3';
                            p_yx[y - 2][x + 1] = '3';
                            p_yx[y - 2][x + 2] = '3';
                            peca_n[3]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 25:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ')
                        {
                            p_yx[y][x] = '3';
                            p_yx[y - 1][x] = '3';
                            p_yx[y - 2][x] = '3';
                            peca_n[3]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 26:
                        if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y][x + 1] = '3';
                            p_yx[y - 1][x + 1] = '3';
                            p_yx[y - 2][x + 1] = '3';
                            peca_n[3]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 27:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 1] == ' ')
                        {
                            p_yx[y][x + 2] = '3';
                            p_yx[y - 1][x + 2] = '3';
                            p_yx[y - 2][x + 2] = '3';
                            peca_n[3]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 28:
                        if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                        {
                            p_yx[y][x] = '4';
                            p_yx[y][x + 1] = '4';
                            p_yx[y - 1][x] = '4';
                            p_yx[y - 1][x + 1] = '4';
                            peca_n[4]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 29:
                        if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                        {
                            p_yx[y][x + 1] = '4';
                            p_yx[y][x + 2] = '4';
                            p_yx[y - 1][x + 1] = '4';
                            p_yx[y - 1][x + 2] = '4';
                            peca_n[4]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 30:
                        if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y - 1][x] = '4';
                            p_yx[y - 1][x + 1] = '4';
                            p_yx[y - 2][x] = '4';
                            p_yx[y - 2][x + 1] = '4';
                            peca_n[4]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 31:
                        if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ')
                        {
                            p_yx[y - 1][x + 1] = '4';
                            p_yx[y - 1][x + 2] = '4';
                            p_yx[y - 2][x + 1] = '4';
                            p_yx[y - 2][x + 2] = '4';
                            peca_n[4]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 32:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y][x] = '5';
                            p_yx[y][x + 1] = '5';
                            p_yx[y][x + 2] = '5';
                            p_yx[y - 1][x + 1] = '5';
                            p_yx[y - 2][x + 1] = '5';
                            peca_n[5]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 33:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                        {
                            p_yx[y][x] = '5';
                            p_yx[y - 1][x] = '5';
                            p_yx[y - 1][x + 1] = '5';
                            p_yx[y - 1][x + 2] = '5';
                            p_yx[y - 2][x] = '5';
                            peca_n[5]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 34:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                        {
                            p_yx[y][x + 1] = '5';
                            p_yx[y - 1][x + 1] = '5';
                            p_yx[y - 2][x] = '5';
                            p_yx[y - 2][x + 1] = '5';
                            p_yx[y - 2][x + 2] = '5';
                            peca_n[5]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 35:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ')
                        {
                            p_yx[y][x + 2] = '5';
                            p_yx[y - 1][x] = '5';
                            p_yx[y - 1][x + 1] = '5';
                            p_yx[y - 1][x + 2] = '5';
                            p_yx[y - 2][x + 2] = '5';
                            peca_n[5]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 36:
                        if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                        {
                            p_yx[y][x + 1] = '6';
                            p_yx[y - 1][x] = '6';
                            p_yx[y - 1][x + 2] = '6';
                            p_yx[y - 2][x] = '6';
                            p_yx[y - 2][x + 1] = '6';
                            p_yx[y - 2][x + 2] = '6';
                            peca_n[6]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 37:
                        if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ')
                        {
                            p_yx[y][x + 1] = '6';
                            p_yx[y][x + 2] = '6';
                            p_yx[y - 1][x] = '6';
                            p_yx[y - 1][x + 2] = '6';
                            p_yx[y - 2][x + 1] = '6';
                            p_yx[y - 2][x + 2] = '6';
                            peca_n[6]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 38:
                        if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y][x] = '6';
                            p_yx[y][x + 1] = '6';
                            p_yx[y][x + 2] = '6';
                            p_yx[y - 1][x] = '6';
                            p_yx[y - 1][x + 2] = '6';
                            p_yx[y - 2][x + 1] = '6';
                            peca_n[6]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 39:
                        if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                        {
                            p_yx[y][x] = '6';
                            p_yx[y][x + 1] = '6';
                            p_yx[y - 1][x] = '6';
                            p_yx[y - 1][x + 2] = '6';
                            p_yx[y - 2][x] = '6';
                            p_yx[y - 2][x + 1] = '6';
                            peca_n[6]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 40:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y][x] = '7';
                            p_yx[y][x + 2] = '7';
                            p_yx[y - 1][x] = '7';
                            p_yx[y - 1][x + 1] = '7';
                            p_yx[y - 1][x + 2] = '7';
                            p_yx[y - 2][x] = '7';
                            p_yx[y - 2][x + 2] = '7';
                            peca_n[7]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 41:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y][x] = '7';
                            p_yx[y][x + 1] = '7';
                            p_yx[y][x + 2] = '7';
                            p_yx[y - 1][x + 1] = '7';
                            p_yx[y - 2][x] = '7';
                            p_yx[y - 2][x + 1] = '7';
                            p_yx[y - 2][x + 2] = '7';
                            peca_n[7]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    case 42:
                        if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ')
                        {
                            p_yx[y][x] = '8';
                            p_yx[y][x + 1] = '8';
                            p_yx[y][x + 2] = '8';
                            p_yx[y - 1][x] = '8';
                            p_yx[y - 1][x + 2] = '8';
                            p_yx[y - 2][x] = '8';
                            p_yx[y - 2][x + 1] = '8';
                            p_yx[y - 2][x + 2] = '8';
                            peca_n[8]++;
                        }
                        else
                        {
                            tentativa_v++;
                            e_v = 1;
                        }
                        break;
                    default:
                        e_v = 1;
                        break;
                    }
                }
                else
                { // colocar a peça com identificador global 5
                    p_yx[y - 1][x + 1] = '1';
                    peca_n[1]++;
                }
            } while (e_v != 0);       // repetir enquanto a flag "e_v" esta ativa
        } while (x < dim_tabu_x - 2); // repetir enquanto não completar a linha de matrizes 3x3
    } while (y > 3);                  // repetir enquanto não completar todas linha de matrizes 3x3
}

void modo_p2()
{ // Modo de Posicionamento 2
    int m = 1, quantidade, erro, n_pecas_max, n_pecas_escolhidas;
    system("clear");
    print_logo();
    do
    {
        do
        {
            erro = 0;
            printf("Escolha a quantidade de peças do tipo %d: \n", m);
            if (scanf("%d", &quantidade) != 1)
            {
                char erro;
                scanf("%c", &erro);
                erro = 1;
                quantidade = 0;
                system("clear");
                print_logo();
                printf("Erro! Escolha novamente!\n\n");
            }
            else
            {
                n_pecas_max = ((dim_tabu_x * dim_tabu_y) / 9) / 2;
                peca_n[m] = quantidade;
                m = m + 1;
                n_pecas_escolhidas = peca_n[1] + peca_n[2] + peca_n[3] + peca_n[4] + peca_n[5] + peca_n[6] + peca_n[7] + peca_n[8];
            }
            if (n_pecas_max < n_pecas_escolhidas)
            {
                system("clear");
                print_logo();
                printf("Excedeu o número de peças\n\n");
                m = 1;
                for (m = 1; m <= 8; m++)
                {
                    peca_n[m] = 0;
                }
                m = 1;
                erro = 1; //reset array
            }
            if (peca_n[m - 2] < peca_n[m - 1] && m != 2)
            {
                system("clear");
                print_logo();
                printf("O número de peças de um tipo de maior dimensão é superior\n\n");
                m = 1;
                for (m = 1; m <= 8; m++)
                {
                    peca_n[m] = 0;
                }
                m = 1;
                erro = 1; //reset array
            }
        } while (erro != 0 || n_pecas_max < n_pecas_escolhidas);
    } while (n_pecas_escolhidas < n_pecas_max && m <= 8);
    if (m < 9)
    {
        printf("\nNúmero máximo de peças atingido!!!\n");
    }
    if (m == 9)
    {
        printf("\nTodos os tipos de peças defenidos!!!\n");
    }
    peca_n[0] = ((dim_tabu_x * dim_tabu_y) / 9) - n_pecas_escolhidas;

    int matriz_x, matriz_y, x, y, selecao_tipo, variante, tentativa_v, tentativa_p[9] = {0}, n_peca[9] = {0}, i, j, i_tabuleiro = 0, erro_tabuleiro = 0, erro_peca = 0, e_v = 0;

    do
    {
        memset(p_yx, ' ', sizeof(p_yx));
        matriz_y = -1;
        erro_tabuleiro = 0;
        for (i = 0; i <= 8; i++)
        { // igualar a variável "n_peca" a "peca_n"
            n_peca[i] = peca_n[i];
        }

        do
        {
            matriz_x = -1;
            matriz_y++;
            y = dim_tabu_y - (matriz_y * 3);

            do
            {
                for (j = 0; j <= 8; j++)
                { // reset da variável tentativa
                    tentativa_p[j] = 0;
                }
                matriz_x++;
                x = 1 + (matriz_x * 3);
                tentativa_v = -1;
                do
                {
                    erro_peca = 0;
                    selecao_tipo = rand() % 9;

                    if ((n_peca[0] == 0 || tentativa_p[0] == 1) && (n_peca[1] == 0 || tentativa_p[1] == 1) && (n_peca[2] == 0 || tentativa_p[2] == 1) && (n_peca[3] == 0 || tentativa_p[3] == 1) && (n_peca[4] == 0 || tentativa_p[4] == 1) && (n_peca[5] == 0 || tentativa_p[5] == 1) & (n_peca[6] == 0 || tentativa_p[6] == 1) & (n_peca[7] == 0 || tentativa_p[7] == 1) && (n_peca[8] == 0 || tentativa_p[8] == 1))
                    {
                        i_tabuleiro++;
                        erro_tabuleiro = 1; // verificar se faltam algumas peças e se estas são impossíveis de colocar, desta forma ativar a flag "erro_tabuleiro" e incrementar o nº de tabuleiro gerados
                    }
                    if (tentativa_p[selecao_tipo] == 1)
                    {
                        erro_peca = 1;
                    } // Se ja tentamos colocar essa peça, ativa a flag "erro_peca"
                    else
                    {
                        if (selecao_tipo == 0 && n_peca[0] != 0)
                        { // Se a peça for 0 e ainda houver peças desse tipo para colocar
                            n_peca[0]--;
                            e_v = 0;
                        }
                        else if (selecao_tipo == 1 && n_peca[1] != 0)
                        { // Se a peça for do tipo 1 e ainda houver peças desse tipo para colocar
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                } // Se a flag e_v estiver ativa, percorre todas as variantes desse tipo
                                else
                                {
                                    variante = rand() % 9;
                                } // Aleatoriza a variante da peça
                                switch (variante)
                                { // cada "case" verificar se a peça gerada pode ser colocada, senão a flag "e_v" é ativa
                                case 0:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ')
                                    {
                                        p_yx[y][x] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                                    {
                                        p_yx[y][x + 1] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 2:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                                    {
                                        p_yx[y][x + 2] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 3:
                                    if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ')
                                    {
                                        p_yx[y - 1][x] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 4:
                                    p_yx[y - 1][x + 1] = '1';
                                    n_peca[1]--;
                                    break;
                                case 5:
                                    if (p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                                    {
                                        p_yx[y - 1][x + 2] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 6:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ')
                                    {
                                        p_yx[y - 2][x] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 7:
                                    if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y - 2][x + 1] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 8:
                                    if (p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                                    {
                                        p_yx[y - 2][x + 2] = '1';
                                        n_peca[1]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 8)
                                {
                                    erro_peca = 1;
                                    tentativa_p[1] = 1;
                                }                                  // se não conseguir colocar nenhuma variante (tentativa=8), ativa a flag "erro_peca" e a flag "tentativa_p[1]"
                            } while (tentativa_v < 8 && e_v == 1); // repete este ciclo enquanto a "tentativa"<8 e  a flag "e_v" estiver ativa
                        }
                        else if (selecao_tipo == 2 && n_peca[2] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                }
                                else
                                {
                                    variante = rand() % 12;
                                }
                                switch (variante)
                                {
                                case 0:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                                    {
                                        p_yx[y][x] = '2';
                                        p_yx[y][x + 1] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                                    {
                                        p_yx[y][x + 1] = '2';
                                        p_yx[y][x + 2] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 2:
                                    if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ')
                                    {
                                        p_yx[y - 1][x] = '2';
                                        p_yx[y - 1][x + 1] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 3:
                                    if (p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ')
                                    {
                                        p_yx[y - 1][x + 1] = '2';
                                        p_yx[y - 1][x + 2] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 4:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y - 2][x] = '2';
                                        p_yx[y - 2][x + 1] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 5:
                                    if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                                    {
                                        p_yx[y - 2][x + 1] = '2';
                                        p_yx[y - 2][x + 2] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 6:
                                    if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ')
                                    {
                                        p_yx[y][x] = '2';
                                        p_yx[y - 1][x] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 7:
                                    if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ')
                                    {
                                        p_yx[y - 1][x] = '2';
                                        p_yx[y - 2][x] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 8:
                                    if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                                    {
                                        p_yx[y][x + 1] = '2';
                                        p_yx[y - 1][x + 1] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 9:
                                    if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y - 1][x + 1] = '2';
                                        p_yx[y - 2][x + 1] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 10:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                                    {
                                        p_yx[y][x + 2] = '2';
                                        p_yx[y - 1][x + 2] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 11:
                                    if (p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ')
                                    {
                                        p_yx[y - 1][x + 2] = '2';
                                        p_yx[y - 2][x + 2] = '2';
                                        n_peca[2]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 11)
                                {
                                    erro_peca = 1;
                                    tentativa_p[2] = 1;
                                }
                            } while (tentativa_v < 11 && e_v == 1);
                        }
                        else if (selecao_tipo == 3 && n_peca[3] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                }
                                else
                                {
                                    variante = rand() % 6;
                                }
                                switch (variante)
                                {
                                case 0:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                                    {
                                        p_yx[y][x] = '3';
                                        p_yx[y][x + 1] = '3';
                                        p_yx[y][x + 2] = '3';
                                        n_peca[3]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                                    {
                                        p_yx[y - 1][x] = '3';
                                        p_yx[y - 1][x + 1] = '3';
                                        p_yx[y - 1][x + 2] = '3';
                                        n_peca[3]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 2:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ')
                                    {
                                        p_yx[y - 2][x] = '3';
                                        p_yx[y - 2][x + 1] = '3';
                                        p_yx[y - 2][x + 2] = '3';
                                        n_peca[3]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 3:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ')
                                    {
                                        p_yx[y][x] = '3';
                                        p_yx[y - 1][x] = '3';
                                        p_yx[y - 2][x] = '3';
                                        n_peca[3]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 4:
                                    if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y][x + 1] = '3';
                                        p_yx[y - 1][x + 1] = '3';
                                        p_yx[y - 2][x + 1] = '3';
                                        n_peca[3]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 5:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 1] == ' ')
                                    {
                                        p_yx[y][x + 2] = '3';
                                        p_yx[y - 1][x + 2] = '3';
                                        p_yx[y - 2][x + 2] = '3';
                                        n_peca[3]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 5)
                                {
                                    erro_peca = 1;
                                    tentativa_p[3] = 1;
                                }
                            } while (tentativa_v < 5 && e_v == 1);
                        }
                        else if (selecao_tipo == 4 && n_peca[4] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                }
                                else
                                {
                                    variante = rand() % 4;
                                }
                                switch (variante)
                                {
                                case 0:
                                    if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                                    {
                                        p_yx[y][x] = '4';
                                        p_yx[y][x + 1] = '4';
                                        p_yx[y - 1][x] = '4';
                                        p_yx[y - 1][x + 1] = '4';
                                        n_peca[4]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                                    {
                                        p_yx[y][x + 1] = '4';
                                        p_yx[y][x + 2] = '4';
                                        p_yx[y - 1][x + 1] = '4';
                                        p_yx[y - 1][x + 2] = '4';
                                        n_peca[4]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 2:
                                    if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y - 1][x] = '4';
                                        p_yx[y - 1][x + 1] = '4';
                                        p_yx[y - 2][x] = '4';
                                        p_yx[y - 2][x + 1] = '4';
                                        n_peca[4]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 3:
                                    if (p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ')
                                    {
                                        p_yx[y - 1][x + 1] = '4';
                                        p_yx[y - 1][x + 2] = '4';
                                        p_yx[y - 2][x + 1] = '4';
                                        p_yx[y - 2][x + 2] = '4';
                                        n_peca[4]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 3)
                                {
                                    erro_peca = 1;
                                    tentativa_p[4] = 1;
                                }
                            } while (tentativa_v < 3 && e_v == 1);
                        }
                        else if (selecao_tipo == 5 && n_peca[5] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                }
                                else
                                {
                                    variante = rand() % 4;
                                }
                                switch (variante)
                                {
                                case 0:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y][x] = '5';
                                        p_yx[y][x + 1] = '5';
                                        p_yx[y][x + 2] = '5';
                                        p_yx[y - 1][x + 1] = '5';
                                        p_yx[y - 2][x + 1] = '5';
                                        n_peca[5]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                                    {
                                        p_yx[y][x] = '5';
                                        p_yx[y - 1][x] = '5';
                                        p_yx[y - 1][x + 1] = '5';
                                        p_yx[y - 1][x + 2] = '5';
                                        p_yx[y - 2][x] = '5';
                                        n_peca[5]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 2:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                                    {
                                        p_yx[y][x + 1] = '5';
                                        p_yx[y - 1][x + 1] = '5';
                                        p_yx[y - 2][x] = '5';
                                        p_yx[y - 2][x + 1] = '5';
                                        p_yx[y - 2][x + 2] = '5';
                                        n_peca[5]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 3:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ')
                                    {
                                        p_yx[y][x + 2] = '5';
                                        p_yx[y - 1][x] = '5';
                                        p_yx[y - 1][x + 1] = '5';
                                        p_yx[y - 1][x + 2] = '5';
                                        p_yx[y - 2][x + 2] = '5';
                                        n_peca[5]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 3)
                                {
                                    erro_peca = 1;
                                    tentativa_p[5] = 1;
                                }
                            } while (tentativa_v < 3 && e_v == 1);
                        }
                        else if (selecao_tipo == 6 && n_peca[6] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                }
                                else
                                {
                                    variante = rand() % 4;
                                }
                                switch (variante)
                                {
                                case 0:
                                    if (p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ')
                                    {
                                        p_yx[y][x + 1] = '6';
                                        p_yx[y - 1][x] = '6';
                                        p_yx[y - 1][x + 2] = '6';
                                        p_yx[y - 2][x] = '6';
                                        p_yx[y - 2][x + 1] = '6';
                                        p_yx[y - 2][x + 2] = '6';
                                        n_peca[6]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ')
                                    {
                                        p_yx[y][x + 1] = '6';
                                        p_yx[y][x + 2] = '6';
                                        p_yx[y - 1][x] = '6';
                                        p_yx[y - 1][x + 2] = '6';
                                        p_yx[y - 2][x + 1] = '6';
                                        p_yx[y - 2][x + 2] = '6';
                                        n_peca[6]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 2:
                                    if (p_yx[y - 2][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y][x] = '6';
                                        p_yx[y][x + 1] = '6';
                                        p_yx[y][x + 2] = '6';
                                        p_yx[y - 1][x] = '6';
                                        p_yx[y - 1][x + 2] = '6';
                                        p_yx[y - 2][x + 1] = '6';
                                        n_peca[6]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 3:
                                    if (p_yx[y - 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y - 3][x + 2] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ')
                                    {
                                        p_yx[y][x] = '6';
                                        p_yx[y][x + 1] = '6';
                                        p_yx[y - 1][x] = '6';
                                        p_yx[y - 1][x + 2] = '6';
                                        p_yx[y - 2][x] = '6';
                                        p_yx[y - 2][x + 1] = '6';
                                        n_peca[6]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 3)
                                {
                                    erro_peca = 1;
                                    tentativa_p[6] = 1;
                                }
                            } while (tentativa_v < 3 && e_v == 1);
                        }
                        else if (selecao_tipo == 7 && n_peca[7] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            do
                            {
                                if (e_v == 1)
                                {
                                    tentativa_v++;
                                    variante = tentativa_v;
                                    e_v = 0;
                                }
                                else
                                {
                                    variante = rand() % 2;
                                }
                                switch (variante)
                                {
                                case 0:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y][x] = '7';
                                        p_yx[y][x + 2] = '7';
                                        p_yx[y - 1][x] = '7';
                                        p_yx[y - 1][x + 1] = '7';
                                        p_yx[y - 1][x + 2] = '7';
                                        p_yx[y - 2][x] = '7';
                                        p_yx[y - 2][x + 2] = '7';
                                        n_peca[7]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                case 1:
                                    if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ')
                                    {
                                        p_yx[y][x] = '7';
                                        p_yx[y][x + 1] = '7';
                                        p_yx[y][x + 2] = '7';
                                        p_yx[y - 1][x + 1] = '7';
                                        p_yx[y - 2][x] = '7';
                                        p_yx[y - 2][x + 1] = '7';
                                        p_yx[y - 2][x + 2] = '7';
                                        n_peca[7]--;
                                    }
                                    else
                                    {
                                        e_v = 1;
                                    }
                                    break;
                                }
                                if (tentativa_v >= 2)
                                {
                                    erro_peca = 1;
                                    tentativa_p[7] = 1;
                                }
                            } while (tentativa_v < 2 && e_v == 1);
                        }
                        else if (selecao_tipo == 8 && n_peca[8] != 0)
                        { // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                            if (p_yx[y + 1][x + 1] == ' ' && p_yx[y + 1][x] == ' ' && p_yx[y + 1][x - 1] == ' ' && p_yx[y][x - 1] == ' ' && p_yx[y - 1][x - 1] == ' ' && p_yx[y - 2][x - 1] == ' ' && p_yx[y - 3][x - 1] == ' ' && p_yx[y - 3][x] == ' ' && p_yx[y - 3][x + 1] == ' ' && p_yx[y + 1][x + 2] == ' ' && p_yx[y + 1][x + 3] == ' ' && p_yx[y][x + 3] == ' ' && p_yx[y - 1][x + 3] == ' ' && p_yx[y - 2][x + 3] == ' ' && p_yx[y - 3][x + 3] == ' ' && p_yx[y - 3][x + 2] == ' ')
                            {
                                p_yx[y][x] = '8';
                                p_yx[y][x + 1] = '8';
                                p_yx[y][x + 2] = '8';
                                p_yx[y - 1][x] = '8';
                                p_yx[y - 1][x + 2] = '8';
                                p_yx[y - 2][x] = '8';
                                p_yx[y - 2][x + 1] = '8';
                                p_yx[y - 2][x + 2] = '8';
                                n_peca[8]--;
                            }
                            else
                            {
                                erro_peca = 1;
                                tentativa_p[8] = 1;
                            }
                        }
                        else
                        {
                            erro_peca = 1;
                        }
                    }
                } while (erro_peca == 1 && erro_tabuleiro == 0); // Repete este ciclo enquanto a flag "erro_peca" estiver ativa e a flag "erro_tabuleiro" estiver inativa

            } while (x < dim_tabu_x - 2 && erro_tabuleiro == 0); // Repete este ciclo enquanto não completar a linha de matrizes 3x3
        } while (y > 3 && erro_tabuleiro == 0);                  // Repete este ciclo enquanto não completar todas linha de matrizes 3x3
    } while (i_tabuleiro < 1000 && erro_tabuleiro == 1);         // Repete este ciclo enquanto não forem gerados 1000 tabuleiro e a flag "erro_tabuleiro" estiver ativa

    if (i_tabuleiro == 1000)
    { // Erro -1 pois não foi possível gerar o tabuleiro nas ultimas 1000 vezes
        printf("\n-1 : Não foi possível gerar o tabuleiro.\n\n");
        exit(1);
    }
}

void modo_d1()
{ // Modo de Disparo 1

    int x, y, disparo = 0, n_peca[9] = {0}, erro = 0, e = 0;
    char x_alfa = '0', d_yx[17][26], resposta[256];
    memset(d_yx, 0, sizeof(d_yx));

    n_peca[1] = peca_n[1];
    n_peca[2] = 2 * peca_n[2];
    n_peca[3] = 3 * peca_n[3];
    n_peca[4] = 4 * peca_n[4];
    n_peca[5] = 5 * peca_n[5];
    n_peca[6] = 6 * peca_n[6];
    n_peca[7] = 7 * peca_n[7];
    n_peca[8] = 8 * peca_n[8];

    do
    {
        y = rand() % (dim_tabu_y);
        x = rand() % (dim_tabu_x);
        x++;              // pois a função "rand" devolve valores no intervalo [0,dim_tabu_x - 1], incrementando 1, fica no intervalo [1,dim_tabu_x]
        y++;              // pelo mesmo motivo da linha anterior
        x_alfa = x + '@'; // converter o valor de "x" na letra do alfabeto correspondente "x_alfa"
        if (d_yx[y][x] != 1)
        { // se a flag "d_yx" não estiver ativa
            do
            {
                erro = 0;
                e = 0;
                printf("%c%d\n", x_alfa, y);
                scanf("%s", resposta);
                if (stringComp(resposta) > 1 || (((resposta[0] < 49 && resposta[0] != 45) || resposta[0] > 56) && stringComp(resposta) == 1))
                {             // verificar se a resposta tem  mais de 1 carácter ou no caso de ter só 1 se é diferente de " " ( 45 na tabela de ASCII) e não estiver no interalo [1,8]( [49,56] na tabela de ASCII ) , ou seja verificar se o carácter é inválido
                    erro = 1; // ativar a flag "erro"
                    printf("\n-1 : Carácter inválido! Introduza novamente.\n\n");
                }
                if (stringComp(resposta) == 1 && erro == 0)
                {
                    yx[y][x] = resposta[0];
                } // verifica se a resposta tem 1 carácter e a flag "erro" esta inativa, nesse caso iguala o único carácter da resposta à posição do tabuleiro correspondente
                if ((yx[y][x]) != ' ' && erro == 0)
                {                               // Se o carácter inserido for diferente de " " e a flag "erro" estiver inativa
                    disparo = (yx[y][x]) - '0'; // converter o número da variável (char)"yx" para (int)"disparo"
                    if (n_peca[disparo] == 0 && erro == 0)
                    { // se o "n_peca" correspondente ao "disparo" for 0 e a flag "erro" estiver inativa, quer dizer que já foram descobertas todas as peças desse tipo ativando a flag "e"
                        e = 1;
                        printf("\n-1 : Já foram descobertas todas as peças desse tipo.\n\n");
                    }
                    if (e == 0)
                    {
                        (n_peca[disparo])--;
                    } // Se a flag "e" estiver inativa (o disparo for válido), decrementa as pecas correspondente a esse disparo
                }
                if (erro == 0 && e == 0)
                {
                    (d_yx[y][x]) = 1;
                    tentativa_j[2]++;
                }                          // Se as flags "erro" e "e" estiverem inativas (o disparo for válido) ativa a flag "d_yx" correspondente para indicar que essa coordenada ja foi aleatorizada e incrementa as tentativas
            } while (erro == 1 || e == 1); // Repete este ciclo enquanto uma das flags "erro" ou "e" estiver ativa
        }
    } while (n_peca[1] != 0 || n_peca[2] != 0 || n_peca[3] != 0 || n_peca[4] != 0 || n_peca[5] != 0 || n_peca[6] != 0 || n_peca[7] != 0 || n_peca[8] != 0); // Repete este ciclo enquanto existirem pecas por posicionar
}

void modo_d2_3()
{                                                                                                                                                                                                             // Modo de Disparo 2 e 3
    int x, y, matriz_x, matriz_y = -1, disparo = 0, disparos_peca[9] = {0}, n_peca[9] = {0}, i, j, m, n, e = 0, erro = 0, sequencia[2][9] = {{-1, 0, -2, -1, -1, 0, -2, 0, -2}, {1, 1, 1, 0, 2, 0, 2, 2, 0}}; // sequencia de disparos explicada no guia de implementação
    char x_alfa = '0', resposta[256], d_yx[17][26];
    memset(d_yx, 0, sizeof(d_yx));

    n_peca[1] = peca_n[1];
    n_peca[2] = 2 * peca_n[2];
    n_peca[3] = 3 * peca_n[3];
    n_peca[4] = 4 * peca_n[4];
    n_peca[5] = 5 * peca_n[5];
    n_peca[6] = 6 * peca_n[6];
    n_peca[7] = 7 * peca_n[7];
    n_peca[8] = 8 * peca_n[8];

    do
    {
        matriz_x = -1;
        matriz_y++;
        y = dim_tabu_y - (matriz_y * 3);

        do
        {
            for (i = 0; i <= 8; i++)
            { // reset da variável "disparos_peca"
                disparos_peca[i] = 0;
            }
            matriz_x++;
            x = 1 + (matriz_x * 3);
            j = 0;
            do
            {
                if (modo_dis == 2 || (modo_dis == 3 && d_yx[y + (sequencia[0][j])][x + (sequencia[1][j])] != '1'))
                { // Se o Modo de Disparo for 2 ou se for 3 e a flag "d_yx" correspondente estiver inativa ( se estiver ativa salta a cordenada do disparo )

                    do
                    {
                        x_alfa = x + (sequencia[1][j]) + '@'; // converter o valor de "x" na letra do alfabeto correspondente "x_alfa"
                        erro = 0;
                        e = 0;
                        printf("%c%d\n", x_alfa, (y + (sequencia[0][j])));
                        scanf("%s", resposta);
                        if (stringComp(resposta) > 1 || (((resposta[0] < 49 && resposta[0] != 45) || resposta[0] > 56) && stringComp(resposta) == 1))
                        { // verificar se a resposta tem  mais de 1 carácter ou no caso de ter só 1 se é diferente de " " ( 45 na tabela de ASCII) e não estiver no interalo [1,8]( [49,56] na tabela de ASCII ) , ou seja verificar se o carácter é inválido
                            erro = 1;
                            printf("\n-1 : Carácter inválido! Introduza novamente.\n\n");
                        }
                        if (stringComp(resposta) == 1 && erro == 0)
                        {
                            yx[y + (sequencia[0][j])][x + (sequencia[1][j])] = resposta[0];
                        } // verifica se a resposta tem 1 carácter e a flag "erro" esta inativa, nesse caso iguala o único carácter da resposta à posição do tabuleiro correspondente
                        if (yx[y + (sequencia[0][j])][x + (sequencia[1][j])] != ' ' && erro == 0)
                        {                                                                       // Se o carácter inserido for diferente de " " e a flag "erro" estiver inativa
                            disparo = (yx[y + (sequencia[0][j])][x + (sequencia[1][j])]) - '0'; // converter o número da variável (char)"yx" para (int)"disparo"
                            if (n_peca[disparo] == 0 && erro == 0)
                            { // se o "n_peca" correspondente ao "disparo" for 0 e a flag "erro" estiver inativa, quer dizer que já foram descobertas todas as peças desse tipo ativando a flag "e"
                                e = 1;
                                printf("\n-1 : Já foram descobertas todas as peças desse tipo.\n\n");
                            }
                            if (e == 0)
                            {
                                (disparos_peca[disparo])++;
                                (n_peca[disparo])--;
                            } // Se a flag "e" estiver inativa, incrementa o disparos da peça correspondente e decrementa o nº de peças da peça correspondente
                        }
                        if (e == 0 && erro == 0)
                        {
                            tentativa_j[2]++;
                        }                          // Se as flags "erro" e "e" estiverem inativas ( o disparo for válido ) incrementa as tentativas
                    } while (erro == 1 || e == 1); // Repete este ciclo enquanto uma das flags "erro" ou "e" estiver ativa
                }
                j++;
            } while (j <= 8 && disparos_peca[1] < 1 && disparos_peca[2] < 2 && disparos_peca[3] < 3 && disparos_peca[4] < 4 && disparos_peca[5] < 5 && disparos_peca[6] < 6 && disparos_peca[7] < 7 && disparos_peca[8] < 8); // Repete este ciclo enquanto não percorrer a matriz toda (j<=8) e os disparos da peça 'x' sejam menores que 'x'
            if (modo_dis == 3)
            { // Se o modo disparo for o 3, este bloco de código irá ativar as flags "d_yx" em torno das peças colocadas (restrição 1)
                for (m = 0; m <= 8; m++)
                {
                    if (yx[y + sequencia[0][m]][x + sequencia[1][m]] != ' ')
                    {
                        for (n = 0; n <= 8; n++)
                        {
                            d_yx[y + 1 + sequencia[0][m] + sequencia[0][n]][x - 1 + sequencia[1][m] + sequencia[1][n]] = '1';
                        }
                    }
                }
            }
        } while ((x < dim_tabu_x - 2) && (n_peca[1] != 0 || n_peca[2] != 0 || n_peca[3] != 0 || n_peca[4] != 0 || n_peca[5] != 0 || n_peca[6] != 0 || n_peca[7] != 0 || n_peca[8] != 0)); // Repete este ciclo enquanto não completar a linha de matrizes 3x3 e existirem pecas por posicionar
    } while (y > 3 && (n_peca[1] != 0 || n_peca[2] != 0 || n_peca[3] != 0 || n_peca[4] != 0 || n_peca[5] != 0 || n_peca[6] != 0 || n_peca[7] != 0 || n_peca[8] != 0));                    // Repete este ciclo enquanto não completar todas linha de matrizes 3x3 e existirem pecas por posicionar
}

void print_tabu()
{
    int n_colunas, n_linhas, k, l, min, max_1, max_2;
    n_colunas = dim_tabu_x;
    n_linhas = dim_tabu_y;

    switch (n_colunas)
    {
    case 9:

        printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        min = (n_linhas - 2);
        max_1 = (n_linhas / 3);
        max_2 = n_linhas;
        for (l = 1; l <= max_1; l++)
        {
            for (k = max_2; k > min; k--)
            {
                if (k >= 10)
                {
                    printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9]);
                }
                else
                {
                    printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9]);
                }
                printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
            if (k >= 10)
            {
                printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9]);
            }
            else
            {
                printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9]);
            }
            printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            max_2 = (max_2 - 3);
            min = (min - 3);
        }
        printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║\n");
        break;
    case 12:

        printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        min = (n_linhas - 2);
        max_1 = (n_linhas / 3);
        max_2 = n_linhas;
        for (l = 1; l <= max_1; l++)
        {
            for (k = max_2; k > min; k--)
            {
                if (k >= 10)
                {
                    printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12]);
                }
                else
                {
                    printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12]);
                }
                printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
            if (k >= 10)
            {
                printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12]);
            }
            else
            {
                printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12]);
            }
            printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            max_2 = (max_2 - 3);
            min = (min - 3);
        }
        printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║\n");
        break;
    case 15:

        printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        min = (n_linhas - 2);
        max_1 = (n_linhas / 3);
        max_2 = n_linhas;
        for (l = 1; l <= max_1; l++)
        {
            for (k = max_2; k > min; k--)
            {
                if (k >= 10)
                {
                    printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15]);
                }
                else
                {
                    printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15]);
                }
                printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
            if (k >= 10)
            {
                printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15]);
            }
            else
            {
                printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15]);
            }
            printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            max_2 = (max_2 - 3);
            min = (min - 3);
        }
        printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║\n");
        break;
    case 18:

        printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        min = (n_linhas - 2);
        max_1 = (n_linhas / 3);
        max_2 = n_linhas;
        for (l = 1; l <= max_1; l++)
        {
            for (k = max_2; k > min; k--)
            {
                if (k >= 10)
                {
                    printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18]);
                }
                else
                {
                    printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18]);
                }
                printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
            if (k >= 10)
            {
                printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18]);
            }
            else
            {
                printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18]);
            }
            printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            max_2 = (max_2 - 3);
            min = (min - 3);
        }
        printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║\n");
        break;
    case 21:

        printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        min = (n_linhas - 2);
        max_1 = (n_linhas / 3);
        max_2 = n_linhas;
        for (l = 1; l <= max_1; l++)
        {
            for (k = max_2; k > min; k--)
            {
                if (k >= 10)
                {
                    printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21]);
                }
                else
                {
                    printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21]);
                }
                printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
            if (k >= 10)
            {
                printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21]);
            }
            else
            {
                printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21]);
            }
            printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            max_2 = (max_2 - 3);
            min = (min - 3);
        }
        printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║ S │ T │ U ║\n");
        break;
    case 24:

        printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        min = (n_linhas - 2);
        max_1 = (n_linhas / 3);
        max_2 = n_linhas;
        for (l = 1; l <= max_1; l++)
        {
            for (k = max_2; k > min; k--)
            {
                if (k >= 10)
                {
                    printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21], yx[k][22], yx[k][23], yx[k][24]);
                }
                else
                {
                    printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21], yx[k][22], yx[k][23], yx[k][24]);
                }
                printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
            }
            if (k >= 10)
            {
                printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21], yx[k][22], yx[k][23], yx[k][24]);
            }
            else
            {
                printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n", k, yx[k][1], yx[k][2], yx[k][3], yx[k][4], yx[k][5], yx[k][6], yx[k][7], yx[k][8], yx[k][9], yx[k][10], yx[k][11], yx[k][12], yx[k][13], yx[k][14], yx[k][15], yx[k][16], yx[k][17], yx[k][18], yx[k][19], yx[k][20], yx[k][21], yx[k][22], yx[k][23], yx[k][24]);
            }
            printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
            max_2 = (max_2 - 3);
            min = (min - 3);
        }
        printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║ S │ T │ U ║ V │ W │ X ║\n");
        break;
    }
    printf("\n");
}

void print_pecas()
{
    printf("\nPeças(1) = %d    Peças(2) = %d    Peças(3) = %d    Peças(4) = %d    Peças(5) = %d    Peças(6) = %d    Peças(7) = %d    Peças(8) = %d\n", peca_n[1], peca_n[2], peca_n[3], peca_n[4], peca_n[5], peca_n[6], peca_n[7], peca_n[8]);
}

void print_dimensao()
{
    printf("\nDimensão = %d x %d \n", dim_tabu_y, dim_tabu_x);
}

void print_logo()
{
    printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
    switch (modo_jogo)
    {
    case 0:
        printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   █▀█\n                    █ ▀ █ █▄█ █▄▀ █▄█   █▄█\n\n");
        break;
    case 1:
        printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▄█\n                    █ ▀ █ █▄█ █▄▀ █▄█    █\n\n");
        break;
    case 2:
        printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▀█\n                    █ ▀ █ █▄█ █▄▀ █▄█   █▄\n\n");
        break;
    case 3:
        printf("               █ █▄ █ █▀ ▀█▀ █▀█ █ █ █▀▀ █▀█ █▀▀ █▀\n               █ █ ▀█ ▄█  █  █▀▄ █▄█ █▄▄ █▄█ ██▄ ▄█\n\n");
        break;
    }
}

int stringComp(char *str)
{ // Calcular o comprimento da string
    int i = 0;

    while (str[i] != '\0')
        i++; // Enquanto o carácter for diferente de NULL incrementa "i"

    return i;
}
