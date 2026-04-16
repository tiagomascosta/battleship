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
#include <getopt.h>

#define DEFAULT_DIM_TABU_X 9 //valor de colunas do tabuleiro default
#define DEFAULT_DIM_TABU_Y 9 //valor de linhas do tabuleiro default

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
int stringComp();

int modo_jogo = 0, modo_pos = 1, modo_dis=1, dim_tabu_x=DEFAULT_DIM_TABU_X, dim_tabu_y=DEFAULT_DIM_TABU_Y, peca_n[9], tentativa_j[3];
char yx[17][26];

time_t t; 

    int main( int argc, char *argv[] ){ // Função que lê as opções do programa e o direciona para o modo de Jogo correspondente
        srand((unsigned)time(&t));
        memset(yx,'-',sizeof(yx)); // escrever '-' em todas as matrizes da variável
        int option = 'h';
        
        while ((option= getopt(argc, argv, "ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1){ // ler as opções escritas pelo utilizador na consola
            switch(option){
                case 'h': instrucoes(); break;
                case 't':
                    sscanf(optarg, "%dx%d", &dim_tabu_y,&dim_tabu_x);
                    if(dim_tabu_x % 3 || dim_tabu_x<9 || dim_tabu_x>24 || dim_tabu_y % 3 || dim_tabu_y<9 || dim_tabu_y>15){ // verificar se o tabuleriro inserido é valido
                        dim_tabu_x=DEFAULT_DIM_TABU_X; dim_tabu_y=DEFAULT_DIM_TABU_Y;
                    }
                    break;
                case 'j':
                    sscanf(optarg, "%d", &modo_jogo);
                    break;
                case 'p':
                    sscanf(optarg, "%d", &modo_pos);
                    break;
                case 'd':
                    sscanf(optarg, "%d", &modo_dis);
                    if(modo_jogo != 2){ // verificar se no modo de jogo pretendido pode ser definido modo de disparo // ATENÇÃO: NOTAMOS QUE NO SCRIPT QUE NOS FORNECEU ESTA RESTRIÇÃO PROVOCA UM CONFLITO, CONTUDO NO ENUNCIADO É REFERIDA ESTA RESTRIÇÃO. 
                        printf("\n-1 : No modo de jogo escolhido não é definido o modo de disparo.\n\n");
                        instrucoes();
                    }
                    break;
                case '1':
                    sscanf(optarg, "%d", &peca_n[1]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '2':
                    sscanf(optarg, "%d", &peca_n[2]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '3':
                    sscanf(optarg, "%d", &peca_n[3]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '4':
                    sscanf(optarg, "%d", &peca_n[4]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '5':
                    sscanf(optarg, "%d", &peca_n[5]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '6':
                    sscanf(optarg, "%d", &peca_n[6]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '7':
                    sscanf(optarg, "%d", &peca_n[7]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
                case '8':
                    sscanf(optarg, "%d", &peca_n[8]);
                    if(modo_pos==1 && (modo_jogo==0 || modo_jogo==1)){
                        printf("\n-1 : No modo de posicionamento escolhido não são definidas as peças.\n\n");
                        instrucoes();
                    }
                    break;
            }
        }
        
        if (((dim_tabu_y*dim_tabu_x)/9)<(peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8])){ // Verificar Restrição 2
            printf("\n-1 : O número de peças excedeu o número maximo de peças da matriz\n\n");
            return(1);
        }

        switch(modo_jogo){ // Encaminhar o programa para o modo de jogo pretendido
            case 0: modo_j0(); break;
            case 1: modo_j1(); break;
            case 2: modo_j2(); break; 
            default: // Caso o modo de jogo não seja válido termina o Programa com erro -1
                printf("\n-1 : Modo de Jogo inválido.\n\n");
                return(1); 
                break; 
        }
        return(0);  
    }

    void modo_j0(){ // Modo de Jogo 0

        switch(modo_pos){ // Encaminhar o programa para o modo de posicionamento pretendido
            case 1:modo_p1(); break; 
            case 2:modo_p2(); break;
            default: // Caso o modo de posicionamento não seja válido terminar a void com erro -1
                printf("\n-1 : Modo de posicionamento inválido.\n\n");
                exit(1);
                break;
        }
        print_logo();
        print_tabu();
    }

    void modo_j1(){ // Modo de Jogo 1
        int x, y=0, t_pecas=0, erro=0;
        char  x_alfa = 0, resposta[256], d_yx[17][26];
        memset(d_yx,0,sizeof(d_yx));

        t_pecas = peca_n[1] + peca_n[2]*2 + peca_n[3]*3 + peca_n[4]*4 + peca_n[5]*5 + peca_n[6]*6 + peca_n[7]*7 + peca_n[8]*8;

        switch(modo_pos){ // Encaminhar o programa para o modo de disparo pretendido
            case 1: modo_p1();break; 
            case 2: modo_p2();break;
            default: // Caso o modo de disparo não seja válido terminar a void com erro -1
                printf("\n-1 : Modo de posicionamento inválido.\n\n");
                exit(1);
                break;
        }

        time_t time_i = time(NULL); // Guardar Contagem do tempo neste momento

        print_logo();
        
            while(t_pecas != 0 || erro==1 ){ // verificar se o jogador ainda não descobriu todas as peças ou se houve algum erro
                erro=0;
                scanf("%s", resposta);
                if(stringComp(resposta)>3 || stringComp(resposta)<2 ){ // verificar se a resposta tem menos de 2 caracteres ou mais de 3
                    printf("\n-1 : Caracteres inválidos! Introduza novamente.\n\n");
                    erro=1;
                }
                else{
                    x_alfa = resposta[0];
                    if(stringComp(resposta)==2){y = resposta[1]-48;} // associara cordenada y a resposta se esta tiver 2 caracteres(y<9)
                    if(stringComp(resposta)==3){y = (resposta[1]-48)*10 + (resposta[2]-48);} // associara cordenada y a resposta se esta tiver 3 caracteres (y>9)      
                    if (x_alfa<65 || (x_alfa > (dim_tabu_x + 64) && x_alfa<96) || x_alfa > (dim_tabu_x + 96) || y<=0 || y > dim_tabu_y){ // verificar se as coordenasdas introduzidas são invalidas
                        printf("\n-1 : Coordenada inválida! Introduza novamente.\n\n");
                        erro=1;
                    }
                }
                if(x_alfa <= dim_tabu_x + 64){ // verificar se inseriu letras Maiúsculas
                        x = x_alfa - 64;
                    }
                    else{x = x_alfa - 96;} 

                if(erro==0){ // verificar se não houve erros ao inserir as coordenadas
                    tentativa_j[1]++;
                    printf("%c\n",yx[y][x]);
                    if (d_yx[y][x] != '1'){ // verificar se a coordenada ja tinha sido inserida  
                        if(yx[y][x] != '-'){t_pecas--;} // verificar se existe peça  
                    }
                    d_yx[y][x]='1';
                }
            }

        time_t time_f = time(NULL); // Guardar Contagem do tempo neste momento
        time_t time_spent= (time_f - time_i); // Calcular tempo decorrido ente as contagens do tempo guardadas
        
        printf("Fim de Jogo: %d jogadas em %ld segundos\n", tentativa_j[1], time_spent);
        print_tabu();
    }
            
    void modo_j2(){ // Modo de Jogo 2
        
        print_logo();

        time_t time_i = time(NULL); //início da contagem do tempo

        switch(modo_dis){
            case 1: modo_d1(); break; 
            case 2: modo_d2_3(); break;
            case 3: modo_d2_3(); break;
            default: 
                printf("\n-1 : Modo de disparo inválido\n\n");
                instrucoes();
                break;
        }

        time_t time_f = time(NULL); //fim de contagem do tempo
        time_t time_spent= (time_f - time_i);

        printf("Fim de Jogo: %d jogadas em %ld segundos\n" ,tentativa_j[2], time_spent);
        print_tabu();
    }

    void instrucoes(){ // Mensagem de Ajuda
        printf("Instruções:\n\n");
        printf("== Comandos ==\n\n");  
        printf(" -h   ajuda para o utilizador\n");
        printf(" -t   dimensões do tabuleiro (linha x coluna)\n");
        printf(" -j   modo de jogo (0 a 2)\n");
        printf(" -p   modo de posicionamento de peças pelo computador (1 a 2)\n");
        printf(" -d   modo de disparo de peças pelo computador (1 a 3)\n");
        printf(" -1   número de peças tipo 1 (mínimo 1)\n");
        printf(" -2   número de peças tipo 2\n");
        printf(" -3   número de peças tipo 3\n");
        printf(" -4   número de peças tipo 4\n");
        printf(" -5   número de peças tipo 5\n");
        printf(" -6   número de peças tipo 6\n");
        printf(" -7   número de peças tipo 7\n");
        printf(" -8   número de peças tipo 8\n\n");
        printf("== Modos de Jogo ==\n\n");
        printf(" Modo de Jogo 0:\n"); 
        printf(" O modo de jogo 0 só será totalmente válido se o invocar da seguinte forma:\n"); 
        printf(" ./wargame –t linhaxcoluna -j 0 -p [1 ou 2] [-1 a -8]\n\n");
        printf(" Modo de Jogo 1:\n");  
        printf(" O modo de jogo 1 só será totalmente válido se o invocar da seguinte forma:\n");
        printf(" ./wargame –t linhaxcoluna -j 1 -p [1 ou 2] [-1 a -8]\n\n");
        printf(" Modo de Jogo 2:\n"); 
        printf(" O modo de jogo 2 só será totalmente válido se o invocar da seguinte forma:\n"); 
        printf(" ./wargame –t linhaxcoluna -j 2 -d [1 ou 3] [-1 a -8]\n\n");
        exit(1);
    }
    
    void modo_p1(){ // Modo de Posicionamento 1
        int matriz_x, matriz_y=-1, x, y, peca, tentativa_v, e_v; // "tentativa_v" regista o nº de tentativas de colocação de uma variante e "e_v" é uma flag de erro de variante

        do{
            matriz_x=-1;
            matriz_y++;
            y=dim_tabu_y-(matriz_y*3);
            
            do{
                matriz_x++;
                x=1+(matriz_x*3);
                tentativa_v=1;
                
                do{
                    e_v=0;
                    if (tentativa_v<=3){ // verificar se as tentativas de colocar a peça < 3 
                        peca= rand() % 43;
                        switch(peca){ // cada "case" verificar se a peça gerada pode ser colocada, senão a flag "e_v" é ativa e incrementa-se o nº de tentativas
                        case 0:
                            peca_n[0]++;
                            break;
                        case 1: 
                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-'){
                            yx[y][x] = '1'; peca_n[1]++;
                            } 
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 2: 
                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){
                                yx[y][x+1] = '1'; peca_n[1]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 3: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'){
                                yx[y][x+2] = '1'; peca_n[1]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 4: 
                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){
                                yx[y-1][x] = '1'; peca_n[1]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 5: 
                            yx[y-1][x+1] = '1'; peca_n[1]++;
                            break;
                        case 6: 
                            if (yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){
                                yx[y-1][x+2] = '1'; peca_n[1]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 7: 
                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){
                                yx[y-2][x] = '1'; peca_n[1]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 8: 
                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                yx[y-2][x+1] = '1'; peca_n[1]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 9: 
                            if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'){
                                yx[y-2][x+2] = '1'; peca_n[1]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 10:
                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                yx[y][x] = '2';yx[y][x+1] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 11:
                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                yx[y][x+1] = '2';yx[y][x+2] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 12:
                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' ){
                                yx[y-1][x] = '2';yx[y-1][x+1] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 13:
                            if (yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){
                                yx[y-1][x+1] = '2';yx[y-1][x+2] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 14:
                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                yx[y-2][x] = '2';yx[y-2][x+1] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 15:
                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                yx[y-2][x+1] = '2';yx[y-2][x+2] = '2';peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 16:
                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' ){
                                yx[y][x] = '2';yx[y-1][x] = '2';peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 17:
                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' ){
                                yx[y-1][x] = '2';yx[y-2][x] = '2';peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 18:
                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                yx[y][x+1] = '2';yx[y-1][x+1] = '2';peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 19:
                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                yx[y-1][x+1] = '2';yx[y-2][x+1] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 20:
                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                yx[y][x+2] = '2';yx[y-1][x+2] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 21:
                            if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){
                                yx[y-1][x+2] = '2';yx[y-2][x+2] = '2'; peca_n[2]++;
                            } 
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 22: 
                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'){
                                yx[y][x] = '3';yx[y][x+1] = '3';yx[y][x+2] = '3'; peca_n[3]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 23: 
                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                yx[y-1][x] = '3';yx[y-1][x+1] = '3';yx[y-1][x+2] = '3'; peca_n[3]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 24: 
                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'){
                                yx[y-2][x] = '3';yx[y-2][x+1] = '3';yx[y-2][x+2] = '3'; peca_n[3]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 25: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){
                                yx[y][x] = '3';yx[y-1][x] = '3';yx[y-2][x] = '3'; peca_n[3]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 26: 
                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                yx[y][x+1] = '3';yx[y-1][x+1] = '3';yx[y-2][x+1] = '3';peca_n[3]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 27: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-'){
                                yx[y][x+2] = '3';yx[y-1][x+2] = '3';yx[y-2][x+2] = '3'; peca_n[3]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 28: 
                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){
                                yx[y][x] = '4';yx[y][x+1] = '4';yx[y-1][x] = '4';yx[y-1][x+1] = '4'; peca_n[4]++;
                            }
                            else {tentativa_v++;  e_v=1;} 
                            break;
                        case 29: 
                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){
                                yx[y][x+1] = '4';yx[y][x+2] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';peca_n[4]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 30: 
                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-2][x] = '4';yx[y-2][x+1] = '4';peca_n[4]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 31: 
                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'){
                                yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x+1] = '4';yx[y-2][x+2] = '4';peca_n[4]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 32: 
                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                yx[y][x] = '5';yx[y][x+1] = '5';yx[y][x+2] = '5';yx[y-1][x+1] = '5';yx[y-2][x+1] = '5';peca_n[5]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 33: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){
                                yx[y][x] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '5';peca_n[5]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 34: 
                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){
                                yx[y][x+1] = '5';yx[y-1][x+1] = '5';yx[y-2][x] = '5';yx[y-2][x+1] = '5';yx[y-2][x+2] = '5';peca_n[5]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 35: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){
                                yx[y][x+2] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x+2] = '5';peca_n[5]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 36: 
                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){
                                yx[y][x+1] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_n[6]++;
                            } 
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 37: 
                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){
                                yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6'; peca_n[6]++;
                            } 
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 38: 
                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x+1] = '6'; peca_n[6]++;
                            } 
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 39: 
                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){
                                yx[y][x] = '6';yx[y][x+1] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6'; peca_n[6]++;
                            } 
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 40: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-'){
                                yx[y][x] = '7';yx[y][x+2] = '7';yx[y-1][x] = '7';yx[y-1][x+1] = '7';yx[y-1][x+2] = '7';yx[y-2][x] = '7';yx[y-2][x+2] = '7';peca_n[7]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        case 41: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-'){
                                yx[y][x] = '7';yx[y][x+1] = '7';yx[y][x+2] = '7';yx[y-1][x+1] = '7';yx[y-2][x] = '7';yx[y-2][x+1] = '7';yx[y-2][x+2] = '7'; peca_n[7]++;
                            }else {tentativa_v++; e_v=1;} 
                            break;
                        case 42: 
                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-'){
                                yx[y][x] = '8';yx[y][x+1] = '8';yx[y][x+2] = '8';yx[y-1][x] = '8';yx[y-1][x+2] = '8';yx[y-2][x] = '8';yx[y-2][x+1] = '8';yx[y-2][x+2] = '8'; peca_n[8]++;
                            }
                            else {tentativa_v++; e_v=1;} 
                            break;
                        default: 
                            e_v=1;
                            break;
                        }
                    }
                    else { // colocar a peça com identificador global 5
                        yx[y-1][x+1] = '1';peca_n[1]++;
                    }
                }while (e_v != 0); // repetir enquanto a flag "e_v" esta ativa
            }while(x< dim_tabu_x - 2); // repetir enquanto não completar a linha de matrizes 3x3 
        }while(y>3); // repetir enquanto não completar todas linha de matrizes 3x3
    }

    void modo_p2(){ // Modo de Posicionamento 2
        int n_pecas_total, n_pecas_max, matriz_x, matriz_y, x, y, selecao_tipo, variante, tentativa_v, tentativa_p[9]={0}, n_peca[9]={0}, i, j, i_tabuleiro=0, erro_tabuleiro=0, erro_peca=0, e_v=0; // "tentativa_p" flag tentativa de colocação de peça
    
        n_pecas_total= peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8];
        n_pecas_max=((dim_tabu_x*dim_tabu_y)/9)/2;
        peca_n[0]= ((dim_tabu_x*dim_tabu_y)/9) - n_pecas_total;

        for (i=2;i<=8;i++){ // Verificar Restrição 3 
            if((peca_n[i]>peca_n[i-1]) && (modo_jogo==0 || modo_jogo==1)){
                printf("\n-1 : Nunca pode haver mais peças de um tipo de maior dimensão do que de um tipo de menor dimensão.\n\n");
                exit(1);
            }
        }
        
        if (n_pecas_total>n_pecas_max){ // Verificar Restrição 4
            printf("\n-1 : O número de peças excedeu o número máximo de peças da matriz.\n\n");
            exit(1);
        }

        do{ 
            memset(yx,'-',sizeof(yx));
            matriz_y=-1;
            erro_tabuleiro=0;
            for(i=0;i<=8;i++){ // igualar a variável "n_peca" a "peca_n"
                n_peca[i]=peca_n[i];
            }
            
            do{
                matriz_x=-1;
                matriz_y++;
                y=dim_tabu_y-(matriz_y*3);

                do{
                    for(j=0;j<=8;j++){ // reset da variável tentativa
                        tentativa_p[j]=0;
                    }
                    matriz_x++;
                    x=1+(matriz_x*3);
                    tentativa_v=-1; 
                    do{ 
                        erro_peca=0;
                        selecao_tipo = rand() % 9;
                            
                        if ((n_peca[0]==0 || tentativa_p[0]==1) && (n_peca[1]==0 || tentativa_p[1]==1) && (n_peca[2]==0 || tentativa_p[2]==1) && (n_peca[3]==0 || tentativa_p[3]==1) && (n_peca[4]==0 || tentativa_p[4]==1) && (n_peca[5]==0 || tentativa_p[5]==1) &(n_peca[6]==0 || tentativa_p[6]==1) &(n_peca[7]==0 || tentativa_p[7]==1) && (n_peca[8]==0 || tentativa_p[8]==1) ){
                            i_tabuleiro++;erro_tabuleiro=1; // verificar se faltam algumas peças e se estas são impossíveis de colocar, desta forma ativar a flag "erro_tabuleiro" e incrementar o nº de tabuleiro gerados
                            } 
                        if (tentativa_p[selecao_tipo]==1){erro_peca=1;} // Se ja tentamos colocar essa peça, ativa a flag "erro_peca"
                        else{
                            if(selecao_tipo==0 && n_peca[0] != 0){ // Se a peça for 0 e ainda houver peças desse tipo para colocar 
                                n_peca[0]--; e_v=0;
                            }
                            else if (selecao_tipo == 1 && n_peca[1] != 0){ // Se a peça for do tipo 1 e ainda houver peças desse tipo para colocar
                                do{ 
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;} // Se a flag e_v estiver ativa, percorre todas as variantes desse tipo  
                                    else{variante= rand() % 9;} // Aleatoriza a variante da peça
                                    switch(variante){ // cada "case" verificar se a peça gerada pode ser colocada, senão a flag "e_v" é ativa
                                        case 0:
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' ){
                                                yx[y][x] = '1'; n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                        break;
                                        case 1: 
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                                yx[y][x+1] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 2:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y][x+2] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 3:
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' ){
                                                yx[y-1][x] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 4: 
                                            yx[y-1][x+1] = '1';n_peca[1]--;
                                            break;
                                        case 5: 
                                            if (yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y-1][x+2] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 6: 
                                        if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' ){
                                                yx[y-2][x] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 7: 
                                        if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y-2][x+1] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 8: 
                                            if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y-2][x+2] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                    }
                                    if(tentativa_v>=8){erro_peca=1;tentativa_p[1]=1;} // se não conseguir colocar nenhuma variante (tentativa=8), ativa a flag "erro_peca" e a flag "tentativa_p[1]" 
                                }while (tentativa_v<8 && e_v==1 ); // repete este ciclo enquanto a "tentativa"<8 e  a flag "e_v" estiver ativa 
                            }
                            else if (selecao_tipo == 2 && n_peca[2] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 12;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'  ){
                                                yx[y][x] = '2';yx[y][x+1] = '2';n_peca[2]--;
                                            } 
                                            else {e_v=1;}
                                            break;
                                        case 1:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'   ){
                                                yx[y][x+1] = '2';yx[y][x+2] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 2:
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-'  ){
                                                yx[y-1][x] = '2';yx[y-1][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3:
                                            if (yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'  ){
                                                yx[y-1][x+1] = '2';yx[y-1][x+2] = '2';n_peca[2]--;
                                            } 
                                            else {e_v=1;} 
                                            break;
                                        case 4:
                                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'  ){
                                                yx[y-2][x] = '2';yx[y-2][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 5:
                                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'   ){
                                                    yx[y-2][x+1] = '2';yx[y-2][x+2] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 6:
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-'  ){
                                                yx[y][x] = '2';yx[y-1][x] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 7:
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  ){
                                                yx[y-1][x] = '2';yx[y-2][x] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 8:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'  ){
                                                yx[y][x+1] = '2';yx[y-1][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 9:
                                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'  ){
                                                yx[y-1][x+1] = '2';yx[y-2][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 10:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'  ){
                                                yx[y][x+2] = '2';yx[y-1][x+2] = '2';n_peca[2]--;
                                            } 
                                            else {e_v=1;} 
                                            break;
                                        case 11:
                                        if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'  ){
                                            yx[y-1][x+2] = '2';yx[y-2][x+2] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                    }
                                    if(tentativa_v>=11){erro_peca=1;tentativa_p[2]=1;}
                                }while (tentativa_v<11 && e_v==1 );  
                            }
                            else if (selecao_tipo == 3 && n_peca[3] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 6;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y][x] = '3';yx[y][x+1] = '3';yx[y][x+2] = '3';n_peca[3]--;
                                            }else {e_v=1;} 
                                            break;
                                        case 1: 
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y-1][x] = '3';yx[y-1][x+1] = '3';yx[y-1][x+2] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 2: 
                                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y-2][x] = '3';yx[y-2][x+1] = '3';yx[y-2][x+2] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3: 
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){
                                                yx[y][x] = '3';yx[y-1][x] = '3';yx[y-2][x] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 4:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y][x+1] = '3';yx[y-1][x+1] = '3';yx[y-2][x+1] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 5: 
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' ){
                                                yx[y][x+2] = '3';yx[y-1][x+2] = '3';yx[y-2][x+2] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                    }       
                                    if(tentativa_v>=5){erro_peca=1;tentativa_p[3]=1;}
                                }while (tentativa_v<5 && e_v==1 );
                            }
                            else if (selecao_tipo == 4 && n_peca[4] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 4;} 
                                    switch(variante){
                                        case 0:
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                                yx[y][x] = '4';yx[y][x+1] = '4';yx[y-1][x] = '4';yx[y-1][x+1] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y][x+1] = '4';yx[y][x+2] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 2: 
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-2][x] = '4';yx[y-2][x+1] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3: 
                                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){
                                                yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x+1] = '4';yx[y-2][x+2] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa_p[4]=1;}
                                }while (tentativa_v<3 && e_v==1 );
                            }
                            else if (selecao_tipo == 5 && n_peca[5] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 4;}
                                    switch(variante){
                                        case 0: 
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                                yx[y][x] = '5';yx[y][x+1] = '5';yx[y][x+2] = '5';yx[y-1][x+1] = '5';yx[y-2][x+1] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1: 
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){
                                                yx[y][x] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 2: 
                                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){
                                                yx[y][x+1] = '5';yx[y-1][x+1] = '5';yx[y-2][x] = '5';yx[y-2][x+1] = '5';yx[y-2][x+2] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){
                                                yx[y][x+2] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x+2] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa_p[5]=1;}
                                }while (tentativa_v<3 && e_v==1 );
                            }
                            else if (selecao_tipo == 6 && n_peca[6] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                do{
                                if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                else{variante= rand() % 4;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                                    yx[y][x+1] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';n_peca[6]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1: 
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' ){
                                                yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';n_peca[6]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 2: 
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x+1] = '6';n_peca[6]--;
                                            } 
                                            else {e_v=1;} 
                                            break;
                                        case 3: 
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y][x] = '6';yx[y][x+1] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';n_peca[6]--;
                                                }
                                                else {e_v=1;} 
                                                break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa_p[6]=1;}
                                }while (tentativa_v<3 && e_v==1 );
                            }
                            else if (selecao_tipo == 7 && n_peca[7] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                do{
                                if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                else{variante= rand() % 2;}
                                   switch(variante){
                                        case 0:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y][x] = '7';yx[y][x+2] = '7';yx[y-1][x] = '7';yx[y-1][x+1] = '7';yx[y-1][x+2] = '7';yx[y-2][x] = '7';yx[y-2][x+2] = '7';n_peca[7]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){
                                                    yx[y][x] = '7';yx[y][x+1] = '7';yx[y][x+2] = '7';yx[y-1][x+1] = '7';yx[y-2][x] = '7';yx[y-2][x+1] = '7';yx[y-2][x+2] = '7';n_peca[7]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                    }       
                                    if(tentativa_v>=2){erro_peca=1;tentativa_p[7]=1;}
                                }while (tentativa_v<2 && e_v==1 );
                            }
                            else if (selecao_tipo == 8 && n_peca[8] != 0){ // o funcionamento deste bloco de código é análogo ao bloco acima (explicado no bloco da peça tipo 1)
                                if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){
                                    yx[y][x] = '8';yx[y][x+1] = '8';yx[y][x+2] = '8';yx[y-1][x] = '8';yx[y-1][x+2] = '8';yx[y-2][x] = '8';yx[y-2][x+1] = '8';yx[y-2][x+2] = '8';n_peca[8]--;
                                    } 
                                    else {erro_peca=1;tentativa_p[8]=1;} 
                            } 
                            else{erro_peca=1;}
                        }
                    }while(erro_peca==1 && erro_tabuleiro==0); // Repete este ciclo enquanto a flag "erro_peca" estiver ativa e a flag "erro_tabuleiro" estiver inativa 

                }while(x< dim_tabu_x - 2 && erro_tabuleiro==0); // Repete este ciclo enquanto não completar a linha de matrizes 3x3
            }while(y>3 && erro_tabuleiro==0 ); // Repete este ciclo enquanto não completar todas linha de matrizes 3x3
        }while(i_tabuleiro<1000 && erro_tabuleiro==1); // Repete este ciclo enquanto não forem gerados 1000 tabuleiro e a flag "erro_tabuleiro" estiver ativa
        
        if(i_tabuleiro==1000){ // Erro -1 pois não foi possível gerar o tabuleiro nas ultimas 1000 vezes
            printf("\n-1 : Não foi possível gerar o tabuleiro.\n\n");
            exit(1);
        }
    }
   
    void modo_d1(){ // Modo de Disparo 1

        int x, y, disparo=0, n_peca[9]={0}, erro=0, e=0;
        char x_alfa='0', d_yx[17][26], resposta[256];
        memset(d_yx,0,sizeof(d_yx));

        n_peca[1]=peca_n[1]; n_peca[2]=2*peca_n[2]; 
        n_peca[3]=3*peca_n[3]; n_peca[4]=4*peca_n[4]; 
        n_peca[5]=5*peca_n[5]; n_peca[6]=6*peca_n[6]; 
        n_peca[7]=7*peca_n[7]; n_peca[8]=8*peca_n[8];

        do{  
            y = rand() % (dim_tabu_y);
            x = rand() % (dim_tabu_x);
            x++; // pois a função "rand" devolve valores no intervalo [0,dim_tabu_x - 1], incrementando 1, fica no intervalo [1,dim_tabu_x]
            y++; // pelo mesmo motivo da linha anterior
            x_alfa = x + '@'; // converter o valor de "x" na letra do alfabeto correspondente "x_alfa"
            if(d_yx[y][x] != 1){ // se a flag "d_yx" não estiver ativa
                do{
                    erro=0;
                    e=0;
                    printf("%c%d\n", x_alfa, y);
                    scanf("%s", resposta);
                    if(stringComp(resposta)>1 || (((resposta[0]<49 && resposta[0] != 45) || resposta[0]>56) && stringComp(resposta)==1)){ // verificar se a resposta tem  mais de 1 carácter ou no caso de ter só 1 se é diferente de "-" ( 45 na tabela de ASCII) e não estiver no interalo [1,8]( [49,56] na tabela de ASCII ) , ou seja verificar se o carácter é inválido
                       erro=1; // ativar a flag "erro"
                       printf("\n-1 : Carácter inválido! Introduza novamente.\n\n");
                    }
                    if (stringComp(resposta)==1 && erro==0){yx[y][x]=resposta[0];} // verifica se a resposta tem 1 carácter e a flag "erro" esta inativa, nesse caso iguala o único carácter da resposta à posição do tabuleiro correspondente
                    if((yx[y][x]) != '-' && erro==0){ // Se o carácter inserido for diferente de "-" e a flag "erro" estiver inativa 
                        disparo=(yx[y][x]) -'0'; // converter o número da variável (char)"yx" para (int)"disparo"
                        if (n_peca[disparo]==0 && erro==0){ // se o "n_peca" correspondente ao "disparo" for 0 e a flag "erro" estiver inativa, quer dizer que já foram descobertas todas as peças desse tipo ativando a flag "e"
                            e=1; 
                            printf("\n-1 : Já foram descobertas todas as peças desse tipo.\n\n");
                        }
                        if (e==0){(n_peca[disparo])--;} // Se a flag "e" estiver inativa (o disparo for válido), decrementa as pecas correspondente a esse disparo
                    } 
                    if (erro==0 && e==0){(d_yx[y][x])=1;tentativa_j[2]++;} // Se as flags "erro" e "e" estiverem inativas (o disparo for válido) ativa a flag "d_yx" correspondente para indicar que essa coordenada ja foi aleatorizada e incrementa as tentativas
                }while(erro==1 || e==1); // Repete este ciclo enquanto uma das flags "erro" ou "e" estiver ativa
            }
        }while(n_peca[1] != 0 || n_peca[2] != 0 || n_peca[3] != 0 || n_peca[4] != 0 || n_peca[5] != 0 || n_peca[6] != 0 || n_peca[7] != 0 || n_peca[8] != 0); // Repete este ciclo enquanto existirem pecas por posicionar 
    }

    void modo_d2_3(){ // Modo de Disparo 2 e 3
        int x, y, matriz_x, matriz_y=-1, disparo=0, disparos_peca[9]={0}, n_peca[9]={0}, i, j, m, n, e=0, erro=0, sequencia[2][9]={{-1,0,-2,-1,-1,0,-2,0,-2},{1,1,1,0,2,0,2,2,0}}; // sequencia de disparos explicada no guia de implementação; "disparos_peca" contabiliza os disparos efetuados a uma peça por matriz
        char x_alfa='0', resposta[256],d_yx[17][26];
        memset(d_yx,0,sizeof(d_yx));

        n_peca[1]=peca_n[1]; n_peca[2]=2*peca_n[2]; 
        n_peca[3]=3*peca_n[3]; n_peca[4]=4*peca_n[4]; 
        n_peca[5]=5*peca_n[5]; n_peca[6]=6*peca_n[6]; 
        n_peca[7]=7*peca_n[7]; n_peca[8]=8*peca_n[8]; 

        do{ 
            matriz_x=-1;
            matriz_y++;
            y=dim_tabu_y-(matriz_y*3);
            
            do{
                for(i=0;i<=8;i++){ // reset da variável "disparos_peca"
                    disparos_peca[i]=0;
                }
                matriz_x++;
                x=1+(matriz_x*3);
                j=0;     
                    do{
                        if(modo_dis==2 || (modo_dis==3 && d_yx[y+(sequencia[0][j])][x+(sequencia[1][j])] != '1')){ // Se o Modo de Disparo for 2 ou se for 3 e a flag "d_yx" correspondente estiver inativa ( se estiver ativa salta a cordenada do disparo )
                    
                            do{
                                x_alfa = x + (sequencia[1][j]) + '@'; // converter o valor de "x" na letra do alfabeto correspondente "x_alfa"
                                erro=0;
                                e=0;
                                printf("%c%d\n",x_alfa, (y+(sequencia[0][j])));
                                scanf("%s", resposta);
                                if(stringComp(resposta)>1 || (((resposta[0]<49 && resposta[0] != 45) || resposta[0]>56) && stringComp(resposta)==1)){ // verificar se a resposta tem  mais de 1 carácter ou no caso de ter só 1 se é diferente de "-" ( 45 na tabela de ASCII) e não estiver no interalo [1,8]( [49,56] na tabela de ASCII ) , ou seja verificar se o carácter é inválido
                                    erro=1;
                                    printf("\n-1 : Carácter inválido! Introduza novamente.\n\n");
                                }
                                if (stringComp(resposta)==1 && erro==0){yx[y+(sequencia[0][j])][x+(sequencia[1][j])]=resposta[0];} // verifica se a resposta tem 1 carácter e a flag "erro" esta inativa, nesse caso iguala o único carácter da resposta à posição do tabuleiro correspondente
                                if(yx[y+(sequencia[0][j])][x+(sequencia[1][j])] != '-' && erro==0){  // Se o carácter inserido for diferente de "-" e a flag "erro" estiver inativa
                                    disparo=(yx[y+(sequencia[0][j])][x+(sequencia[1][j])]) -'0'; // converter o número da variável (char)"yx" para (int)"disparo"
                                    if (n_peca[disparo]==0 && erro==0){ // se o "n_peca" correspondente ao "disparo" for 0 e a flag "erro" estiver inativa, quer dizer que já foram descobertas todas as peças desse tipo ativando a flag "e"
                                        e=1;
                                        printf("\n-1 : Já foram descobertas todas as peças desse tipo.\n\n");
                                    }
                                    if (e==0){(disparos_peca[disparo])++;(n_peca[disparo])--;} // Se a flag "e" estiver inativa, incrementa o disparos da peça correspondente e decrementa o nº de peças da peça correspondente 
                                }
                                if (e==0 && erro==0){tentativa_j[2]++;} // Se as flags "erro" e "e" estiverem inativas ( o disparo for válido ) incrementa as tentativas
                            }while(erro==1 || e==1); // Repete este ciclo enquanto uma das flags "erro" ou "e" estiver ativa
                        }
                        j++;
                    }while(j<=8 && disparos_peca[1] < 1 && disparos_peca[2] < 2 && disparos_peca[3] < 3 && disparos_peca[4] < 4 && disparos_peca[5] < 5 && disparos_peca[6] < 6 && disparos_peca[7] < 7 && disparos_peca[8] < 8); // Repete este ciclo enquanto não percorrer a matriz toda (j<=8) e os disparos da peça 'x' sejam menores que 'x'
                if(modo_dis==3){ // Se o modo disparo for o 3, este bloco de código irá ativar as flags "d_yx" em torno das peças colocadas (restrição 1) 
                    for(m=0;m<=8;m++){ 
                        if(yx[y+sequencia[0][m]][x+sequencia[1][m]]!='-'){
                            for (n=0;n<=8;n++){
                                d_yx[y+1 + sequencia[0][m]+sequencia[0][n]][x-1 +sequencia[1][m]+sequencia[1][n]]='1';
                            }
                        }
                    }
                }
            }while((x< dim_tabu_x-2) && (n_peca[1] != 0 || n_peca[2] != 0 || n_peca[3] != 0 || n_peca[4] != 0 || n_peca[5] != 0 || n_peca[6] != 0 || n_peca[7] != 0 || n_peca[8] != 0)); // Repete este ciclo enquanto não completar a linha de matrizes 3x3 e existirem pecas por posicionar 
        }while(y>3 && (n_peca[1] != 0 || n_peca[2] != 0 || n_peca[3] != 0 || n_peca[4] != 0 || n_peca[5] != 0 || n_peca[6] != 0 || n_peca[7] != 0 || n_peca[8] != 0)); // Repete este ciclo enquanto não completar todas linha de matrizes 3x3 e existirem pecas por posicionar 
    }

    int stringComp(char *str){  // Calcular o comprimento da string
        int i=0;  
     
        while(str[i] != '\0') i++; // Enquanto o carácter for diferente de NULL incrementa "i"
     
        return i;  
    } 

	void print_tabu(){ // Print do Tabuleiro
        int l, i, j, k;
        l=dim_tabu_y;
        for(i=dim_tabu_x+1;i<=25;i++){ // Apaga todas as coordenadas da matriz "yx" para além da dimensão do tabuleiro de jogo 
            for(j=0;j<=16;j++){
                yx[j][i]=' ';
            }
        }
        do{
            if(l<10){ // Se o número das linhas for < 10 escreve um espaço antes do número para as matrizes ficarem alinhadas
                printf(" ");
            } 
            printf("%d %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",l,yx[l][1],yx[l][2],yx[l][3],yx[l][4],yx[l][5],yx[l][6],yx[l][7],yx[l][8],yx[l][9],yx[l][10],yx[l][11],yx[l][12],yx[l][13],yx[l][14],yx[l][15],yx[l][16],yx[l][17],yx[l][18],yx[l][19],yx[l][20],yx[l][21],yx[l][22],yx[l][23],yx[l][24]);      
            l--;
        }while(l>0); // Repete este ciclo enquanto não forem escritas todas as linhas (l>0)
        printf("  ");
        for(k=65;k<=(dim_tabu_x+64);k++){ // escreve as letras correspondentes as colunas do tabuleiro
            printf(" %c", k);
        }
        printf("\n");
    }

    void print_logo(){ // Print do Cabeçalho do Programa 
        if (modo_jogo != 0){ // Se o modo de jogo for diferente de 0, pois ele não escreve esta parte do cabeçalho no modo de jogo 0
            printf("* ================================\n");
            switch(modo_jogo){ // Escreve o cabeçalho consoante o modo de jogo
                case 1:
                    printf("* Modo de Jogo 1\n");
                    printf("* Insira as coordenadas de disparo\n");
                    break;
                case 2:
                    printf("* Modo de Jogo 2\n");
                    printf("* Crie um tabuleiro com as características indicadas\n");
                    printf("* Responda aos disparos do programa\n");
                    break;
            }
            printf("* ================================\n");
        }
        printf("%dx%d",dim_tabu_y,dim_tabu_x); //print da dimensão do tabuleiro
        printf(" %d %d %d %d %d %d %d %d\n",peca_n[1],peca_n[2],peca_n[3],peca_n[4],peca_n[5],peca_n[6],peca_n[7],peca_n[8]); //print do número de peças de cada tipo
    }
    