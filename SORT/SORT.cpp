#include <stdio.h>

int main()
{
  int numero;
  int ElencoNumeri[1000] = {0};
  int max = 0;

  scanf("%d", &numero);

  while( numero != -1 )
    {
      ElencoNumeri[numero] += 1;
      scanf("%d", &numero);
      if( numero > max )
        max = numero+1;
    }

  for( int i = 0; i < max; ++i )
    {
      if( ElencoNumeri[i] != 0 )
        {
          if( ElencoNumeri[i] == 1 )
            printf("%d\n", i );
          else
            {
              for( int j = 0; j < ElencoNumeri[i]; ++j)
                printf("%d\n", i );
            }
        }
    }

  return 0;

}
