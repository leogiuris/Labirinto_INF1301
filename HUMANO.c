#include"HUMANO.H"
#include<stdio.h>
#include<conio.h>

void HUM_ConstroiLabirinto(tpLabirinto * pLab)
{
	char c;
	printf("construa seu labirinto usando as teclas WASD.\nPara finalizar digite 'f'.\n");
	c = _getch();

	if(c == 'd'){
		LAB_ConstroiLeste(pLab);
	}
	if(c == 'w'){
		LAB_ConstroiNorte(pLab);
	}
	if(c == 'a'){
		LAB_ConstroiOeste(pLab);
	}
	if(c == 's'){
		LAB_ConstroiSul(pLab);
	}
	if(c == 'f'){
		LAB_FinalizaConstrucao(pLab);
		return;
	}

	HUM_ConstroiLabirinto(pLab);
}

void HUM_PercorreLabirinto(tpLabirinto * pLab)
{
	char c;
	char * val = (char*)malloc(1);
	printf("Percorra o labirinto usando as teclas WASD.\nTente chegar no final ('f').\n");
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
	LAB_ObterValor(pLab,val);
	if(*val == 'f'){
		return;
	}
	HUM_PercorreLabirinto(pLab);
}

