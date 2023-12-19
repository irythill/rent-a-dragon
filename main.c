#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/warrior.h"
#include "includes/dragon.h"
#include "includes/element.h"
#include "includes/rent.h"

/* ----- MENUS ----- */

void mainMenu()
{
  printf("KHALEESI RENT-A-DRAGON <> THE BEST DRAGON RENTAL OF ALL WESTEROS\n\n");

  printf("MAIN MENU\n");

  printf("0 - Leave\n");
  printf("1 - Warriors\n");
  printf("2 - Dragons\n");
  printf("3 - Elements\n");
  printf("4 - Rentals\n");

  printf("\nPick an option > ");
}

void warriorMenu()
{
  printf("\nWARRIOR'S MENU\n");

  printf("0 - Main menu\n");
  printf("1 - List warriors\n");
  printf("2 - Register warriors\n");
  printf("3 - Change warrior data\n");
  printf("4 - Search warriors\n");
  printf("5 - Delete warriors\n");

  printf("\nPick an option > ");
}

void dragonMenu()
{
  printf("\nDRAGON'S MENU\n");

  printf("0 - Main menu\n");
  printf("1 - List dragons\n");
  printf("2 - Register dragons\n");
  printf("3 - Change dragon data\n");
  printf("4 - Search dragons\n");
  printf("5 - Delete dragons\n");

  printf("\nPick an option > ");
}

void elementMenu()
{
  printf("\nELEMENT'S MENU\n");

  printf("0 - Main menu\n");
  printf("1 - List elements\n");
  printf("2 - Register elements\n");
  printf("3 - Change element data\n");
  printf("4 - Search elements\n");
  printf("5 - Delete elements\n");

  printf("\nPick an option > ");
}

void rentMenu()
{
  printf("\nRENTAL'S MENU\n");

  printf("0 - Main menu\n");
  printf("1 - List rentals\n");
  printf("2 - Register rentals\n");
  printf("3 - Change rental data\n");
  printf("4 - Search rentals\n");
  printf("5 - Delete rentals\n");

  printf("\nPick an option > ");
}

/* ----- LISTAR ----- */

void listWarrior()
{
  int i;
  Warrior w;
  for (i = 0; i < qtyWarriors(); i++)
  {
    if (getWarriorByIndex(i, &w) == 1)
    {
      printf("\nID: %d || NAME: %s || KINGDOM: %s || TITLE: %s\n",
             w.code,
             w.name,
             w.kingdom,
             w.title);
    }
  }
  if (qtyWarriors() == 0)
  {
    printf("\nNO WARRIOR REGISTERED!\n\n");
  }
}

void listDragon()
{
  int i;
  Dragon d;
  Element e;

  for (i = 0; i < qtyDragons(); i++)
  {
    if (getDragonByIndex(i, &d) == 1)
    {
      findElementByCode(d.elementCode, &e);
      printf("\nID: %d || NAME: %s || AGE: %d || DAILY VALUE: %.2f || STOCK: %d || ELEMENT: %s || VULNERABILITY: %s\n",
             d.code,
             d.name,
             d.age,
             d.dailyValue,
             d.stock,
             e.name,
             e.vulnerability);
    }
  }
  if (qtyDragons() == 0)
  {
    printf("\nNO DRAGON REGISTERED!\n\n");
  }
}

void listElement()
{
  int i;
  Element e;
  for (i = 0; i < qtyElements(); i++)
  {
    if (getElementByIndex(i, &e) == 1)
    {
      printf("\nID: %d || NAME: %s || VULNERABILITY: %s\n",
             e.code,
             e.name,
             e.vulnerability);
    }
  }
  if (qtyElements() == 0)
  {
    printf("\nNO ELEMENT REGISTERED!\n\n");
  }
}

void listRent()
{
  int i;
  Rent r;
  Warrior w;
  Dragon d;
  for (i = 0; i < qtyRentals(); i++)
  {
    if (getRentByIndex(i, &r) == 1)
    {
      findWarriorByCode(r.codeWarrior, &w);
      findDragonByCode(r.codeDragon, &d);

      printf("\nID: %d || WARRIOR'S NAME: %s || DRAGON'S NAME: %s || RENTAL START: %s || RENTAL END: %s || PAID VALUE: %.2f\n",
             r.code,
             w.name,
             d.name,
             r.rentalStart,
             r.rentalEnd,
             r.paid);
    }
  }

  if (qtyRentals() == 0)
  {
    printf("\nNO RENTAL REGISTERED!\n\n");
  }
}

/* ----- CADASTRAR ----- */

void registerWarrior()
{
  Warrior w;

  printf("\nWARRIOR REGISTRATION\n\n");

  printf("Inform the warrior's NAME: ");
  fflush(stdin);
  scanf("%[^\n]s", w.name);

  printf("Inform the warrior's KINGDOM: ");
  fflush(stdin);
  scanf("%[^\n]s", w.kingdom);

  printf("Inform the warrior's TITLE: ");
  fflush(stdin);
  scanf("%[^\n]s", w.title);

  if (saveWarrior(w) == 1)
  {
    printf("\nSUCCESFULLY REGISTERED!\n\n");
  }
  else
  {
    printf("\nFAIL TO REGISTER!\n\n");
  }
}

void registerDragon()
{
  Dragon d;
  Element e;
  int code;
  int flag;

  printf("\nDRAGON REGISTRATION\n\n");

  printf("Inform the dragon's NAME: ");
  fflush(stdin);
  scanf("%[^\n]s", d.name);

  printf("Inform the dragon's AGE (numbers only): ");
  scanf("%d", &d.age);

  printf("Inform the dragon's DAILY VALUE: ");
  scanf("%f", &d.dailyValue);

  printf("Inform the dragon's STOCK: ");
  scanf("%d", &d.stock);

  printf("Pick an element from the list below\n");
  listElement();

  printf("Inform the element's CODE: ");
  scanf("%d", &d.elementCode);

  flag = saveDragon(d);

  if (flag == 1)
  {
    printf("\nSUCCESFULLY REGISTERED!\n\n");
  }
  if (flag == 0)
  {
    printf("\nFAIL TO REGISTER\n\n");
  }
}

void registerElement()
{
  Element e;

  printf("\nELEMENT REGISTRATION\n\n");

  printf("Inform the element's NAME: ");
  fflush(stdin);
  scanf("%[^\n]s", e.name);

  printf("Inform the element's VULNERABILITY: ");
  fflush(stdin);
  scanf("%[^\n]s", e.vulnerability);

  if (saveElement(e) == 1)
  {
    printf("\nSUCCESFULLY REGISTERED!\n\n");
  }
  else
  {
    printf("\nFAIL TO REGISTER!\n\n");
  }
}

void registerRent()
{
  Rent r;

  printf("Inform the WARRIOR CODE: ");
  scanf("%d", &r.codeWarrior);

  printf("Inform the DRAGON CODE: ");
  scanf("%d", &r.codeDragon);

  printf("Inform the RENTAL START DATE (dd/mm/yy): ");
  scanf("%s", r.rentalStart);

  printf("Inform the RENTAL END DATE (dd/mm/yy): ");
  scanf("%s", r.rentalEnd);

  printf("Inform the RENTAL VALUE: ");
  scanf("%f", &r.paid);

  int flag = saveRent(r);

  if (flag == 5)
  {
    printf("\nFAIL TO RENT, WARRIOR HAS AN ACTIVE RENTAL!\n\n");
  }

  if (flag == 4)
  {
    printf("\nFAIL TO RENT, COULDN'T FIND THE WARRIOR!\n\n");
  }

  if (flag == 3)
  {
    printf("FAIL TO RENT, COULDN'T FIND THE DRAGON\n\n");
  }

  if (flag == 2)
  {
    printf("FAIL TO RENT, NO STOCK LEFT!\n\n");
  }

  if ((flag == 1) && (decreaseStock(r.codeDragon) == 1))
  {
    printf("\nSUCCESFULLY RENTED!\n\n");
  }
  // else
  // {
  // 	printf("\nERROR 303, SOMETHING WENT WRONG. PLEASE CONTACT OUR IT SUPPORT LEADER MISSANDEI!\n\n");
  // }
}

/* ----- PROCURAR ----- */

void findWarrior()
{
  int i;
  int code;
  Warrior w;

  printf("Inform the warrior's CODE you want to search for: ");
  scanf("%d", &code);

  if (findWarriorByCode(code, &w) == 1)
  {
    printf("WARRIOR FOUND! Info below:\n");
    printf("\nID: %d || NAME: %s || KINGDOM: %s || TITLE: %s\n\n",
           w.code,
           w.name,
           w.kingdom,
           w.title);
  }
  else
  {
    printf("\nWARRIOR IS NOT REGISTERED!\n\n");
  }
}

void findDragon()
{
  int i;
  int code;
  Dragon d;
  Element e;

  printf("Inform the dragon's CODE you want to search for: ");
  scanf("%d", &code);

  if (findDragonByCode(code, &d) == 1)
  {
    findElementByCode(d.elementCode, &e);

    printf("DRAGON FOUND! Info below:\n");
    printf("\nID: %d || NAME: %s || AGE: %d || DAILY VALUE: %.2f || STOCK: %d || ELEMENT: %s || VULNERABILITY: %s\n",
           d.code,
           d.name,
           d.age,
           d.dailyValue,
           d.stock,
           e.name,
           e.vulnerability);
  }
  else
  {
    printf("\nDRAGON IS NOT REGISTERED!\n\n");
  }
}

void findElement()
{
  int i;
  int code;
  Element e;

  printf("Inform the element's CODE you want to search for: ");
  scanf("%d", &code);

  if (findElementByCode(code, &e) == 1)
  {
    printf("ELEMENT FOUND! Info below:\n");
    printf("\nID: %d || NAME: %s || VULNERABILITY: %s\n",
           e.code,
           e.name,
           e.vulnerability);
  }
  else
  {
    printf("\nELEMENT IS NOT REGISTERED!\n\n");
  }
}

void findRent()
{
  int i;
  int code;
  Rent r;
  Warrior w;
  Dragon d;

  printf("Inform the rentals' CODE you want to search for: ");
  scanf("%d", &code);

  if (findRentByCode(code, &r) == 1)
  {
    findWarriorByCode(i, &w);
    findDragonByCode(i, &d);

    printf("RENTAL FOUND! Info below:\n");
    printf("\nID: %d || WARRIOR NAME: %s || DRAGON NAME: %s || RENTAL START: %s || RENTAL END: %s || PAID VALUE: %.2f\n",
           r.code,
           w.name,
           d.name,
           r.rentalStart,
           r.rentalEnd,
           r.paid);
  }
  else
  {
    printf("\nRENTAL NOT REGISTERED!\n\n");
  }
}

/* ----- EXCLUIR ----- */

void deleteWarrior()
{
  int code;
  int flag;
  printf("REGISTERED WARRIORS\n");
  listWarrior();

  printf("\nInform the warrior's CODE you wish to delete: ");
  scanf("%d", &code);
  flag = deleteWarriorByCode(code);

  if (flag == 2)
  {
    printf("\nFAIL TO DELETE, WARRIOR HAS AN ACTIVE RENTAL!\n\n");
  }
  else if (flag == 0)
  {
    printf("\nFAIL TO DELETE!\n\n");
  }
  else if (flag == 1)
  {
    printf("\nSUCCESFULLY DELETED!\n\n");
  }
}

void deleteDragon()
{
  int code;
  int flag;
  printf("REGISTERED DRAGONS\n");
  listDragon();

  printf("\nInform the dragon's CODE you wish to delete: ");
  scanf("%d", &code);
  flag = deleteDragonByCode(code);

  if (flag == 2)
  {
    printf("\nFAIL TO DELETE, DRAGON HAS AN ACTIVE RENTAL!\n\n");
  }
  else if (flag == 0)
  {
    printf("\nFAIL TO DELETE!\n\n");
  }
  else if (flag == 1)
  {
    printf("\nSUCCESFULLY DELETED!\n\n");
  }
}

void deleteElement()
{
  int code;
  int flag;

  printf("REGISTERED ELEMENTS\n");
  listElement();

  printf("\nInform the element's CODE you wish to delete: ");
  scanf("%d", &code);

  flag = deleteElementByCode(code);

  if (flag == 2)
  {
    printf("\nFAIL TO DELETE, ELEMENT HAS A LINK WITH A DRAGON!\n\n");
  }
  else if (flag == 0)
  {
    printf("\nFAIL TO DELETE!\n\n");
  }
  else if (flag == 1)
  {
    printf("\nSUCCESFULLY DELETED!\n\n");
  }
}

void deleteRent()
{
  Rent r;
  int code;

  printf("REGISTERED RENTALS\n");
  listRent();

  printf("\nInform the rentals' CODE you wish to delete: ");
  scanf("%d", &code);

  findRentByCode(code, &r);
  code = r.codeDragon;

  if ((deleteRentByCode(code) == 1) && (increaseStock(r.codeDragon) == 1))
  {
    printf("\nSUCCESFULLY DELETED!\n\n");
  }
  else
  {
    printf("\nFAIL TO DELETE RENTAL!\n\n");
  }
}

/* ----- ATUALIZAR ----- */

void changeWarrior()
{
  int code;
  Warrior w;

  listWarrior();

  printf("Inform the warrior's CODE you want to update info: ");
  scanf("%d", &code);

  if (findWarriorByCode(code, &w) == 1)
  {
    printf("\nCurrent NAME: %s\n", w.name);
    printf("Type the warrior's new NAME: ");
    fflush(stdin);
    scanf("%[^\n]s", w.name);

    printf("\nCurrent KINGDOM: %s\n", w.kingdom);
    printf("Type the warrior's new KINGDOM: ");
    fflush(stdin);
    scanf("%[^\n]s", w.kingdom);

    printf("\nCurrent TITLE: %s\n", w.title);
    printf("Type the warrior's new TITLE: ");
    fflush(stdin);
    scanf("%[^\n]s", w.title);

    if (updateWarrior(w) == 1)
    {
      printf("SUCCESFULLY UPDATED!\n");
    }
  }
  else if (findWarriorByCode(code, &w) == 0)
  {
    printf("\nWARRIOR IS NOT REGISTERED!\n\n");
  }
}

void changeDragon()
{
  int code;
  Dragon d;

  listDragon();

  printf("Inform the dragon's CODE you want to update info: ");
  scanf("%d", &code);

  if (findDragonByCode(code, &d) == 1)
  {
    printf("\nCurrent NAME: %s\n", d.name);
    printf("Type the dragon's new NAME: ");
    fflush(stdin);
    scanf("%[^\n]s", d.name);

    printf("\nCurrent AGE: %d\n", d.age);
    printf("Type the dragon's new AGE: ");
    scanf("%d", &d.age);

    printf("\nCurrent DAILY VALUE: %.2f\n", d.dailyValue);
    printf("Type the dragon's new DAILY VALUE: ");
    scanf("%f", &d.dailyValue);

    if (updateDragon(d) == 1)
    {
      printf("\nSUCCESFULLY UPDATED!\n");
    }
  }
  else if (findDragonByCode(code, &d) == 0)
  {
    printf("\nDRAGON IS NOT REGISTERED!\n\n");
  }
}

void changeElement()
{
  int code;
  Element e;

  listElement();

  printf("Inform the element's CODE you want to update info: ");
  scanf("%d", &code);

  if (findElementByCode(code, &e) == 1)
  {
    printf("\nCurrent NAME: %s\n", e.name);
    printf("Type the element's new NAME: ");
    fflush(stdin);
    scanf("%[^\n]s", e.name);

    printf("\nCurrent VULNERABILITY: %s\n", e.vulnerability);
    printf("Type the element's new VULNERABILITY: ");
    fflush(stdin);
    scanf("%[^\n]s", e.vulnerability);

    if (updateElement(e) == 1)
    {
      printf("SUCCESFULLY UPDATED!\n");
    }
  }
  else if (findElementByCode(code, &e) == 0)
  {
    printf("\nELEMENT IS NOT REGISTERED!\n\n");
  }
}

void changeRent()
{
  int code;
  Rent r;

  listRent();

  printf("Inform the rentals' CODE you want to update info: ");
  scanf("%d", &code);

  if (findRentByCode(code, &r) == 1)
  {
    printf("\nCurrent START DATE: %s\n", r.rentalStart);
    printf("Type the rentals' new START DATE: ");
    fflush(stdin);
    scanf("%[^\n]s", r.rentalStart);

    printf("\nCurrent END DATE: %s\n", r.rentalEnd);
    printf("Type the rentals' new END DATE: ");
    fflush(stdin);
    scanf("%[^\n]s", r.rentalEnd);

    if (updateRent(r) == 1)
    {
      printf("SUCCESFULLY UPDATED!\n");
    }
  }
  else if (findRentByCode(code, &r) == 0)
  {
    printf("\nRENT IS NOT REGISTERED!\n\n");
  }
}

/* ----- MAIN ----- */

int main(int argc, char const *argv[])
{

  // if (initWarrior() == 1)
  // {
  // 	initWarrior();
  // }
  // else
  // {
  // 	printf("sei la");
  // }
  initWarrior();
  initDragon();
  initElement();
  initRent();

  int menu;
  int submenuWarrior;
  int submenuDragon;
  int submenuElement;
  int submenuRent;
  int submenuFind;
  int rate;

  do
  {
    mainMenu();
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
      do
      {
        warriorMenu();
        scanf("%d", &submenuWarrior);
        switch (submenuWarrior)
        {
        case 1:
          listWarrior();
          system("pause && cls");
          break;

        case 2:
          registerWarrior();
          system("pause && cls");
          break;

        case 3:
          changeWarrior();
          system("pause && cls");
          break;

        case 4:
          findWarrior();
          system("pause && cls");
          break;

        case 5:
          deleteWarrior();
          system("pause && cls");
          break;
        }
      } while (submenuWarrior != 0);
      system("cls");
      break;

    case 2:
      do
      {
        dragonMenu();
        scanf("%d", &submenuDragon);
        switch (submenuDragon)
        {
        case 1:
          listDragon();
          system("pause && cls");
          break;

        case 2:
          registerDragon();
          system("pause && cls");
          break;

        case 3:
          changeDragon();
          system("pause && cls");
          break;

        case 4:
          findDragon();
          system("pause && cls");
          break;

        case 5:
          deleteDragon();
          system("pause && cls");
          break;
        }
      } while (submenuDragon != 0);
      system("cls");
      break;

    case 3:
      do
      {
        elementMenu();
        scanf("%d", &submenuElement);
        switch (submenuElement)
        {
        case 1:
          listElement();
          system("pause && cls");
          break;

        case 2:
          registerElement();
          system("pause && cls");
          break;

        case 3:
          changeElement();
          system("pause && cls");
          break;

        case 4:
          findElement();
          system("pause && cls");
          break;

        case 5:
          deleteElement();
          system("pause && cls");
          break;
        }
      } while (submenuElement != 0);
      system("cls");
      break;

    case 4:
      do
      {
        rentMenu();
        scanf("%d", &submenuRent);
        switch (submenuRent)
        {
        case 1:
          listRent();
          system("pause && cls");
          break;

        case 2:
          registerRent();
          system("pause && cls");
          break;

        case 3:
          changeRent();
          system("pause && cls");
          break;

        case 4:
          findRent();
          system("pause && cls");
          break;

        case 5:
          deleteRent();
          system("pause && cls");
          break;
        }
      } while (submenuRent != 0);
      system("cls");
      break;

    default:
      printf("THANK YOU FOR USING OUR SYSTEM!\n\n");

      printf("This is a small satisfaction survey, it will not take you more than 5 minutes to answer!\n");
      printf("Please, rate our system:\n");
      printf("1 - Awful \n2 - Bad \n3 - Medium \n4 - Good \n5 - Very good\n");
      printf("Rate > ");
      scanf("%d", &rate);

      if ((rate == 1) || (rate == 2) || (rate == 3))
      {
        printf("Thanks for your participation and transparency! Daenerys is inviting you for a little ride at her castle. PS: her dragons will be there too!\n\n");
      }
      else
      {
        printf("Thanks for your participation!\n");
      }
      system("pause && cls");
    }
  } while (menu != 0);

  finishWarrior();
  finishDragon();
  finishElement();
  finishRent();
  return 0;
}