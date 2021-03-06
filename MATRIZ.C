/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Matriz
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   lgs   11/09/2019 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   rs   08/09/2019 Adaptacao de codigo para multiplas matrizes
*       1.00   dp   04/09/2019 In�cio do desenvolvimento
*
***************************************************************************/

#include	<malloc.h>
#include	<stdio.h>

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor do n� da Matriz
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
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
    /* Valor do n� */

} tpNoMatriz ;

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor da cabe�a de uma Matriz
*
*
*  $ED Descri��o do tipo
*     A cabe�a da Matriz � o ponto de acesso para uma determinada Matriz.
*     Por interm�dio da refer�ncia para o n� corrente e do ponteiro
*     pai pode-se navegar a Matriz sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a Matriz em forma de co-rotina.
*
***********************************************************************/

typedef struct tgMatriz {

	tpNoMatriz * pNoOrigem ;
               /* Ponteiro para a raiz da Matriz */

    tpNoMatriz * pNoCorr ;
               /* Ponteiro para o n� corrente da Matriz */

	int linhas;
	int colunas;

} tpMatriz ;

/*****  Dados encapsulados no m�dulo  *****/



/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

void ImprimeMat(tpMatriz *pMat);

void DestroiMatriz( tpNoMatriz * pMat );

void ExcluiNoLista(void * elem);

void ResetaMat(tpMatriz * pMat);

void MAT_RetornaOrigem(tpMatriz * pMat);

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: MAT Criar Matriz
*  ****/

MAT_tpCondRet MAT_CriarMatriz(tpMatriz ** pMat, int lin, int col, void * valorInicial)
{
	int i,j;
	tpNoMatriz ** mat;

	if(lin < 1 || col < 1)
		return MAT_CondRetTamanhoInvalido;
	
    if ( *pMat != NULL )
    {
		
        MAT_DestruirMatriz( *pMat ) ;
    } /* if */
	
	*pMat = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
    if ( pMat == NULL )
    {
		
		return MAT_CondRetFaltouMemoria ;
    } /* if */
	
	mat = (tpNoMatriz**)malloc(lin*sizeof(tpNoMatriz*));
	for(i=0; i<lin ;i++)
	{
		
		mat[i] = (tpNoMatriz*)malloc(col*sizeof(tpNoMatriz));
		for(j=0; j<col; j++)
		{
			
			mat[i][j].Valor = valorInicial;
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

}/* Fim fun��o: MAT Destruir Matriz */


/***************************************************************************
*
*  Fun��o: MAT Destruir Matriz
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
	
} /* Fim fun��o: MAT Destruir Matriz */


/***************************************************************************
*
*  Fun��o: MAT Destruir Matriz
*  ****/

MAT_tpCondRet MAT_InsereValor(tpMatriz*pMatriz, void * Valor)
{ 
	if(pMatriz==NULL)
	{

		return MAT_CondRetMatrizNaoExiste;
	}
	/*tratar falha no n� corrente*/
	if(pMatriz->pNoCorr==NULL)
	{
		return MAT_CondRetErroEstrutura;
	}
	pMatriz->pNoCorr->Valor = Valor;
	return MAT_CondRetOK;
}/* Fim fun��o: MAT Destruir Matriz */

/***************************************************************************
*
*  Fun��o: MAT Destruir Matriz
*  ****/

MAT_tpCondRet MAT_RetiraValor(tpMatriz**pMatriz)
{
  //tratar matriz nao existente
   if(*pMatriz==NULL)
	{

		return MAT_CondRetMatrizNaoExiste;
	}
  /*tratar falha no n� corrente*/
  if((*pMatriz)->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
 (* pMatriz)->pNoCorr->Valor = NULL;
  return MAT_CondRetOK;
}

/***************************************************************************
*
*  Fun��o: MAT Move Matriz
*  ****/

MAT_tpCondRet MAT_ObterValor(tpMatriz*pMatriz, void ** ValorCorrente)
{
  if(pMatriz==NULL)
	{

		return MAT_CondRetMatrizNaoExiste;
	}
  if(pMatriz->pNoOrigem==NULL)
  {
    return MAT_CondRetMatrizNaoExiste;
  }
  /*tratar falha no n� corrente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
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
  /*tratar falha no n� corrente*/
  if(pMatriz->pNoCorr==NULL)
  {
    return MAT_CondRetErroEstrutura;
  }
  /*tratar Leste n�o existente*/
  if(pMatriz->pNoCorr->pNoroeste ==NULL)
  {
    return MAT_CondRetNaoPossuiVizinho;
  }
  pMatriz->pNoCorr = pMatriz->pNoCorr->pNoroeste;
  return MAT_CondRetOK;
}

MAT_tpCondRet MoveCoord(tpMatriz *pMatriz, int x, int y)
{
	MAT_tpCondRet ret;

	if( x==0 && y==0 )
		return MAT_CondRetDirecaoInvalida;

	if(x == 0 ^ y == 0){
		if(x == 0)
			if(y>0)
				ret = MoveNorte(pMatriz);
			else
				ret = MoveSul(pMatriz);
		else
			if(x>0)
				ret = MoveLeste(pMatriz);
			else
				ret = MoveOeste(pMatriz);
	}
	else{
		if( x==y )
			if(x>0)
				ret = MoveNordeste(pMatriz);
			else
				ret = MoveSudoeste(pMatriz);
		else
			if(x>0)
				ret = MoveNoroeste(pMatriz);
			else
				ret = MoveSudeste(pMatriz);
	}

	return ret;
}


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

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
				str[i*col + j] = *(char*)pMat->pNoCorr->Valor;
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
/********** Fim do m�dulo de implementa��o: M�dulo Matriz **********/

////