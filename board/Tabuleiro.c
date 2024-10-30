#include "Tabuleiro.h"
#include <stdio.h>

void inicializar_tabuleiro(Board *tabuleiro)
{
  for (int i = 0; i < TAMANHO_TABULEIRO; i++)
  {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++)
    {
      tabuleiro->grid[i][j] = '~'; // Inicializa o oceano como vazio
    }
  }
  tabuleiro->total_navios = 0;
}

void posicionar_navio(Board *tabuleiro, Ship navio)
{
  for (int i = 0; i < navio.tamanho; i++)
  {
    int x = navio.posicao_inicial.x + (navio.orientacao == 0 ? i : 0);
    int y = navio.posicao_inicial.y + (navio.orientacao == 1 ? i : 0);
    tabuleiro->grid[x][y] = 'N';
  }
  tabuleiro->navios[tabuleiro->total_navios++] = navio;
}

int fazer_jogada(Board *tabuleiro, int x, int y)
{
  if (tabuleiro->grid[x][y] == '~')
  {
    tabuleiro->grid[x][y] = 'O'; // Erro
    return 0;
  }
  else if (tabuleiro->grid[x][y] == 'N')
  {
    tabuleiro->grid[x][y] = 'X'; // Acerto

    for (int i = 0; i < tabuleiro->total_navios; i++)
    {
      if (verificar_impacto(&tabuleiro->navios[i], x, y))
      {
        if (tabuleiro->navios[i].vida == 0)
        {
          printf("Navio afundado!\n");
        }
        return 1; // Acerto
      }
    }
  }
  return -1;
}

void exibir_tabuleiro(Board *tabuleiro, int revelar_navios)
{
  for (int i = 0; i < TAMANHO_TABULEIRO; i++)
  {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++)
    {
      char simbolo = tabuleiro->grid[i][j];
      if (simbolo == 'N' && !revelar_navios)
      {
        simbolo = '~'; // Oculta navios se "revelar_navios" for falso
      }
      printf("%c ", simbolo);
    }
    printf("\n");
  }
}
