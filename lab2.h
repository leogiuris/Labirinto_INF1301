#include"MATRIZ.H"
#include<stdio.h>
#include<stdlib.h>


typedef enum{

	LAB_CondRetOK = 0,
	LAB_CondRetFaltouMemoria = 1,
	LAB_CondRetLabirintoNaoExiste = 2
	
}LAB_tpCondRet ;

typedef struct tgLabirinto tpLabirinto;




LAB_tpCondRet LAB_CriarLabirinto(tpLabirinto ** pLab, int lin, int col);
void LAB_ObterValor(tpLabirinto * pLab, char * valor);
void LAB_ConstroiLeste (tpLabirinto *pLab);
void LAB_ConstroiSul (tpLabirinto *pLab);
void LAB_ConstroiNorte (tpLabirinto *pLab);
void LAB_ConstroiOeste (tpLabirinto *pLab);
void FinalizaConstrucao(tpLabirinto * pLab);
void LAB_PercorreLeste(tpLabirinto * pLab);
void LAB_PercorreSul(tpLabirinto * pLab);
void LAB_PercorreOeste(tpLabirinto * pLab);
void LAB_PercorreNorte(tpLabirinto * pLab);
LAB_tpCondRet LAB_DestruirLabirinto(tpLabirinto * pLab);