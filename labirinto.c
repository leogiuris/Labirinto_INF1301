#include"labirinto.h"
#include "MATRIZ.H"
#include"HUMANO.H"
#include"RESOLVEDOR.H"

#define PAREDE	'@'
#define CAMINHO ' '
#define INICIO	'i'
#define	FIM		'f'
#define RASTRO	'.'

char * parede;
char * caminho;
char * inicio;
char * fim;
char * rastro;



typedef struct tgLabirinto{
	tpMatriz * mat;
	int lin;
	int col;
}tpLabirinto;


void Inicializa()
{
	parede = (char*)malloc(1);
	caminho = (char*)malloc(1);
	inicio = (char*)malloc(1);
	fim = (char*)malloc(1);
	rastro = (char*)malloc(1);

	*parede = PAREDE;
	*caminho = CAMINHO;
	*inicio = INICIO;
	*fim = FIM;
	*rastro = RASTRO;
	return;
}


void ImprimeLabirinto(tpLabirinto * pLab);

LAB_tpCondRet LAB_CriarLabirinto(tpLabirinto ** pLab, int linhas, int colunas)
{
	tpMatriz * pMat = NULL;
	MAT_tpCondRet ret;
	
	if(*pLab!=NULL) 
		LAB_DestruirLabirinto(*pLab);

	Inicializa();
	*pLab = (tpLabirinto *) malloc(sizeof(tpLabirinto));

	ret = MAT_CriarMatriz(&pMat,linhas,colunas,(void*)parede);

	(*pLab)->mat = pMat;
	(*pLab)->lin = linhas;
	(*pLab)->col = colunas;
	MAT_InsereValor((*pLab)->mat,(void*)inicio);
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

	//printf("\n>>[ VERIFIVA_VIZINHO ]");
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveCoord(pLab->mat,x,y) != MAT_CondRetOK){
		//printf("--PAREDE\n");
		return 0;
	}
	MAT_ObterValor(pLab->mat, &temp);
	*valor = *(char*)temp;
	MoveCoord(pLab->mat,-x,-y);

	if(*valor == CAMINHO || *valor == FIM)
	{
		//printf("--CAMINHO\n");
		return 1;
	}
	else
		{
		//printf("--PAREDE\n");
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
	
	*valor = *(char*)temp;


	return LAB_CondRetOK;
}


void LAB_RetornaInicio(tpLabirinto * pLab)
{
	MAT_RetornaOrigem(pLab->mat);
}


LAB_tpCondRet LAB_CavaLeste (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveLeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)caminho);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}


LAB_tpCondRet LAB_CavaSul (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveSul(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)caminho);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_CavaNorte (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveNorte(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)caminho);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

LAB_tpCondRet LAB_CavaOeste (tpLabirinto *pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	if(MoveOeste(pLab->mat) == MAT_CondRetNaoPossuiVizinho)
	{
		
		return LAB_CondRetNaoPossuiVizinho;
	}

	MAT_InsereValor(pLab->mat,(void*)caminho);
	
	ImprimeLabirinto(pLab);
	return LAB_CondRetOK;
}

void LAB_LimpaRastro(tpLabirinto * pLab)
{
	char * val;
	int i, j,cont = 0;
	int lin = pLab->lin;
	int col = pLab->col;
	for(i = 0; i < lin; i++)
	{
		LAB_RetornaInicio(pLab);
		while(cont < i)
		{
			MoveSul(pLab->mat);
			cont++;
		}
		cont = 0;

		for(j = 0; j < lin; j++)
		{
			LAB_ObterValor(pLab, val);

			if(*val == *rastro)
				MAT_InsereValor(pLab->mat,(void*)caminho);

			MoveLeste(pLab->mat);

		}
	}
	LAB_RetornaInicio(pLab);

}


void LAB_ReiniciaLabirinto(tpLabirinto * pLab)
{
	int i, j,cont = 0;
	int lin = pLab->lin;
	int col = pLab->col;
	for(i = 0; i < lin; i++)
	{
		LAB_RetornaInicio(pLab);
		while(cont < i)
		{
			MoveSul(pLab->mat);
			cont++;
		}
		cont = 0;

		for(j = 0; j < lin; j++)
		{
			MAT_InsereValor(pLab->mat, (void*)parede);

			MoveLeste(pLab->mat);

		}
	}
	LAB_RetornaInicio(pLab);

	MAT_InsereValor(pLab->mat, (void*)inicio);

}


void ImprimeLabirinto(tpLabirinto * pLab)
{
	char * str;
	int i,j,cont = 0;
	int lin = pLab->lin;
	int col = pLab->col;
	system("cls");
	str = ObtemMatrizString(pLab->mat);

	printf("\n\n           ===== LABIRINTO ======\n\n");
	printf("           %c",218);
	for(i=0; i<2*col+1; i++)
	{
		printf("%c",196);
	}
	printf("%c",191);

	for(i=0; i<lin; i++)
	{
		printf("\n");
		printf("           | ");
		for(j=0; j<col;j++)
		{
			printf("%c",str[i*col+j]);
			if(j< col-1)
				printf(" ");
		}
		printf(" |");
	}

	printf("\n           %c", 192);
	for(i=0; i<2*col+1; i++)
	{
		printf("%c",196);
	}
	printf("%c\n\n", 217);
}

void LAB_InsereRastro(tpLabirinto * pLab){
	MAT_InsereValor(pLab->mat,(void*)rastro);
}


void LAB_InsereCaminho(tpLabirinto * pLab){
	MAT_InsereValor(pLab->mat,(void*)caminho);
}



LAB_tpCondRet LAB_FinalizaConstrucao(tpLabirinto * pLab)
{
	//AE: Labirinto tem que existir
	if(pLab==NULL)
		return LAB_CondRetLabirintoNaoExiste;

	MAT_InsereValor(pLab->mat,(void*)fim);
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

	
	return LAB_CondRetOK;
}

void LAB_MoveLivre(tpLabirinto * pLab, int x, int y)
{
	MoveCoord(pLab->mat,x,y);
	ImprimeLabirinto(pLab);
}

void LAB_Constroi(tpLabirinto * pLab, char valor)
{
	if(valor == 'p')
		MAT_InsereValor(pLab->mat, (void*)parede);
	if(valor == ' ')
		MAT_InsereValor(pLab->mat, (void*)caminho);
	if(valor == 'f')
		MAT_InsereValor(pLab->mat, (void*)fim);
	if(valor == 'r')
		LAB_ReiniciaLabirinto(pLab);
}

void JogaHumano(tpLabirinto *pLab)
{
	HUM_PercorreLabirinto(pLab);
}

void LAB_Cava(tpLabirinto * pLab)
{
	HUM_ConstroiLabirinto(pLab);
}

void LAB_EscolheModo(char modo,tpLabirinto * pLab)
{
	if(modo == '1')
	{
		LAB_LimpaRastro(pLab);
		ImprimeLabirinto(pLab);
		HUM_PercorreLabirinto(pLab);
		
	}

	if(modo == '2')
	{
		LAB_LimpaRastro(pLab);
		ImprimeLabirinto(pLab);
		if(LAB_Resolver(pLab) == LAB_CondRetResolvido)
			printf("\nParabens! Voce chegou ao fim!\n");
		else
			printf("\nEste labirinto nao tem solucao!\n");
	}
	
	if(modo == 'm')
	{
		LAB_LimpaRastro(pLab);
		ImprimeLabirinto(pLab);
		HUM_Modifica(pLab);
		LAB_RetornaInicio(pLab);
		ImprimeLabirinto(pLab);
	}

	if(modo == 'r')
	{
		LAB_ReiniciaLabirinto(pLab);
		ImprimeLabirinto(pLab);
		LAB_Cava(pLab);
	}
	
}


LAB_tpCondRet LAB_Resolver(tpLabirinto * pLab)
{
	if(RES_ResolverLabirinto(pLab) == RES_CondRetResolvido)
		return LAB_CondRetResolvido;
	else
		return LAB_CondRetSemSolucao;
}


