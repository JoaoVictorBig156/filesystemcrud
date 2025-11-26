#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int criar_cha(char* cha, int codigo){
FILE*file;
file= fopen("cha.txt","a");
fprintf(file, "codigo:%d Nome do cha:%s\n",codigo ,cha);
fclose (file);
return 0;
}
char* ler_cha(int cha_requerido){
    char leitura_cha[31];
    char* cha_lido="Chá não encontrado" ;
    int codigo=0;
    FILE *file;
    file = fopen("cha.txt", "r");
    while (!feof(file))
    {
        fgets(leitura_cha,31,file);
        sscanf(leitura_cha, "%02d[^,],%10s[^,]" ,codigo,cha_lido);
        if(codigo==cha_requerido){
        break;
        }
    }
    fclose(file);
    return cha_lido ;
}
int remover_cha(int cha_requerido){
    int codigo=0;
    char cha_lido[10];
    char leitura_cha[31];
    int encontrada = 0;
    FILE *origem, *destino;
    origem = fopen("cha.txt", "r");
    destino = fopen("temp.txt", "w");
    while (fgets(leitura_cha, 31, origem))
    {
        sscanf(leitura_cha, "%02d[^,],%10s[^,]", codigo, cha_lido);
        if (codigo == cha_requerido)
        {
            encontrada = 1;
            printf("\nExcluindo aluno %s\n", leitura_cha);
        }
        else
        {
            fprintf(destino,"codigo:%d Nome do cha:%s\n", codigo, cha_lido);
        }
    }
    fclose(origem);
    fclose(destino);
    remove("cha.txt");
    rename("temp.txt", "cha.txt");
    if (!encontrada)
    {
        return 0;
    }
    return 1;


}

