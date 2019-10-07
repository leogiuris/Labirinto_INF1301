#include"MATRIZ.H"
#include<stdio.h>
#include<stdlib.h>


typedef enum{

	LAB_CondRetOK = 0,
	LAB_CondRetFaltouMemoria = 1,
	LAB_CondRetLabirintoNaoExiste = 2,
	LAB_CondRetNaoPossuiVizinho = 3,
	LAB_CondRetParede = 4
	
}LAB_tpCondRet ;

typedef struct tgLabirinto tpLabirinto;




LAB_tpCondRet LAB_CriarLabirinto(tpLabirinto ** pLab, int lin, int col);
LAB_tpCondRet LAB_ObterValor(tpLabirinto * pLab, char * valor);
LAB_tpCondRet LAB_ConstroiLeste (tpLabirinto *pLab);
LAB_tpCondRet LAB_ConstroiSul (tpLabirinto *pLab);
LAB_tpCondRet LAB_ConstroiNorte (tpLabirinto *pLab);
LAB_tpCondRet LAB_ConstroiOeste (tpLabirinto *pLab);
LAB_tpCondRet LAB_FinalizaConstrucao(tpLabirinto * pLab);
LAB_tpCondRet LAB_PercorreLeste(tpLabirinto * pLab);
LAB_tpCondRet LAB_PercorreSul(tpLabirinto * pLab);
LAB_tpCondRet LAB_PercorreOeste(tpLabirinto * pLab);
LAB_tpCondRet LAB_PercorreNorte(tpLabirinto * pLab);
LAB_tpCondRet LAB_DestruirLabirinto(tpLabirinto * pLab);