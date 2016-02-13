#include <stdio.h>
int main()
{
  int numero;
  int ElencoNumeri[100000];
  int max = 0;

  scanf("%d", &numero);

  while( numero != -1 )
    {
      if( ElencoNumeri[numero] >= 1 && ElencoNumeri[numero] <= 100000)
        {
          ElencoNumeri[numero] += 1;
          scanf("%d", &numero);
          if( numero > max )
            max = numero+1;
        }
      else
        {
          ElencoNumeri[numero] += 1;
          scanf("%d", &numero);
        }

    }

  for( int i = 0; i < max; ++i )
    {
      if( ElencoNumeri[i] != 0 )
        {
          for( int j = 0; j < ElencoNumeri[i]; ++j)
            printf("%d\n", i );
        }
    }

  return 0;
}
