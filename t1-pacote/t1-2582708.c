#include "trabalho1.h"

/*============================================================================*/
/* Funções do trabalho. */

void codificaStreamImagem (int n_bits){}
void decodificaStreamRBD (int n_bits, int preenche){}

/*----------------------------------------------------------------------------*/
/* Funções auxiliares que DEVEM ser chamadas pelos alunos. */

unsigned int pegaProximoPixel ();
void enviaPixel (unsigned char pixel);
unsigned int pegaProximoByteRBD ();
void enviaByteRBD (unsigned char byte);
