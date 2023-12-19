#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dragon.h"
#include "rent.h"
#include "element.h"

Dragon dragons;

int qtyDrg = 0;
int actualDragon = 0;
int MAX_D = 3;

FILE *drg;

int initDragon()
{
	drg = fopen("dragon.txt", "r+b");
	if (drg == NULL)
	{
		printf("ERROR\n\n!");
		system("pause");
		exit(1);
	}
	fseek(drg, 0, SEEK_END);
	int size = ftell(drg);
	qtyDrg = size / sizeof(Dragon);
	fseek(drg, 0, SEEK_SET);

	int i;
	Dragon d;
	for (i = 0; i < qtyDrg; i++)
	{
		fread(&d, sizeof(Dragon), 1, drg);
		if (d.code > actualDragon)
		{
			actualDragon = d.code;
		}
	}
	actualDragon++;

	/*------------------------------------------------------*/

	// dragons = (Dragon *)malloc(MAX_D * sizeof(Dragon));
	// if (dragons == NULL)
	// {
	// return 0;
	// }

	// int i;
	// for (i = 0; i < MAX_D; i++)
	// {
	// dragons[i].code = -1;
	// dragons[i].elementCode = -1;
	// strcpy(dragons[i].name, "");
	// dragons[i].age = -1;
	// dragons[i].dailyValue = 0.00;
	// dragons[i].stock = -1;
	// }
	// dragons->code = actualDragon++;
	// dragons->elementCode = 1;
	// strcpy(dragons->name, "Toothless");
	// dragons->age = 250;
	// dragons->dailyValue = 5.50;
	// dragons->stock = 2;
	// qtyDrg++;

	// return 1;
}

int saveDragon(Dragon d)
{
	d.code = actualDragon++;
	fseek(drg, 0, SEEK_END);
	fwrite(&d, sizeof(Dragon), 1, drg);
	qtyDrg++;
	return 1;

	/*------------------------------------------------------*/

	// if (qtyDrg == MAX_D)
	// {
	// increaseDragon(d);
	// }

	// d.code = actualDragon++;
	// dragons[qtyDrg] = d;
	// qtyDrg++;
	// return 1;
}

int qtyDragons()
{
	return qtyDrg;
}

int deleteDragonByCode(int code)
{
	FILE *dd;
	Dragon dltd;

	dd = fopen("tempDrg.txt", "w+b");
	rewind(drg);

	if ((drg == NULL) || (dd == NULL))
	{
		printf("ERROR!\n\n");
	}
	else
	{
		fflush(drg);
		while (fread(&dltd, sizeof(Dragon), 1, drg) == 1)
		{
			if (code != dltd.code)
			{
				fwrite(&dltd, sizeof(Dragon), 1, dd);
				qtyDrg--;
			}
		}
	}

	fclose(drg);
	fclose(dd);

	remove("dragon.txt");
	rename("tempDrg.txt", "dragon.txt");

	drg = fopen("dragon.txt", "r+b");
	return 1;

	/*------------------------------------------------------*/

	// if (isDragonRent(code) == 1)
	// {
	// return 2;
	// }

	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// if (dragons[i].code == code)
	// {
	// dragons[i] = dragons[qtyDrg - 1];
	// dragons[qtyDrg - 1].code = 0;
	// qtyDrg--;
	// return 1;
	// decreaseDragon();
	// }
	// }
	// return 0;
}

int getDragonByIndex(int index, Dragon *d)
{
	fseek(drg, index * sizeof(Dragon), SEEK_SET);
	fread(d, sizeof(Dragon), 1, drg);
	rewind(drg);
	return 1;

	/*------------------------------------------------------*/

	// *d = dragons[index];
	// return 1;
}

int findDragonByCode(int code, Dragon *d)
{
	Dragon dc;
	rewind(drg);
	fseek(drg, 0, SEEK_CUR);

	int i;
	for (i = 0; i < qtyDrg; i++)
	{
		fread(&dc, sizeof(Dragon), 1, drg);
		if (code == dc.code)
		{
			*d = dc;
			return 1;
		}
	}

	/*------------------------------------------------------*/

	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// *d = dragons[i];
	// if (d->code == code)
	// {
	// return 1;
	// }
	// }
	// return 0;
}

int checkDragonByCode(int code)
{
	// if (isDragonRent(code) == 1)
	// {
	// return 2;
	// }

	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// if (dragons[i].code == code)
	// {
	// return 1;
	// }
	// }
	// return 0;
}

int checkDragonByElementCode(int elementCode)
{
	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// if (dragons[i].elementCode == elementCode)
	// {
	// return 1;
	// }
	// }
	// return 0;
}

void increaseDragon(Dragon d)
{
	// MAX_D++;
	// Dragon *backup = (Dragon *)realloc(dragons, MAX_D * sizeof(Dragon));

	// if (backup != NULL)
	// {
	// dragons = backup;
	// }
	// else
	// {
	// MAX_D--;
	// }
}

int decreaseDragon()
{
	// if (qtyDrg <= (MAX_D * 0.4))
	// {
	// Dragon *backup = (Dragon *)realloc(dragons, MAX_D / 2 * sizeof(Dragon));
	// if (backup != NULL)
	// {
	// dragons = backup;
	// return 1;
	// }
	// else
	// {
	// free(backup);
	// return 0;
	// }
	// }
}

int finishDragon()
{
	fclose(drg);

	/*------------------------------------------------------*/

	// free(dragons);
	// dragons = NULL;
}

int updateDragon(Dragon d)
{
	FILE *ud;
	Dragon updd;

	ud = fopen("newDrg.txt", "w+b");
	rewind(drg);

	while (fread(&updd, sizeof(Dragon), 1, drg) == 1)
	{
		if (updd.code != d.code)
		{
			fwrite(&updd, sizeof(Dragon), 1, ud);
		}
		else
		{
			fwrite(&d, sizeof(Dragon), 1, ud);
		}
	}

	fclose(drg);
	fclose(ud);

	remove("dragon.txt");
	rename("newDrg.txt", "dragon.txt");

	drg = fopen("dragon.txt", "r+b");
	return 1;

	/*------------------------------------------------------*/

	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// if (dragons[i].code == d.code)
	// {
	// dragons[i] = d;
	// return 1;
	// }
	// }
	// return 0;
}

int increaseStock(int code)
{
	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// Dragon d = dragons[i];
	// if (d.code == code)
	// {
	// dragons[i].stock++;
	// return 1;
	// }
	// }
	// return 0;
}

int decreaseStock(int code)
{
	// int i;
	// for (i = 0; i < qtyDrg; i++)
	// {
	// Dragon d = dragons[i];
	// if (d.code == code)
	// {
	// dragons[i].stock--;
	// return 1;
	// }
	// }
	// return 0;
}

// int checkStock(int stock)
// {
// 	int i;
// 	for (i = 0; i < qtyDrg; i++)
// 	{
// 		if (stock == 0)
// 		{
// 			return 1;
// 		}
// 	}
// 	return 0;
// }
