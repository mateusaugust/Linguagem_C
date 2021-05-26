//Mateus Augusto da Silva

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int jogar (char *palavra_secreta, char *dica, int *pointer_tamanho_palavra){

    char tracinhos[100], letras_usadas[100], chute;
    int acertos=0, erros=0, controle_erros, contador;

    for(contador=0; contador<*pointer_tamanho_palavra; contador++){
        tracinhos[contador]='_';
    }

    for(contador=0; contador<99; contador++){
    	letras_usadas[contador]='\0';
	}

   do{
        printf("Dica palavra secreta: %s\n", dica);
        printf("%s\n\n", tracinhos);

		printf("Letras já usadas/erradas: %s ", letras_usadas);
		fflush(stdin);

        printf("\n\nDigite seu chute: ");
        scanf("%c", &chute );
        printf("\n");

		controle_erros=0;

        for(contador=0; contador<*pointer_tamanho_palavra; contador++){
            if(palavra_secreta[contador]== chute){
            	controle_erros++;
                tracinhos[contador]=chute;
                acertos ++;
            }
        }

        if(controle_erros==0){
             for(contador=0; contador<99;contador++){
        		if(letras_usadas[contador]=='\0'){
        		letras_usadas[contador]=chute;
        		break;
			}
		}
            erros++;
        }

        controle_erros=0;

        if(erros==1){
            printf("-----------------\n");
            printf("|               |\n");
            printf("|               |\n");
            printf("|               O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("-----\n");
        }

        if(erros==2){
            printf("-----------------\n");
            printf("|               |\n");
            printf("|               |\n");
            printf("|               O\n");
            printf("|               H \n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("-----\n");
        }

        if(erros==3){
            printf("-----------------\n");
            printf("|               |\n");
            printf("|               |\n");
            printf("|               O\n");
            printf("|               H\\ \n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("-----\n");
        }

        if(erros==4){
            printf("-----------------\n");
            printf("|               |\n");
            printf("|               |\n");
            printf("|               O \n");
            printf("|              /H\\ \n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("-----\n");
        }

        if(erros==5){
            printf("-----------------\n");
            printf("|               |\n");
            printf("|               |\n");
            printf("|               O  \n");
            printf("|              /H\\ \n");
            printf("|                \\ \n");
            printf("|\n");
            printf("|\n");
            printf("-----\n");
        }

        if(erros==6){
            system("color 40");

            printf("-----------------\n");
            printf("|               |\n");
            printf("|               |\n");
            printf("|               O\n");
            printf("|              /H\\  \n");
            printf("|              / \\  \n");
            printf("|\n");
            printf("|\n");
            printf("-----          \n\n");

            printf("Você perdeu!!!!\n\n");

            system("pause");
        }


        if(acertos==*pointer_tamanho_palavra){
        	printf("%s\n", tracinhos);
        	printf("Você acertou todas as letras!!\n\n");
        	system("pause");
			}

			system("pause && cls");
   }while(erros<6 && acertos<*pointer_tamanho_palavra);
   system("color 07");
}

int inserir_dica (char *dica){

    printf("\n\n\t\tDigite uma dica sobre a palavra secreta: ");
    scanf(" %[^\n]",dica);
}

int inserir_palavra_secreta(char *palavra_secreta, int *pointer_tamanho_palavra){

    printf("\n\n\t\tDigite a palavra secreta: ");
    scanf("  %[^\n]",palavra_secreta);

    *pointer_tamanho_palavra= strlen(palavra_secreta);
}

int encaminha_opcao_escolhida(int opcao_escolhida_menu, char *palvra_secreta, int *pointer_tamanho_palavra, char *dica){

    switch(opcao_escolhida_menu){
        case 1:
            inserir_palavra_secreta(palvra_secreta, pointer_tamanho_palavra);
        break;

        case 2:
            inserir_dica(dica);
        break;

        case 3:
            jogar(palvra_secreta, dica, pointer_tamanho_palavra);
        break;

        case 0:
            printf("\n\n\tPrograma Finalizado Com Sucesso!!\n\n");
        break;
    }
    system("cls");
}

int menu (int opcao_escolhida_menu, char *palvra_secreta, int *pointer_tamanho_palavra, char *dica){

    do{
        printf("\t\t ===================\n ");
        printf("\t\t|   Jogo da Forca   |");
        printf("\n\t\t =================== ");

        printf("\n\n");

        printf("\t\t ===================\n ");
        printf("\t\t        Menu       ");
        printf("\n\t\t(1) Inserir palavra secreta.\n\n\t\t(2) Inserir dica.\n\n\t\t(3) Iniciar o Jogo.\n\n\t\t(0) Finalizar o Jogo.");
        printf("\n\t\t =================== ");

        printf("\n\n\t\tDigite a opção escolhida ->");
        scanf("%d", &opcao_escolhida_menu);

        system("cls");

        encaminha_opcao_escolhida(opcao_escolhida_menu, palvra_secreta, pointer_tamanho_palavra, dica);

    }while(opcao_escolhida_menu!=0);
}

int main (){
    setlocale(LC_ALL,"portuguese");
    system("color 07");

    char palvra_secreta[100],dica[200];
    int *pointer_tamanho_palavra, opcao_escolhida_menu, tamanho_palavra;

    pointer_tamanho_palavra=&tamanho_palavra;

    menu(opcao_escolhida_menu, palvra_secreta, pointer_tamanho_palavra, dica);

return 0;
}

