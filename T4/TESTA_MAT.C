/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTMAT.C
*  Letras identificadoras:      TMAT
*
*  Autores: Daniel Peralta, Leonardo Santiago
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     3.00   lgs,dp	26/09/2019	Inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo Matriz. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo matriz:
*
*     "=criar"        - chama a função MAT_CriarMatriz( )
*     "=insval" <Char>
*                   - chama a função MAT_InsereValor( <Char> ) <-----------atualizar aqui
*     "=retavl"	       -chama a função RetiraMatriz( )
*     "=iroeste"      - chama a função MoveOeste( )
*     "=irleste"      - chama a função MoveLeste( )
*     "=irnorte"      - chama a função MoveNorte( )
*     "=irsul"	      - chama a função MoveSul( )
*     "=irsudeste"    - chama a função MoveSudeste( )
*     "=irsudoeste"   - chama a função MoveSudoeste( )
*     "=irnordeste"   - chama a função MoveNordeste( )
*     "=irnoroeste"   - chama a função MoveNoroeste( )
*     "=obter" <Char>
*                   - chama a função MAT_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a função MAT_DestruirMatriz( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include	<string.h>
#include    "TST_ESPC.H"
#include	<malloc.h>

#include    "generico.h"
#include    "lerparm.h"

#include    "MATRIZ.H"

#ifdef _DEBUG
	#include   "CESPDIN.H"
	#include   "IdTiposEspaco.def"
#endif

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_MAT_CMD		"=criar"    //recebe 3 parametros: (condret,indice,tamanho)
#define		INS_VAL_CMD			"=insval"	//recebe 2 parametros: (condret,

#define		RET_VAL_CMD			"=retval"	//<------------------ pq tem esse comando se já existe o "obbter valor"??? 

#define     IR_OESTE_CMD		"=iroeste"
#define     IR_LESTE_CMD		"=irleste"
#define		IR_NORTE_CMD		"=irnorte"
#define		IR_SUL_CMD			"=irsul"
#define		IR_SUDESTE_CMD		"=irsudeste"
#define		IR_SUDOESTE_CMD		"=irsudoeste"
#define		IR_NOROESTE_CMD		"=irnoroeste"
#define		IR_NORDESTE_CMD		"=irnordeste"
#define     OBTER_VAL_CMD		"=obter"
#define     DESTROI_CMD			"=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


#define QTD_MAT 6

tpMatriz * pontMat [QTD_MAT];
//***********************************************************************
//*
//*  $FC Função: TMAT Efetuar operações de teste específicas para Matriz
//*
//*  $ED Descrição da função
//*     Efetua os diversos comandos de teste específicos para o módulo
//*     Matriz sendo testado.
//*
//*  $EP Parâmetros
//*     $P ComandoTeste - String contendo o comando
//*
//*  $FV Valor retornado
//*     Ver TST_tpCondRet definido em TST_ESPC.H
//*
//***********************************************************************/

void ExcluirValor(void * pValor);






   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      MAT_tpCondRet CondRetObtido   = MAT_CondRetOK ;
      MAT_tpCondRet CondRetEsperada = MAT_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */


	  //----------------------------
      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  //---------------------------


	  int linhas, colunas;
	  int indice;
	  
	  char valor;
	  
	  
      int  NumLidos = -1 ;
      

      /* Testar MAT Criar matriz */
	 
         if ( strcmp( ComandoTeste , CRIAR_MAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iiii" ,
                               &indice,&linhas,&colunas,&CondRetEsperada ) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

			
				CondRetObtido = MAT_CriarMatriz(&pontMat[indice], linhas,colunas,NULL);




            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz" );
         
		 } /* fim ativa: Testar MAT Criar matriz */

	else if ( strcmp( ComandoTeste , INS_VAL_CMD ) == 0 )
         {
			 
			 NumLidos = LER_LerParametros( "ci" ,
                               &valor,&CondRetEsperada ) ;

		
		 CondRetObtido = MAT_InsereValor(pontMat[0], &valor);

		 if(CondRetObtido == MAT_CondRetOK){
			 void * temp;
			 MAT_ObterValor(pontMat[0], &temp);
			 return TST_CompararChar(valor,*(char*)temp, "Valor inserido incorreto.");
		 }

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz" );

         } /* fim ativa: Testar MAT Destruir Matriz */


		  else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
         {
			 void* temp;
			 NumLidos = LER_LerParametros( "ci" ,&valor, &CondRetEsperada );

            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = MAT_ObterValor(pontMat[0], &temp );

			
			return TST_CompararChar(valor,*(char*)temp, "Valor inserido incorreto.");

            

         } /* fim ativa: Testar MAT Obter valor corrente */


	 else if ( strcmp( ComandoTeste , RET_VAL_CMD ) == 0 )
         {
			 char elem = 'a';
			 void * ttemp;
			 NumLidos = LER_LerParametros( "i" , &CondRetEsperada );

			 if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			 
			 MAT_InsereValor(pontMat[0],&elem);
			
			

			 CondRetObtido = MAT_RetiraValor(&pontMat[0]);
			
			
			 if(CondRetObtido == MAT_CondRetOK){
				void *temp;
				
				
				
				 MAT_ObterValor(pontMat[0], &temp);
				 
				 if(NULL==(char)temp)
					
				 return TST_CompararChar(NULL,(char)temp, "Valor inserido incorreto.");
			 }


           return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao retirar valor do no" );


         } /* fim ativa: Testar MAT Obter valor corrente */



#pragma region Mover
      /* Testar MAT Ir para nó oeste */ //<------------ todos os comandos de movimento precisam ser atualizados pra como o Rafael fizer

         else if ( strcmp( ComandoTeste , IR_OESTE_CMD ) == 0 )
         {

			
            NumLidos = LER_LerParametros("i" ,&CondRetEsperada);
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveOeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para oeste." );

         } /* fim ativa: Testar MAT Ir para nó oeste */


      /* Testar MAT Ir para nó leste */

         else if ( strcmp( ComandoTeste , IR_LESTE_CMD ) == 0 )
         {


            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */


			
			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveLeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para leste." );

         } /* fim ativa: Testar MAT Ir para nó leste */

      /* Testar MAT Obter valor corrente */


		 else if ( strcmp( ComandoTeste , IR_NORTE_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveNorte(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para norte." );

         } /* fim ativa: Testar MAT Ir para nó norte */



		 /* Testar MAT Ir para nó sul */

         else if ( strcmp( ComandoTeste , IR_SUL_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveSul(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para sul." );

         } /* fim ativa: Testar MAT Ir para nó sul */



		 /* Testar MAT Ir para nó sudeste */

         else if ( strcmp( ComandoTeste , IR_SUDESTE_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveSudeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para sudeste." );

         } /* fim ativa: Testar MAT Ir para nó sudeste */




		 /* Testar MAT Ir para nó sudoeste */

         else if ( strcmp( ComandoTeste , IR_SUDOESTE_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveSudoeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para sudoeste." );

         } /* fim ativa: Testar MAT Ir para nó sudoeste */



		 /* Testar MAT Ir para nó nordeste */

         else if ( strcmp( ComandoTeste , IR_NORDESTE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveNordeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para nordeste." );

         } /* fim ativa: Testar MAT Ir para nó nordeste */



		 /* Testar MAT Ir para nó noroeste */

         else if ( strcmp( ComandoTeste , IR_NOROESTE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			MAT_RetornaOrigem(pontMat[0]);
			MoveSudeste(pontMat[0]);
            CondRetObtido = MoveNoroeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para noroeste." );

         } /* fim ativa: Testar MAT Ir para nó noroeste */

#pragma endregion



      /* Testar MAT Destruir matriz */

        else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
        {
			int i;
			
			NumLidos = LER_LerParametros("i" ,&i) ;
			
			MAT_DestruirMatriz( pontMat[i] ) ;
            
			
            return TST_CondRetOK ;

         } /* fim ativa: Testar MAT Destruir Matriz */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TMAT Efetuar operações de teste específicas para Matriz */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
