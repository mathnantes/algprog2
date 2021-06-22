#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// prototipo da funcao polinomio
float polinomio(float x, int n, float a[MAX]);

int
main()
{
    int k;
    scanf("%d", &k); // input do numero de casos de teste

    if (k <= 0)
      exit(0);

    scanf("\n"); // o scanf do "k" estava bugando, consegui solucionar com esse segundo scanf

    for (int y = 0; y < k; y++)
    {
      int aSize = 1;
      float* a = (float*)malloc(aSize * sizeof(float)); // tamanho inicial do vetor
      char buffer[10000];
      int pos, bytes_read;
      float num;
      int num_read = 0;

      // solucao que encontrei para ler o tamanho do vetor e a quantidade de elementos no mesmo scanf
      if (fgets(buffer, sizeof(buffer), stdin) != 0)
      {
        for (pos = 0; sscanf(buffer+pos, "%f%n", &num, &bytes_read) != EOF; pos += bytes_read)
        {
            // altera o valor do vetor de acordo com a quantidade de elementos inseridos logo no comeco
            if (num_read >= aSize)
            {
                aSize += 1;
                a = (float*)realloc(a, aSize * sizeof(float));
            }

            // guarda os valores no vetor
            a[num_read] = num;
            num_read++;
        }
      }

      float x = a[0];
      int n = a[1];
      int bSize = num_read - 2;
      float b[bSize];
      float valor;

      // passa os coeficientes reais para um vetor secundario que sera utilizado na funcao polinomio
      for (int i = 0; i < bSize; i++)
        b[i] = a[i+2];

      valor = polinomio(x, n, b);

      printf("%f\n", valor);

      free(a); // limpa a memoria

    }

    return 0;
}

// funcao recursiva para calculo do valor do polinomio usando a regra de Horner
float
polinomio(float x, int n, float a[MAX])
{
  float valor = 0;
  int p;

  for (p = n-1; p > 0; p--)
  {
    valor = (valor + a[p]) * x;
  }
  valor = valor + a[0];

  return valor;
}
