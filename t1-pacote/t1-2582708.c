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

    int pixel, aux, numero;

    while (aux != 0xFFFFFFFF)
    {
        numero = 0xFF; //numero para comparação.
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
        enviaByteRBD(pixel); //envia o byte final para ser implementado.
    }

}
void decodificaStreamRBD (int n_bits, int preenche)
{
    int byte, aux, copiaByte, posicao;

    while (aux != 0xFFFFFFFF)
    {

        byte = pegaProximoByteRBD();
        aux = byte; //repete o mesmo processo da função acima.
        posicao=1;

        for(int i=0; i < 8/n_bits; i++)
        {

            copiaByte = byte; //coleta uma cópia do byte para não haver perda de dados

            copiaByte = copiaByte >> 8-n_bits*posicao; //desloca os bits de acordo com n_bits e a posição deles no byte (j define essa posição).
            copiaByte = copiaByte << 8-n_bits; //desloca os bits de acordo com n_bits, apenas.

            enviaPixel(copiaByte); //envia o pixel final para ser implementado.
            posicao++; //vai para a posição do próximo fragmento.
        }
    }
}
