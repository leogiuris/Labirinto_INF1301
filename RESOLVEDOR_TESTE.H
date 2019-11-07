
#if ! defined( Resolvedor_ )
#define Resolvedor_




 
#if defined( RESOLVEDOR_OWN )
   #define MATRIZ_EXT
#else
   #define RESOLVEDOR_EXT extern
#endif

#include<stdio.h>
#include"labirinto.h"
typedef enum {

	RES_CondRetOK = 0,
	RES_CondRetNaoOK = 1,
	RES_CondRetNaoCriouRaiz = 2,
	RES_CondRetFaltouMemoria = 3,
	RES_CondRetErroEstrutura = 4,
	RES_CondRetNaoEhFolha = 5,
	RES_CondRetArvoreNaoExiste = 6,
	RES_CondRetArvoreVazia = 7,
	RES_CondRetNoEhRaiz = 8,
	RES_CondRetNaoPossuiFilho = 9,
	RES_CondRetResolvido = 10

}RES_tpCondRet;

	
RES_tpCondRet RES_ResolverLabirinto(tpLabirinto * pLab);

RES_tpCondRet RES_CriarResolvedor( void );

void RES_DestruirResolvedor( void );

RES_tpCondRet RES_InserirSul( int ValorParm );

RES_tpCondRet RES_InserirNorte( int ValorParm );

RES_tpCondRet RES_InserirLeste( int ValorParm );

RES_tpCondRet RES_InserirOeste( int ValorParm );


#undef Resolvedor_EXT

/********** Fim do m�dulo de defini��o: M�dulo Matriz **********/

#else
#endif