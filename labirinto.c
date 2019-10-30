#include"labirinto.h"
#include "MATRIZ.H"
#include"HUMANO.H"
#include"RESOLVEDOR.H"

#define PAREDE	'@'
#define CAMINHO ' '
#define INICIO	'i'
#define	FIM		'f'


typedef struct tgLabirinto{
	tpMatriz * mat;
	int lin;
	int col;
}tpLabirinto;



void ImprimeLabirinto(tpLabirinto * pLab);

LAB_tpCondRet LAB_CriarLabirinto(tpLabirinto ** pLab, int linhas, int colunas)
{
	tpMatriz * pMat = NULL;
	MAT_tpCondRet ret;

	if(*pLab!=NULL) 
		LAB_DestruirLabirinto(*pLab);

	*pLab = (tpLabirinto *) malloc(sizeof(tpLabirinto));

	ret = MAT_CriarMatriz(&pMat,linhas,colunas);

	(*pLab)->mat = pMat;
	(*pLab)->lin = linhas;
	(*pLab)->col = colunas;
	MAT_InsereValor((*pLab)->mat,(void*)INICIO);
	ImprimeLabirinto(*pLab);

	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_DestruirLabirinto(tpLabirinto * pLab)
{
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;
	
	MAT_DestruirMatriz(pLab->mat);
	free(pLab);
	return LAB_CondRetOK;
}

int LAB_VerificarVizinho(tpLabirinto * pLab, int x, int y)
{
	MAT_tpCondRet ret;
	void * temp;
	char * valor = (char*)malloc(1);

	printf("\n>>[ VERIFIVA_VIZINHO ]");
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveCoord(pLab->mat,x,y) != MAT_CondRetOK){
		printf("--PAREDE\n");
		return 0;
	}
	MAT_ObterValor(pLab->mat, &temp);
	*valor = (char)temp;
	MoveCoord(pLab->mat,-x,-y);

	if(*valor == CAMINHO || *valor == FIM)
	{
		printf("--CAMINHO\n");
		return 1;
	}
	else
		{
		printf("--PAREDE\n");
		return 0;
	}

}

LAB_tpCondRet LAB_ObterValor(tpLabirinto * pLab, char * valor)
{
	//AE: Labirinto tem que existir
	

	void * temp;

	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	MAT_ObterValor(pLab->mat, &temp);
	
	*valor = (char)temp;


	return LAB_CondRetOK;
}

void LAB_RetornaInicio(tpLabirinto * pLab)
{
	MAT_RetornaOrigem(pLab->mat);
}


LAB_tpCondRet LAB_ConstroiLeste (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveLeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_ConstroiSul (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveSul(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_ConstroiNorte (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveNorte(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_ConstroiOeste (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveOeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)CAMINHO);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

void ImprimeLabirinto(tpLabirinto * pLab)
{
	char * str;
	int i,j,cont = 0;
	int lin = pLab->lin;
	int col = pLab->col;
	system("cls");
	str = ObtemMatrizString(pLab->mat);


	printf(" %c",218);
	for(i=0; i<2*col+1; i++)
	{
		printf("%c",196);
	}
	printf("%c",191);

	for(i=0; i<lin; i++)
	{
		printf("\n");
		printf(" | ");
		for(j=0; j<col;j++)
		{
			printf("%c",str[i*col+j]);
			if(j< col-1)
				printf(" ");
		}
		printf(" |");
	}

	printf("\n %c", 192);
	for(i=0; i<2*col+1; i++)
	{
		printf("%c",196);
	}
	printf("%c\n", 217);
}


LAB_tpCondRet LAB_FinalizaConstrucao(tpLabirinto * pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	MAT_InsereValor(pLab->mat,(void*)FIM);
	LAB_RetornaInicio(pLab);
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_IrLeste(tpLabirinto * pLab)
{

	char * ret = (char*)malloc(1);

	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveLeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveOeste(pLab->mat);
		return LAB_CondRetParede;
	}

	ImprimeLabirinto(pLab);
	if(*ret== FIM)
		return LAB_CondRetResolvido;

	
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_IrOeste(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);

	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveOeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveLeste(pLab->mat);
		return LAB_CondRetParede;
	}

	ImprimeLabirinto(pLab);
	if(*ret== FIM)
		return LAB_CondRetResolvido;

	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_IrSul(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);

	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveSul(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveNorte(pLab->mat);
		return LAB_CondRetParede;
	}

	ImprimeLabirinto(pLab);

	if(*ret== FIM)
		return LAB_CondRetResolvido;

	
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_IrNorte(tpLabirinto * pLab)
{
	char * ret = (char*)malloc(1);

	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveNorte(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}
	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveSul(pLab->mat);
		return LAB_CondRetParede;
	}

	ImprimeLabirinto(pLab);
	if(*ret== FIM)
		return LAB_CondRetResolvido;

	
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_IrCoord(tpLabirinto * pLab, int x, int y)
{
	char * ret = (char*)malloc(1);

	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;



	if(x == 0 && y == 0 ) return LAB_CondRetParede;



	if(MoveCoord(pLab->mat,x,y) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}



	LAB_ObterValor(pLab,ret);
	if(*ret == PAREDE)
	{
		MoveCoord(pLab->mat,-x,-y);
		return LAB_CondRetParede;
	}

	ImprimeLabirinto(pLab);

	if(*ret== FIM)
		return LAB_CondRetResolvido;

	printf("andou\n");
	return LAB_CondRetOK;
}

void LAB_EscolheModo(int modo,tpLabirinto * pLab)
{
	
	if(modo == 1){
		HUM_ConstroiLabirinto(pLab);
		HUM_PercorreLabirinto(pLab);
	}
	if(modo == 2){
		HUM_ConstroiLabirinto(pLab);
		LAB_Resolver(pLab);
	}
}

void LAB_TestarResolvedor(){
	RES_Teste();
}

void LAB_Resolver(tpLabirinto * pLab)
{
	RES_tpCondRet ret;
	ret = RES_ResolverLabirinto(pLab);
	if(ret == RES_CondRetResolvido)
		printf("foi\n");
	else
		printf("nao foi\n");
}


void JogaHumano(tpLabirinto *pLab)
{
	HUM_PercorreLabirinto(pLab);
}
