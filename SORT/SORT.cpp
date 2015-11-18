#include <iostream>

int main()
{

  int numero;
  int ElencoNumeri[1000] = {0};
  int max = 0;

  std::cin >> numero;

  while( numero != -1 )
    {
      ElencoNumeri[numero] += 1;
      std::cin >>numero;
      if( numero > max )
        max = numero+1;
    }

  for( int i = 0; i < max; i++ )
    {
      if( ElencoNumeri[i] != 0 )
        {
          if( ElencoNumeri[i] == 1 )
            std::cout << i << std::endl;
          else
            {
              for( int j = 0; j < ElencoNumeri[i]; j++)
                std::cout << i << std::endl;
            }
        }
    }

  return 0;

}
