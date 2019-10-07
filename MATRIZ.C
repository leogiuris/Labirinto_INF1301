/***************************************************************************
*  $MCI Módulo de implementação: Módulo Matriz
*
*  Arquivo gerado:              Matriz.C
*  Letras identificadoras:      MAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Leonardo Santiago, Rafael Serpa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   lgs   11/09/2019 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   rs   08/09/2019 Adaptacao de codigo para multiplas matrizes
*       1.00   dp   04/09/2019 Início do desenvolvimento
*
***************************************************************************/

#include	<malloc.h>
#include	<stdio.h>

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor do nó da Matriz
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

typedef struct tgNoMatriz {

	struct tgNoMatriz * pNorte ; 
	struct tgNoMatriz * pNordeste ;
	struct tgNoMatriz * pLeste ;
	struct tgNoMatriz * pSudeste ;
	struct tgNoMatriz * pSul ;
	struct tgNoMatriz * pSudoeste ;
	struct tgNoMatriz * pOeste ;
	struct tgNoMatriz * pNoroeste ;

    void * Valor ;
    /* Valor do nó */

} tpNoMatriz ;

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor da cabeça de uma Matriz
*
*
*  $ED Descrição do tipo
*     A cabe‡a da Matriz é o ponto de acesso para uma determinada Matriz.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     pai pode-se navegar a Matriz sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a Matriz em forma de co-rotina.
*
***********************************************************************/

typedef struct tgMatriz {

	tpNoMatriz * pNoOrigem ;
               /* Ponteiro para a raiz da Matriz */

    tpNoMatriz * pNoCorr ;
               /* Ponteiro para o nó corrente da Matriz */

	int linhas;
	int colunas;

} tpMatriz ;

/*****  Dados encapsulados no módulo  *****/



/***** Protótipos das funções encapuladas no módulo *****/

void ImprimeMat(tpMatriz *pMat);

void DestroiMatriz( tpNoMatriz * pMat );

void ExcluiNoLista(void * elem);

void ResetaMat(tpMatriz * pMat);

void MAT_RetornaOrigem(tpMatriz * pMat);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: MAT Criar Matriz
*  ****/

MAT_tpCondRet MAT_CriarMatriz(tpMatriz ** pMat, int lin, int col)
{
	int i,j;
	tpNoMatriz ** mat;

	//printf("[Cria Matriz]\n");
	if(lin < 1 || col < 1)
		return MAT_CondRetTamanhoInvalido;
	//printf("b\n");
    if ( *pMat != NULL )
    {
		
        MAT_DestruirMatriz( *pMat ) ;
    } /* if */
	//printf("c\n");
	*pMat = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
    if ( pMat == NULL )
    {
		
		return MAT_CondRetFaltouMemoria ;
    } /* if */
	//printf("d\n");
	mat = (tpNoMatriz**)malloc(lin*sizeof(tpNoMatriz*));
	for(i=0; i<lin ;i++)
	{
		
		mat[i] = (tpNoMatriz*)malloc(col*sizeof(tpNoMatriz));
		for(j=0; j<col; j++)
		{
			
			mat[i][j].Valor = (void*)('@');
			mat[i][j].pNorte = NULL;
			mat[i][j].pNordeste = NULL;
			mat[i][j].pNoroeste = NULL;
			mat[i][j].pLeste = NULL;
			mat[i][j].pOeste = NULL;
			mat[i][j].pSudeste = NULL;
			mat[i][j].pSul = NULL;
			mat[i][j].pSudoeste = NULL;
		}
	}
	
	for(i=0; i<lin ;i++){
		for(j=0; j<col; j++){
			
			if(i>0)
			{
				
				mat[i][j].pNorte = &mat[i-1][j];
				if(j>0)
					mat[i][j].pNoroeste = &mat[i-1][j-1];
				if(j<col)
					mat[i][j].pNordeste = &mat[i-1][j+1];
			}
			if(i<lin-1)
			{
				mat[i][j].pSul = &mat[i+1][j];
				if(j>0)
					mat[i][j].pSudoeste = &mat[i+1][j-1];
				if(j<col)
					mat[i][j].pSudeste = &mat[i+1][j+1];
			}
			if(j>0)
			{
				mat[i][j].pOeste = &mat[i][j-1];
			}
			if(j<col-1)
			{
				mat[i][j].pLeste = &mat[i][j+1];
			}
		}// end for j
	}// end for i

	
    (*pMat)->pNoOrigem = &mat[0][0] ;
	(*pMat)->pNoCorr = &mat[0][0];
	(*pMat)->linhas = lin;
	(*pMat)->colunas = col;

    return MAT_CondRetOK ;

}/* Fim função: MAT Destruir Matriz */


/***************************************************************************
*
*  Função: MAT Destruir Matriz
*  ****/

void MAT_DestruirMatriz( tpMatriz * pMat )
{	
	
	if(pMat!=NULL)
	{
		
		int i,lin = pMat->linhas;

		MAT_RetornaOrigem(pMat);

		while(lin>1)
		{	
			
			for(i=lin; i>1; i--)
			{
				
				  MoveSul(pMat);
			}
			
			DestroiMatriz(pMat->pNoCorr);
			
			MAT_RetornaOrigem(pMat);
			lin--;
		}
	
		DestroiMatriz(pMat->pNoCorr);
		
		
		pMat=NULL;
		free(pMat);
		
	}
	
} /* Fim função: MAT Destruir Matriz */


/***************************************************************************
*
*  Função: MAT Destruir Matriz
*  ****/

MAT_tpCondRet MAT_InsereValor(tpMatriz*pMatriz, void * Valor)
{ 
	if(pMatriz==NULL)
	{

		return MAT_CondRetMatrizNaoExiste;
	}
	/*tratar falha no nó corrente*/
	if(pMatriz->pNoCorr==NULL)
	{
		return MAT_CondRetErroEstrutura;
	}
	pMatriz->pNoCorr->Valor = Valor;
	return MAT_CondRetOK;
}/* Fim função: MAT Destruir Matriz */

/***************************************************************************
*
*  Função: MAT Destruir Matriz
*  ****/

MAT_tpCondRet MAT_RetiraValor(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz==NULL)
	{

		return MAT_CondRetMatrizNaoExiste;
	}
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  pMatriz->pNoCorr->Valor = NULL;
  return MAT_CondRetOK;
}

/***************************************************************************
*
*  Função: MAT Move Matriz
*  ****/

MAT_tpCondRet ObterValor(tpMatriz*pMatriz, void ** ValorCorrente)
{
  if(pMatriz==NULL)
	{

		return MAT_CondRetMatrizNaoExiste;
	}
  if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }

  *ValorCorrente = pMatriz->pNoCorr->Valor;
  return MAT_CondRetOK;
}



MAT_tpCondRet MoveLeste(tpMatriz*pMatriz)
{

	 if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pLeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pLeste;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveOeste(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pOeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pOeste;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveNorte(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pNorte ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pNorte;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveSul(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pSul ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pSul;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveSudeste(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pSudeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pSudeste;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveSudoeste(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pSudoeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pSudoeste;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveNordeste(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pNordeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pNordeste;
  return MAT_CondRetOK;
}
MAT_tpCondRet MoveNoroeste(tpMatriz*pMatriz)
{
  //tratar matriz nao existente
   if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no nó corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste não existente*/
  if(pMatriz->pNoCorr->pNoroeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pNoroeste;
  return MAT_CondRetOK;
}



/*****  Código das funções encapsuladas no módulo  *****/

void MAT_RetornaOrigem(tpMatriz * pMat)
{
	pMat->pNoCorr = pMat->pNoOrigem;
}


void ResetaMat(tpMatriz * pMat)
{
	int i,j,cont = 0;
	int lin = pMat->linhas;
	int col = pMat->colunas;

	for(i=0; i<lin; i++)
	{
		
		MAT_RetornaOrigem(pMat);
		while(cont!=i)
		{
			  MoveSul(pMat);
			cont++;
		}cont = 0;

		for(j=0; j<col; j++)
		{
			pMat->pNoCorr->Valor = (void*)(219);
			if(j<col-1)
				 MoveLeste(pMat);
		}
	}

}


char * ObtemMatrizString(tpMatriz * pMat)
{
	char * str;
	int i,j,cont = 0;
	int lin = pMat->linhas;
	int col = pMat->colunas;
	tpNoMatriz * temp = pMat->pNoCorr;
	str = (char*)malloc(col*lin);
	
	
	for(i=0; i<lin; i++)
	{
		MAT_RetornaOrigem(pMat);
		while(cont!=i)
		{
			MoveSul(pMat);
			cont++;
		}cont = 0;

		for(j=0; j<col; j++)
		{
			if(pMat->pNoCorr == temp)
			{
				str[i*col + j] = 'o';
			}
			else
			{
				str[i*col + j] = (char)pMat->pNoCorr->Valor;;
			}
			if(j < col-1)
				 MoveLeste(pMat);
		}
		
	}
	pMat->pNoCorr = temp;
	return str;
}


void ImprimeMat(tpMatriz *pMat)
{
	int i,j,cont = 0;
	int lin = pMat->linhas;
	int col = pMat->colunas;
	tpNoMatriz * temp = pMat->pNoCorr;
	
	for(i=0; i<lin; i++)
	{
		printf("\n");
		MAT_RetornaOrigem(pMat);
		while(cont!=i)
		{
			  MoveSul(pMat);
			cont++;
		}cont = 0;

		for(j=0; j<col; j++)
		{
			if(pMat->pNoCorr == temp)
				printf("o ");
			else
				printf("%c ",(char)pMat->pNoCorr->Valor);
			if(j < col-1)
				 MoveLeste(pMat);
		}
		
	}
	pMat->pNoCorr = temp;
	printf("\n");
}


void DestroiMatriz(tpNoMatriz * pMat )
{
	
	free(pMat);	
}
/********** Fim do módulo de implementação: Módulo Matriz **********/

////