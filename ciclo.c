#include <stdio.h>

int
ciclo (int n)
{
  int comprimento = 1;

  while (n > 1)
  {
    printf("%d ", n);

    if (n % 2 == 0)
      n = n/2;
    else
      n = n*3 + 1;

    ++comprimento;
  }

  if (n == 1)
  {
    printf("%d\n", n);
    return comprimento;
  }
  else
  {
    ciclo(n);
    return 0;
  }

}

int
main()
{
  int k, i, valor;

  scanf("%d", &k);

  for (i = 0; i < k; i++)
  {
    scanf("%d", &valor);

    printf("%d\n", ciclo(valor));
  }

  return 0;
}
