#ifndef TABULEIRO
#define TABULEIRO

#include "../models/Navio.h"

#define TAMANHO_TABULEIRO 10
#define MAX_NAVIOS 5

typedef struct
{
  char grid[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  Ship navios[MAX_NAVIOS];
  int total_navios;
} Board;

void inicializar_tabuleiro(Board *tabuleiro);
void posicionar_navio(Board *tabuleiro, Ship navio);
int fazer_jogada(Board *tabuleiro, int x, int y);
void exibir_tabuleiro(Board *tabuleiro, int revelar_navios);

#endif
