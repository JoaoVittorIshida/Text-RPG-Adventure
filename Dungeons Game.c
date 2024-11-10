#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

//Declaração de variáveis globais com status a serem alterados e acumulados durante a partida.
int ouro = 0, vida = 100, mana = 100, atq = 10, def = 0, pot=0, resp = 0, sala = 0;
int monvida = 0, monatq = 0, mondef = 0, monmortos = 0;
int sorte,montipo;
//índice de cada tipo de monstro
enum monstro{fraco=1,comum=2,forte=3};


void menu(){
//Menu a ser exibido em todas as salas
system("cls");
printf("\n|--------------------------------------|");
printf("\n     Vida(%d) Mana(%d) Ouro(%d)     ",vida,mana,ouro);
printf("\n   Pocoes(%d) Ataque(%d) Defesa(%d);",pot,atq,def);
printf("\n|--------------------------------------|");
printf("\n\n\nSala atual: %d",sala);
printf("\n      .-.");
printf("\n    __|=|__");
printf("\n   (_/`-`\\_)");
printf("\n   //\\___/\\\\");
printf("\n   <>/   \\<>");
printf("\n    \\|_._|/");
printf("\n     <_I_>");
printf("\n      |||");
printf("\n     /_|_\\\n");
printf("\n(1) Avancar!");
printf("\n(2) Usar pocao.");
printf("\n(3) Mercador.\n");
}

void usarpot(){
    //Sistema de utilização de poções de vida
    system("cls");
    if(pot>0){
        pot--;
        vida = vida + 25;
        printf("\nPocao utilizada! +25 de vida.\n");
        printf("\n\n      |~|  ");
        printf("\n      | |  ");
        printf("\n    .'   `.");
        printf("\n    `.___.'");
        Sleep(2000);
    }
    else{
        printf("\nNao tem pocoes!\n");
        printf("\n\n      |~|  ");
        printf("\n      | |  ");
        printf("\n    .'   `.");
        printf("\n    `.___.'");
        Sleep(2000);
    }
}

void menumercador(){
    //Menu exibido ao falar com o mercador
    system("cls");
    printf("  ___________________");
    printf("\n  |                 |");
    printf("\n  |  Lojinha do ze  |");
    printf("\n  |_________________|");
    printf("\n          |\\|         _____");
    printf("\n          |/|      /`^ \\   `\\");
    printf("\n          |\\|    /` [_] `\\   `\\");
    printf("\n          |/|  /` ___    _`\\___`\\");
    printf("\n          |\\|  | [_|_]  [_] |   |");
    printf("\n----------|/|--|------------|---|-----");
    printf("\n\nMeus recursos: Ouro(%d) Pocoes(%d)\nMeus status: Ataque(%d) Defesa(%d)\n",ouro,pot,atq,def);
    printf("\n(1) 30g - Comprar pocoes.\n(2) 25g - Aprimorar ataque +5.\n(3) 25g - Aprimorar defesa +2.\n(4) Retornar ao menu.\n");
}

void sistemamercador(){
    //Sistema do mercador
    //Executa a compra e adiciona a variável correspondente a compra realizada
    //Caso não tenha ouro, a compra não é realizada
    do{
        menumercador();
        scanf(" %d",&resp);
        switch(resp)
        {
            case 1:
                if(ouro>=30){
                    ouro = ouro - 30;
                    pot = pot + 1;
                    system("cls");
                    printf("\nPocao comprada!");
                    printf("\n\n      |~|  ");
                    printf("\n      | |  ");
                    printf("\n    .'   `.");
                    printf("\n    `.___.'");
                    Sleep(2000);

                }
                else{
                    system("cls");
                    printf("Voce nao tem ouro suficiente.");
                    Sleep(2000);
                }
                break;
            case 2:
                if(ouro>=25){
                    ouro = ouro - 25;
                    atq = atq + 5;
                    system("cls");
                    printf("\nAtaque aprimorado!");
                    printf("\n\n         />_________________________________");
                    printf("\n[########[]_________________________________>");
                    printf("\n         \\>\n\n");
                    Sleep(2000);}
                else{
                    system("cls");
                    printf("Voce nao tem ouro suficiente.");
                    Sleep(2000);
                }
                break;
            case 3:
                if(ouro>=25){
                    ouro = ouro - 25;
                    def = def + 2;
                    system("cls");
                    printf("\nDefesa aprimorada!");
                    printf("\n\n    |`-._/\\_.-`|");
                    printf("\n    |    ||    |");
                    printf("\n    |___o()o___|");
                    printf("\n    |__((<>))__|");
                    printf("\n    \\   o\\/o   /");
                    printf("\n     \\   ||   /");
                    printf("\n      \\  ||  /");
                    printf("\n       '.||.'");
                    printf("\n         ``\n\n");
                    Sleep(2000);}
                else{
                    system("cls");
                    printf("Voce nao tem ouro suficiente.");
                    Sleep(2000);
                }
                break;
            case 4:
                return;
                break;
            default:
                system("cls");
                printf("Comando invalido.");
                printf("\n\n   __   __");
                printf("\n   \\ \\ / /");
                printf("\n    \\ V / ");
                printf("\n     > <  ");
                printf("\n    / . \\ ");
                printf("\n   /_/ \\_\\\n\n");
                Sleep(1500);
                break;
        }
    }while(resp!=4);
}

void bau(){

    //Bau aleatório que pode ser encontrado nas salas
    system("cls");
    printf("\nEncontrou um bau!\n+30 de ouro\n+1 pocao");
    printf("\n\n      __________");
    printf("\n    /\\____;;___\\");
    printf("\n   | /         /");
    printf("\n   `. ())oo() .");
    printf("\n    |\\(%%()*^^()^\\");
    printf("\n   %%| |-%%-------|");
    printf("\n  %% \\ | %%  ))   |");
    printf("\n  %%  \\|%%________|");
    printf("\n   %%%%%%%%\n\n");
    ouro = ouro + 30;
    pot++;
    sala++;
    Sleep(2500);
}

void menubatalha(){

    //Menu de batalha contra os monstros, altera a arte do monstro de acordo com seu tipo
    system("cls");
    printf("\n[Batalha]\n\nSeu status: Vida(%d) Mana (%d) Pocoes(%d) Ataque(%d) Defesa(%d)\n",vida,mana,pot,atq,def);
    printf("Status do inimigo: Vida(%d) Ataque(%d) Defesa(%d)",monvida,monatq,mondef);
    if(montipo == fraco)
    {
        printf("\n\n      .-.");
        printf("\n     (o.o)");
        printf("\n      |=|");
        printf("\n     __|__");
        printf("\n   //.=|=.\\\\");
        printf("\n  // .=|=. \\\\");
        printf("\n  \\\\ .=|=. //");
        printf("\n   \\\\(_=_)//");
        printf("\n    (:| |:)");
        printf("\n     || ||");
        printf("\n     () ()");
        printf("\n     || ||");
        printf("\n     || ||");
        printf("\n    ==' '==");
    }
    if(montipo == comum)
    {
        printf("\n\n                        *");
        printf("\n                     *");
        printf("\n          (\\___/)     (");
        printf("\n          \\ (- -)     )\\ *");
        printf("\n          c\\   >'    ( #");
        printf("\n            )-_/      '");
        printf("\n     _______| |__    ,|//");
        printf("\n    # ___ `  ~   )  ( /");
        printf("\n    \\,|  | . ' .) \\ /#");
        printf("\n   _( /  )   , / \\ / |");
        printf("\n    //  ;;,,;,;   \\,/");
        printf("\n     _,#;,;;,;,");
        printf("\n    /,i;;;,,;#,;");
        printf("\n   ((  %%;;,;,;;,;");
        printf("\n    ))  ;#;,;%%;;,,");
        printf("\n  _//    ;,;; ,#;,");
        printf("\n /_)     #,;  //");
        printf("\n        //    \\|_");
        printf("\n        \\|_    |#\\");
        printf("\n         |#\\    -");
        printf("\n          -");
    }
    if(montipo == forte)
    {
        printf("\n\n     .      .");
        printf("\n     |\\____/|");
        printf("\n    (\\|----|/)");
        printf("\n     \\ 0  0 /");
        printf("\n      |    |");
        printf("\n   ___/\\../\\____");
        printf("\n  /     --       \\");
        printf("\n /  \\         /   \\");
        printf("\n|    \\___/___/(   |");
        printf("\n\\  /|  }{   | \\   )");
        printf("\n \\  ||__}{__|  |  |");
        printf("\n  \\  |;;;;;;;\\  \\ / \\_______");
        printf("\n   \\ /;;;;;;;;| [,,[|======'");
        printf("\n     |;;;;;;/ |     /");
        printf("\n     ||;;|\\   |");
        printf("\n     ||;;/|   /");
        printf("\n      \\_|:||__|");
        printf("\n      \\ ;||  /");
        printf("\n      |= || =|");
        printf("\n      |= /\\ =|");
        printf("\n      /_/  \\_\\");
    }
}

void monstromorreu(){

    //Ao elimitar um monstro, define o loot a ser recebido de acordo com o tipo do monstro + fator de sorte aplicado com a função random
    sorte = (rand() % 10);
                    if(montipo == fraco){
                        if(sorte<=5){
                            printf("\nO monstro foi morto! +20 de ouro  +0 pocao");
                            ouro = ouro + 20;
                        }
                        else{
                            printf("\nO monstro foi morto! +20 de ouro  +1 pocao");
                            ouro = ouro + 20;
                            pot++;
                        }
                    }
                    else if(montipo == comum){
                        if(sorte<=5){
                            printf("\nO monstro foi morto! +25 de ouro  +0 pocao");
                            ouro = ouro + 25;
                        }
                        else{
                            printf("\nO monstro foi morto! +25 de ouro  +1 pocao");
                            ouro = ouro + 25;
                            pot++;
                        }
                    }
                    else{
                        if(sorte<=5){
                            printf("\nO monstro foi morto! +30 de ouro  +0 pocao");
                            ouro = ouro + 30;
                        }
                        else{
                            printf("\nO monstro foi morto! +30 de ouro  +1 pocao");
                            ouro = ouro + 30;
                            pot++;
                        }
                    }
    return;
}

int sistemabatalha(){

    //Sistema de batalha contra os monstros, monstros definidos aleatóriamente pela função Random
    system("cls");
    sorte = (rand() % 10);
    if (sorte >=0 && sorte <= 2){
        monvida = 40 + (8*monmortos);
        monatq = 8 + (1*monmortos);
        mondef = 0 + (1*monmortos);
        montipo = fraco;
        printf("\nVoce encontrou um monstro fraco! A batalha ira se iniciar.");
        printf("\n\n      .-.");
        printf("\n     (o.o)");
        printf("\n      |=|");
        printf("\n     __|__");
        printf("\n   //.=|=.\\\\");
        printf("\n  // .=|=. \\\\");
        printf("\n  \\\\ .=|=. //");
        printf("\n   \\\\(_=_)//");
        printf("\n    (:| |:)");
        printf("\n     || ||");
        printf("\n     () ()");
        printf("\n     || ||");
        printf("\n     || ||");
        printf("\n    ==' '==");
    }
    else if(sorte >= 3 && sorte <= 8){
        monvida = 50 + (10*monmortos);
        monatq = 10 + (2*monmortos);
        mondef = 0 + (1*monmortos);
        montipo = comum;
        printf("\nVoce encontrou um monstro comum! A batalha ira se iniciar.");
        printf("\n\n                        *");
        printf("\n                     *");
        printf("\n          (\\___/)     (");
        printf("\n          \\ (- -)     )\\ *");
        printf("\n          c\\   >'    ( #");
        printf("\n            )-_/      '");
        printf("\n     _______| |__    ,|//");
        printf("\n    # ___ `  ~   )  ( /");
        printf("\n    \\,|  | . ' .) \\ /#");
        printf("\n   _( /  )   , / \\ / |");
        printf("\n    //  ;;,,;,;   \\,/");
        printf("\n     _,#;,;;,;,");
        printf("\n    /,i;;;,,;#,;");
        printf("\n   ((  %%;;,;,;;,;");
        printf("\n    ))  ;#;,;%%;;,,");
        printf("\n  _//    ;,;; ,#;,");
        printf("\n /_)     #,;  //");
        printf("\n        //    \\|_");
        printf("\n        \\|_    |#\\");
        printf("\n         |#\\    -");
        printf("\n          -");
    }
    else{
        monvida = 60 + (12*monmortos);
        monatq = 12 + (3*monmortos);
        mondef = 1 + (2*monmortos);
        montipo = forte;
        printf("\nVoce encontrou um monstro forte! A batalha ira se iniciar.");
        printf("\n\n     .      .");
        printf("\n     |\\____/|");
        printf("\n    (\\|----|/)");
        printf("\n     \\ 0  0 /");
        printf("\n      |    |");
        printf("\n   ___/\\../\\____");
        printf("\n  /     --       \\");
        printf("\n /  \\         /   \\");
        printf("\n|    \\___/___/(   |");
        printf("\n\\  /|  }{   | \\   )");
        printf("\n \\  ||__}{__|  |  |");
        printf("\n  \\  |;;;;;;;\\  \\ / \\_______");
        printf("\n   \\ /;;;;;;;;| [,,[|======'");
        printf("\n     |;;;;;;/ |     /");
        printf("\n     ||;;|\\   |");
        printf("\n     ||;;/|   /");
        printf("\n      \\_|:||__|");
        printf("\n      \\ ;||  /");
        printf("\n      |= || =|");
        printf("\n      |= /\\ =|");
        printf("\n      /_/  \\_\\");
    }
    Sleep(2000);
    //Batalha contra o monstro, o jogo exibe o menu para escolher as ações a serem realizadas
    do{
        menubatalha();
        printf("\n\n(1) - Ataque basico\n(2) - Habilidades\n(3) - Usar pocao\n");
        scanf(" %d",&resp);
        switch(resp)
        {
            //O algorítmo de dano causado é simples, ataque do usuário menos a defesa do alvo, caso causa dano crítico, dano do usuário é dobrado
            case 1:
                system("cls");
                sorte = (rand() % 10);
                if(sorte>=8){
                    printf("\nVoce atacou o monstro com um acerto critico, causando %d de dano.\n",((atq*2)-mondef));
                    monvida = monvida - ((atq*2)-mondef);
                }
                else{
                    printf("\nVoce atacou o monstro com um acerto normal, causando %d de dano.\n",(atq-mondef));
                monvida = monvida - (atq-mondef);
                }
                Sleep(1000);
                if(monvida<=0){
                    monstromorreu();
                    sala++;
                    monmortos++;
                    Sleep(2500);
                    return 1;
                }
                else{
                    printf("\nO monstro te atacou, causando %d de dano.",(monatq-def));
                    vida = vida - (monatq-def);
                    mana = mana + 5;
                    if (mana>100)
                        mana = 100;
                    Sleep(2000);
                    if(vida<=0)
                        return 0;
                    else
                        break;
                }
            case 2:
            //Menu de habilidades especiais
                menubatalha();
                printf("\n\n(1) - Soco de gelo\n(2) - Meditar\n(3) - Voltar\n");
                scanf(" %d",&resp);
                switch(resp)
                {
                    //A habilidade Soco de Gelo possui um multiplicador de dano de 1.5x e pode causar crítico ou congelar o alvo por 1 rodada
                    case 1:
                        if (mana>=30){
                            system("cls");
                            mana = mana - 30;
                            sorte = (rand() % 10);
                            if(sorte>=8){
                                printf("\nVoce atacou o monstro com um soco de gelo critico, causando %d de dano.\n",(((atq+(atq/2))*2)-mondef));
                                monvida = monvida - (((atq+(atq/2))*2)-mondef);
                            }
                            else{
                                printf("\nVoce atacou o monstro com um soco de gelo, causando %d de dano.\n",((atq+(atq/2))-mondef));
                                monvida = monvida - ((atq+(atq/2))-mondef);
                            }
                            Sleep(1000);
                            if(monvida<=0){
                                monstromorreu();
                                sala++;
                                monmortos++;
                                Sleep(2500);
                                return 1;
                                }
                                else{
                                    sorte = (rand() % 10);
                                    if(sorte>=6){
                                        printf("\nO monstro foi congelado e nao conseguiu te atacar!");
                                        Sleep(2000);
                                        break;
                                    }
                                    else{
                                    printf("\nO monstro te atacou, causando %d de dano.",(monatq-def));
                                    vida = vida - (monatq-def);
                                    Sleep(2000);
                                    if(vida<=0)
                                        return 0;
                                    else
                                        break;
                                    }
                                    }
                        }
                        else{
                            system("cls");
                            printf("Voce nao tem mana suficiente.");
                            Sleep(2000);
                        }
                        break;

                    //A habilidade Meditar cura o usuário em um valor fixo + a defesa dividida por 2, e em seguida, tudo multiplicado por 2
                    //Ao mesmo tempo, o ataque do inimigo causa dano reduzido, tornando assim essa uma rodada de cura pra o usuário
                    case 2:
                        system("cls");
                        if(mana>=35){
                            mana = mana - 35;
                            int vidacurada = (15 + (def/2)) * 2;
                            int danoredmon;
                            printf("\nVoce meditou e curou %d de vida!\n",vidacurada);
                            vida = vida + vidacurada;
                            Sleep(1000);
                            sorte = (rand() % 10);
                            if(sorte>=6){
                                danoredmon = (monatq/2)-(def/2);
                                if (danoredmon<0)
                                    danoredmon = 0;
                                printf("O monstro te atacou, causando %d de dano.",danoredmon);
                                vida = vida - danoredmon;
                            }
                            else{
                                danoredmon = (monatq/3)-(def/2);
                                if (danoredmon<0)
                                    danoredmon = 0;
                                printf("\nO monstro te atacou, causando %d de dano.",danoredmon);
                                vida = vida - danoredmon;
                            }
                            Sleep(2000);
                            if(vida<=0)
                                return 0;
                            else
                                break;
                        }
                        else{
                            system("cls");
                            printf("Voce nao tem mana suficiente.");
                            Sleep(2000);
                        }
                        break;
                    case 3:
                        break;

                    default:
                        system("cls");
                        printf("Comando invalido.");
                        printf("\n\n   __   __");
                        printf("\n   \\ \\ / /");
                        printf("\n    \\ V / ");
                        printf("\n     > <  ");
                        printf("\n    / . \\ ");
                        printf("\n   /_/ \\_\\\n\n");
                        Sleep(1500);
                        break;
                }
                break;
            case 3:
                system("cls");
                usarpot();
                break;
            default:
                system("cls");
                printf("Comando invalido.");
                printf("\n\n   __   __");
                printf("\n   \\ \\ / /");
                printf("\n    \\ V / ");
                printf("\n     > <  ");
                printf("\n    / . \\ ");
                printf("\n   /_/ \\_\\\n\n");
                Sleep(1500);
                break;
        }
    }while(1==1);
}

int main(){

    //Inicio do programa, define o personagem como vivo e cria/abre um arquivo txt para registrar o recorde de salas do jogador
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int vivo = 1;
    int recorde = 0;
    FILE *rec;
    rec = fopen("recorde.txt","w+");
    fscanf(rec,"d",&recorde);
    printf("\nBem vindo Text-RPG-Adventure!\nRecorde atual: %d salas\n\nPressione qualquer tecla para iniciar o jogo.",recorde);
    getch();
    //Menu padrão do jogo, contém as escolhas a serem realizadas, sala seguinte é definida aleatóriamente pela função Random
    do{
        menu();
        scanf(" %d", &resp);
        switch(resp)
        {
            //Caso 1 define a próxima sala com base na função Random (seed da função definida pela função Time, tornando assim cada run mais única)
            case 1:
                sorte = (rand() % 100);
                if (sorte>=85 && sorte<=100){
                    bau();
                    mana = mana + 10;
                    if (mana>100)
                        mana = 100;
                    break;
                }
                else if(sorte>=0 && sorte<=40){
                    vivo = sistemabatalha();
                    mana = mana + 10;
                    if (mana>100)
                        mana = 100;
                    break;
                }
                else{
                    system("cls");
                    sorte = (rand() % 10);
                    ouro = ouro + sorte;
                    printf("\nAchou uma sala pacifica com algumas urnas! + %d de ouro\n",sorte);
                    sala++;
                    mana = mana + 10;
                    if (mana>100)
                        mana = 100;
                    Sleep(2000);
                    break;}
            case 2:
                usarpot();
                break;
            case 3:
                sistemamercador();
                break;
            default:
                system("cls");
                printf("Comando invalido.");
                printf("\n\n   __   __");
                printf("\n   \\ \\ / /");
                printf("\n    \\ V / ");
                printf("\n     > <  ");
                printf("\n    / . \\ ");
                printf("\n   /_/ \\_\\\n\n");
                Sleep(1500);
                break;
        }

    }while(vivo==1);
    //Menu do jogo encerra com o retorno da morte do jogador, finalizado após ver as estatísticas e os créditos finais.
    system("cls");
    printf("\nVoce morreu.\nDeseja ver sua estatisticas? (1 para sim, qualquer outro valor para nao)\n");
    scanf(" %d",&resp);
    if(resp==1){
        printf("\nAndares totais: %d\nMonstros derrotados: %d\n",sala,monmortos);
            if(sala>recorde)
                printf("Novo recorde registrado!");
        Sleep(2000);
        printf("Obrigado por jogar! Jogo criado por: Joao Vittor Ishida");
    }
    else{
        if(sala>recorde)
            printf("Novo recorde registrado! %d salas!",sala);
        printf("\nObrigado por jogar! Jogo criado por: Joao Vittor Ishida");}
    getch();
}