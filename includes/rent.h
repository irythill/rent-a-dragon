typedef struct
{
  int code;
  int codeWarrior;
  int codeDragon;
  float paid;
  char rentalStart[30];
  char rentalEnd[30];
} Rent;

int initRent();
int saveRent(Rent r);
int qtyRentals();
int deleteRentByCode(int code);
int getRentByIndex(int index, Rent *r);
int findRentByCode(int code, Rent *r);
int checkRentByCode(int code);
int isWarriorRent(int codeWarrior);
int isDragonRent(int codeDragon);
void increaseRent(Rent r);
int decreaseRent();
int finishRent();
int updateRent();