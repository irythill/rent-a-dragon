#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "warrior.h"
#include "rent.h"

Warrior warriors;

int qtyWar = 0;
int actualWarrior = 0;
int MAX_W = 3;

FILE *war;

int initWarrior()
{
	war = fopen("warrior.txt", "r+b");
	if (war == NULL)
	{
		printf("ERROR\n\n!");
		system("pause");
		exit(1);
	}
	fseek(war, 0, SEEK_END);
	int size = ftell(war);
	qtyWar = size / sizeof(Warrior);
	fseek(war, 0, SEEK_SET);

	int i;
	Warrior w;
	for (i = 0; i < qtyWar; i++)
	{
		fread(&w, sizeof(Warrior), 1, war);
		if (w.code > actualWarrior)
		{
			actualWarrior = w.code;
		}
	}
	actualWarrior++;

	/*------------------------------------------------------*/

	// warriors = (Warrior *)malloc(MAX_W * sizeof(Warrior));
	// if (warriors == NULL)
	// {
	// 	return 0;
	// }

	// int i;
	// for (i = 0; i < MAX_W; i++)
	// {
	// 	warriors[i].code = -1;
	// 	// strcpy(warriors[i].name, "");
	// 	// strcpy(warriors[i].kingdom, "");
	// 	// strcpy(warriors[i].title, "");
	// }
	// warriors->code = actualWarrior++;
	// strcpy(warriors->name, "Ragnar Lothbrok");
	// strcpy(warriors->kingdom, "Kattegat");
	// strcpy(warriors->title, "Jarl");
	// qtyWar++;

	// return 1;
}

int saveWarrior(Warrior w)
{
	w.code = actualWarrior++;
	fseek(war, 0, SEEK_END);
	fwrite(&w, sizeof(Warrior), 1, war);
	qtyWar++;
	return 1;

	/*------------------------------------------------------*/

	// if (qtyWar == MAX_W)
	// {
	// 	increaseWarrior(w);
	// }

	// w.code = actualWarrior++;
	// warriors[qtyWar] = w;
	// qtyWar++;
	// return 1;
}

int qtyWarriors()
{
	return qtyWar;
}

int deleteWarriorByCode(int code)
{
	FILE *dw;
	Warrior dltw;

	dw = fopen("tempWar.txt", "w+b");
	rewind(war);

	if ((war == NULL) || (dw == NULL))
	{
		printf("ERROR!\n\n");
	}
	else
	{
		fflush(war);
		while (fread(&dltw, sizeof(Warrior), 1, war) == 1)
		{
			if (code != dltw.code)
			{
				fwrite(&dltw, sizeof(Warrior), 1, dw);
				qtyWar--;
			}
		}
	}

	fclose(war);
	fclose(dw);

	remove("warrior.txt");
	rename("tempWar.txt", "warrior.txt");

	war = fopen("warrior.txt", "r+b");
	return 1;

	/*------------------------------------------------------*/

	// int i;

	// if (isWarriorRent(code) == 1)
	// {
	// 	return 2;
	// }

	// for (i = 0; i < qtyWar; i++)
	// {
	// 	if (warriors[i].code == code)
	// 	{
	// 		warriors[i] = warriors[qtyWar - 1];
	// 		warriors[qtyWar - 1].code = 0;
	// 		qtyWar--;
	// 		return 1;
	// 		decreaseWarrior();
	// 	}
	// }
	// return 0;
}

int getWarriorByIndex(int index, Warrior *w)
{
	fseek(war, index * sizeof(Warrior), SEEK_SET);
	fread(w, sizeof(Warrior), 1, war);
	rewind(war);
	return 1;

	/*------------------------------------------------------*/

	// *w = warriors[index];
	// return 1;
}

int findWarriorByCode(int code, Warrior *w)
{
	Warrior wc;
	rewind(war);
	fseek(war, 0, SEEK_CUR);

	int i;
	for (i = 0; i < qtyWar; i++)
	{
		fread(&wc, sizeof(Warrior), 1, war);
		if (code == wc.code)
		{
			*w = wc;
			return 1;
		}
	}

	/*------------------------------------------------------*/

	// int i;
	// for (i = 0; i < qtyWar; i++)
	// {
	// 	*w = warriors[i];
	// 	if (w->code == code)
	// 	{
	// 		return 1;
	// 	}
	// }
	// return 0;
}

int checkWarriorByCode(int code)
{
	// 	int i;
	// 	for (i = 0; i < qtyWar; i++)
	// 	{
	// 		if (warriors[i].code == code)
	// 		{
	// 			return 1;
	// 		}
	// 	}
	// return 0;
}

void increaseWarrior(Warrior w)
{
	// MAX_W++;
	// Warrior *backup = (Warrior *)realloc(warriors, MAX_W * sizeof(Warrior));

	// if (backup != NULL)
	// {
	// 	warriors = backup;
	// }
	// else
	// {
	// 	MAX_W--;
	// }
}

int decreaseWarrior()
{
	// if (qtyWar <= (MAX_W * 0.4))
	// {
	// 	Warrior *backup = (Warrior *)realloc(warriors, MAX_W / 2 * sizeof(Warrior));
	// 	if (backup != NULL)
	// 	{
	// 		warriors = backup;
	// 		return 1;
	// 	}
	// 	else
	// 	{
	// 		free(backup);
	// return 0;
	// 	}
	// }
}

int finishWarrior()
{
	fclose(war);

	/*------------------------------------------------------*/

	// free(warriors);
	// warriors = NULL;
}

int updateWarrior(Warrior w)
{
	FILE *uw;
	Warrior updw;

	uw = fopen("newWar.txt", "w+b");
	rewind(war);

	while (fread(&updw, sizeof(Warrior), 1, war) == 1)
	{
		if (updw.code != w.code)
		{
			fwrite(&updw, sizeof(Warrior), 1, uw);
		}
		else
		{
			fwrite(&w, sizeof(Warrior), 1, uw);
		}
	}

	fclose(war);
	fclose(uw);

	remove("warrior.txt");
	rename("newWar.txt", "warrior.txt");

	war = fopen("warrior.txt", "r+b");
	return 1;

	/*------------------------------------------------------*/

	// int i;
	// for (i = 0; i < qtyWar; i++)
	// {
	// 	if (warriors[i].code == w.code)
	// 	{
	// 		warriors[i] = w;
	// 		return 1;
	// 	}
	// }
	// return 0;
}
