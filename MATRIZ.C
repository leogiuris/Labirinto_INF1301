///***************************************************************************
//*  $MCI Módulo de implementação: Módulo árvore
//*
//*  Arquivo gerado:              ARVORE.C
//*  Letras identificadoras:      ARV
//*
//*  Nome da base de software:    Exemplo de teste automatizado
//*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
//*
//*  Projeto: Disciplinas INF 1628 / 1301
//*  Gestor:  DI/PUC-Rio
//*  Autores: avs - Arndt von Staa
//*
//*  $HA Histórico de evolução:
//*     Versão  Autor    Data     Observações
//*       3.00   avs   28/02/2003 Uniformização da interface das funções e
//*                               de todas as condições de retorno.
//*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
//*       1.00   avs   15/08/2001 Início do desenvolvimento
//*
//***************************************************************************/
//
//#include	<malloc.h>
//#include	<stdio.h>
//
//#define MATRIZ_OWN
//#include "MATRIZ.H"
//#undef MATRIZ_OWN
//
///***********************************************************************
//*
//*  $TC Tipo de dados: ARV Descritor do nó da árvore
//*
//*
//*  $ED Descrição do tipo
//*     Descreve a organização do nó
//*
//***********************************************************************/
//
//typedef struct tgNoMatriz {
//
//	struct tgNoMatriz * pNorte ; 
//	struct tgNoMatriz * pNordeste ;
//	struct tgNoMatriz * pLeste ;
//	struct tgNoMatriz * pSudeste ;
//	struct tgNoMatriz * pSul ;
//	struct tgNoMatriz * pSudoeste ;
//	struct tgNoMatriz * pOeste ;
//	struct tgNoMatriz * pNoroeste ;
//
//    void * Valor ;
//    /* Valor do nó */
//
//} tpNoMatriz ;
//
///***********************************************************************
//*
//*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
//*
//*
//*  $ED Descrição do tipo
//*     A cabe‡a da árvore é o ponto de acesso para uma determinada árvore.
//*     Por intermédio da referência para o nó corrente e do ponteiro
//*     pai pode-se navegar a árvore sem necessitar de uma pilha.
//*     Pode-se, inclusive, operar com a árvore em forma de co-rotina.
//*
//***********************************************************************/
//
//typedef struct tgMatriz {
//
//	tpNoMatriz * pNoOrigem ;
//               /* Ponteiro para a raiz da árvore */
//
//    tpNoMatriz * pNoCorr ;
//               /* Ponteiro para o nó corrente da árvore */
//
//	int fileiras;
//	int colunas;
//
//} tpMatriz ;
//
///*****  Dados encapsulados no módulo  *****/
//
//tpNoMatriz ** mat;
//
///***** Protótipos das funções encapuladas no módulo *****/
//
//void imprimeMat( tpNoMatriz ** mat, int fil, int col);
//
//void DestroiMatriz( tpNoMatriz ** mat );
//
//void ExcluiNoLista(void * elem);
//
//
///*****  Código das funções exportadas pelo módulo  *****/
//
///***************************************************************************
//*
//*  Função: ARV Criar árvore
//*  ****/
//
//MAT_tpCondRet MAT_CriarMatriz(tpMatriz ** pMat, int fil, int col)
//{
//	
//	int i,j;
//	printf("a\n");
//	*pMat = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
//	
//
//	printf("\n[CriarMatriz]\n");  
//  //  if ( pMatriz != NULL )
//  //  {
//		//printf("funcionou!\n");
//  //      MAT_DestruirMatriz( ) ;
//  //  } /* if */
//
//    if ( *pMat == NULL )
//    {
//		return MAT_CondRetFaltouMemoria ;
//    } /* if */
//
//	mat = (tpNoMatriz**)malloc(fil*sizeof(tpNoMatriz*));
//	for(i=0; i<fil ;i++)
//	{
//		mat[i] = (tpNoMatriz*)malloc(col*sizeof(tpNoMatriz));
//		for(j=0; j<col; j++)
//		{
//			mat[i][j].Valor = NULL;
//			mat[i][j].pNorte = NULL;
//			mat[i][j].pNordeste = NULL;
//			mat[i][j].pNoroeste = NULL;
//			mat[i][j].pLeste = NULL;
//			mat[i][j].pOeste = NULL;
//			mat[i][j].pSudeste = NULL;
//			mat[i][j].pSul = NULL;
//			mat[i][j].pSudoeste = NULL;
//		}
//	}
//
//	for(i=0; i<fil ;i++){
//		for(j=0; j<col; j++){
//			mat[i][j].Valor = (void*)('a' +(i*col) + j);
//			if(i>0)
//			{
//				mat[i][j].pNorte = &mat[i-1][j];
//				if(j>0)
//					mat[i][j].pNoroeste = &mat[i-1][j-1];
//				if(j<col)
//					mat[i][j].pNordeste = &mat[i-1][j+1];
//			}
//			if(i<fil-1)
//			{
//				mat[i][j].pSul = &mat[i+1][j];
//				if(j>0)
//					mat[i][j].pSudoeste = &mat[i+1][j-1];
//				if(j<col)
//					mat[i][j].pSudeste = &mat[i+1][j+1];
//			}
//			if(j>0)
//			{
//				mat[i][j].pOeste = &mat[i][j-1];
//			}
//			if(j<col-1)
//			{
//				mat[i][j].pLeste = &mat[i][j+1];
//			}
//		}// end for j
//	}// end for i
//
//	
//    (*pMat)->pNoOrigem = &mat[0][0] ;
//	(*pMat)->pNoCorr = (*pMat)->pNoOrigem ;
//	(*pMat)->fileiras = fil;
//	(*pMat)->colunas = col;
//	
//     return MAT_CondRetOK ;
//
//}/* Fim função: ARV Destruir árvore */
//
//
///***************************************************************************
//*
//*  Função: ARV Destruir árvore
//*  ****/
//
//void MAT_DestruirMatriz( tpMatriz ** pMat )
//{
//	printf("\n[DestruirMatriz]\n");
//    if ( *pMat != NULL )
//	{
//         if ( (*pMat)->pNoOrigem != NULL )
//         {
//			printf("a\n");
//            DestroiMatriz( mat ) ;
//         } /* if */
//
//		 printf("b\n");
//         free( *pMat ) ;
//         pMat = NULL ;
//	} /* if */
//	printf("foi krl\n");
//} /* Fim função: ARV Destruir árvore */
//
///***************************************************************************
//*
//*  Função: ARV Adicionar filho à esquerda
//*  ****/
//
//   ARV_tpCondRet ARV_InserirEsquerda( char ValorParm )
//   {
//
//      ARV_tpCondRet CondRet ;
//
//      tpNoArvore * pCorr ;
//      tpNoArvore * pNo ;
//
//      /* Tratar vazio, esquerda */
//
//         CondRet = CriarNoRaiz( ValorParm ) ;
//         if ( CondRet != ARV_CondRetNaoCriouRaiz )
//         {
//            return CondRet ;
//         } /* if */
//
//      /* Criar nó à esquerda de folha */
//
//         pCorr = pArvore->pNoCorr ;
//         if ( pCorr == NULL )
//         {
//            return ARV_CondRetErroEstrutura ;
//         } /* if */
//               
//         if ( pCorr->pNoEsq == NULL )
//         {
//            pNo = CriarNo( ValorParm ) ;
//            if ( pNo == NULL )
//            {
//               return ARV_CondRetFaltouMemoria ;
//            } /* if */
//            pNo->pNoPai      = pCorr ;
//            pCorr->pNoEsq    = pNo ;
//            pArvore->pNoCorr = pNo ;
//
//            return ARV_CondRetOK ;
//         } /* if */
//
//      /* Tratar não folha à esquerda */
//
//         return ARV_CondRetNaoEhFolha ;
//
//   } /* Fim função: ARV Adicionar filho à esquerda */
//
///***************************************************************************
//*
//*  Função: ARV Ir para nó à esquerda
//*  ****/
//
//   ARV_tpCondRet ARV_IrNoEsquerda( void )
//   {
//
//      if ( pArvore == NULL )
//      {
//         return ARV_CondRetArvoreNaoExiste ;
//      } /* if */
//
//      if ( pArvore->pNoCorr == NULL )
//      {
//         return ARV_CondRetArvoreVazia ;
//      } /* if */
//
//      if ( pArvore->pNoCorr->pNoEsq == NULL )
//      {
//         return ARV_CondRetNaoPossuiFilho ;
//      } /* if */
//
//      pArvore->pNoCorr = pArvore->pNoCorr->pNoEsq ;
//      return ARV_CondRetOK ;
//
//   } /* Fim função: ARV Ir para nó à esquerda */
//
///***************************************************************************
//*
//*  Função: ARV Ir para nó à direita
//*  ****/
//
//   ARV_tpCondRet ARV_IrNoDireita( void )
//   {
//
//      if ( pArvore == NULL )
//      {
//         return ARV_CondRetArvoreNaoExiste ;
//      } /* if */
//
//      if ( pArvore->pNoCorr == NULL )
//      {
//         return ARV_CondRetArvoreVazia ;
//      } /* if */
//
//      if ( pArvore->pNoCorr->pNoDir == NULL )
//      {
//         return ARV_CondRetNaoPossuiFilho ;
//      } /* if */
//
//      pArvore->pNoCorr = pArvore->pNoCorr->pNoDir ;
//      return ARV_CondRetOK ;
//
//   } /* Fim função: ARV Ir para nó à direita */
//
///***************************************************************************
//*
//*  Função: ARV Obter valor corrente
//*  ****/
//
//   ARV_tpCondRet ARV_ObterValorCorr( char * ValorParm )
//   {
//
//      if ( pArvore == NULL )
//      {
//         return ARV_CondRetArvoreNaoExiste ;
//      } /* if */
//      if ( pArvore->pNoCorr == NULL )
//      {
//         return ARV_CondRetArvoreVazia ;
//      } /* if */
//      * ValorParm = pArvore->pNoCorr->Valor ;
//
//      return ARV_CondRetOK ;
//
//   } /* Fim função: ARV Obter valor corrente */
//
//
///*****  Código das funções encapsuladas no módulo  *****/
//
//
//
///***********************************************************************
//*
//*  $FC Função: ARV Destruir a estrutura da árvore
//*
//*  $EAE Assertivas de entradas esperadas
//*     pNoArvore != NULL
//*
//***********************************************************************/
//
//void DestroiMatriz( tpNoMatriz ** mat )
//{
//	int i,j;
//	printf("c\n");
//	for(i=0; &mat[i]!=NULL ;i++)
//	{
//		for(j=0;&mat[i][j]!=NULL;j++)
//		{
//			printf("i");
//			free(&mat[i][j]);
//		}	
//	}
//	free(mat);
//	
//	return;
//} /* Fim função: ARV Destruir a estrutura da árvore */
//
///********** Fim do módulo de implementação: Módulo árvore **********/
//
