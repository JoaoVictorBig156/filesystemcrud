#include "filesystemcrud_functions.c"
#include <assert.h>
void main()
{
    assert(criar_cha("hibisco", 1)==0)  ;
    assert(criar_cha("comomila", 2)==0) ;
    FILE *file;
    file = fopen("cha.txt", "r");
    assert(file != NULL);
    char *leitura = ler_cha(1);
    leitura[strcspn(leitura, "\r\n")] = 0;
    assert(strcmp(leitura, "codigo:01 ,Nome do cha:hibisco") == 0);
}
