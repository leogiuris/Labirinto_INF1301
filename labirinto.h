#if ! defined( Labirinto_ )
#define Labirinto_
/***************************************************************************
*
*  $MCD Modulo de definicao: Modulo Labirinto
*
*  Arquivo gerado:              LABIRINTO.H
*  Letras identificadoras:      LAB
*
*  Projeto: Labirinto
*  Autores: Daniel Peralta(dp), Rafael Serpa(rs), Leonardo Santiago(lgs)
*
*  $HA Historico de evolucao:
*     Versao	Autor			Data		Observacoes
*       3.00   (lgs,rs,dp)   03/10/2019		Correcao de erros e uniformizacao da interface										
*       2.00   lgs			24/09/2019		Realizacao de testes
*       1.00   lgs			23/09/2019		Inicio do desenvolvimento
*
*  $ED Descricao de modulo
*		Este modulo implementa um conjunto de funcoes para criar, construir
*		e resolver labirintos usando as funcoes de acesso do modulo matriz.
*		O labirinto possui um ponteiro para uma matriz e seu tamanho em linhas e colunas.
*		A cada momento o modulo admite no maximo um unico labirinto.
*		Ao iniciar a execucao do programa nao existe Labirinto.
*		
*
***************************************************************************/
 
#if defined( LABIRINTO_OWN )
   #define LABIRINTO_EXT
#else
   #define LABIRINTO_EXT extern
#endif



#include<stdio.h>
#include<stdlib.h>

/***********************************************************************
*
*  $TC Tipo de dados: MAT Condicoes de retorno
*
*
***********************************************************************/

typedef enum{

	LAB_CondRetOK = 0, //executou correto

	LAB_CondRetFaltouMemoria = 1,	//erro ao alocar memoria

	LAB_CondRetLabirintoNaoExiste = 2,	//labirinto nao existe

	LAB_CondRetNaoPossuiVizinho = 3,	/*no corrente da matriz nao possui vizinho
										na direcao desejada */

	LAB_CondRetParede = 4,	/* no corrente nao pode mover para a direcao desejada
							pois esta eh parede */ 

	LAB_CondRetResolvido = 5,	//chegou no fim do labirinto

	LAB_CondRetSemSolucao = 6	//chegou no fim do labirinto
	
}LAB_tpCondRet ;


typedef struct tgLabirinto tpLabirinto;


//	Funcao: LAB Criar Labirinto
//
//	Destricao da funcao:
//		Cria labirinto preenchido com paredes(char)
//		Caso ja exista labirinto, esta sera destruida e criada novamente
//
//	Valor retornado:
//		LAB_CondRetOK
//		LAB_CondRetFaltouMemoria
//
//	Assertivas de entrada:
//		linhas e colunas devem ser maiores que 1
//		
//	Assertivas de saida:
//		valor obtido em pLab é igual a 'i'
//
LAB_tpCondRet LAB_CriarLabirinto(tpLabirinto ** pLab, int lin, int col);




//	Funcao: LAB Obter Valor
//
//	Destricao da funcao:
//		Obtem valor contido na posição do jogador
//
//	Valor retornado:
//		LAB_CondRetOK
//		LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor obtido nao pode ser diferente de INICIO,CAMINHO,PAREDE E FIM
//
LAB_tpCondRet LAB_ObterValor(tpLabirinto * pLab, char * valor);


//	Funcao: LAB Constroi Leste
//
//	Destricao da funcao:
//		Move a posição do jogador para leste e muda o valor para caminho (' ')
//
//	Valor retornado:
//		LAB_CondRetOK
//		LAB_CondRetNaoPossuiVizinho
//      LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido deve ser igual a CAMINHO
//
LAB_tpCondRet LAB_CavaLeste (tpLabirinto *pLab);




//	Funcao: LAB Constroi Sul
//
//	Destricao da funcao:
//		Move a posição do jogador para sul e muda o valor para caminho (' ')
//
//	Valor retornado:
//		LAB_CondRetOK
//		LAB_CondRetNaoPossuiVizinho
//      LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido deve ser igual a CAMINHO
//
LAB_tpCondRet LAB_CavaSul (tpLabirinto *pLab);



//	Funcao: LAB Constroi Norte
//
//	Destricao da funcao:
//		Move a posição do jogador para norte e muda o valor para caminho (' ')
//
//	Valor retornado:
//		LAB_CondRetOK
//		LAB_CondRetNaoPossuiVizinho
//      LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido deve ser igual a CAMINHO
//
LAB_tpCondRet LAB_CavaNorte (tpLabirinto *pLab);



//	Funcao: LAB Constroi Oeste
//
//	Destricao da funcao:
//		Move a posição do jogador para Oeste e muda o valor para caminho (' ')
//
//	Valor retornado:
//		LAB_CondRetOK
//		LAB_CondRetNaoPossuiVizinho
//      LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido deve ser igual a CAMINHO
//
LAB_tpCondRet LAB_CavaOeste (tpLabirinto *pLab);


//	Funcao: LAB Finaliza Construção
//
//	Destricao da funcao:
//		Muda o valor da posição do jogador para FIM e move para a posição inicial
//
//	Valor retornado:
//		LAB_CondRetOK
//      LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido deve ser igual a FIM

LAB_tpCondRet LAB_FinalizaConstrucao(tpLabirinto * pLab);
/////////////////////////////////////////////////////////


//	Funcao: LAB Percorre Leste
//
//	Destricao da funcao:
//		Faz o jogador mover para a direcao leste, a fim de resolver o labirinto
//
//	Valor retornado:
//		LAB_CondRetOK
//      LAB_CondRetLabirintoNaoExiste
//		LAB_CondRetNaoPossuiVizinho
//		LAB_CondRetParede
//		LAB_CondRetResolvido
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido na posicao do jogador nao pode ser diferente de CAMINHO, INICIO E FIM

LAB_tpCondRet LAB_IrLeste(tpLabirinto * pLab);
/////////////////////////////////////////////////////////


//	Funcao: LAB Percorre Sul
//
//	Destricao da funcao:
//		Faz o jogador mover para a direcao sul, a fim de resolver o labirinto
//
//	Valor retornado:
//		LAB_CondRetOK
//      LAB_CondRetLabirintoNaoExiste
//		LAB_CondRetNaoPossuiVizinho
//		LAB_CondRetParede
//		LAB_CondRetResolvido
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido na posicao do jogador nao pode ser diferente de CAMINHO, INICIO E FIM
//
LAB_tpCondRet LAB_IrSul(tpLabirinto * pLab);
/////////////////////////////////////////////////////////


//	Funcao: LAB Percorre Oeste
//
//	Destricao da funcao:
//		Faz o jogador mover para a direcao oeste, a fim de resolver o labirinto
//
//	Valor retornado:
//		LAB_CondRetOK
//      LAB_CondRetLabirintoNaoExiste
//		LAB_CondRetNaoPossuiVizinho
//		LAB_CondRetParede
//		LAB_CondRetResolvido
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido na posicao do jogador nao pode ser diferente de CAMINHO, INICIO E FIM
//
LAB_tpCondRet LAB_IrOeste(tpLabirinto * pLab);
/////////////////////////////////////////////////////////


//	Funcao: LAB Percorre Norte
//
//	Destricao da funcao:
//		Faz o jogador mover para a direcao norte, a fim de resolver o labirinto
//
//	Valor retornado:
//		LAB_CondRetOK
//      LAB_CondRetLabirintoNaoExiste
//		LAB_CondRetNaoPossuiVizinho
//		LAB_CondRetParede
//		LAB_CondRetResolvido
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		valor contido na posicao do jogador nao pode ser diferente de CAMINHO, INICIO E FIM

LAB_tpCondRet LAB_IrNorte(tpLabirinto * pLab);
/////////////////////////////////////////////////////////


//	Funcao: LAB Destruir Labirinto
//
//	Destricao da funcao:
//		Destroi a matriz e libera a estrutura tpLabirinto
//
//	Valor retornado:
//		LAB_CondRetOK
//      LAB_CondRetLabirintoNaoExiste
//
//	Assertivas de entrada:
//		labirinto deve existir
//		
//	Assertivas de saida:
//		ponteiro para labirinto deve ser igual a NULL

LAB_tpCondRet LAB_DestruirLabirinto(tpLabirinto * pLab);

int LAB_VerificarVizinho(tpLabirinto * pLab, int x, int y);

LAB_tpCondRet LAB_IrCoord(tpLabirinto * pLab, int x, int y);

void LAB_RetornaInicio(tpLabirinto * pLab);

LAB_tpCondRet LAB_Resolver(tpLabirinto * pLab);

void LAB_Cava(tpLabirinto * pLab);

void LAB_Constroi(tpLabirinto * pLab, char valor);

void LAB_MoveLivre(tpLabirinto * pLab, int x, int y);

void LAB_EscolheModo(char modo,tpLabirinto * pLab);

void ImprimeLabirinto(tpLabirinto * pLab);

void LAB_InsereRastro(tpLabirinto * pLab);

void LAB_InsereCaminho(tpLabirinto * pLab);

void LAB_LimpaRastro(tpLabirinto * pLab);

LAB_tpCondRet LAB_ReiniciaLabirinto(tpLabirinto * pLab);
/////////////////////////////////////////////////////

#undef Labirinto_EXT

/********** Fim do modulo de definicao: Modulo Matriz **********/

#else
#endif