#include<stdio.h>
#include<stdlib.h>
#include"labirinto.h"
#include"conio.h"
#include<windows.h>
#include"LEA.H"

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
	if(c == 'f'){
		LAB_FinalizaConstrucao(pLab);
		return;
	}

	ConstroiLabirinto(pLab);
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
	


int main()
{
	
	LAB_CriarLabirinto(&pLab,5,5);
	ConstroiLabirinto(pLab);
	//HUM_PercorreLabirinto(pLab);
	LAB_Resolver(pLab);
	printf("aaaaaaaa\n");
	
	
	//LAB_DestruirLabirinto(pLab);
	printf("bbb\n");
	printf("\nParabens! Voce chegou ao fim!\n");
	
	_getch();
	return 0;

}

