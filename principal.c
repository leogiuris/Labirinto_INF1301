#include<stdio.h>
#include<stdlib.h>
#include"labirinto.h"
#include"conio.h"
#include<windows.h>


tpLabirinto * pLab;




void Menu()
{
	char c;
	printf("\n[1] Resolver Manual\n[2] Resolvedor Automatico\n[m] Modificar Labirinto\n[q] Sair\n\n");
	c = _getch();
	if(c == '1' || c == '2' || c == 'm')
	{
		
		LAB_EscolheModo(c,pLab);
		Menu();
	}
	else
	{
		if(c == 'q')
			return;

		printf("Comando Invalido\n");
		Menu();
	}
}


int main()
{

	printf("\n\n===== LABIRINTO ======\n\n\n");
	printf("Pressione qualquer tecla para comecar.\n\n");
	_getch();
	LAB_CriarLabirinto(&pLab,9,9);
	LAB_Cava(pLab);
	Menu();
	
	return 0;

}
