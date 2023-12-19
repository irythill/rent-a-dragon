typedef struct
{
  int code;
  char kingdom[30];
  char name[30];
  char title[30];
} Warrior;

int initWarrior();
int saveWarrior(Warrior w);
int qtyWarriors();
int getWarriorByIndex(int index, Warrior *w);
int findWarriorByCode(int code, Warrior *w);
int deleteWarriorByCode(int code);
int checkWarriorByCode(int code);
int finishWarrior();
void increaseWarrior();
int decreaseWarrior();
int updateWarrior();