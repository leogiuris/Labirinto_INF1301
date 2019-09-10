/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTARV.C
*  Letras identificadoras:      TARV
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
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo árvore. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     =criar        - chama a função ARV_CriarArvore( )
*     =insdir <Char>
*                   - chama a função ARV_InserirDireita( <Char> )
*                     Obs. notação: <Char>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=insesq" <Char>
*                   - chama a função ARV_InserirEsquerda( <Char> )
*     "=irpai"      - chama a função ARV_IrPai( )
*     "=iresq"      - chama a função ARV_IrEsquerda( )
*     "=irdir"      - chama a função ARV_IrDireita( )
*     "=obter" <Char>
*                   - chama a função ARV_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a função ARV_DestruirArvore( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "MATRIZ.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_MAT_CMD		"=criar"
#define		INS_VAL_CMD			"=insval"

#define		RET_VAL_CMD			"=retval" //<------------------ pq tem esse comando se já existe o "obbter valor"??? 

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


/***********************************************************************
*
*  $FC Função: TARV Efetuar operações de teste específicas para árvore
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     árvore sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/




#define QTD_MAT 4
 tpMatriz * pontMat [QTD_MAT];


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

	  int valorTamanho;
	int indice;

      int  NumLidos = -1 ;

      //TST_tpCondRet Ret ;

      /* Testar MAT Criar matriz */

         if ( strcmp( ComandoTeste , CRIAR_MAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
                               &CondRetEsperada,&indice,&valorTamanho ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			while(indice<QTD_MAT)
			{
				CondRetObtido = MAT_CriarMatriz(&pontMat[indice], valorTamanho+indice);
				indice++;
			}


            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz" );
         
		 } /* fim ativa: Testar MAT Criar matriz */

      /* Testar MAT Ir para nó oeste */ //<------------ todos os comandos de movimento precisam ser atualizados pra como o Rafael fizer

         //else if ( strcmp( ComandoTeste , IR_OESTE_CMD ) == 0 )
         //{


         //   NumLidos = LER_LerParametros("iii" ,
         //                      &CondRetEsperada,&valorLinha,&valorColuna);
         //   if ( NumLidos != 3 )
         //   {
         //      return TST_CondRetParm ;
         //   } /* if */

         //   CondRetObtido = MAT_IrNoEsquerda(&pontMat, valorLinha, valorColuna);

         //   return TST_CompararInt( CondRetEsperada , CondRetObtido ,
         //                           "Retorno errado ao ir para oeste." );

         //} /* fim ativa: Testar MAT Ir para nó oeste */


      /* Testar ARV Ir para nó leste */

         //else if ( strcmp( ComandoTeste , IR_LESTE_CMD ) == 0 )
         //{


         //   NumLidos = LER_LerParametros("iii" ,
         //                      &CondRetEsperada,&valorLinha,&valorColuna) ;
         //   if ( NumLidos != 3 )
         //   {
         //      return TST_CondRetParm ;
         //   } /* if */

         //   CondRetObtido = MAT_IrNoDireita(&pontMat, valorLinha, valorColuna);

         //   return TST_CompararInt( CondRetEsperada , CondRetObtido ,
         //                           "Retorno errado ao ir para leste." );

         //} /* fim ativa: Testar MAT Ir para nó leste */

      /* Testar MAT Obter valor corrente */

         //else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
         //{


         //   NumLidos = LER_LerParametros( "ci" ,
         //                      &ValorEsperado , &CondRetEsperada );
         //   if ( NumLidos != 2 )
         //   {
         //      return TST_CondRetParm ;
         //   } /* if */

         //   CondRetObtido = MAT_ObterValorCorr( &ValorObtido );

         //Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
         //                          "Retorno errado ao obter valor corrente." );


         //   if ( Ret != TST_CondRetOK )
         //   {
         //      return Ret ;
         //   } /* if */


         //   return TST_CompararChar( ValorEsperado , ValorObtido ,
         //                            "Conteúdo do nó está errado." );

         //} /* fim ativa: Testar MAT Obter valor corrente */

      /* Testar MAT Destruir matriz */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {
			 int i;
			for(i=0;i< QTD_MAT;i++){
				MAT_DestruirMatriz( pontMat[i] ) ;
			}
            

            return TST_CondRetOK ;

         } /* fim ativa: Testar ARV Destruir árvore */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TARV Efetuar operações de teste específicas para árvore */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

