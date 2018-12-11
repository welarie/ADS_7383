#include <iostream>
#include <fstream>
#include "bt.h"
#include <sstream>
#include <ctype.h>
#include <cstring>

using namespace std;

bool check_inp(base* arrayKLP, base* arrayLKP)
{
  int k=0;
  for(int i=0; i<strlen(arrayKLP); i++)
  {
    for(int j=0; j<strlen(arrayLKP); j++)
    {
      if(arrayLKP[j] == arrayKLP[i])
      k++;
    }
  }
  if(k == strlen(arrayKLP))
    return true;
  else
  {
    cerr << "Перечисления содержат разные узлы" << endl;
    exit(1);
  }

}

int main()
{
  bool b = 0;
  char c;
  base *arrayKLP=(char*)calloc(20, sizeof(char));
  base *arrayLKP=(char*)calloc(20, sizeof(char));
  int run = 0;
    cout << "Введите 1, если хотите ввести выражение с клавиатуры.\n"
            "Введите 2, если еспользовать выражение из файла test.txt.\n"
            "Введите 3, если хотите закончить работу." << endl;
    cin >> run;
    switch(run)
    {
      case 1:
        {
          cout << "Введите КЛП и ЛКП: \n";
          cin.get();
          base c;
          do
          c=getchar();
          while(c == ' ');
          int j=0;
          while(!isspace(c))
          {
            arrayKLP[j]=c;
            j++;
            c=getchar();
          }
          do
          c=getchar();
          while(c == ' ');
          j=0;
          while(!isspace(c))
          {
            arrayLKP[j]=c;
            j++;
            c=getchar();
          }
          check_inp(arrayKLP, arrayLKP);
          b=1;
          break;
        }
      case 2:
        {
          ifstream outfile;
          outfile.open("test.txt");
          if (!outfile)
          {
            cout << "Входной файл не открыт!\n";
            b = 0;
            break;
          }
          outfile >> arrayKLP;
          outfile >> arrayLKP;
          check_inp(arrayKLP, arrayLKP);
          outfile.close();
          b=1;
          break;
        }
      case 3:
        {
          b=0;
          break;
        }
      default:
        {
          cout << "Введите верное число\n";
          b=0;
          break;
        }
    }
    if(b)
    {
      binTree b;
      b = new Node;
      int i=0, res=0, n=0;
      res = createBT(arrayKLP, arrayLKP, i, b);
      cout << "Результат работы программы: \n";
      printBT(b, i, n);
      cout << endl;
      LPK(b, i);
      cout << endl << endl;
    }
return 0;
}
