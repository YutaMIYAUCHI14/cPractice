#include "kionstat.h"

double kion_heikin(double array[], int size)
{
  int i;
  double sum;

  sum = 0.0;
  for(i = 0; i < size; i++)
    {
      sum += array[i];
    }

  return sum / size;
}

double kion_max(double array[], int size)
{
  int i;
  double vmax;

  vmax = array[0];
  for(i = 1; i < size; i++)
    {
      if(array[i] > vmax)
	{
	  vmax = array[i];
	}
    }

  return vmax;
}

double kion_min(double array[], int size)
{
  int i;
  double vmin;

  vmin = array[0];
  for(i = 1; i < size; i++)
    {
      if(array[i] < vmin)
	{
	  vmin = array[i];
	}
    }

  return vmin;
}
