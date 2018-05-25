#include <stdio.h>

struct aluno
{
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
};

int aprovado(struct aluno a)
{
    float media;
    media=((a.nota1 + a.nota2 + a.nota3)/3);
    if (media>=7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct aluno a;

    scanf("%99s%f%f%f", a.nome, &a.nota1, &a.nota2, &a.nota3);
    if(aprovado(a))
    {
        printf("O aluno %s foi aprovado!\n", a.nome);
    }
    else
    {
        printf("Sinto muito, mas o aluno %s foi reprovado! Até o ano que vem!\n", a.nome);
    }
    return 0;
}
