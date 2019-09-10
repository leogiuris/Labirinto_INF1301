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
#include	<string.h>
#include    "TST_ESPC.H"
#include	<malloc.h>

#include    "generico.h"
#include    "lerparm.h"
#include	"LISTA.H"
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
void ExcluirValor(void * pValor);

void string2lista(LIS_tppLista lista, char * frase);

void ImprimeLista(LIS_tppLista lista);

 char * geraFrase(LIS_tppLista lista);


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
	  char frase[10];
	  char fraseRet[10];
	  LIS_tppLista lista = LIS_CriarLista(ExcluirValor);
	  
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

			CondRetObtido = MAT_CriarMatriz(&pontMat[indice], valorTamanho);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz" );
         
		 } /* fim ativa: Testar MAT Criar matriz */

	else if ( strcmp( ComandoTeste , INS_VAL_CMD ) == 0 )
         {
			


			 LIS_tppLista l = LIS_CriarLista(ExcluirValor);
			 NumLidos = LER_LerParametros( "is" ,
                               &CondRetEsperada,frase ) ;

			 

			string2lista(lista,frase);

			
            
		 CondRetObtido = MAT_InsereValor(pontMat[0], lista);

		 CondRetObtido = ObterValor(pontMat[0], l);

			 printf("\n%s\n",frase);
				ImprimeLista(lista);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz" );

         } /* fim ativa: Testar ARV Destruir árvore */


      /* Testar MAT Ir para nó oeste */ //<------------ todos os comandos de movimento precisam ser atualizados pra como o Rafael fizer

         else if ( strcmp( ComandoTeste , IR_OESTE_CMD ) == 0 )
         {


            NumLidos = LER_LerParametros("i" ,&CondRetEsperada);
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MoveOeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para oeste." );

         } /* fim ativa: Testar MAT Ir para nó oeste */


      /* Testar ARV Ir para nó leste */

         else if ( strcmp( ComandoTeste , IR_LESTE_CMD ) == 0 )
         {


            NumLidos = LER_LerParametros("i" ,
                               &CondRetEsperada) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MoveLeste(pontMat[0]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para leste." );

         } /* fim ativa: Testar MAT Ir para nó leste */

      /* Testar MAT Obter valor corrente */

         else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
         {
			 TST_tpCondRet Ret;
			 LIS_tppLista l = LIS_CriarLista(ExcluirValor);

            NumLidos = LER_LerParametros( "si" ,
                               frase , &CondRetEsperada );
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ObterValor( pontMat[0], l);

         Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter valor corrente." );


            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */


            return TST_CompararChar(  *geraFrase(l) , frase[0] ,
                                     "Conteúdo do nó está errado." );

         } /* fim ativa: Testar MAT Obter valor corrente */

      /* Testar MAT Destruir matriz */

        else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
        {
			int i;
			for(i=0;i< QTD_MAT;i++)
			{
				MAT_DestruirMatriz( pontMat[i] ) ;
			}
            

            return TST_CondRetOK ;

         } /* fim ativa: Testar ARV Destruir árvore */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TARV Efetuar operações de teste específicas para árvore */

/********** Fim do módulo de implementação: Módulo de teste específico **********/


   void ExcluirValor(void * pValor)
   {
	   pValor = NULL;
   }


   void string2lista(LIS_tppLista lista,char * frase)
   {
	   int i;
		for(i=0; i<strlen(frase); i++)
		{
			//printf("i");
			LIS_InserirElementoApos(lista, frase+i);
		}
   }

   char * geraFrase(LIS_tppLista lista){
	  
	   char * frase;
	   int cont = 0,i = 0;
	   LIS_tpCondRet ret = LIS_CondRetOK;
	   IrInicioLista(lista);
	   while(ret != LIS_CondRetFimLista)
	   {

		   cont++;

		   //printf("%c",*(LIS_tppLista*)LIS_ObterValor(lista));
		   ret = LIS_AvancarElementoCorrente(lista,1);
	   }

	   frase=(char*)malloc(cont);
	   
	   IrInicioLista(lista);
	   for(i=0;frase+i!=NULL;i++){
		   frase[i] = (char) *(LIS_tppLista*)LIS_ObterValor(lista);
	   }
	   return frase;
   }

   void ImprimeLista(LIS_tppLista lista)
   {
	   LIS_tpCondRet ret = LIS_CondRetOK;
	   printf("ai ai ai\n");
	   IrInicioLista(lista);
	   printf("ui ui\n");
	   
	   printf("PRONTO??\n");
		IrInicioLista(lista);

	   while(ret != LIS_CondRetFimLista)
	   {
		   printf("%c",*(LIS_tppLista*)LIS_ObterValor(lista));
		   ret = LIS_AvancarElementoCorrente(lista,1);
	   }

   }