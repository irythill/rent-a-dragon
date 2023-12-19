#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rent.h"
#include "dragon.h"
#include "warrior.h"

Rent *rentals;

int qtyRnt = 0;
int actualRent = 1;
int MAX_R = 3;

int initRent()
{
  rentals = (Rent *)malloc(MAX_R * sizeof(Rent));
  if (rentals == NULL)
  {
    return 0;
  }

  int i;
  for (i = 0; i < MAX_R; i++)
  {
    rentals[i].code = -1;
  }

  return 1;
}

int saveRent(Rent r)
{
  if (isWarriorRent(r.codeWarrior) == 1)
  {
    return 5;
  }

  if (checkWarriorByCode(r.codeWarrior) == 0)
  {
    return 4;
  }

  if (checkDragonByCode(r.codeDragon) == 0)
  {
    return 3;
  }

  // Dragon d;

  // if (d.stock == 0)
  // {
  //   return 2;
  // }

  if (qtyRnt == MAX_R)
  {
    increaseRent(r);
  }
  r.code = actualRent++;
  rentals[qtyRnt] = r;
  qtyRnt++;
  return 1;
}

int qtyRentals()
{
  return qtyRnt;
}

int deleteRentByCode(int code)
{
  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    if (rentals[i].code == code)
    {
      rentals[i] = rentals[qtyRnt - 1];
      rentals[qtyRnt - 1].code = 0;
      qtyRnt--;
      return 1;
      decreaseRent();
    }
  }
  return 0;
}

int getRentByIndex(int index, Rent *r)
{
  *r = rentals[index];
  return 1;
}

int findRentByCode(int code, Rent *r)
{
  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    *r = rentals[i];
    if (r->code == code)
    {
      return 1;
    }
  }
  return 0;
}

int checkRentByCode(int code)
{
  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    if (rentals[i].code == code)
    {
      return 1;
    }
  }
  return 0;
}

int isWarriorRent(int codeWarrior)
{
  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    if (rentals[i].codeWarrior == codeWarrior)
    {
      return 1;
    }
  }
  return 0;
}

int isDragonRent(int codeDragon)
{
  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    if (rentals[i].codeDragon == codeDragon)
    {
      return 1;
    }
  }
  return 0;
}

void increaseRent(Rent r)
{
  MAX_R++;
  Rent *backup = (Rent *)realloc(rentals, MAX_R * sizeof(Rent));

  if (backup != NULL)
  {
    rentals = backup;
    saveRent(r);
  }
  else
  {
    MAX_R--;
  }
}

int decreaseRent()
{
  if (qtyRnt <= (MAX_R * 0.4))
  {
    Rent *backup = (Rent *)realloc(rentals, MAX_R / 2 * sizeof(Rent));
    if (backup != NULL)
    {
      rentals = backup;
      return 1;
    }
    else
    {
      free(backup);
      return 0;
    }
  }
}

int finishRent()
{
  free(rentals);
  rentals = NULL;
}

int updateRent(Rent r)
{
  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    if (rentals[i].code == r.code)
    {
      rentals[i] = r;
      return 1;
    }
  }
  return 0;
}