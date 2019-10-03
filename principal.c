#include<stdio.h>
#include<stdlib.h>
#include"lab2.h"
#include"conio.h"
#include<windows.h>
tpLabirinto * pLab;



void ConstroiLabirinto(tpLabirinto * pLab)
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
	if(c=='f'){
		FinalizaConstrucao(pLab);
		return;
	}

	ConstroiLabirinto(pLab);
}

void PercorreLabirinto(tpLabirinto * pLab)
{
	char c;
	char * val = (char*)malloc(1);
	printf("Percorra o labirinto usando as teclas WASD.\nTente chegar no final ('f').\n");
	c = _getch();

	if(c == 'd'){
		LAB_PercorreLeste(pLab);
	}
	if(c == 'w'){
		LAB_PercorreNorte(pLab);
	}
	if(c == 'a'){
		LAB_PercorreOeste(pLab);
	}
	if(c == 's'){
		LAB_PercorreSul(pLab);
	}
	LAB_ObterValor(pLab,val);
	if(*val=='f'){
		return;
	}
	PercorreLabirinto(pLab);
}
	


int main()
{
	char * b = (char *)malloc(1);

	LAB_CriarLabirinto(&pLab,15,15);
	ConstroiLabirinto(pLab);
	PercorreLabirinto(pLab);
	printf("\nParabens! Voce chegou ao fim!\n");
	_getch();
	return 0;
}