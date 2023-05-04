/*============================================================================*/
/* CSF13 - 2023-1 - TRABALHO 1                                                */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/* Reduzindo a profundidade de bits de imagens (decodificando). */
/*============================================================================*/

#include "trabalho1.h"

/*============================================================================*/

#define ARQUIVO_RBD "img/teste0-4.rbd" /* Entrada codificada. */
#define ARQUIVO_IMG "img/teste0-4.bmp" /* Imagem de sa�da. */
#define BPP 4 /* Precisa ser 1, 2 ou 4. */

/*============================================================================*/

int main ()
{
    criaStreamsDecod (ARQUIVO_RBD);
    decodificaStreamRBD (BPP, 0);
    salvaStreamImagem (ARQUIVO_IMG);
    destroiStreams ();
    return (0);
}

/*============================================================================*/
