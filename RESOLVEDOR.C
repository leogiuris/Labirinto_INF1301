





#include   <stdio.h>
#include	<time.h>
#include	<stdlib.h>
#include "RESOLVEDOR.H"
#include "RESOLVEDOR_TESTE.H"

#include <windows.h>
#include	<math.h>

#define SLEEP Sleep(10)
#define LIM_PASSOS 10000



   typedef struct tgNoArvore {

         struct tgNoArvore * pNoAnterior ;
               

         struct tgNoArvore * pNoNorte ;
               

         struct tgNoArvore * pNoSul ;

		 
		 struct tgNoArvore * pNoOeste ;
               

         struct tgNoArvore * pNoLeste ;


         int Valor ;
               /* Valor do n� */

   } tpNo ;

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabe�a de uma �rvore
*
*
*  $ED Descri��o do tipo
*     A cabe�a da �rvore � o ponto de acesso para uma determinada �rvore.
*     Por interm�dio da refer�ncia para o n� corrente e do ponteiro
*     pai pode-se navegar a �rvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a �rvore em forma de co-rotina.
*
***********************************************************************/

   typedef struct tgArvore {

         tpNo * pNoInicio ;
               /* Ponteiro para a raiz da �rvore */

         tpNo * pNoCorr ;
               /* Ponteiro para o n� corrente da �rvore */

   } tpResolvedor ;

/*****  Dados encapsulados no m�dulo  *****/

      static tpResolvedor * pResolvedor = NULL ;
            /* Ponteiro para a cabe�a da �rvore */
	  //void * balde[4];
	  //int qtdBalde = 0;
	  int passos = 0;

	  int tentativas = 1;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static tpNo * CriarNo( int ValorParm ) ;

   static RES_tpCondRet CriarNoRaiz( int ValorParm ) ;

   static void DestroiArvore( tpNo * pNo ) ;

    RES_tpCondRet RES_CriarResolvedor( void );

	void RES_DestruirResolvedor( void );

	RES_tpCondRet RES_InserirSul( int ValorParm );

		RES_tpCondRet RES_InserirNorte( int ValorParm );

		RES_tpCondRet RES_InserirLeste( int ValorParm );

		RES_tpCondRet RES_InserirOeste( int ValorParm );
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: ARV Criar �rvore
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

	  CriarNoRaiz( 0 ) ;

      return RES_CondRetOK ;

   } /* Fim fun��o: ARV Criar �rvore */

/***************************************************************************
*
*  Fun��o: ARV Destruir �rvore
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

		 tentativas = 1; passos = 0;
      } /* if */

   } /* Fim fun��o: ARV Destruir �rvore */

   /***************************************************************************
*
*  Fun��o: ARV Adicionar filho � esquerda
*  ****/

   RES_tpCondRet RES_InserirSul( int ValorParm )
   {

      RES_tpCondRet CondRet ;

      tpNo * pCorr ;
      tpNo * pNo ;

      /* Tratar vazio, esquerda */
	  printf("[ INSERE SUL ]");
         CondRet = CriarNoRaiz( 0 ) ;
         if ( CondRet != RES_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar n� � esquerda de folha */

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

			printf("--OK\n");
            return RES_CondRetOK ;
         } /* if */

      /* Tratar n�o folha � esquerda */

         return RES_CondRetNaoEhFolha ;

   } /* Fim fun��o: ARV Adicionar filho � esquerda */

   /***************************************************************************
*
*  Fun��o: ARV Adicionar filho � esquerda
*  ****/

   RES_tpCondRet RES_InserirNorte( int ValorParm )
   {

      RES_tpCondRet CondRet ;

      tpNo * pCorr ;
      tpNo * pNo ;

      /* Tratar vazio, esquerda */
	  printf("[ INSERE NORTE ]");
         CondRet = CriarNoRaiz( 0 ) ;
         if ( CondRet != RES_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar n� � esquerda de folha */

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

			printf("--OK\n");
            return RES_CondRetOK ;
         } /* if */

      /* Tratar n�o folha � esquerda */

         return RES_CondRetNaoEhFolha ;

   } /* Fim fun��o: ARV Adicionar filho � esquerda */

/***************************************************************************
*
*  Fun��o: ARV Adicionar filho � esquerda
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

      /* Criar n� � esquerda de folha */

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

      /* Tratar n�o folha � esquerda */

         return RES_CondRetNaoEhFolha ;

   } /* Fim fun��o: ARV Adicionar filho � esquerda */

/***************************************************************************
*
*  Fun��o: ARV Adicionar filho � direita
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

      /* Criar n� � direita de folha */

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

      /* Tratar n�o folha � direita */

         return RES_CondRetNaoEhFolha ;

   } /* Fim fun��o: ARV Adicionar filho � direita */

/***************************************************************************
*
*  Fun��o: ARV Ir para n� pai
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
      } 
	  else 
	  {
         return RES_CondRetNoEhRaiz ;
      } /* if */

   } /* Fim fun��o: ARV Ir para n� pai */

/***************************************************************************
*
*  Fun��o: ARV Ir para n� � esquerda
*  ****/

   RES_tpCondRet RES_IrNoOeste( tpLabirinto * pLab )
   {
	   LAB_tpCondRet ret;
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

	  ret = LAB_IrOeste(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoOeste ;
	  if(ret != LAB_CondRetOK)
		  //printf("ret LAB: %d\n", ret);
	  if(ret == LAB_CondRetResolvido)
		  return RES_CondRetResolvido;

      return RES_CondRetOK ;

   } /* Fim fun��o: ARV Ir para n� � esquerda */

/***************************************************************************
*
*  Fun��o: ARV Ir para n� � direita
*  ****/

   RES_tpCondRet RES_IrNoLeste( tpLabirinto * pLab )
   {
	   LAB_tpCondRet ret;
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

	  ret = LAB_IrLeste(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoLeste ;
	  if(ret != LAB_CondRetOK)
		  //printf("ret LAB: %d\n");
	  if(ret == LAB_CondRetResolvido)
		  return RES_CondRetResolvido;

      return RES_CondRetOK ;

   } /* Fim fun��o: ARV Ir para n� � direita */




   /***************************************************************************
*
*  Fun��o: ARV Ir para n� � direita
*  ****/

   RES_tpCondRet RES_IrNoNorte( tpLabirinto * pLab )
   {
	   LAB_tpCondRet ret;
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

	  ret = LAB_IrNorte(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoNorte ;
	  if(ret != LAB_CondRetOK)
		  //printf("ret LAB: %d\n");
	  if(ret == LAB_CondRetResolvido)
		  return RES_CondRetResolvido;

      return RES_CondRetOK ;

   } /* Fim fun��o: ARV Ir para n� � direita */

   
   /***************************************************************************
*
*  Fun��o: ARV Ir para n� � direita
*  ****/

   RES_tpCondRet RES_IrNoSul( tpLabirinto * pLab )
   {
	   LAB_tpCondRet ret;
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

	  ret = LAB_IrSul(pLab);
      pResolvedor->pNoCorr = pResolvedor->pNoCorr->pNoSul ;

	  if(ret != LAB_CondRetOK)
		  //printf("ret LAB: %d\n");
	  if(ret == LAB_CondRetResolvido)
		  return RES_CondRetResolvido;
	  
      return RES_CondRetOK ;

   } /* Fim fun��o: ARV Ir para n� � direita */
/***************************************************************************
*
*  Fun��o: ARV Obter valor corrente
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

   } /* Fim fun��o: ARV Obter valor corrente */


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

	   if(ret == RES_CondRetResolvido)
		  return ret;


	   LAB_InsereRastro(pLab);

	   return RES_CondRetOK;
   }

   RES_tpCondRet RetornaInicio(tpLabirinto * pLab)
   {
	   int x,y;
	   
	   pResolvedor->pNoCorr->Valor++;

	   while(RES_IrAnterior() == RES_CondRetOK)
	   {
		   pResolvedor->pNoCorr->Valor++;
	   }
	   
	   tentativas++;
	   LAB_LimpaRastro(pLab);
	   LAB_RetornaInicio(pLab);
	   
	   return RES_CondRetOK;
   }


   RES_tpCondRet SondaLabirinto(tpLabirinto *pLab)
   {
	   tpNo * pNo = pResolvedor->pNoCorr;
	   RES_tpCondRet ret = RES_CondRetNaoOK;

	    if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pNo == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */

	  if( LAB_VerificarVizinho(pLab,1,0) == 1 && (pNo->pNoAnterior == NULL || pNo != pNo->pNoAnterior->pNoOeste))
		  ret = RES_InserirLeste(0);
	  if(LAB_VerificarVizinho(pLab,-1,0) == 1 && (pNo->pNoAnterior == NULL || pNo != pNo->pNoAnterior->pNoLeste))
		  ret = RES_InserirOeste(0);
	  if(LAB_VerificarVizinho(pLab,0,1) == 1 && (pNo->pNoAnterior == NULL || pNo != pNo->pNoAnterior->pNoSul))
		  ret = RES_InserirNorte(0);
	  if(LAB_VerificarVizinho(pLab,0,-1) == 1 && (pNo->pNoAnterior == NULL || pNo != pNo->pNoAnterior->pNoNorte))
		  ret = RES_InserirSul(0);

	  return RES_CondRetOK;
   } 



   /**/

   //DECIDE QUAL CAMINHO TOMAR COM BASE NOS VALORES DOS N�S VIZINHOS
   RES_tpCondRet DecideCaminho(int * x, int * y)
   {
	   int menor = LIM_PASSOS;
	   int num;
	   
	   
	   tpNo * pNo = pResolvedor->pNoCorr;


	   if(pNo->pNoLeste != NULL)
	   {
		   menor = pNo->pNoLeste->Valor;
	   }
	   if(pNo->pNoOeste != NULL)
	   {
		   if(pNo->pNoOeste->Valor < menor)
		   {
			   menor = pNo->pNoOeste->Valor;
		   }
	   }
	   if(pNo->pNoNorte != NULL)
	   {
		   if(pNo->pNoNorte->Valor < menor)
		   {
			   menor = pNo->pNoNorte->Valor;
		   }
	   }
	   if(pNo->pNoSul != NULL)
	   {
		   if(pNo->pNoSul->Valor < menor)
		   {
			   menor = pNo->pNoSul->Valor;
		   }
	   }
	   
	   while(1)
	   {
		   
		   num = rand()%4;
		   
		   if(num == 0 && pNo->pNoLeste != NULL)
			   if(pNo->pNoLeste->Valor == menor)
			   {
				   *x = 1; *y = 0;
				   break;
			   }
		   if(num == 1 && pNo->pNoOeste != NULL)
			   if(pNo->pNoOeste->Valor == menor)
			   {
				   *x = -1; *y = 0;
				   break;
			   }
		   if(num == 2 && pNo->pNoNorte != NULL)
			   if(pNo->pNoNorte->Valor == menor)
			   {
				   *x = 0; *y = 1;
				   break;
			   }
		   if(num == 3 && pNo->pNoSul != NULL)
			   if(pNo->pNoSul->Valor == menor)
			   {
				   *x = 0; *y = -1;
				   break;
			   }

	   }

		
	   return RES_CondRetOK;
   }



   //DIZ SE O N� CORRENTE EST� NUM BECO SEM SA�DA (N H� VIZINHOS EXCETO PAI)
   int Beco()
   {
	   tpNo * pNo = pResolvedor->pNoCorr;
	   if(pNo == pResolvedor->pNoInicio)
		   return 0;
	   if(pNo->pNoLeste == NULL && pNo->pNoOeste == NULL && pNo->pNoNorte == NULL && pNo->pNoSul == NULL){
		   
		   return 1;
	   }
	   else
		   return 0;
   }


   //ANDA PELAS MENORES PONTUA��ES
   //ASSIM QUE CHEGAR NUM N� C PONTUA��O 0, COME�A A INSERIR MAIS N�S NA ARVORE E ESCOLHE UM PRA ANDAR
   RES_tpCondRet PercorreLabirinto(tpLabirinto * pLab)
   {
	   RES_tpCondRet ret = RES_CondRetOK;
	   tpNo * pNo = pResolvedor->pNoCorr;
	   int cont = 0;

	  if ( pResolvedor == NULL )
      {
         return RES_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pNo == NULL )
      {
         return RES_CondRetArvoreVazia ;
      } /* if */
	  
	  while(pNo->Valor>0 && Beco()==0)
	  {

		  int x,y;
		  DecideCaminho(&x,&y);
		  ret = RES_IrNoCoord(pLab,x,y);
		  passos++;
		  SLEEP;
		  if(passos >LIM_PASSOS)
			  return RES_CondRetNaoOK;
	  }

	  SondaLabirinto(pLab);
	  while(Beco() == 0 && ret != RES_CondRetResolvido)
	  {
		  int x,y;
		  
		  cont++;
		  if(cont > 100)
			  return RES_CondRetNaoOK;

		  SLEEP;
		  DecideCaminho(&x,&y);
		  SLEEP;
		  ret = RES_IrNoCoord(pLab,x,y);
		  passos++;
		  if(passos == LIM_PASSOS){
			  printf("ret: %d, passos: %d\n",ret, passos);
			  return RES_CondRetNaoOK;
		  }
		  SLEEP;
		  if(ret == RES_CondRetResolvido)
			  return ret;
		  if(passos >LIM_PASSOS)
			  return RES_CondRetNaoOK;

		  SondaLabirinto(pLab);
	  }

	  if(Beco()==1)
		  RetornaInicio(pLab);
		  
	  if(ret == RES_CondRetResolvido)
		  return ret;

	  return RES_CondRetOK;

   }

/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� da �rvore
*
*  $FV Valor retornado
*     Ponteiro para o n� criado.
*     Ser� NULL caso a mem�ria tenha se esgotado.
*     Os ponteiros do n� criado estar�o nulos e o valor � igual ao do
*     par�metro.
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

   } /* Fim fun��o: ARV Criar n� da �rvore */


/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� raiz da �rvore
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

   } /* Fim fun��o: ARV Criar n� raiz da �rvore */


/***********************************************************************
*
*  $FC Fun��o: ARV Destruir a estrutura da �rvore
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
      }
	  if ( pNo->pNoNorte != NULL )
      {
         DestroiArvore( pNo->pNoNorte ) ;
      } /* if */

      if ( pNo->pNoSul != NULL )
      {
         DestroiArvore( pNo->pNoSul ) ;
      }/* if */

      free( pNo ) ;

   } /* Fim fun��o: ARV Destruir a estrutura da �rvore */


 RES_tpCondRet RES_ResolverLabirinto(tpLabirinto * pLab)
 {
	 RES_tpCondRet ret = RES_CondRetOK;
	 
	 RES_CriarResolvedor();
	 srand(time(0));
	 while(ret != RES_CondRetResolvido && passos < LIM_PASSOS)
	 {
		 ret = PercorreLabirinto(pLab);
		 if(ret == RES_CondRetResolvido)
		 {
			 printf("%d tentativas\n%d passos\n",tentativas,passos);
			 
			 RES_DestruirResolvedor();

			  return ret;
		 }
		 SLEEP;
	 }

	 RES_DestruirResolvedor();
	 return ret;
 }



