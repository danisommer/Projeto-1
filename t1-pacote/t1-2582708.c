/*============================================================================*/
/* CSF13 - 2023-1 - TRABALHO 1                                                */
/*----------------------------------------------------------------------------*/
/* AUTOR: DANIEL ZAKI SOMMER, 2582708                                         */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*============================================================================*/


#include "trabalho1.h"

void codificaStreamImagem (int n_bits)
{

    int numero, pixel, aux;

    while (aux != 0xFFFFFFFF)
    {
        numero = 0x00; //numero para compara��o.
        for(int i=0; i < 8/n_bits; i++) //o processo de forma��o de um byte varia conforme o valor de n_bits. Quanto maior for n_bits, menos repeti��es ser�o necess�rias para obter o byte.
        {
            pixel = pegaProximoPixel();
            aux = pixel; //guarda o valor original de 'pixel' para poder utiliz�-lo no encerramento do loop (aux != 0xFFFFFFFF), sem ser prejudicado pela manipula��o da vari�vel "pixel".

            pixel = pixel >> (8-n_bits);
            pixel = pixel << (8-n_bits); //desloca o pixel para que todos os valores fora do n�mero m�ximo delimitado por n_bits seja transformado em 0.
            pixel = pixel >> (n_bits*i); //desloca o pixel para que n�o haja uma mistura entre os bits de cada pixel na hora que for junt�-los.
            pixel = pixel | numero; //opera��o para juntar os bits
            numero = pixel;

        }
        enviaByteRBD(pixel); //envia o pixel final para ser implementado.
    }

}
void decodificaStreamRBD (int n_bits, int preenche)
{

    enviaPixel (); //inserir char
    pegaProximoByteRBD (); //== int


}
