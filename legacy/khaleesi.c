#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Enable strcmp

// MACROS
#define MAX_WR 8  // Maximum Warrior Rows
#define MAX_DR 10 // Maximum Dragon Rows
#define MAX_C 40  // Maximum Columns (works for every defined matrix)

// Warrior Matrix
char Warrior[MAX_WR][MAX_C];
char Reign[MAX_WR][MAX_C];
char Title[MAX_WR][MAX_C];

// Dragon Matrix
char Dragon[MAX_DR][MAX_C];
int Age[MAX_DR];
char Element[MAX_DR][MAX_C];

// Delivery Date Matrix
char deliveryDate[MAX_WR][MAX_C];

int i;                    // Warrior index
int j;                    // Dragon index
int rentedDragon[MAX_WR]; // Rented Dragon
int nota;

int main(int argc, char *argv[])
{
  int menu;
  for (i = 0; i < MAX_WR; i++)
  {
    Warrior[i][0] = '\0';
    Reign[i][0] = '\0';
    Title[i][0] = '\0';
    deliveryDate[i][0] = '\0';
    rentedDragon[i] = -1;
  }

  for (j = 0; j < MAX_DR; j++)
  {
    Dragon[j][0] = '\0';
    Age[j] = -1;
    Element[j][0] = '\0';
  }

  printf("{-[-(LOCADORA KHALEESI)-]-} || {-[-(A MELHOR LOCADORA DE DRAGOES DE WESTEROS)-]-}\n\n");

  do
  {
    printf("[[[ ~> SEJA BEM-VINDO <~ ]]]\n\n");

    printf("{ 0 - Sair;                                    }\n");
    printf("{ 1 - Listar guerreiros;                       }\n");
    printf("{ 2 - Cadastrar guerreiro pelo codigo;         }\n");
    printf("{ 3 - Pesquisar guerreiro pelo nome;           }\n");
    printf("{ 4 - Excluir guerreiro pelo codigo;           }\n");
    printf("{ 5 - Listar dragoes;                          }\n");
    printf("{ 6 - Cadastrar dragao pelo codigo;            }\n");
    printf("{ 7 - Pesquisar dragao pelo nome;              }\n");
    printf("{ 8 - Excluir dragao pelo codigo;              }\n");
    printf("{ 9 - Listar dragoes locados;                  }\n");
    printf("{ 10 - Locar dragao;                           }\n");
    printf("{ 11 - Devolver dragao pelo codigo do cliente; }\n\n");

    printf("Escolha uma das opcoes do menu acima ~> ");
    scanf("%d", &menu);
    system("cls");

    switch (menu)
    {
    case 1:
      printf("[[[ LISTA DE GUERREIROS CADASTRADOS ]]]\n\n");

      for (i = 0; i < MAX_WR; i++)
      {
        if (Warrior[i][0] != '\0')
          printf("CODIGO: %d || NOME: %s || REINO: %s || TITULO: %s\n\n", i, Warrior[i], Reign[i], Title[i]);
      }
      system("pause");
      system("cls");
      break;

    case 2:
      printf("[[[ CADASTRO DE GUERREIROS ]]]\n\n");

      printf("Digite o CODIGO do guerreiro ~> ");
      scanf("%d", &i);

      if ((i < 0) || (i > MAX_WR))
      {
        printf("O CODIGO NEGATIVO OU MAIOR QUE O NUMERO MAXIMO DE CADASTROS!\n\n");
      }
      else if (Warrior[i][0] != '\0')
      {
        printf("CODIGO JA SENDO UTILIZADO!\n\n");
      }
      else
      {
        printf("Digite o NOME do guerreiro ~> ");
        fflush(stdin);
        scanf("%[^\n]s", Warrior[i]);

        printf("Digite o REINO do guerreiro ~> ");
        fflush(stdin);
        scanf("%[^\n]s", Reign[i]);

        printf("Digite o TITULO do guerreiro ~> ");
        fflush(stdin);
        scanf("%[^\n]s", Title[i]);

        printf("Guerreiro cadastrado com sucesso!\n\n");
      }
      system("pause");
      system("cls");
      break;

    case 3:
      printf("[[[ PESQUISAR GUERREIRO PELO NOME ]]]\n\n");
      char searchWarrior[MAX_C];
      int warriorFound = 0;

      printf("Digite o NOME do guerreiro que deseja pesquisar ~> ");
      fflush(stdin);
      scanf("%[^\n]s", searchWarrior);

      for (i = 0; i < MAX_WR; i++)
      {
        if (strcmp(searchWarrior, Warrior[i]) == 0)
        {
          printf("Cliente encontrado! Abaixo as informacoes:\n");
          printf("COD: %d || NOME: %s || REINO: %s || TITULO: %s\n\n", i, Warrior[i], Reign[i], Title[i]);
          warriorFound++;
        }
      }
      if (warriorFound == 0)
      {
        printf("CADASTRO NAO ENCONTRADO NO SISTEMA!\n\n");
      }
      system("pause");
      system("cls");
      break;

    case 4:
      printf("[[[ EXCLUIR GUERREIRO PELO CODIGO ]]]\n\n");
      int deleteWarrior = 1;

      printf("[[[ LISTA DE GUERREIROS CADASTRADOS ]]]\n\n");

      for (i = 0; i < MAX_WR; i++)
      {
        if (Warrior[i][0] != '\0')
        {
          printf("CODIGO: %d || NOME: %s || REINO: %s || TITULO: %s\n\n", i, Warrior[i], Reign[i], Title[i]);
        }
      }

      printf("Digite o CODIGO do guerreiro que voce quer excluir ~> ");
      scanf("%d", &i);

      if ((i < 0) || (i > MAX_DR) || (Warrior[i][0] == '\0'))
      {
        printf("NENHUM GUERREIRO CADASTRADO COM ESSE CODIGO!\n\n");
      }
      else if (rentedDragon[i] != -1)
      {
        printf("O GUERREIRO POSSUI UMA LOCACAO ATIVA!\n\n");
      }
      else
      {
        printf("Voce escolheu o guerreiro %s!\n", Warrior[i]);
        printf("Deseja proceder com a exclusao? (Digite 1 para CONFIRMAR ou 2 para CANCELAR) ~> ");
        scanf("%d", &deleteWarrior);

        if (deleteWarrior == 1)
        {
          Warrior[i][0] = '\0';
          Reign[i][0] = '\0';
          Title[i][0] = '\0';

          printf("Guerreiro deletado com sucesso!\n\n");
        }
        else if (deleteWarrior == 2)
        {
          printf("EXCLUSAO CANCELADA!\n\n");
        }
        else
        {
          printf("OPCAO NAO VALIDA!\n\n");
        }
      }
      system("pause");
      system("cls");
      break;

    case 5:
      printf("{{{ LISTA DE DRAGOES CADASTRADOS }}}\n\n");

      for (j = 0; j < MAX_DR; j++)
      {
        if (Dragon[j][0] != '\0')
        {
          printf("CODIGO: %d || NOME: %s || IDADE: %d || ELEMENTO: %s\n\n", j, Dragon[j], Age[j], Element[j]);
        }
      }
      system("pause");
      system("cls");
      break;

    case 6:
      printf("{{{ CADASTRO DE DRAGOES }}}\n\n");

      printf("Digite o CODIGO do dragao +> ");
      scanf("%d", &j);

      if ((j < 0) || (j > MAX_DR))
      {
        printf("CODIGO NEGATIVO OU MAIOR QUE O NUMERO MAXIMO DE CADASTROS!\n\n");
      }
      else if (Dragon[j][0] != '\0')
      {
        printf("CODIGO JA SENDO UTILIZADO!\n\n");
      }
      else
      {
        printf("Digite o NOME do dragao +> ");
        fflush(stdin);
        scanf("%[^\n]s", Dragon[j]);

        printf("Digite a IDADE do dragao +> ");
        scanf("%d", &Age[j]);

        printf("Digite o ELEMENTO do dragao +> ");
        fflush(stdin);
        scanf("%[^\n]s", Element[j]);

        printf("Dragao cadastrado com sucesso!\n\n");
      }
      system("pause");
      system("cls");
      break;

    case 7:
      printf("{{{ PESQUISAR DRAGAO PELO NOME }}}\n\n");
      char searchDragon[MAX_C];
      int dragonFound = 0;

      printf("Digite o NOME do dragao que deseja pesquisar +> ");
      fflush(stdin);
      scanf("%[^\n]s", searchDragon);

      for (j = 0; j < MAX_DR; j++)
      {
        if (strcmp(searchDragon, Dragon[j]) == 0)
        {
          printf("Dragao encontrado! Abaixo as informacoes:\n");
          printf("COD: %d || NOME: %s || IDADE: %d || ELEMENTO: %s\n\n", j, Dragon[j], Age[j], Element[j]);
          dragonFound++;
        }
      }
      if (dragonFound == 0)
      {
        printf("Dragao nao encontrado!\n\n");
      }
      system("pause");
      system("cls");
      break;

    case 8:
      printf("{{{ EXCLUIR DRAGAO PELO CODIGO }}}\n\n");
      int deleteDragon = 1;

      printf(">>> LISTA DE DRAGOES CADASTRADOS <<<\n\n");

      for (j = 0; j < MAX_DR; j++)
      {
        if (Dragon[j][0] != '\0')
        {
          printf("CODIGO: %d || NOME: %s || IDADE: %d || ELEMENTO: %s\n\n", j, Dragon[j], Age[j], Element[j]);
        }
      }

      printf("Digite o CODIGO do dragao que voce quer excluir: ");
      scanf("%d", &j);

      if ((j < 0) || (j > MAX_DR) || (Dragon[j][0] == '\0'))
      {
        printf("CODIGO INVALIDO OU DRAGAO NAO CADASTRADO!\n\n");
      }
      else
      {
        int rentedDragonFound = 0;
        for (i = 0; i < MAX_WR; i++)
        {
          if (rentedDragon[j] != -1)
          {
            rentedDragonFound++;
          }
        }

        if (rentedDragonFound == 0)
        {
          printf("Voce escolheu o dragao %s!\n", Dragon[j]);
          printf("Deseja proceder com a exclusao? (Digite 1 para CONFIRMAR ou 2 para CANCELAR): ");
          scanf("%d", &deleteDragon);

          if (deleteDragon == 1)
          {
            Dragon[j][0] = '\0';
            Age[j] = -1;
            Element[j][0] = '\0';

            printf("Dragao deletado com sucesso!\n\n");
          }
          else if (deleteDragon == 2)
          {
            printf("Exclusao cancelada!\n\n");
          }
          else
          {
            printf("OPCAO NAO VALIDA!\n\n");
          }
        }
        else
        {
          printf("O DRAGAO JA ESTA LOCADO!\n\n");
        }
      }
      system("pause");
      system("cls");
      break;

    case 9:
      printf("... LISTA DE DRAGOES LOCADOS ...\n\n");
      for (i = 0; i < MAX_WR; i++)
      {
        if (rentedDragon[i] >= 0)
          printf("COD: %d || NOME: %s || LOCADO POR: %s || ENTREGA: %s \n\n", rentedDragon[i], Dragon[rentedDragon[i]], Warrior[i], deliveryDate[i]);
      }
      break;

    case 10:
      printf("... LOCACAO DE DRAGAO ...\n\n");

      printf("[[[ LISTA DE GUERREIROS CADASTRADOS ]]]\n\n");

      for (i = 0; i < MAX_WR; i++)
      {
        if (Warrior[i][0] != '\0')
        {
          printf("CODIGO: %d || NOME: %s || REINO: %s || TITULO: %s\n\n", i, Warrior[i], Reign[i], Title[i]);
        }
      }

      printf("Digite o CODIGO do guerreiro ~> ");
      scanf("%d", &i);

      if ((i >= 0) && (i < MAX_WR) && (Warrior[i][0] != '\0') && (rentedDragon[i] == -1))
      {
        printf("{{{ LISTA DE DRAGOES CADASTRADOS }}}\n\n");

        for (j = 0; j < MAX_DR; j++)
        {
          if (Dragon[j][0] != '\0')
          {
            printf("CODIGO: %d || NOME: %s || IDADE: %d || ELEMENTO: %s\n\n", j, Dragon[j], Age[j], Element[j]);
          }
        }

        printf("Digite o codigo do DRAGAO que deseja locar +> ");
        scanf("%d", &j);

        if ((j >= 0) && (j < MAX_DR) && (Dragon[j][0] != '\0'))
        {
          printf("Digite uma data de entrega, formato DD/MM/AA: ");
          scanf("%s", deliveryDate[i]);
          rentedDragon[i] = j;

          printf("SUCESSO, O dragao foi locado!\n\n");
        }
        else
        {
          printf("DRAGAO NAO ESTA CADASTRADO NO SISTEMA!\n\n");
        }
      }
      else
      {
        printf("NAO FOI POSSIVEL FAZER A LOCACAO DO DRAGAO!\n\n");
      }

      system("pause");
      system("cls");
      break;

    case 11:
      printf("{{{ DEVOLUCAO DE DRAGAO }}}\n\n");

      for (i = 0; i < MAX_WR; i++)
      {
        if (Warrior[i][0] != '\0')
          printf("CODIGO: %d || NOME: %s || REINO: %s || TITULO: %s\n\n", i, Warrior[i], Reign[i], Title[i]);
      }

      printf("Digite o codigo do GUERREIRO que deseja devolver ~> ");
      scanf("%d", &i);

      if ((i < 0) || (i > MAX_DR))
      {
        printf("CODIGO INVALIDO!\n\n");
      }
      else if (Warrior[i][0] == '\0')
      {
        printf("GUERREIRO NAO CADASTRADO!\n\n");
      }
      else if (rentedDragon[i] == -1)
      {
        printf("GUERREIRO NAO POSSUI UMA LOCACAO ATIVA!\n\n");
      }
      else
      {
        deliveryDate[i][0] = '\0';
        rentedDragon[i] = -1;
        printf("SUCESSO, o dragao foi devolvido!\n\n");
      }
      system("pause");
      system("cls");
      break;

    default:
      printf("OBRIGADO POR UTILIZAR O NOSSO SERVICO, VOLTE SEMPRE!\n\n");

      printf("Abaixo uma pesquisa de satisfacao, considere participar pois sera muito importante!\n");
      printf("Que nota voce da para o nosso servico: \n1 - Pessimo\n2 - Ruim\n3 - Mediano\n4 - Bom\n5 - Muito bom\nNOTA ~> ");
      scanf("%d", &nota);

      if ((nota == 1) || (nota == 2) || (nota == 3))
      {
        printf("Agradecemos a sua transparencia! Daenerys Targaryen te convida ao castelo dela para uma conversinha (acompanhada de seus dragoes) :D\n\n");
      }
      else
      {
        printf("Obrigado pela participacao!\n");
      }
      system("pause");
      system("cls");
    }
  } while (menu != 0);

  return 0;
}