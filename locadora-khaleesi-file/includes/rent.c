#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rent.h"
#include "dragon.h"
#include "warrior.h"

Rent rentals;

FILE *rnt;

int qtyRnt = 0;
int actualRent = 0;
int MAX_R = 3;

int initRent()
{
  rnt = fopen("rent.txt", "r+b");
  if (rnt == NULL)
  {
    printf("ERROR\n\n!");
    system("pause");
    exit(1);
  }
  fseek(rnt, 0, SEEK_END);
  int size = ftell(rnt);
  qtyRnt = size / sizeof(Rent);
  fseek(rnt, 0, SEEK_SET);

  int i;
  Rent r;
  for (i = 0; i < qtyRnt; i++)
  {
    fread(&r, sizeof(Rent), 1, rnt);
    if (r.code > actualRent)
    {
      actualRent = r.code;
    }
  }
  actualRent++;

  /*------------------------------------------------------*/

  // rentals = (Rent *)malloc(MAX_R * sizeof(Rent));
  // if (rentals == NULL)
  // {
  // return 0;
  // }

  // int i;
  // for (i = 0; i < MAX_R; i++)
  // {
  // rentals[i].code = -1;
  // }

  // return 1;
}

int saveRent(Rent r)
{
  r.code = actualRent++;
  fseek(rnt, 0, SEEK_END);
  fwrite(&r, sizeof(Rent), 1, rnt);
  qtyRnt++;
  return 1;

  /*------------------------------------------------------*/

  // if (isWarriorRent(r.codeWarrior) == 1)
  // {
  // return 5;
  // }

  // if (checkWarriorByCode(r.codeWarrior) == 0)
  // {
  // return 4;
  // }

  // if (checkDragonByCode(r.codeDragon) == 0)
  // {
  // return 3;
  // }

  // Dragon d;

  // if (d.stock == 0)
  // {
  //   return 2;
  // }

  // if (qtyRnt == MAX_R)
  // {
  // increaseRent(r);
  // }
  // r.code = actualRent++;
  // rentals[qtyRnt] = r;
  // qtyRnt++;
  // return 1;
}

int qtyRentals()
{
  return qtyRnt;
}

int deleteRentByCode(int code)
{
  FILE *dr;
  Rent dltr;

  dr = fopen("tempRnt", "w+b");
  rewind(rnt);

  if ((rnt == NULL) || (dr == NULL))
  {
    printf("ERROR!\n\n");
  }
  else
  {
    fflush(rnt);
    while (fread(&dltr, sizeof(Rent), 1, rnt) == 1)
    {
      if (code != dltr.code)
      {
        fwrite(&dltr, sizeof(Rent), 1, dr);
        qtyRnt--;
      }
    }
  }

  fclose(rnt);
  fclose(dr);

  remove("rent.txt");
  rename("tempRnt", "rent.txt");

  rnt = fopen("rent.txt", "r+b");
  return 1;

  /*------------------------------------------------------*/

  // int i;
  // for (i = 0; i < qtyRnt; i++)
  // {
  // if (rentals[i].code == code)
  // {
  // rentals[i] = rentals[qtyRnt - 1];
  // rentals[qtyRnt - 1].code = 0;
  // qtyRnt--;
  // return 1;
  // decreaseRent();
  // }
  // }
  // return 0;
}

int getRentByIndex(int index, Rent *r)
{
  fseek(rnt, index * sizeof(Rent), SEEK_SET);
  fread(r, sizeof(Rent), 1, rnt);
  rewind(rnt);
  return 1;

  /*------------------------------------------------------*/

  // *r = rentals[index];
  // return 1;
}

int findRentByCode(int code, Rent *r)
{
  Rent rc;
  rewind(rnt);
  fseek(rnt, 0, SEEK_CUR);

  int i;
  for (i = 0; i < qtyRnt; i++)
  {
    fread(&rc, sizeof(Rent), 1, rnt);
    if (code == rc.code)
    {
      *r = rc;
      return 1;
    }
  }

  /*------------------------------------------------------*/

  // int i;
  // for (i = 0; i < qtyRnt; i++)
  // {
  // *r = rentals[i];
  // if (r->code == code)
  // {
  // return 1;
  // }
  // }
  // return 0;
}

int checkRentByCode(int code)
{
  // int i;
  // for (i = 0; i < qtyRnt; i++)
  // {
  // if (rentals[i].code == code)
  // {
  // return 1;
  // }
  // }
  // return 0;
}

int isWarriorRent(int codeWarrior)
{
  // int i;
  // for (i = 0; i < qtyRnt; i++)
  // {
  // if (rentals[i].codeWarrior == codeWarrior)
  // {
  // return 1;
  // }
  // }
  // return 0;
}

int isDragonRent(int codeDragon)
{
  // int i;
  // for (i = 0; i < qtyRnt; i++)
  // {
  // if (rentals[i].codeDragon == codeDragon)
  // {
  // return 1;
  // }
  // }
  // return 0;
}

void increaseRent(Rent r)
{
  // MAX_R++;
  // Rent *backup = (Rent *)realloc(rentals, MAX_R * sizeof(Rent));

  // if (backup != NULL)
  // {
  // rentals = backup;
  // saveRent(r);
  // }
  // else
  // {
  // MAX_R--;
  // }
}

int decreaseRent()
{
  // if (qtyRnt <= (MAX_R * 0.4))
  // {
  // Rent *backup = (Rent *)realloc(rentals, MAX_R / 2 * sizeof(Rent));
  // if (backup != NULL)
  // {
  // rentals = backup;
  // return 1;
  // }
  // else
  // {
  // free(backup);
  // return 0;
  // }
  // }
}

int finishRent()
{
  fclose(rnt);

  /*------------------------------------------------------*/

  // free(rentals);
  // rentals = NULL;
}

int updateRent(Rent r)
{
  FILE *ur;
  Rent updr;

  ur = fopen("newRnt.txt", "w+b");
  rewind(rnt);

  while (fread(&updr, sizeof(Rent), 1, rnt) == 1)
  {
    if (updr.code != r.code)
    {
      fwrite(&updr, sizeof(Rent), 1, ur);
    }
    else
    {
      fwrite(&r, sizeof(Rent), 1, ur);
    }
  }

  fclose(rnt);
  fclose(ur);

  remove("rent.txt");
  rename("newRnt.txt", "rent.txt");

  rnt = fopen("rent.txt", "r+b");
  return 1;

  /*------------------------------------------------------*/

  // int i;
  // for (i = 0; i < qtyRnt; i++)
  // {
  // if (rentals[i].code == r.code)
  // {
  // rentals[i] = r;
  // return 1;
  // }
  // }
  // return 0;
}
