#include "Navio.h"

Ship criar_navio(int x, int y, int tamanho, int orientacao)
{
  Ship navio;
  navio.posicao_inicial.x = x;
  navio.posicao_inicial.y = y;
  navio.tamanho = tamanho;
  navio.orientacao = orientacao;
  navio.vida = tamanho; // A vida inicial é igual ao tamanho do navio
  return navio;
}

int verificar_impacto(Ship *navio, int x, int y)
{
  for (int i = 0; i < navio->tamanho; i++)
  {
    int posX = navio->posicao_inicial.x + (navio->orientacao == 0 ? i : 0);
    int posY = navio->posicao_inicial.y + (navio->orientacao == 1 ? i : 0);

    if (posX == x && posY == y)
    {
      navio->vida--;
      return 1; // Retorna 1 se for atingido
    }
  }
  return 0; // Retorna 0 se não for atingido
}
