#include<stdio.h>
#include<stdlib.h>
#include"labirinto.h"
#include"conio.h"
#include<windows.h>


tpLabirinto * pLab;



void Menu()
{
	char c;

	ImprimeLabirinto(pLab);
	printf("\n   MENU\n\n [1] Resolver Manual\n [2] Resolvedor Automatico\n [m] Modificar Labirinto\n [r] Reiniciar Labirinto\n [q] Sair\n\n");
	c = _getch();
	if(c == '1' || c == '2' || c == 'm' || c == 'r')
	{
		
		LAB_EscolheModo(c,pLab);
		Menu();
	}
	else
	{
		if(c == 'a' || c == 'w' || c == 'd' || c == 's')
			LAB_EscolheModo('1',pLab);

		if(c == 'q')
			return;

		Menu();
	}
}


int main()
{

	system("mode con: cols=50 lines=30 ");


	printf("\n\n           ===== LABIRINTO ======\n\n\n");
	printf("  Pressione qualquer tecla para comecar.\n\n");
	_getch();
	LAB_CriarLabirinto(&pLab,9,9);
	LAB_Cava(pLab);
	Menu();
	
	return 0;

}
