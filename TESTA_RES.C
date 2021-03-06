/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Matriz. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo matriz:
*
*     "=criar"        - chama a fun��o MAT_CriarMatriz( )
*     "=insval" <Char>
*                   - chama a fun��o MAT_InsereValor( <Char> ) <-----------atualizar aqui
*     "=retavl"	       -chama a fun��o RetiraMatriz( )
*     "=iroeste"      - chama a fun��o MoveOeste( )
*     "=irleste"      - chama a fun��o MoveLeste( )
*     "=irnorte"      - chama a fun��o MoveNorte( )
*     "=irsul"	      - chama a fun��o MoveSul( )
*     "=irsudeste"    - chama a fun��o MoveSudeste( )
*     "=irsudoeste"   - chama a fun��o MoveSudoeste( )
*     "=irnordeste"   - chama a fun��o MoveNordeste( )
*     "=irnoroeste"   - chama a fun��o MoveNoroeste( )
*     "=obter" <Char>
*                   - chama a fun��o MAT_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a fun��o MAT_DestruirMatriz( )
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

/* Tabela dos nomes dos comandos de teste espec�ficos */

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

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/





/***********************************************************************
*
*  $FC Fun��o: TMAT Efetuar opera��es de teste espec�ficas para Matriz
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Matriz sendo testado.
*
*  $EP Par�metros
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

   } /* Fim fun��o: TMAT Efetuar opera��es de teste espec�ficas para Matriz */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
