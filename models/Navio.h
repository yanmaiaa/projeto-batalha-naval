#ifndef NAVIO_H
#define NAVIO_H

#define TAMANHO_NAVIO 5

typedef struct
{
  int x;
  int y;
} Ponto;

typedef struct
{
  Ponto posicao_inicial;
  int tamanho;
  int orientacao; 
  int vida;      
} Ship;

// Funções para criar e manipular navios
Ship criar_navio(int x, int y, int tamanho, int orientacao);
int verificar_impacto(Ship *navio, int x, int y);

#endif
