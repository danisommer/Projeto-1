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
        numero = 0x00; //numero para comparação.
        for(int i=0; i < 8/n_bits; i++) //o processo de formação de um byte varia conforme o valor de n_bits. Quanto maior for n_bits, menos repetições serão necessárias para obter o byte.
        {
            pixel = pegaProximoPixel();
            aux = pixel; //guarda o valor original de 'pixel' para poder utilizá-lo no encerramento do loop (aux != 0xFFFFFFFF), sem ser prejudicado pela manipulação da variável "pixel".

            pixel = pixel >> (8-n_bits);
            pixel = pixel << (8-n_bits); //desloca o pixel para que todos os valores fora do número máximo delimitado por n_bits seja transformado em 0.
            pixel = pixel >> (n_bits*i); //desloca o pixel para que não haja uma mistura entre os bits de cada pixel na hora que for juntá-los.
            pixel = pixel | numero; //operação para juntar os bits
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
