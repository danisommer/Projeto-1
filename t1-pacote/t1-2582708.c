#include "trabalho1.h"

void codificaStreamImagem (int n_bits){ //n_bits deve ser 4, 2 ou 1

    int numero, pixel, aux;

    while (aux != 0xFFFFFFFF)
    {
        numero = 0x00;
        for(int i=0; i < 8/n_bits; i++)
        {
            pixel = pegaProximoPixel();
            aux = pixel;

            pixel = pixel >> (8-n_bits);
            pixel = pixel << (8-n_bits);
            pixel = pixel >> (n_bits*i);
            pixel = pixel | numero;
            numero = pixel;

        }
        enviaByteRBD(pixel);
    }

}
void decodificaStreamRBD (int n_bits, int preenche){










}

/*

void enviaPixel (unsigned char pixel);
unsigned int pegaProximoByteRBD ();


*/
