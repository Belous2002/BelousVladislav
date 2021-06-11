#define N 20
int main( void )
{
  double mas[N] [N + 1];
  double x[N]; 
  int otv[N]; 
  int i, j, k, n;
  
  clrscr();
  do
  {
    printf( "Введите число уравнений системы: " );
    scanf( "%d", & n );
    if ( N < n )
      printf( "Слишком большое число уравнений. Повторите ввод\n" );
  }
  while ( N < n );
  printf( "Введите систему:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n + 1; j++ )
      scanf( "%lf", & mas[i] [j] );
  
  clrscr();
  printf( "Система:\n" );
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n + 1; j++ )
      printf( "%7.2f ", mas[i] [j] );
    printf( "\n" );
  }
  
  for ( i = 0; i < n + 1; i++ )
    otv[i] = i;
  
  for ( k = 0; k < n; k++ )
  { 
    glavelem( k, mas, n, otv ); 
    if ( fabs( mas[k] [k] ) < 0.0001 )
    {
      printf( "Система не имеет единственного решения" );
      return ( 0 );
    }
    for ( j = n; j >= k; j-- )
      mas[k] [j] /= mas[k] [k];
    for ( i = k + 1; i < n; i++ )
      for ( j = n; j >= k; j-- )
        mas[i] [j] -= mas[k] [j] * mas[i] [k];
  }
  
  for ( i = 0; i < n; i++ )
    x[i] = mas[i] [n];
  for ( i = n - 2; i >= 0; i-- )
    for ( j = i + 1; j < n; j++ )
      x[i] -= x[j] * mas[i] [j];
  
  printf( "Ответ:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      if ( i == otv[j] )
      { 
        printf( "%f\n", x[j] );
        break;
      }
  return ( 0 );
}

void glavelem( int k, double mas[] [N + 1], int n, int otv[] )
{
  int i, j, i_max = k, j_max = k;
  double temp;
 
  for ( i = k; i < n; i++ )
    for ( j = k; j < n; j++ )
      if ( fabs( mas[i_max] [j_max] ) < fabs( mas[i] [j] ) )
      {
        i_max = i;
        j_max = j;
      }
  
  for ( j = k; j < n + 1; j++ )
  {
    temp = mas[k] [j];
    mas[k] [j] = mas[i_max] [j];
    mas[i_max] [j] = temp;
  }
  
  for ( i = 0; i < n; i++ )
  {
    temp = mas[i] [k];
    mas[i] [k] = mas[i] [j_max];
    mas[i] [j_max] = temp;
  }
  
  i = otv[k];
  otv[k] = otv[j_max];
  otv[j_max] = i;
}
