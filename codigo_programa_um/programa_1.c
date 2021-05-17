//Mateus Augusto da Silva

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int save_vetor1 (int *v1, int tam_vetor1){
    int i;

    printf("\nDigite a sequência desejada:\n");

    for(i=0; i<tam_vetor1; i++){
            scanf("%d", &v1[i]);

    }
}

int calc_media (int *v1, int tam_vetor1, int *pm){
    int soma=0, i;

    for(i=0; i<tam_vetor1; i++){
        soma=soma+v1[i];

    }
    *pm=soma/tam_vetor1;
}

int calc_var (int *v1, int tam_vetor1, int *pm){
    int i, varia, sub=0, soma=0, pvar=0;

    for(i=0; i<tam_vetor1; i++){
        sub=v1[i]-*pm;
        varia=pow(sub, 2);
        soma=varia+soma;
        }

        pvar=soma/tam_vetor1;

        printf("\nA variança desses números é - > %d\n", pvar );
}

int main (){
    setlocale(LC_ALL,"portuguese");
    system("color 0C");

    int *v1, tam_vetor1, *pm, media;

    pm=&media;


    printf("Digite o número para fazer a variância -> ");
    scanf("%d", &tam_vetor1);

    v1 = (int*) malloc(tam_vetor1*sizeof(int));

    save_vetor1(v1, tam_vetor1);

    calc_media(v1, tam_vetor1, pm);

    calc_var(v1, tam_vetor1, pm);
return 0;
}
