#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

int calc_fft()
{
  int i = 0; 
  double data[2*64];

  for (i = 0; i < 64; i++)
    {
       REAL(data,i) = 0.0; 
       IMAG(data,i) = 0.0;
    }

  REAL(data,0) = 1.0;

  for (i = 1; i <= 10; i++)
    {
       REAL(data,i) = 1.0;
       REAL(data,64-i) = 1.0;
    }

  for (i = 0; i < 64; i++)
    {
      printf ("%d %e %e\n", i,
              REAL(data,i), IMAG(data,i));
    }
  printf ("\n\n");

  gsl_fft_complex_radix2_forward (data, 1, 64);

  for (i = 0; i < 64; i++)
    {
      printf ("%d %e %e\n", i,
              REAL(data,i)/sqrt(64),
              IMAG(data,i)/sqrt(64));
    }

  return 0;
}

#ifndef MODELONE_LIB
int main()
{
    calc_fft();
}
#endif
