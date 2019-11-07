#include"HUMANO.H"
#include<stdio.h>
#include<conio.h>



void HUM_Modifica(tpLabirinto * pLab)
{
	char c;
	printf("   Construa seu labirinto usando as teclas WASD.\n [ESPACO] - Caminho\n [p] - Parede\n [r] - Reiniciar Labirinto\n [f] - Final\n [q] - Voltar\n");
	c = _getch();

	if(c == 'd'){
		LAB_MoveLivre(pLab,1,0);
	}
	if(c == 'w'){
		LAB_MoveLivre(pLab,0,1);
	}
	if(c == 'a'){
		LAB_MoveLivre(pLab,-1,0);
	}
	if(c == 's'){
		LAB_MoveLivre(pLab,0,-1);
	}
	if(c == ' ' || c == 'p' || c == 'f' || c == 'r')
	{
		LAB_Constroi(pLab,c);
	}
	if(c == 'q'){
		LAB_RetornaInicio(pLab);
		ImprimeLabirinto(pLab);
		return;
	}
	ImprimeLabirinto(pLab);
	HUM_Modifica(pLab);
}

void HUM_ConstroiLabirinto(tpLabirinto * pLab)
{
	char c;
	printf("  Construa seu labirinto usando as teclas WASD.\n  Para finalizar pressione 'f'.\n  Caso queira reiniciar, pressione 'r'\n");
	c = _getch();

	if(c == 'd'){
		LAB_CavaLeste(pLab);
	}
	if(c == 'w'){
		LAB_CavaNorte(pLab);
	}
	if(c == 'a'){
		LAB_CavaOeste(pLab);
	}
	if(c == 's'){
		LAB_CavaSul(pLab);
	}
	if(c == 'r'){
		LAB_Constroi(pLab,c);
	}
	if(c == 'f'){
		LAB_FinalizaConstrucao(pLab);
		return;
	}

	ImprimeLabirinto(pLab);
	HUM_ConstroiLabirinto(pLab);
}

void HUM_PercorreLabirinto(tpLabirinto * pLab)
{
	char c;
	char * val = (char*)malloc(1);
	printf("  Percorra o labirinto usando as teclas WASD.\n  Tente chegar no final ('f').\n\n [q] - Sair\n [m] - Modificar\n");
	c = _getch();

	if(c == 'd'){
		LAB_IrCoord(pLab,1,0);
	}
	if(c == 'w'){
		LAB_IrCoord(pLab,0,1);
	}
	if(c == 'a'){
		LAB_IrCoord(pLab,-1,0);
	}
	if(c == 's'){
		LAB_IrCoord(pLab,0,-1);
	}

	if(c == 'm')
	{
		ImprimeLabirinto(pLab);
		HUM_Modifica(pLab);
	}

	if(c == 'q')
		return;

	LAB_ObterValor(pLab,val);
	if(*val == 'f'){
		printf("\n  Parabens! Voce chegou ao fim!\n\n  Aperte qualquer tecla para voltar ao menu.\n");
		_getch();
		return;
	}

	ImprimeLabirinto(pLab);
	HUM_PercorreLabirinto(pLab);
}

