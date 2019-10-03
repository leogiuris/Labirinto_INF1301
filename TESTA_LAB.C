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

#include    "generico.h"
#include    "lerparm.h"
#include    "lab2.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define		CRIAR_LAB_CMD		"=criar"
#define		DESTRUIR_LAB_CMD	"=destruir"
#define		CONSTRUIR_NORTE_CMD	"=LAB_Constroin"
#define		CONSTRUIR_LESTE_CMD	"=constl"
#define		CONSTRUIR_SUL_CMD	"=consts"
#define		CONSTRUIR_OESTE_CMD	"=consto"
#define		FIM_CONSTRUCAO_CMD	"=fimconst"
#define		LAB_Percorre_NORTE_CMD	"=percn"
#define		LAB_Percorre_LESTE_CMD	"=percl"
#define		LAB_Percorre_SUL_CMD	"=percs"
#define		LAB_Percorre_OESTE_CMD	"=perco"
#define		OBTER_VALOR_CMD		"=obtem"





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

      LAB_tpCondRet CondRetObtido   = LAB_CondRetOK ;
      LAB_tpCondRet CondRetEsperada = LAB_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */


	  //----------------------------
      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  //---------------------------

	  int  NumLidos = -1 ;

	  int lin,col;



	  if ( strcmp( ComandoTeste , CRIAR_LAB_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
                               &lin,&col,&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

			
			CondRetObtido = LAB_CriarLabirinto(&pLab,lin,col);




            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz" );
         
		 } /* fim ativa: Testar MAT Criar matriz */

	  if( strcmp( ComandoTeste , DESTRUIR_LAB_CMD ) == 0 )
	  {
		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = LAB_DestruirLabirinto(pLab);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao destruir labirinto" );
	  }

      return TST_CondRetNaoConhec ;

   } /* Fim função: TMAT Efetuar operações de teste específicas para Matriz */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
