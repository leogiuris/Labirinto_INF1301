#if ! defined( Matriz_ )
#define Matriz_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Matriz
*
*  Arquivo gerado:              Matriz.H
*  Letras identificadoras:      MAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Daniel Peralta, Rafael Serpa, Leonardo Santiago
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   11/09/2019 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   09/09/2019 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   03/09/2019 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar Matrizes
*     A Matriz possui uma cabe�a que cont�m uma refer�ncia para a Origem(0,0) da
*     Matriz e outra para um n� corrente da Matriz.
*     A cada momento o m�dulo admite no m�ximo uma �nica Matriz.
*     Ao iniciar a execu��o do programa n�o existe Matriz.
*     O n� corrente ser� nulo se e somente se a Matriz estiver vazia.
*
***************************************************************************/
 
#if defined( MATRIZ_OWN )
   #define MATRIZ_EXT
#else
   #define MATRIZ_EXT extern
#endif


/***********************************************************************
*
*  $TC Tipo de dados: MAT Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         MAT_CondRetOK = 0 ,
               /* Executou correto */


         
               /* N�o � folha relativa � dire��o de inser��o desejada */

         MAT_CondRetMatrizNaoExiste = 4 ,
               /* Matriz n�o existe */

         MAT_CondRetMatrizVazia = 5 ,
               /* Matriz est� vazia */



         MAT_CondRetNaoPossuiVizinho = 7 ,
               /* N� corrente n�o possui filho na dire��o desejada */

         MAT_CondRetFaltouMemoria = 8,
               /* Faltou mem�ria ao alocar dados */

		 MAT_CondRetTamanhoInvalido = 9, 
		 MAT_CondRetErroEstrutura = 10
   } MAT_tpCondRet ;




   typedef struct tgMatriz tpMatriz;
/***********************************************************************
*
*  $FC Fun��o: MAT Criar matriz
*
*  $ED Descri��o da fun��o
*     Cria uma nova Matriz vazia.
*     Caso j� exista uma Matriz, esta ser� destru�da.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*
***********************************************************************/

   MAT_tpCondRet MAT_CriarMatriz(tpMatriz ** pMat, int lin, int col, void * valorInicial);

   MAT_tpCondRet MAT_InsereValor(tpMatriz*pMatriz, void * Valor);
/***********************************************************************
*
*  $FC Fun��o: MAT Destruir Matriz
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo e a cabe�a da Matriz, anulando a Matriz corrente.
*     Faz nada caso a Matriz corrente n�o exista.
*
***********************************************************************/
   char * ObtemMatrizString(tpMatriz * pMat);
   void MAT_DestruirMatriz( tpMatriz * pMat );

   void ImprimeMat(tpMatriz *pMat);
/***********************************************************************
*
*  $FC Fun��o: MAT Adicionar filho � esquerda
*
*  $EP Par�metros
*     $P ValorParm - valor a ser inserido no novo n�.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetErroEstrutura
*     MAT_CondRetFaltouMemoria
*     MAT_CondRetNaoEhFolha     - caso n�o seja folha para a esquerda
*
***********************************************************************/

MAT_tpCondRet	MAT_ObterValor(tpMatriz*pMatriz, void **ValorCorrente);

MAT_tpCondRet	MAT_RetiraValor(tpMatriz*pMatriz);
/***********************************************************************
*
*  $FC Fun��o: MAT Adicionar filho � direita
*
*  $EP Par�metros
*     $P ValorParm - valor a ser inserido no novo n�
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetErroEstrutura
*     MAT_CondRetFaltouMemoria
*     MAT_CondRetNaoEhFolha     - caso n�o seja folha para a direita
*
***********************************************************************/

   MAT_tpCondRet MAT_InserirDireita( char ValorParm ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� pai
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNoEhRaiz
*
***********************************************************************/
   MAT_tpCondRet MoveOeste(tpMatriz*pMatriz);
   MAT_tpCondRet MoveLeste(tpMatriz*pMatriz);
   MAT_tpCondRet MoveNorte(tpMatriz*pMatriz);
   MAT_tpCondRet MoveSul(tpMatriz*pMatriz);
   MAT_tpCondRet MoveNordeste(tpMatriz*pMatriz);
   MAT_tpCondRet MoveNoroeste(tpMatriz*pMatriz);
   MAT_tpCondRet MoveSudeste(tpMatriz*pMatriz);
   MAT_tpCondRet MoveSudoeste(tpMatriz*pMatriz);
   MAT_tpCondRet MoveCoord(tpMatriz *pMatriz, int x, int y);
	void MAT_RetornaOrigem(tpMatriz * pMat);


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� � esquerda
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiFilho   - n� corrente n�o possui filho � esquerda
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoEsquerda( void ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� � direita
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiFilho   - n� corrente n�o possui filho � direita
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoDireita( void ) ;

   MAT_tpCondRet ObterValor(tpMatriz*pMatriz, void ** ValorCorrente);

/***********************************************************************
*
*  $FC Fun��o: MAT Obter valor corrente
*
*  $EP Par�metros
*     $P ValorParm - � o par�metro que receber� o valor contido no n�.
*                    Este par�metro � passado por refer�ncia.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*
***********************************************************************/

  

#undef Matriz_EXT

/********** Fim do m�dulo de defini��o: M�dulo Matriz **********/

#else
#endif