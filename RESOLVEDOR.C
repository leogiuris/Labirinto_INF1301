//
//#include "LEA.H"
//#include"labirinto.h"
//
//
//int ehInicio;
//
//typedef struct resolvedor{
//
//	tpNo * Origem;
//	tpNo * Corrente;
//
//}tpResolvedor;
//
//
//typedef struct noResolvedor{
//
//	tpNo * anterior;
//	tpNo * norte;
//	tpNo * leste;
//	tpNo * sul;
//	tpNo * oeste;
//
//	int valor;
//
//}tpNo;
//
//
//void RES_AddCaminho(tpResolvedor * pRes, tpLabirinto * pLab)
//{
//	tpNo * no =(tpNo*)LEA_mallocTag(sizeof(tpNo),"tpNo");
//	if(ehInicio)
//		no->anterior = NULL;
//	else
//		no->anterior = pRes->Corrente;
//
//	if(no->
//
//	
//
//void RES_Criar(tpResolvedor ** pRes, tpLabirinto * pLab)
//{
//	*pRes = (tpResolvedor*)LEA_mallocTag(sizeof(tpResolvedor**),"RES_Cabeca");
//}



#include   <malloc.h>
#include   <stdio.h>

#include "RESOLVEDOR.H"
#include "LEA.H"
#include"labirinto.h"

   typedef struct tgNoArvore {

         struct tgNoArvore * pNoAnterior ;
               

         struct tgNoArvore * pNoNorte ;
               

         struct tgNoArvore * pNoSul ;

		 
		 struct tgNoArvore * pNoOeste ;
               

         struct tgNoArvore * pNoLeste ;


         int Valor ;
               /* Valor do nó */

   } tpNo ;

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

   typedef struct tgArvore {

         tpNo * pNoInicio ;
               /* Ponteiro para a raiz da árvore */

         tpNo * pNoCorr ;
               /* Ponteiro para o nó corrente da árvore */

   } tpResolvedor ;

/*****  Dados encapsulados no módulo  *****/

      static tpResolvedor * pResolvedor = NULL ;
            /* Ponteiro para a cabe‡a da árvore */

/***** Protótipos das funções encapuladas no módulo *****/

   static tpNo * CriarNo( int ValorParm ) ;

   static RES_tpCondRet CriarNoRaiz( int ValorParm ) ;

   static void DestroiArvore( tpNo * pNo ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar árvore
*  ****/

   RES_tpCondRet RES_CriarResolvedor( void )
   {

      if ( pResolvedor != NULL )
      {
         RES_DestruirResolvedor( ) ;
      } /* if */

      pResolvedor = ( tpResolvedor * ) malloc( sizeof( tpResolvedor )) ;
      if ( pResolvedor == NULL )
      {
         return RES_CondRetFaltouMemoria ;
      } /* if */

      pResolvedor->pNoInicio = NULL ;
      pResolvedor->pNoCorr = NULL ;

      return RES_CondRetOK ;

   } /* Fim função: ARV Criar árvore */

/***************************************************************************
*
*  Função: ARV Destruir árvore
*  ****/

   void RES_DestruirResolvedor( void )
   {

      if ( pResolvedor != NULL )
      {
         if ( pResolvedor->pNoInicio != NULL )
         {
            DestroiArvore( pResolvedor->pNoInicio ) ;
         } /* if */
         free( pResolvedor ) ;
         pResolvedor = NULL ;
      } /* if */

   } /* Fim função: ARV Destruir árvore */

   /***************************************************************************
*
*  Função: ARV Adicionar filho à esquerda
*  ****/

   RES_tpCondRet RES_InserirSul( int ValorParm )
   {

      RES_tpCondRet CondRet ;

      tpNo * pCorr ;
      tpNo * pNo ;

      /* Tratar vazio, esquerda */

         CondRet = CriarNoRaiz( 0 ) ;
         if ( CondRet != RES_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à esquerda de folha */

         pCorr = pResolvedor->pNoCorr ;
         if ( pCorr == NULL )
         {
            return RES_CondRetErroEstrutura ;
         } /* if */
               
         if ( pCorr->pNoSul == NULL )
         {
            pNo = CriarNo( 0 ) ;
            if ( pNo == NULL )
            {
               return RES_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoAnterior      = pCorr ;
            pCorr->pNoSul    = pNo ;
            //pResolvedor->pNoCorr = pNo ;

            return RES_CondRetOK ;
         } /* if */

      /* Tratar não folha à esquerda */

         return RES_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à esquerda */

   /***************************************************************************
*
*  Função: ARV Adicionar filho à esquerda
*  ****/

   RES_tpCondRet RES_InserirNorte( int ValorParm )
   {

      RES_tpCondRet CondRet ;

      tpNo * pCorr ;
      tpNo * pNo ;

      /* Tratar vazio, esquerda */

         CondRet = CriarNoRaiz( 0 ) ;
         if ( CondRet != RES_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à esquerda de folha */

         pCorr = pResolvedor->pNoCorr ;
         if ( pCorr == NULL )
         {
            return RES_CondRetErroEstrutura ;
         } /* if */
               
         if ( pCorr->pNoNorte == NULL )
         {
            pNo = CriarNo( 0 ) ;
            if ( pNo == NULL )
            {
               return RES_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoAnterior      = pCorr ;
            pCorr->pNoNorte    = pNo ;
            //pResolvedor->pNoCorr = pNo ;

            return RES_CondRetOK ;
         } /* if */

      /* Tratar não folha à esquerda */

         return RES_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à esquerda */

/***************************************************************************
*
*  Função: ARV Adicionar filho à esquerda
*  ****/

   RES_tpCondRet RES_InserirOeste( int ValorParm )
   {

      RES_tpCondRet CondRet ;

      tpNo * pCorr ;
      tpNo * pNo ;

      /* Tratar vazio, esquerda */

         CondRet = CriarNoRaiz( 0 ) ;
         if ( CondRet != RES_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à esquerda de folha */

         pCorr = pResolvedor->pNoCorr ;
         if ( pCorr == NULL )
         {
            return RES_CondRetErroEstrutura ;
         } /* if */
               
         if ( pCorr->pNoOeste == NULL )
         {
            pNo = CriarNo( 0 ) ;
            if ( pNo == NULL )
            {
               return RES_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoAnterior      = pCorr ;
            pCorr->pNoOeste    = pNo ;
            //pResolvedor->pNoCorr = pNo ;

            return RES_CondRetOK ;
         } /* if */

      /* Tratar não folha à esquerda */

         return RES_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à esquerda */

/***************************************************************************
*
*  Função: ARV Adicionar filho à direita
*  ****/

   RES_tpCondRet RES_InserirLeste( int ValorParm )
   {

      RES_tpCondRet CondRet ;

      tpNo * pCorr ;
      tpNo * pNo ;

      /* Tratar vazio, direita */

         CondRet = CriarNoRaiz( 0 ) ;
         if ( CondRet != RES_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à direita de folha */

         pCorr = pResolvedor->pNoCorr ;
         if ( pCorr == NULL )
         {
            return RES_CondRetErroEstrutura ;
         } /* if */

         if ( pCorr->pNoLeste == NULL )
         {
            pNo = CriarNo( 0 ) ;
            if ( pNo == NULL )
            {
               return RES_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoAnterior      = pCorr ;
            pCorr->pNoLeste    = pNo ;
            //pResolvedor->pNoCorr = pNo ;

            return RES_CondRetOK ;
         } /* if */

      /* Tratar não folha à direita */

         return RES_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à direita */

/***************************************************************************
*
*  Função: ARV Ir para nó pai
*  ****/

   RES_tpCondRet RES_IrAnterior( void)
   {

      if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

      if ( pResolvedor->pNoCorr->pNoAnterior != NULL )
      {
         pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoAnterior ;
         return RES_CondRetOK ;
      } else {
         return RES_CondRetNoEhRaiz ;
      } /* if */

   } /* Fim função: ARV Ir para nó pai */

/***************************************************************************
*
*  Função: ARV Ir para nó à esquerda
*  ****/

   RES_tpCondRet RES_IrNoOeste( tpLabirinto * pLab )
   {

      if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

      if ( pResolvedor->pNoCorr->pNoOeste == NULL )
      {
         return RES_CondRetNaoPossuiFilho ;
      } /* if */

	  LAB_IrOeste(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoOeste ;
      return RES_CondRetOK ;

   } /* Fim função: ARV Ir para nó à esquerda */

/***************************************************************************
*
*  Função: ARV Ir para nó à direita
*  ****/

   RES_tpCondRet RES_IrNoLeste( tpLabirinto * pLab )
   {

      if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

      if ( pResolvedor->pNoCorr->pNoLeste == NULL )
      {
         return RES_CondRetNaoPossuiFilho ;
      } /* if */

	  LAB_IrLeste(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoLeste ;
      return RES_CondRetOK ;

   } /* Fim função: ARV Ir para nó à direita */




   /***************************************************************************
*
*  Função: ARV Ir para nó à direita
*  ****/

   RES_tpCondRet RES_IrNoNorte( tpLabirinto * pLab )
   {

      if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

      if ( pResolvedor->pNoCorr->pNoNorte == NULL )
      {
         return RES_CondRetNaoPossuiFilho ;
      } /* if */

	  LAB_IrNorte(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoNorte ;
      return RES_CondRetOK ;

   } /* Fim função: ARV Ir para nó à direita */

   
   /***************************************************************************
*
*  Função: ARV Ir para nó à direita
*  ****/

   RES_tpCondRet RES_IrNoSul( tpLabirinto * pLab )
   {

      if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

      if ( pResolvedor->pNoCorr->pNoSul == NULL )
      {
         return RES_CondRetNaoPossuiFilho ;
      } /* if */

	  LAB_IrSul(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoSul ;
	  
      return RES_CondRetOK ;

   } /* Fim função: ARV Ir para nó à direita */
/***************************************************************************
*
*  Função: ARV Obter valor corrente
*  ****/

   RES_tpCondRet RES_ObterValorCorr( int * ValorParm )
   {

      if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */
      * ValorParm = pResolvedor->pNoCorr->Valor ;

      return RES_CondRetOK ;

   } /* Fim função: ARV Obter valor corrente */


   RES_tpCondRet RES_IrNoCoord(tpLabirinto * pLab, int x, int y )
   {
	   RES_tpCondRet ret;
	   if(x==0)
		   if(y>0)
			   ret = RES_IrNoNorte(pLab);
		   else
			   ret = RES_IrNoSul(pLab);
	   else
		   if(x>0)
			   ret = RES_IrNoLeste(pLab);
		   else
			   ret = RES_IrNoOeste(pLab);
	   return RES_CondRetOK;
   }

   RES_tpCondRet RetornaInicio(tpLabirinto * pLab)
   {
	   pResolvedor->pNoCorr->Valor++;

	   while(RES_IrAnterior() == RES_CondRetOK)
	   {
		   pResolvedor->pNoCorr->Valor++;
	   }

	   LAB_RetornaInicio(pLab);
	   return RES_CondRetOK;
   }


   RES_tpCondRet SondaLabirinto(tpLabirinto *pLab)
   {
	    if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pResolvedor->pNoCorr == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

	  if( pResolvedor->pNoCorr->pNoLeste != pResolvedor->pNoCorr->pNoAnterior && LAB_VerificarVizinho(pLab,1,0) == 1)
		  RES_InserirLeste(0);
	  if(pResolvedor->pNoCorr->pNoOeste != pResolvedor->pNoCorr->pNoAnterior && LAB_VerificarVizinho(pLab,-1,0) == 1)
		  RES_InserirOeste(0);
	  if(pResolvedor->pNoCorr->pNoNorte != pResolvedor->pNoCorr->pNoAnterior && LAB_VerificarVizinho(pLab,0,1) == 1)
		  RES_InserirNorte(0);
	  if(pResolvedor->pNoCorr->pNoSul != pResolvedor->pNoCorr->pNoAnterior && LAB_VerificarVizinho(pLab,0,-1) == 1)
		  RES_InserirSul(0);
	  
	  return RES_CondRetOK;
   } 


   RES_tpCondRet DecideCaminho(int * x, int * y)
   {
	   int maior=0;
	   tpNo * pNo = pResolvedor->pNoCorr;

	   if(pNo->pNoLeste != NULL)
		   if(pNo->pNoLeste->Valor>maior){
			   *x=1; *y=0;
			   maior = pNo->pNoLeste->Valor;
		   }
	   if(pNo->pNoOeste != NULL)
		   if(pNo->pNoOeste->Valor>maior){
			   *x=-1; *y=0;
			   maior = pNo->pNoOeste->Valor;
		   }
	   if(pNo->pNoNorte != NULL)
		   if(pNo->pNoNorte->Valor>maior){
			   *x=0; *y=1;
			   maior = pNo->pNoNorte->Valor;
		   }
	   if(pNo->pNoSul != NULL)
		   if(pNo->pNoSul->Valor>maior){
			   *x=0; *y=-1;
			   maior = pNo->pNoSul->Valor;
		   }
	   return RES_CondRetOK;
   }

   int Beco()
   {
	   tpNo * pNo = pResolvedor->pNoCorr;

	   if(pNo->pNoLeste == NULL && pNo->pNoOeste == NULL && pNo->pNoNorte == NULL && pNo->pNoSul == NULL)
		   return 1;
	   else
		   return 0;
   }

   RES_tpCondRet PercorreLabirinto(tpLabirinto * pLab)
   {
	   RES_tpCondRet ret;
	   tpNo * pNo = pResolvedor->pNoCorr;

	  if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pNo == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

	  while(pNo->Valor>0 || Beco()==0)
	  {
		  int x,y;
		  DecideCaminho(&x,&y);
		  RES_IrNoCoord(pLab,x,y);
	  }

	  if(Beco())
		  RetornaInicio(pLab);
	  else
	  {
		  //aaaaaaaaaaaaaaaaaaaaaa Q Q FAZ
	  }
		  

   }

/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: ARV Criar nó da árvore
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parâmetro.
*
***********************************************************************/

   tpNo * CriarNo( int ValorParm )
   {

      tpNo * pNo ;

      pNo = ( tpNo * ) malloc( sizeof( tpNo )) ;
      if ( pNo == NULL )
      {
         return NULL ;
      } /* if */

      pNo->pNoAnterior = NULL ;
      pNo->pNoOeste = NULL ;
      pNo->pNoLeste = NULL ;
	  pNo->pNoNorte = NULL ;
	  pNo->pNoSul = NULL ;

      pNo->Valor  = ValorParm ;
      return pNo ;

   } /* Fim função: ARV Criar nó da árvore */


/***********************************************************************
*
*  $FC Função: ARV Criar nó raiz da árvore
*
*  $FV Valor retornado
*     RES_CondRetOK
*     RES_CondRetFaltouMemoria
*     RES_CondRetNaoCriouRaiz
*
***********************************************************************/

   RES_tpCondRet CriarNoRaiz( int ValorParm )
   {

      RES_tpCondRet CondRet ;
      tpNo * pNo ;

      if ( pResolvedor == NULL )
      {
         CondRet = RES_CriarResolvedor( ) ;

         if ( CondRet != RES_CondRetOK )
         {
            return CondRet ;
         } /* if */
      } /* if */

      if ( pResolvedor->pNoInicio == NULL )
      {
         pNo = CriarNo( ValorParm ) ;
         if ( pNo == NULL )
         {
            return RES_CondRetFaltouMemoria ;
         } /* if */
         pResolvedor->pNoInicio = pNo ;
         pResolvedor->pNoCorr = pNo ;

         return RES_CondRetOK ;
      } /* if */

      return RES_CondRetNaoCriouRaiz ;

   } /* Fim função: ARV Criar nó raiz da árvore */


/***********************************************************************
*
*  $FC Função: ARV Destruir a estrutura da árvore
*
*  $EAE Assertivas de entradas esperadas
*     pNoArvore != NULL
*
***********************************************************************/

   void DestroiArvore( tpNo * pNo )
   {

      if ( pNo->pNoOeste != NULL )
      {
         DestroiArvore( pNo->pNoOeste ) ;
      } /* if */

      if ( pNo->pNoLeste != NULL )
      {
         DestroiArvore( pNo->pNoLeste ) ;
      } /* if */

      free( pNo ) ;

   } /* Fim função: ARV Destruir a estrutura da árvore */


   //criar resolvedor
   //checar
   //andar
   //se(beco) -> voltar
   //andar(ate achar folha da arvore)

 void RES_ResolverLabirinto(tpLabirinto * pLab)
 {
	 RES_CriarResolvedor();
