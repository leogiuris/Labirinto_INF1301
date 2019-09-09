#include	<malloc.h>
#include	<stdio.h>


#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN



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

typedef struct tgMatriz {

	tpNoMatriz * pNoOrigem ;
               /* Ponteiro para a raiz da árvore */

    tpNoMatriz * pNoCorr ;
               /* Ponteiro para o nó corrente da árvore */

	int fileiras;
	int colunas;

} tpMatriz ;

/////////////
void ImprimeMat( tpMatriz * pMat);

void DestroiMatriz( tpNoMatriz * pMat );

void ExcluiNoLista(void * elem);

void ResetaMat(tpMatriz * pMat);

void ApagaNo(tpMatriz * pMat);

void ResetaCorr(tpMatriz * pMat);
///////////

MAT_tpCondRet MAT_CriarMatriz(tpMatriz **pMat, int fil,int col)
{
	int i,j;
	tpNoMatriz ** mat;
	printf("\n[CriarMatriz]\n");  
    if ( *pMat != NULL )
    {
		printf("\nah nao\n");
        MAT_DestruirMatriz( *pMat ) ;
    } /* if */
	printf("aham\n");
	*pMat = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
    if ( pMat == NULL )
    {
		
		return MAT_CondRetFaltouMemoria ;
    } /* if */
	printf("sei...\n");
	mat = (tpNoMatriz**)malloc(fil*sizeof(tpNoMatriz*));
	for(i=0; i<fil ;i++)
	{
		printf("i\n");
		mat[i] = (tpNoMatriz*)malloc(col*sizeof(tpNoMatriz));
		for(j=0; j<col; j++)
		{
			printf("j\n");
			mat[i][j].Valor = (void*)('a'+i*col + j);
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

	for(i=0; i<fil ;i++){
		for(j=0; j<col; j++){
			mat[i][j].Valor = (void*)('a' +(i*col) + j);
			if(i>0)
			{
				
				mat[i][j].pNorte = &mat[i-1][j];
				if(j>0)
					mat[i][j].pNoroeste = &mat[i-1][j-1];
				if(j<col)
					mat[i][j].pNordeste = &mat[i-1][j+1];
			}
			if(i<fil-1)
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
	(*pMat)->fileiras = fil;
	(*pMat)->colunas = col;
	

	//ImprimeMat(*pMat);
    return MAT_CondRetOK ;

}/* Fim função: ARV Destruir árvore */

void MAT_DestruirMatriz( tpMatriz * pMat )
{	
	
	int fil = pMat->fileiras;
	int i = fil,j;
	pMat->pNoCorr = pMat->pNoOrigem;
	printf("\n[DestroiMatriz]\n"); 
	while(fil>1)
	{
		for(i=fil;i>0;i--){
			pMat->pNoCorr = pMat->pNoCorr->pSul;
		}
		DestroiMatriz(pMat->pNoCorr);
		pMat->pNoCorr = pMat->pNoOrigem;
		fil--;
	}
	DestroiMatriz(pMat->pNoCorr);
	

	free(pMat);
} /* Fim função: ARV Destruir árvore */



void DestroiMatriz(tpNoMatriz * pMat )
{
	int i,cont = 0;
	printf("la vai...");
	free(pMat);
	
	printf("foi krl\n");
	
}


void ResetaMat(tpMatriz * pMat)
{
	int i,j,cont = 0;
	int fil = pMat->fileiras;
	int col = pMat->colunas;
	for(i=0; i<fil; i++)
	{
		printf("\n");
		pMat->pNoCorr = pMat->pNoOrigem;
		while(cont!=i)
		{
			pMat->pNoCorr = pMat->pNoCorr->pSul;
			cont++;
		}cont = 0;

		for(j=0; j<col; j++)
		{
			pMat->pNoCorr->Valor = (void*)('a'+i*col + j);
			if(j<col-1)
				pMat->pNoCorr = pMat->pNoCorr->pLeste;
		}
	}

}

void ImprimeMat(tpMatriz *pMat)
{
	int i,j,cont = 0;
	int fil = pMat->fileiras;
	int col = pMat->colunas;
	printf("\n[ImprimeMatriz]\n"); 
	for(i=0; i<fil; i++)
	{
		printf("\n");
		pMat->pNoCorr = pMat->pNoOrigem;
		while(cont!=i)
		{
			pMat->pNoCorr = pMat->pNoCorr->pSul;
			cont++;
		}cont = 0;

		for(j=0; j<col; j++)
		{
			
			printf("%c	",(char)pMat->pNoCorr->Valor);
			if(j<col-1)
				pMat->pNoCorr = pMat->pNoCorr->pLeste;
		}
	}
	ResetaMat(pMat);
	printf("\n");
}


void ApagaNo(tpMatriz * pMat)
{
	pMat->pNoCorr->Valor = NULL;
	pMat->pNoCorr->pNorte = NULL;
	pMat->pNoCorr->pNordeste = NULL;
	pMat->pNoCorr->pNoroeste = NULL;
	pMat->pNoCorr->pLeste = NULL;
	pMat->pNoCorr->pOeste = NULL;
	pMat->pNoCorr->pSudeste = NULL;
	pMat->pNoCorr->pSul = NULL;
	pMat->pNoCorr->pSudoeste = NULL;
}

void ResetaCorr(tpMatriz * pMat)
{
	pMat->pNoCorr = pMat->pNoOrigem;
	return;
}





MAT_tpCondRet InsereMatriz(tpMatriz*pMatriz, void * Valor)
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
  pMatriz->pNoCorr->Valor = Valor;
  return MAT_CondRetOK;
}
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



