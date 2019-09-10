#if ! defined( Matriz_ )
#define Matriz_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo árvore
*
*  Arquivo gerado:              Matriz.H
*  Letras identificadoras:      ARV
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
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar matrizes.
*     A matriz possui uma cabeça que contém uma referência para a raíz da
*     árvore e outra para um nó corrente da árvore.
*     A cada momento o módulo admite no máximo uma única árvore.
*     Ao iniciar a execução do programa não existe árvore.
*     A árvore poderá estar vazia. Neste caso a raiz e o nó corrente
*     serão nulos, embora a cabeça esteja definida.
*     O nó corrente será nulo se e somente se a árvore estiver vazia.
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

		 MAT_CondRetErroEstrutura = 1 ,
               /* Estrutura da matriz está errada */

         MAT_CondRetMatrizNaoExiste = 2 ,
               /* Matriz não existe */

         MAT_CondRetMatrizVazia = 3 ,
               /* Matriz está vazia */

         MAT_CondRetNaoPossuiVizinho = 4 ,
               /* Nó corrente não possui filho na direção desejada */

         MAT_CondRetFaltouMemoria = 5,
               /* Faltou memória ao alocar dados */

		 MAT_CondRetTamanhoInvalido = 6,
			   /*Tamanho não é grande o suficiente para se formar uma matriz */

   } MAT_tpCondRet ;

   typedef struct tgMatriz tpMatriz;
/***********************************************************************
*
*  $FC Função: MAT Criar matriz
*
*  $ED Descrição da função
*     Cria uma nova matriz vazia.
*     Caso já exista uma matriz, esta será destruída.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*
***********************************************************************/

   MAT_tpCondRet MAT_CriarMatriz(tpMatriz ** pMat, int tam);


/***********************************************************************
*
*  $FC Função: MAT Destruir matriz
*
*  $ED Descrição da função
*     Destrói a matriz ao qual o ponteiro corrente da estrutura cabeça estiver apontando.
*     Faz nada caso a matriz corrente não exista.
*
***********************************************************************/

   void MAT_DestruirMatriz( tpMatriz * pMat ) ;

/***********************************************************************
*
*  $FC Função: ARV Ir para nó à direita
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiFilho   - nó corrente não possui filho à direita
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoDireita( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Obter valor corrente
*
*  $EP Parâmetros
*     $P ValorParm - é o parâmetro que receberá o valor contido no nó.
*                    Este parâmetro é passado por referência.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*
***********************************************************************/

   MAT_tpCondRet MAT_ObterValorCorr( char * ValorParm ) ;

#undef Matriz_EXT

/********** Fim do módulo de definição: Módulo árvore **********/

#else
#endif
