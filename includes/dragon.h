typedef struct
{
  int code;
  int elementCode;
  char name[30];
  int age;
  float dailyValue;
  int stock;
} Dragon;

int initDragon();
int saveDragon(Dragon d);
int qtyDragons();
int deleteDragonByCode(int code);
int getDragonByIndex(int index, Dragon *d);
int findDragonByCode(int code, Dragon *d);
int checkDragonByCode(int code);
int checkDragonByElementCode(int elementCode);
void increaseDragon(Dragon d);
int decreaseDragon();
int finishDragon();
int updateDragon();
int increaseStock(int code);
int decreaseStock(int code);