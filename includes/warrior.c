#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "warrior.h"
#include "rent.h"

Warrior *warriors;

int qtyWar = 0;
int actualWarrior = 1;
int MAX_W = 3;

int initWarrior()
{
  warriors = (Warrior *)malloc(MAX_W * sizeof(Warrior));
  if (warriors == NULL)
  {
    return 0;
  }

  int i;
  for (i = 0; i < MAX_W; i++)
  {
    warriors[i].code = -1;
  }
  warriors->code = actualWarrior++;
  strcpy(warriors->name, "Ragnar Lothbrok");
  strcpy(warriors->kingdom, "Kattegat");
  strcpy(warriors->title, "Jarl");
  qtyWar++;

  return 1;
}

int saveWarrior(Warrior w)
{
  if (qtyWar == MAX_W)
  {
    increaseWarrior(w);
  }

  w.code = actualWarrior++;
  warriors[qtyWar] = w;
  qtyWar++;
  return 1;
}

int qtyWarriors()
{
  return qtyWar;
}

int deleteWarriorByCode(int code)
{
  int i;

  if (isWarriorRent(code) == 1)
  {
    return 2;
  }

  for (i = 0; i < qtyWar; i++)
  {
    if (warriors[i].code == code)
    {
      warriors[i] = warriors[qtyWar - 1];
      warriors[qtyWar - 1].code = 0;
      qtyWar--;
      return 1;
      decreaseWarrior();
    }
  }
  return 0;
}

int getWarriorByIndex(int index, Warrior *w)
{
  *w = warriors[index];
  return 1;
}

int findWarriorByCode(int code, Warrior *w)
{
  int i;
  for (i = 0; i < qtyWar; i++)
  {
    *w = warriors[i];
    if (w->code == code)
    {
      return 1;
    }
  }
  return 0;
}

int checkWarriorByCode(int code)
{
  int i;
  for (i = 0; i < qtyWar; i++)
  {
    if (warriors[i].code == code)
    {
      return 1;
    }
  }
  return 0;
}

void increaseWarrior(Warrior w)
{
  MAX_W++;
  Warrior *backup = (Warrior *)realloc(warriors, MAX_W * sizeof(Warrior));

  if (backup != NULL)
  {
    warriors = backup;
  }
  else
  {
    MAX_W--;
  }
}

int decreaseWarrior()
{
  if (qtyWar <= (MAX_W * 0.4))
  {
    Warrior *backup = (Warrior *)realloc(warriors, MAX_W / 2 * sizeof(Warrior));
    if (backup != NULL)
    {
      warriors = backup;
      return 1;
    }
    else
    {
      free(backup);
      return 0;
    }
  }
}

int finishWarrior()
{
  free(warriors);
  warriors = NULL;
}

int updateWarrior(Warrior w)
{
  int i;
  for (i = 0; i < qtyWar; i++)
  {
    if (warriors[i].code == w.code)
    {
      warriors[i] = w;
      return 1;
    }
  }
  return 0;
}