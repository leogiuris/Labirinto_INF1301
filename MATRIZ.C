/***************************************************************************
*  $MCI Módulo de implementação: Módulo árvore
*
*  Arquivo gerado:              ARVORE.C
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
***************************************************************************/

#include	<malloc.h>
#include	<stdio.h>

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do nó da árvore
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
*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
*
*
*  $ED Descrição do tipo
*     A cabe‡a da árvore é o ponto de acesso para uma determinada árvore.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     pai pode-se navegar a árvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a árvore em forma de co-rotina.
*
***********************************************************************/

typedef struct tgMatriz {

	tpNoMatriz * pNoOrigem ;
               /* Ponteiro para a raiz da árvore */

    tpNoMatriz * pNoCorr ;
               /* Ponteiro para o nó corrente da árvore */

	int tamanho;

} tpMatriz ;

/*****  Dados encapsulados no módulo  *****/



/***** Protótipos das funções encapuladas no módulo *****/

void ImprimeMat(tpMatriz *pMat);

void DestroiMatriz( tpNoMatriz * pMat );

void ExcluiNoLista(void * elem);

void ResetaMat(tpMatriz * pMat);

void RetornaOrigem(tpMatriz * pMat);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar árvore
*  ****/

MAT_tpCondRet MAT_CriarMatriz(tpMatriz **pMat, int tam)
{
	int i,j;
	tpNoMatriz ** mat;
	//printf("[CriarMatriz]\n");  

	if(tam<1)
		return MAT_CondRetTamanhoInvalido;

    if ( *pMat != NULL )
    {
		//printf("\nah nao\n");
        MAT_DestruirMatriz( *pMat ) ;
    } /* if */
	//printf("aham\n");
	*pMat = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
    if ( pMat == NULL )
    {
		
		return MAT_CondRetFaltouMemoria ;
    } /* if */
	//printf("sei...\n");
	mat = (tpNoMatriz**)malloc(tam*sizeof(tpNoMatriz*));
	for(i=0; i<tam ;i++)
	{
		//printf("i\n");
		mat[i] = (tpNoMatriz*)malloc(tam*sizeof(tpNoMatriz));
		for(j=0; j<tam; j++)
		{
			//printf("j\n");
			mat[i][j].Valor = (void*)('a'+i*tam + j);
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

	for(i=0; i<tam ;i++){
		for(j=0; j<tam; j++){
			mat[i][j].Valor = (void*)('a' +(i*tam) + j);
			if(i>0)
			{
				
				mat[i][j].pNorte = &mat[i-1][j];
				if(j>0)
					mat[i][j].pNoroeste = &mat[i-1][j-1];
				if(j<tam)
					mat[i][j].pNordeste = &mat[i-1][j+1];
			}
			if(i<tam-1)
			{
				mat[i][j].pSul = &mat[i+1][j];
				if(j>0)
					mat[i][j].pSudoeste = &mat[i+1][j-1];
				if(j<tam)
					mat[i][j].pSudeste = &mat[i+1][j+1];
			}
			if(j>0)
			{
				mat[i][j].pOeste = &mat[i][j-1];
			}
			if(j<tam-1)
			{
				mat[i][j].pLeste = &mat[i][j+1];
			}
		}// end for j
	}// end for i

	
    (*pMat)->pNoOrigem = &mat[0][0] ;
	(*pMat)->pNoCorr = &mat[0][0];
	(*pMat)->tamanho = tam;
	
	//printf("krl mano...\n");
	//ImprimeMat(*pMat);
    return MAT_CondRetOK ;

}/* Fim função: ARV Destruir árvore */


/***************************************************************************
*
*  Função: ARV Destruir árvore
*  ****/

void MAT_DestruirMatriz( tpMatriz * pMat )
{	
	if(pMat!=NULL){
		int fil = pMat->tamanho;
		int i = fil;
		RetornaOrigem(pMat);
		//printf("\n[DestroiMatriz]\n"); 
		while(fil>1)
		{
		
			for(i=fil;i>0;i--){
				//printf("i");
				  MoveSul(pMat);
			}
			//printf("\naaaaaa\n");
			DestroiMatriz(pMat->pNoCorr);
			//printf("opa\n");
			RetornaOrigem(pMat);
			fil--;
		}
		//printf("foi?..\n");
		DestroiMatriz(pMat->pNoCorr);
		//printf("ae porra\n");

		pMat=NULL;
		free(pMat);
	}
} /* Fim função: ARV Destruir árvore */


/***************************************************************************
*
*  Função: ARV Destruir árvore
*  ****/

MAT_tpCondRet MAT_InsereValor(tpMatriz*pMatriz, void * Valor)
{ 
  //tratar matriz nao existente
	//printf("aaaaaaa\n");
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
}/* Fim função: ARV Destruir árvore */

/***************************************************************************
*
*  Função: ARV Destruir árvore
*  ****/

MAT_tpCondRet RetiraMatriz(tpMatriz*pMatriz)
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
  pMatriz->pNoCorr->Valor = NULL;
  return MAT_CondRetOK;
}

/***************************************************************************
*
*  Função: ARV Move árvore
*  ****/

MAT_tpCondRet ObterValor(tpMatriz*pMatriz, void *ValorCorrente)
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
  ValorCorrente = pMatriz->pNoCorr->Valor;
  return MAT_CondRetOK;
}



MAT_tpCondRet MoveLeste(tpMatriz*pMatriz)
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

void RetornaOrigem(tpMatriz * pMat)
{
	pMat->pNoCorr = pMat->pNoOrigem;
}

void ResetaMat(tpMatriz * pMat)
{
	int i,j,cont = 0;
	int tam = pMat->tamanho;
	for(i=0; i<tam; i++)
	{
		
		RetornaOrigem(pMat);
		while(cont!=i)
		{
			  MoveSul(pMat);
			cont++;
		}cont = 0;

		for(j=0; j<tam; j++)
		{
			pMat->pNoCorr->Valor = (void*)('a'+i*tam + j);
			if(j<tam-1)
				 MoveLeste(pMat);
		}
	}

}

void ImprimeMat(tpMatriz *pMat)
{
	int i,j,cont = 0;
	int tam = pMat->tamanho;
	
	//printf("\n[ImprimeMatriz]\n"); 
	for(i=0; i<tam; i++)
	{
		printf("\n");
		RetornaOrigem(pMat);
		while(cont!=i)
		{
			  MoveSul(pMat);
			cont++;
		}cont = 0;

		for(j=0; j<tam; j++)
		{
			
			printf("%c	",(char)pMat->pNoCorr->Valor);
			if(j<tam-1)
				 MoveLeste(pMat);
		}
	}
	ResetaMat(pMat);
	printf("\n");
}

void DestroiMatriz(tpNoMatriz * pMat )
{
	free(pMat);	
}
/********** Fim do módulo de implementação: Módulo árvore **********/

////