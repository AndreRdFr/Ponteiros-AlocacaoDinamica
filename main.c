#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers, int size); // lê todos os valores para os espaços
float numbers_average(int *numbers, int size); // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados

int numbers_largest(int *numbers, int size); // calcula o maior número e retorna o valor
int numbers_smallest(int *numbers, int size); // calcula o menor número e retorna o valor
void numbers_even(int *numbers, int size); // exibe os valores pares
void numbers_odd(int *numbers, int size); // exibe os valores ímpares
void numbers_prime(int *numbers, int size); // identifica e exibe os valores primos

void numbers_destroy(int *numbers); // desaloca a variável alocada
// **************************************************************************

// **************************** Implementação ******************************

int *numbers_create(int size)
{
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}

void numbers_read(int *numbers, int size)
{
  if (numbers != NULL)
  {
    for (int i = 0; i < size; i++)
      numbers[i] = rand() % 50;
  }
}

float numbers_average(int *numbers, int size)
{
  float sum = 0.0;
  if (numbers != NULL)
    for (int i = 0; i < size; i++)
      sum += numbers[i];
  if (sum != 0)
    return sum / (float)size;
  return 0;
}

void numbers_show(int *numbers, int size)
{
  printf("[");
  if (numbers != NULL)
  {
    for (int i = 0; i < size; i++)
      if (i == (size - 1))
        printf("%d", numbers[i]);
      else
        printf("%d, ", numbers[i]);
  }
  printf("]\n");
}

// ************ Minhas funções *********************
int numbers_largest(int *numbers, int size)
{
    int maior;
    if(numbers != NULL)
    {
        maior = numbers[0];
        for(int i = 1; i < size; i++)
        {
            if(numbers[i] > maior)
                maior = numbers[i];
        }
        return maior;
    }
    return 0;
}

int numbers_smallest(int *numbers, int size)
{
    int menor;
    if(numbers != NULL)
    {
        menor = numbers[0];
        for(int i = 1; i < size; i++)
        {
            if(numbers[i] < menor)
                menor = numbers[i];
        }
        return menor;
    }
    return 0;
  }

  void numbers_even(int *numbers, int size)
{
    printf("[");
    if (numbers != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if(numbers[i] % 2 == 0)
            {
                if (i == (size - 1))
                    printf("%d", numbers[i]);
                else
                    printf("%d, ", numbers[i]);
            }
        }
    }
    printf("]\n");
}

void numbers_odd(int *numbers, int size)
{
  printf("[");
  if (numbers != NULL)
  {
    for (int i = 0; i < size; i++)
    {
      if(numbers[i] % 2 == 1)
      {
        if (i == (size - 1))
          printf("%d", numbers[i]);
          else
            printf("%d, ", numbers[i]);
      }
    }
  }
  printf("]\n");
}

void numbers_prime(int *numbers, int size)
{
    int primo;
    printf("[");
    if (numbers != NULL)
    {
        for(int i = 0; i < size; i++)
        {
            primo = 0;
            if(numbers[i] == 2)
                primo = 1;

            for(int j = 3; j <= numbers[i]; j += 2)
            {
                if(numbers[i] % j == 0 && numbers[i] % 2 == 1)
                {
                    primo++;
                }
            }
            if(primo == 1)
            {
                if(i == (size - 1))
                    printf("%d", numbers[i]);
                else
                    printf("%d, ", numbers[i]);
            }
        }
    }
    printf("]\n");
}
// *************************************************

void numbers_destroy(int *numbers) { free(numbers); }

// *************************************************************************

int main()
{
  srand(time(NULL));

  int *numbers;

  int size = rand() % 100;

  numbers = numbers_create(size);
  numbers_read(numbers, size);
  
  float avg = numbers_average(numbers, size);

  numbers_show(numbers, size);

  //Minhas funções
  int maior = numbers_largest(numbers, size);
  int menor = numbers_smallest(numbers, size);
  numbers_even(numbers, size);
  numbers_odd(numbers, size);

  printf("Media = %.2f\n", avg);
  printf("Maior = %d\n", maior);
  printf("Menor= %d\n", menor);
  numbers_prime(numbers, size);

  numbers_destroy(numbers);

  return 0;
}