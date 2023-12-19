#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "dragon.h"

Element elements;

int qtyElm = 0;
int actualElement = 0;
int MAX_E = 3;

FILE *elm;

int initElement()
{
  elm = fopen("element.txt", "r+b");
  if (elm == NULL)
  {
    printf("ERROR\n\n!");
    system("pause");
    exit(1);
  }
  fseek(elm, 0, SEEK_END);
  int size = ftell(elm);
  qtyElm = size / sizeof(Element);
  fseek(elm, 0, SEEK_SET);

  int i;
  Element e;
  for (i = 0; i < qtyElm; i++)
  {
    fread(&e, sizeof(Element), 1, elm);
    if (e.code > actualElement)
    {
      actualElement = e.code;
    }
  }
  actualElement++;

  /*------------------------------------------------------*/

  // elements = (Element *)malloc(MAX_E * sizeof(Element));

  // if (elements == NULL)
  // {
  // return 0;
  // }

  // int i;
  // for (i = 0; i < MAX_E; i++)
  // {
  // elements[i].code = -1;
  // strcpy(elements[i].name, "");
  // strcpy(elements[i].vulnerability, "");
  // }
  // elements->code = actualElement++;
  // strcpy(elements->name, "Osorio");
  // strcpy(elements->vulnerability, "Vento");
  // qtyElm++;

  // return 1;
}

int saveElement(Element e)
{
  e.code = actualElement++;
  fseek(elm, 0, SEEK_END);
  fwrite(&e, sizeof(Element), 1, elm);
  qtyElm++;
  return 1;

  /*------------------------------------------------------*/

  // if (qtyElm == MAX_E)
  // {
  // increaseElement(e);
  // }
  // e.code = actualElement++;
  // elements[qtyElm] = e;
  // qtyElm++;
  // return 1;
}

int qtyElements()
{
  return qtyElm;
}

int deleteElementByCode(int code)
{
  FILE *de;
  Element dlte;

  de = fopen("tempElm", "w+b");
  rewind(elm);

  if ((elm == NULL) || (de == NULL))
  {
    printf("ERROR!\n\n");
  }
  else
  {
    fflush(elm);
    while (fread(&dlte, sizeof(Element), 1, elm) == 1)
    {
      if (code != dlte.code)
      {
        fwrite(&dlte, sizeof(Element), 1, de);
        qtyElm--;
      }
    }
  }

  fclose(elm);
  fclose(de);

  remove("element.txt");
  rename("tempElm", "element.txt");

  elm = fopen("element.txt", "r+b");
  return 1;

  /*------------------------------------------------------*/

  // if (checkDragonByElementCode(code) == 1)
  // {
  // return 2;
  // }

  // int i;
  // for (i = 0; i < qtyElm; i++)
  // {
  // if (elements[i].code == code)
  // {
  // elements[i] = elements[qtyElm - 1];
  // elements[qtyElm - 1].code = 0;
  // qtyElm--;
  // return 1;
  // decreaseElement();
  // }
  // }
  // return 0;
}

int getElementByIndex(int index, Element *e)
{
  fseek(elm, index * sizeof(Element), SEEK_SET);
  fread(e, sizeof(Element), 1, elm);
  rewind(elm);
  return 1;

  /*------------------------------------------------------*/

  // *e = elements[index];
  // return 1;
}

int findElementByCode(int code, Element *e)
{
  Element ec;
  rewind(elm);
  fseek(elm, 0, SEEK_CUR);

  int i;
  for (i = 0; i < qtyElm; i++)
  {
    fread(&ec, sizeof(Element), 1, elm);
    if (code == ec.code)
    {
      *e = ec;
      return 1;
    }
  }

  /*------------------------------------------------------*/

  // int i;
  // for (i = 0; i < qtyElm; i++)
  // {
  // *e = elements[i];
  // if (e->code == code)
  // {
  // return 1;
  // }
  // }
  // return 0;
}

void increaseElement(Element e)
{
  // MAX_E++;
  // Element *backup = (Element *)realloc(elements, MAX_E * sizeof(Element));

  // if (backup != NULL)
  // {
  // elements = backup;
  // }
  // else
  // {
  // MAX_E--;
  // }
}

int decreaseElement()
{
  // if (qtyElm <= (MAX_E * 0.4))
  // {
  // Element *backup = (Element *)realloc(elements, MAX_E / 2 * sizeof(Element));
  // if (backup != NULL)
  // {
  // elements = backup;
  // return 1;
  // }
  // else
  // {
  // free(backup);
  // return 0;
  // }
  // }
}

int finishElement()
{
  fclose(elm);

  /*------------------------------------------------------*/

  // free(elements);
  // elements = NULL;
}

int updateElement(Element e)
{
  FILE *ue;
  Element upde;

  ue = fopen("newElm.txt", "w+b");
  rewind(elm);

  while (fread(&upde, sizeof(Element), 1, elm) == 1)
  {
    if (upde.code != e.code)
    {
      fwrite(&upde, sizeof(Element), 1, ue);
    }
    else
    {
      fwrite(&e, sizeof(Element), 1, ue);
    }
  }

  fclose(elm);
  fclose(ue);

  remove("element.txt");
  rename("newElm.txt", "element.txt");

  elm = fopen("element.txt", "r+b");
  return 1;

  /*------------------------------------------------------*/

  // int i;
  // for (i = 0; i < qtyElm; i++)
  // {
  // if (elements[i].code == e.code)
  // {
  // elements[i] = e;
  // return 1;
  // }
  // }
  // return 0;
}
