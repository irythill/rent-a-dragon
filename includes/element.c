#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "dragon.h"

Element *elements;

int qtyElm = 0;
int actualElement = 1;
int MAX_E = 3;

int initElement()
{
  elements = (Element *)malloc(MAX_E * sizeof(Element));

  if (elements == NULL)
  {
    return 0;
  }

  int i;
  for (i = 0; i < MAX_E; i++)
  {
    elements[i].code = -1;
  }
  elements->code = actualElement++;
  strcpy(elements->name, "Osorio");
  strcpy(elements->vulnerability, "Vento");
  qtyElm++;

  return 1;
}

int saveElement(Element e)
{
  if (qtyElm == MAX_E)
  {
    increaseElement(e);
  }
  e.code = actualElement++;
  elements[qtyElm] = e;
  qtyElm++;
  return 1;
}

int qtyElements()
{
  return qtyElm;
}

int deleteElementByCode(int code)
{
  if (checkDragonByElementCode(code) == 1)
  {
    return 2;
  }

  int i;
  for (i = 0; i < qtyElm; i++)
  {
    if (elements[i].code == code)
    {
      elements[i] = elements[qtyElm - 1];
      elements[qtyElm - 1].code = 0;
      qtyElm--;
      return 1;
      decreaseElement();
    }
  }
  return 0;
}

int getElementByIndex(int index, Element *e)
{
  *e = elements[index];
  return 1;
}

int findElementByCode(int code, Element *e)
{
  int i;
  for (i = 0; i < qtyElm; i++)
  {
    *e = elements[i];
    if (e->code == code)
    {
      return 1;
    }
  }
  return 0;
}

void increaseElement(Element e)
{
  MAX_E++;
  Element *backup = (Element *)realloc(elements, MAX_E * sizeof(Element));

  if (backup != NULL)
  {
    elements = backup;
  }
  else
  {
    MAX_E--;
  }
}

int decreaseElement()
{
  if (qtyElm <= (MAX_E * 0.4))
  {
    Element *backup = (Element *)realloc(elements, MAX_E / 2 * sizeof(Element));
    if (backup != NULL)
    {
      elements = backup;
      return 1;
    }
    else
    {
      free(backup);
      return 0;
    }
  }
}

int finishElement()
{
  free(elements);
  elements = NULL;
}

int updateElement(Element e)
{
  int i;
  for (i = 0; i < qtyElm; i++)
  {
    if (elements[i].code == e.code)
    {
      elements[i] = e;
      return 1;
    }
  }
  return 0;
}