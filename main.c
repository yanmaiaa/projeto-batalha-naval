#include "board/Tabuleiro.h"
#include "utils/utils.h"
#include <stdio.h>

int main()
{
  Board jogador1, jogador2;
  inicializar_tabuleiro(&jogador1);
  inicializar_tabuleiro(&jogador2);

  printf("Bem-vindo ao jogo de Batalha Naval!\n");

  printf("Jogador 1, posicione seus navios:\n");
  for (int i = 0; i < MAX_NAVIOS; i++)
  {
    int x = ler_inteiro("Informe a posição inicial X do navio: ");
    int y = ler_inteiro("Informe a posição inicial Y do navio: ");
    int orientacao = ler_inteiro("Informe a orientação do navio (0 = horizontal, 1 = vertical): ");

    if (coordenada_valida(x, y))
    {
      Ship navio = criar_navio(x, y, TAMANHO_NAVIO, orientacao);
      posicionar_navio(&jogador1, navio);
    }
    else
    {
      printf("Coordenadas inválidas! Tente novamente.\n");
      i--; // Repete a tentativa para corrigir o erro
    }
  }

  printf("Jogador 2, posicione seus navios:\n");
  for (int i = 0; i < MAX_NAVIOS; i++)
  {
    int x = ler_inteiro("Informe a posição inicial X do navio: ");
    int y = ler_inteiro("Informe a posição inicial Y do navio: ");
    int orientacao = ler_inteiro("Informe a orientação do navio (0 = horizontal, 1 = vertical): ");

    if (coordenada_valida(x, y))
    {
      Ship navio = criar_navio(x, y, TAMANHO_NAVIO, orientacao);
      posicionar_navio(&jogador2, navio);
    }
    else
    {
      printf("Coordenadas inválidas! Tente novamente.\n");
      i--; // Repete a tentativa para corrigir o erro
    }
  }

  // Loop de turnos
  int turno = 1;
  while (1)
  {
    int x, y;
    Board *tabuleiro_atual = (turno % 2 == 1) ? &jogador2 : &jogador1;
    int jogador_atual = (turno % 2 == 1) ? 1 : 2;

    printf("Tabuleiro do oponente:\n");
    exibir_tabuleiro(tabuleiro_atual, 0);

    printf("Jogador %d, faça sua jogada:\n", jogador_atual);
    x = ler_inteiro("Informe a coordenada X: ");
    y = ler_inteiro("Informe a coordenada Y: ");

    if (coordenada_valida(x, y))
    {
      int resultado = fazer_jogada(tabuleiro_atual, x, y);
      if (resultado == 1)
      {
        printf("Acertou!\n");
      }
      else if (resultado == 0)
      {
        printf("Água!\n");
      }

      // Verifica se todos os navios do oponente foram destruídos
      int navios_restantes = 0;
      for (int i = 0; i < tabuleiro_atual->total_navios; i++)
      {
        if (tabuleiro_atual->navios[i].vida > 0)
        {
          navios_restantes++;
        }
      }

      if (navios_restantes == 0)
      {
        printf("Parabéns, Jogador %d! Você venceu o jogo!\n", jogador_atual);
        break;
      }

      turno++;
    }
    else
    {
      printf("Coordenadas inválidas! Tente novamente.\n");
    }
  }

  return 0;
}
