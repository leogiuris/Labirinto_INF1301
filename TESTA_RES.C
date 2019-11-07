/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTMAT.C
*  Letras identificadoras:      TMAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Daniel Peralta, Leonardo Santiago
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
#include	"labirinto.h"
#include    "generico.h"
#include    "lerparm.h"
#include    "RESOLVEDOR_TESTE.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define		CRIAR_LAB_CMD		"=criarLab"
#define		RESOLVE_LAB_CMD		"=resolver"
#define		CAVAR_NORTE_CMD		"=cavan"
#define		CAVAR_LESTE_CMD		"=caval"
#define		CAVAR_OESTE_CMD		"=cavao"
#define		CAVAR_SUL_CMD		"=cavas"
#define		REINICIA_LAB_CMD	"=reiniciaLab"
#define		CRIAR_RES_CMD		"=criarRes"
#define		INSERE_NORTE_CMD	"=insnorte"
#define		INSERE_SUL_CMD		"=inssul"
#define		INSERE_LESTE_CMD	"=insleste"
#define		INSERE_OESTE_CMD	"=insoeste"

/*****  Código das funções exportadas pelo módulo  *****/





/***********************************************************************
*
*  $FC Função: TMAT Efetuar operações de teste específicas para Matriz
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     Matriz sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

tpLabirinto * pLab;

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      RES_tpCondRet CondRetObtido   = RES_CondRetOK ;
	  LAB_tpCondRet CondRetObtidoLAB = LAB_CondRetOK;
      RES_tpCondRet CondRetEsperada = RES_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */


	  //----------------------------
      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  //---------------------------

	  int  NumLidos = -1;


	  if ( strcmp( ComandoTeste , CRIAR_LAB_CMD ) == 0 )
      {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;

            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			
			CondRetObtidoLAB = LAB_CriarLabirinto(&pLab,9,9);




            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                     "Retorno errado ao criar matriz" );
         
		} /* fim ativa: Testar MAT Criar matriz */


	  	  if( strcmp( ComandoTeste , CAVAR_LESTE_CMD ) == 0 )
	  {
		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtidoLAB = LAB_CavaLeste(pLab);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao CAVAR leste" );
	  }

	  if( strcmp( ComandoTeste , CAVAR_OESTE_CMD ) == 0 )
	  {
		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtidoLAB = LAB_CavaOeste(pLab);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao CAVAR oeste" );
	  }

	  if( strcmp( ComandoTeste , CAVAR_NORTE_CMD ) == 0 )
	  {
		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtidoLAB = LAB_CavaNorte(pLab);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao CAVAR Norte" );
	  }

	  if( strcmp( ComandoTeste , CAVAR_SUL_CMD ) == 0 )
	  {
		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtidoLAB = LAB_CavaSul(pLab);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao CAVAR oeste" );
	  }

	  if( strcmp( ComandoTeste , REINICIA_LAB_CMD ) == 0 )
	  {
		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtidoLAB = LAB_ReiniciaLabirinto(pLab);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao CAVAR oeste" );
	  }




      return TST_CondRetNaoConhec ;

   } /* Fim função: TMAT Efetuar operações de teste específicas para Matriz */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
