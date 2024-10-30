#include "utils.h"
#include <stdio.h>

int ler_inteiro(const char *mensagem)
{
  int valor;
  printf("%s", mensagem);
  scanf("%d", &valor);
  return valor;
}

int coordenada_valida(int x, int y)
{
  return x >= 0 && x < 10 && y >= 0 && y < 10;
}
