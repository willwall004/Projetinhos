#include <stdio.h>
#include <stdlib.h> 

struct arvore
{
	int valor;
	struct arvore* esq;
	struct arvore* dir;
};
typedef struct arvore Arv;

Arv* arv_vazia()
{
	return NULL;
}

Arv* cria_abb(int valor)
{
	Arv* no = malloc(sizeof(Arv));
	no -> valor = valor;
	no -> esq = NULL;
	no -> dir = NULL;
	return no;
}

int maior(Arv* a) //função que retorna o maior valor da árvore
{
    if (a == arv_vazia())
    {
        return 0;
    }
	if (a -> dir)
        	return maior(a -> dir);
	else
		return a -> valor;
}

int busca_abb(Arv* a, int valor) // retorna 1 se encontrou e 0 se não
{
	if(a == arv_vazia())
	{
		return 0;
	}
	if (valor > a -> valor)
	{
		return busca_abb(a -> dir, valor);
	}
	else if (valor < a -> valor)
	{
		return busca_abb(a -> esq, valor);
	}
	return 1;
}

int confirma_abb(Arv* a, int valor) // função que retorna o valor se ele estiver na árvore
{
    if(a == arv_vazia())
	{
		return 0;
	}
    if (valor > a -> valor)
	{
		return confirma_abb(a -> dir, valor);
	}
	else if (valor < a -> valor)
	{
		return confirma_abb(a -> esq, valor);
	}
	return valor;
}
	
void insere_abb(Arv*a, int valor)
{
	if(a -> valor > valor)
	{
		if(a -> esq == arv_vazia())
		{
			a -> esq = cria_abb(valor);
		}
		else
		{
			insere_abb(a -> esq, valor);
		}
	}
	else
	{
		if(a -> dir == arv_vazia())
		{
			a -> dir = cria_abb(valor);
		}
		else
		{
			insere_abb(a -> dir, valor);
		}
	}
}

void imprime_arv(Arv* a)
{
	if(a == arv_vazia())
	{
		printf("NULL");
	}
	else
	{
		printf("(%d ", a -> valor);
		imprime_arv(a -> esq);
		printf(" ");
		imprime_arv(a -> dir);
		printf(")");
	}
}

int main() {
	int v=0, q=0, c, m, i, j;
	Arv* a;
	for (i=1; i>0; i++)
	{
	    scanf("%d", &c); printf("\n");
	    if (c==0)
	    {
	        break;
	    }
	    v=c;
	    if (q==0)
	    {
	        a=cria_abb(v);
	    }
	    insere_abb(a, v);
	    q++;
	}
	printf("A árvore contém %d elementos\n", q);
	m=maior(a);
	for (j=0; j <= m; j++)
	{
	    int g = confirma_abb(a, j+1);
	    if (g != 0)
	    {
	        printf("%d\n", g);
	    }
	}
	return 0;
}