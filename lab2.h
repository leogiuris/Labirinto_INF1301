#include"MATRIZ.H"
#include<stdio.h>
#include<stdlib.h>

typedef struct tgLabirinto tpLabirinto;

void criaLab(tpLabirinto ** pLab, int lin, int col);
void LAB_ObterValor(tpLabirinto * pLab, char * valor);
void ConstroiLeste (tpLabirinto *pLab);
void ConstroiSul (tpLabirinto *pLab);
void ConstroiNorte (tpLabirinto *pLab);
void ConstroiOeste (tpLabirinto *pLab);
void FinalizaConstrucao(tpLabirinto * pLab);
void PercorreLeste(tpLabirinto * pLab);
void PercorreSul(tpLabirinto * pLab);
void PercorreOeste(tpLabirinto * pLab);
void PercorreNorte(tpLabirinto * pLab);