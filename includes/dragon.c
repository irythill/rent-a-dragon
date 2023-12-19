#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dragon.h"
#include "rent.h"
#include "element.h"

Dragon *dragons;

int qtyDrg = 0;
int actualDragon = 1;
int MAX_D = 3;

int initDragon()
{
  dragons = (Dragon *)malloc(MAX_D * sizeof(Dragon));
  if (dragons == NULL)
  {
    return 0;
  }

  int i;
  for (i = 0; i < MAX_D; i++)
  {
    dragons[i].code = -1;
  }
  dragons->code = actualDragon++;
  dragons->elementCode = 1;
  strcpy(dragons->name, "Toothless");
  dragons->age = 250;
  dragons->dailyValue = 5.50;
  dragons->stock = 2;
  qtyDrg++;

  return 1;
}

int saveDragon(Dragon d)
{
  if (qtyDrg == MAX_D)
  {
    increaseDragon(d);
  }

  d.code = actualDragon++;
  dragons[qtyDrg] = d;
  qtyDrg++;
  return 1;
}

int qtyDragons()
{
  return qtyDrg;
}

int deleteDragonByCode(int code)
{
  if (isDragonRent(code) == 1)
  {
    return 2;
  }

  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    if (dragons[i].code == code)
    {
      dragons[i] = dragons[qtyDrg - 1];
      dragons[qtyDrg - 1].code = 0;
      qtyDrg--;
      return 1;
      decreaseDragon();
    }
  }
  return 0;
}

int getDragonByIndex(int index, Dragon *d)
{
  *d = dragons[index];
  return 1;
}

int findDragonByCode(int code, Dragon *d)
{
  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    *d = dragons[i];
    if (d->code == code)
    {
      return 1;
    }
  }
  return 0;
}

int checkDragonByCode(int code)
{
  if (isDragonRent(code) == 1)
  {
    return 2;
  }

  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    if (dragons[i].code == code)
    {
      return 1;
    }
  }
  return 0;
}

int checkDragonByElementCode(int elementCode)
{
  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    if (dragons[i].elementCode == elementCode)
    {
      return 1;
    }
  }
  return 0;
}

void increaseDragon(Dragon d)
{
  MAX_D++;
  Dragon *backup = (Dragon *)realloc(dragons, MAX_D * sizeof(Dragon));

  if (backup != NULL)
  {
    dragons = backup;
  }
  else
  {
    MAX_D--;
  }
}

int decreaseDragon()
{
  if (qtyDrg <= (MAX_D * 0.4))
  {
    Dragon *backup = (Dragon *)realloc(dragons, MAX_D / 2 * sizeof(Dragon));
    if (backup != NULL)
    {
      dragons = backup;
      return 1;
    }
    else
    {
      free(backup);
      return 0;
    }
  }
}

int finishDragon()
{
  free(dragons);
  dragons = NULL;
}

int updateDragon(Dragon d)
{
  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    if (dragons[i].code == d.code)
    {
      dragons[i] = d;
      return 1;
    }
  }
  return 0;
}

int increaseStock(int code)
{
  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    Dragon d = dragons[i];
    if (d.code == code)
    {
      dragons[i].stock++;
      return 1;
    }
  }
  return 0;
}

int decreaseStock(int code)
{
  int i;
  for (i = 0; i < qtyDrg; i++)
  {
    Dragon d = dragons[i];
    if (d.code == code)
    {
      dragons[i].stock--;
      return 1;
    }
  }
  return 0;
}