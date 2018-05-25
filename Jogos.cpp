#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char p;
	inicio:
	printf("Você quer jogar? Responda \"s\" para confirmar ou \"n\" para negar\n"); 
	p = getch();
	if (p == 's')
	{
		char j;
		printf("\nQual jogo queres jogar?\n\n1. Contagem de letra\n2. Cálculo de média do período\n3. Produto, razão e resto\n");
		j = getch();
		if(j=='1')
		{
		
			char letra, palavra[100];
			int i, count = 0;
			
			printf("\nDigite uma palavra: ");
			fflush(stdin);
			scanf("%s", &palavra);
			printf("\n\nAgora, a letra para eu contar: ");
			fflush(stdin);
			letra = getch();
			
			for(i=0; palavra[i]!='\0'; i++)
			{
				if (palavra[i] == letra)
					count++;
			}
			printf("\n\nA palavra %s tem %d letra(s) %c\n", palavra, count, letra);
		}
		else if(j=='2')
		{
			float av1, av2, av3, media;
	
			printf("Quanto tiraste, respectivamente, nas av1, av2, av3?\n");
			fflush(stdin);
			scanf("%f%f%f", &av1, &av2, &av3);
			float t1 = 10 - av1, t2 = 10 - av2, t3 = 10 - av3;
			
			if((t1<t2 && t2<t3) || (t2<t1 && t1<t3))
			{
				int t = 3;
				media = (av1+av2)/2;
				printf("tua média é %.1f e a nota discartada foi a av%d\n", media, t);
			}
			else if((t1<t3 && t3<t2) || (t3<t1 && t1<t2))
			{
				int t = 2;
				media = (av1+av3)/2;
				printf("Tua média é %.1f e a nota discartada foi a av%d\n", media, t);
			}
			else if((t2<t3 && t3<t1) || (t3<t2 && t2<t1))
			{
				int t = 1;
				media = (av3+av2)/2;
				printf("Tua média é %.1f e a nota discartada foi a av%d\n", media, t);
			}
			
			if (media > 7.0)
			{
				printf("Aprovado\n");
			}
			else if (media = 7.0)
			{
				printf("Aprovado, na média\n");
			}
			else
			{
				printf("Reprovado\n");
			}
		}
		else if (j=='3')
		{
			int t;
			for(t=10; t!=2; t++)
			{
				comeco:
				int n1, n2, c1, c2;
				printf("\nDigite dois números inteiros e diferentes de zero aí:\n");
				fflush(stdin);
				scanf("%d%d", &n1, &n2);
				
				if (n1==0 || n2==0)
				{
					printf("\nAh, 0 não! Assim não dá. Vamos de novo\n");
					goto comeco;
				}
				
				c1 = n1/n2;
				c2 = n2/n1;
				printf("O produto dos números é %d\nA razão n1/n2 é %d, com resto %d\nA razão n2/n1 é %d, com resto %d\n", n1*n2, c1, n2/n1, c2);
				
				printf("Queres continuar? (digite 's' caso afirmativo)");
				p = getch();
				if(p != 's')
				{
					break;
				}
			}
		}
		goto inicio;
	}
	else
	{
		printf("\nAté a próxima ;)");
	}
}

