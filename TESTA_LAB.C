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
//
//#include    <string.h>
//#include    <stdio.h>
//#include	<string.h>
//#include    "TST_ESPC.H"
//#include	<malloc.h>
//
//#include    "generico.h"
//#include    "lerparm.h"
//#include    "lab2.h"
//
///* Tabela dos nomes dos comandos de teste espec�ficos */
//
//#define		CRIAR_LAB_CMD		"=criar"
//#define		DESTRUIR_LAB_CMD	"=destruir"
//#define		CONSTRUIR_NORTE_CMD	"=constn"
//#define		CONSTRUIR_LESTE_CMD	"=constl"
//#define		CONSTRUIR_SUL_CMD	"=consts"
//#define		CONSTRUIR_OESTE_CMD	"=consto"
//#define		FIM_CONSTRUCAO_CMD	"=fimconst"
//#define		PERCORRE_NORTE_CMD	"=percn"
//#define		PERCORRE_LESTE_CMD	"=percl"
//#define		PERCORRE_SUL_CMD	"=percs"
//#define		PERCORRE_OESTE_CMD	"=perco"
//#define		OBTER_VALOR_CMD		"=obtem"
//
//
//
//
//
///*****  C�digo das fun��es exportadas pelo m�dulo  *****/
//
//
//
//
//
///***********************************************************************
//*
//*  $FC Fun��o: TMAT Efetuar opera��es de teste espec�ficas para Matriz
//*
//*  $ED Descri��o da fun��o
//*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
//*     Matriz sendo testado.
//*
//*  $EP Par�metros
//*     $P ComandoTeste - String contendo o comando
//*
//*  $FV Valor retornado
//*     Ver TST_tpCondRet definido em TST_ESPC.H
//*
//***********************************************************************/
//
//tpLabirinto * pLab;
//
//   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
//   {
//
//      LAB_tpCondRet CondRetObtido   = LAB_CondRetOK ;
//      LAB_tpCondRet CondRetEsperada = LAB_CondRetFaltouMemoria ;
//                                      /* inicializa para qualquer coisa */
//
//
//	  //----------------------------
//      char ValorEsperado = '?'  ;
//      char ValorObtido   = '!'  ;
//      char ValorDado     = '\0' ;
//	  //---------------------------
//
//	  int  NumLidos = -1;
//	  int lin,col;
//
//
//	  if ( strcmp( ComandoTeste , CRIAR_LAB_CMD ) == 0 )
//      {
//
//            NumLidos = LER_LerParametros( "iii" ,
//                               &lin,&col,&CondRetEsperada ) ;
//            if ( NumLidos != 3 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			
//			CondRetObtido = LAB_CriarLabirinto(&pLab,lin,col);
//
//
//
//
//            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao criar matriz" );
//         
//		} /* fim ativa: Testar MAT Criar matriz */
//
//	  if( strcmp( ComandoTeste , DESTRUIR_LAB_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_DestruirLabirinto(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao destruir labirinto" );
//	  }
//
//	  if( strcmp( ComandoTeste , CONSTRUIR_LESTE_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_CavaLeste(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao construir leste" );
//	  }
//
//	  if( strcmp( ComandoTeste , CONSTRUIR_OESTE_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_CavaOeste(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao construir oeste" );
//	  }
//
//	  if( strcmp( ComandoTeste , CONSTRUIR_NORTE_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_CavaNorte(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao construir Norte" );
//	  }
//
//	  if( strcmp( ComandoTeste , CONSTRUIR_SUL_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_CavaSul(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao construir oeste" );
//	  }
//
//	  if( strcmp( ComandoTeste , FIM_CONSTRUCAO_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_FinalizaConstrucao(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao finalizar construcao" );
//	  }
//
//
//	  
//	  if( strcmp( ComandoTeste , PERCORRE_LESTE_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_PercorreLeste(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao percorrer leste" );
//	  }
//
//	  if( strcmp( ComandoTeste , PERCORRE_NORTE_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_PercorreNorte(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao percorrer leste" );
//	  }
//
//	  if( strcmp( ComandoTeste , PERCORRE_OESTE_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_PercorreOeste(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao percorrer leste" );
//	  }
//
//	  if( strcmp( ComandoTeste , PERCORRE_SUL_CMD ) == 0 )
//	  {
//		  NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;
//            if ( NumLidos != 1 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_PercorreSul(pLab);
//
//			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao percorrer leste" );
//	  }
//
//	  if( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
//	  {
//		  char ret;
//		  char valor;
//		  NumLidos = LER_LerParametros( "ci" , &valor, &CondRetEsperada ) ;
//            if ( NumLidos != 2 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//			CondRetObtido = LAB_ObterValor(pLab,&ret);
//
//			return TST_CompararChar( valor , ret ,
//                                    "Retorno errado ao obter valor" );
//	  }
//
//      return TST_CondRetNaoConhec ;
//
//   } /* Fim fun��o: TMAT Efetuar opera��es de teste espec�ficas para Matriz */
//
///********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
//