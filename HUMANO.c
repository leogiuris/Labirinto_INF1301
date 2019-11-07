#include"HUMANO.H"
#include<stdio.h>
#include<conio.h>



void HUM_Modifica(tpLabirinto * pLab)
{
	char c;
	printf("construa seu labirinto usando as teclas WASD.\n[c] - Caminho\n[p] - Parede\n[f] - Final\n[q] - Voltar\n");
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
	if(c == 'c' || c == 'p' || c == 'f')
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
	printf("construa seu labirinto usando as teclas WASD.\nPara finalizar digite 'f'.\n");
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
	printf("  Percorra o labirinto usando as teclas WASD.\nTente chegar no final ('f').\n\n[q] - Sair\n[m] - Modificar\n");
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
		printf("\nParabens! Voce chegou ao fim!\n");
		return;
	}

	ImprimeLabirinto(pLab);
	HUM_PercorreLabirinto(pLab);
}

