#include<stdio.h>
#include<stdlib.h>
#include"labirinto.h"
#include"conio.h"
#include<windows.h>


tpLabirinto * pLab;



int main()
{
	
	LAB_CriarLabirinto(&pLab,10,10);
	LAB_EscolheModo(2,pLab);
	printf("\nParabens! Voce chegou ao fim!\n");
	
	_getch();
	return 0;

}
