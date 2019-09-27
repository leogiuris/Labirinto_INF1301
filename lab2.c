#include"lab2.h"

#define PAREDE	'@'
#define CAMINHO ' '
#define INICIO	'i'
#define	FIM		'f'


typedef struct tgLabirinto{
	tpMatriz * mat;
	int lin;
	///numero de colunas
	int col;
}tpLabirinto;


void ImprimeLabirinto(tpLabirinto * pLab);

void criaLab(tpLabirinto ** pLab, int linhas, int colunas)
{
	tpMatriz * pMat = NULL;

	if(*pLab!=NULL) return;
	//printf("aaaaa\n");


	*pLab = (tpLabirinto *) malloc(sizeof(tpLabirinto));
	//printf("aaaaa\n");
	MAT_CriarMatriz(&pMat,linhas,colunas);
	//printf("aaaaa\n");
	(*pLab)->mat = pMat;
	(*pLab)->lin = linhas;
	(*pLab)->col = colunas;
	MAT_InsereValor((*pLab)->mat,(void*)INICIO);
	ImprimeLabirinto(*pLab);
	//printf("aaaaa\n");
	return;
}

void LAB_ObterValor(tpLabirinto * pLab, char * valor)
{
	void * temp;

	//printf("[Obtem Valor Labirinto]\n");
	ObterValor(pLab->mat, &temp);
	
	*valor = (char)temp;
	//printf("%c\n",*valor);

	return;
}

void RetornaInicio(tpLabirinto * pLab)
{
	MAT_RetornaOrigem(pLab->mat);
}


void ConstroiLeste (tpLabirinto *pLab)
{
	if(MoveLeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return;
}

void ConstroiSul (tpLabirinto *pLab)
{
	if(MoveSul(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return;
}

void ConstroiNorte (tpLabirinto *pLab)
{
	if(MoveNorte(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return;
}

void ConstroiOeste (tpLabirinto *pLab)
{
	if(MoveOeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return;
}

void ImprimeLabirinto(tpLabirinto * pLab)
{
	char * str;
	int i,j,cont = 0;
	int lin = pLab->lin;
	int col = pLab->col;
	system("cls");
	str = ObtemMatrizString(pLab->mat);
	//printf("%s\n",str);


	printf("  ");
	for(i=0; i<2*col-1; i++)
	{
		printf("_");
	}

	for(i=0; i<lin; i++)
	{
		printf("\n");
		printf(" |");
		for(j=0; j<col;j++)
		{
			printf("%c",str[i*col+j]);
			if(j< col-1)
				printf(" ");
		}
		printf("|");
	}

	printf("\n  ");
	for(i=0; i<2*col-1; i++)
	{
		printf("-");
	}
	printf("\n");
}


void FinalizaConstrucao(tpLabirinto * pLab)
{
	MAT_InsereValor(pLab->mat,(void*)FIM);
	RetornaInicio(pLab);
	ImprimeLabirinto(pLab);
}

void PercorreLeste(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);
	if(MoveLeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveOeste(pLab->mat);
		return;
	}
	ImprimeLabirinto(pLab);
	return;
}

void PercorreOeste(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);
	if(MoveOeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveLeste(pLab->mat);
		return;
	}
	ImprimeLabirinto(pLab);
	return;
}

void PercorreSul(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);
	if(MoveSul(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveNorte(pLab->mat);
		return;
	}
	ImprimeLabirinto(pLab);
	return;
}

void PercorreNorte(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);
	if(MoveNorte(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		printf("nao possui vizinho\n");
		return;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveSul(pLab->mat);
		return;
	}
	ImprimeLabirinto(pLab);
	return;
}

