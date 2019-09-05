//#include	<malloc.h>
//#include	<stdio.h>
//#include	"LISTA.H"
//
//#define MATRIZ_OWN
//#include "MATRIZ.H"
//#undef MATRIZ_OWN
//
//
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
//
//
//tpMatriz * pMatriz = NULL ;
//
//static tpNoMatriz ** mat = NULL;
//
//void imprimeMat( tpNoMatriz ** mat, int fil, int col);
//
//void DestroiMatriz( tpNoMatriz ** mat );
//
//void ExcluiNoLista(void * elem);
//
//
//MAT_tpCondRet MAT_CriarMatriz(tpMatriz * pMat, int fil, int col)
//{
//	
//	int i,j;
//	printf("\n[CriarMatriz]\n");  
//  //  if ( pMatriz != NULL )
//  //  {
//		//printf("funcionou!\n");
//  //      MAT_DestruirMatriz( ) ;
//  //  } /* if */
//
//	
//    pMatriz = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
//	//pMat = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
//
//    if ( pMatriz == NULL )
//    {
//		
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
//    pMatriz->pNoOrigem = &mat[0][0] ;
//	pMatriz->pNoCorr = pMatriz->pNoOrigem ;
//	pMatriz->fileiras = fil;
//	pMatriz->colunas = col;
//
//	pMat = pMatriz;
//	imprimeMat(mat,fil,col);
//	
//    return MAT_CondRetOK ;
//
//}
//
//
//void MAT_DestruirMatriz( void )
//{
//	printf("\n[DestruirMatriz]\n");
//    if ( pMatriz != NULL )
//	{
//         if ( pMatriz->pNoOrigem != NULL )
//         {
//            DestroiMatriz( mat ) ;
//         } /* if */
//
//
//         free( pMatriz ) ;
//         pMatriz = NULL ;
//	} /* if */
//	
//} /* Fim função: ARV Destruir árvore */
//
//
//void DestroiMatriz( tpNoMatriz ** mat )
//{
//	int i;
//	
//	for(i=0; i<pMatriz->fileiras ;i++)
//	{
//		
//		free(mat[i]);
//		
//	}
//	
//	free(mat);
//	
//	return;
//
//	
//} /* Fim função: ARV Destruir a estrutura da árvore */
//
//
//void imprimeMat(tpNoMatriz ** mat, int fil, int col)
//{
//	int i,j;
//
//	for(i=0; i<fil; i++)
//	{
//		printf("\n");
//		for(j=0; j<col; j++)
//		{
//			mat[i][j].Valor = (void*)('a' +(i*col) + j);
//			printf("%c	",mat[i][j].Valor);
//		}
//	}
//
//	printf("valor corrente: %c\n", pMatriz->pNoCorr->Valor);
//	
//}
//
//void ExcluiNoLista(void * elem){
//	free(elem);
//}
//
//
//int main()
//{
//	tpMatriz * pMat1 = NULL;
//	MAT_tpCondRet condRet;
//
//	condRet = MAT_CriarMatriz(pMat1,3,3);
//
//	printf("valor 0,0 pMat1: %c\n", pMat1->pNoOrigem->Valor);
//	MAT_DestruirMatriz();
//
//	return 0;
//}
//
//
