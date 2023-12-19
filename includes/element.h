typedef struct
{
  int code;
  char name[30];
  char vulnerability[30];
} Element;

int initElement();
int saveElement(Element e);
int qtyElements();
int checkElementCode(int code);
int deleteElementByCode(int code);
int getElementByIndex(int index, Element *e);
int findElementByCode(int code, Element *e);
int finishElement();
void increaseElement(Element e);
int decreaseElement();
int updateElement();