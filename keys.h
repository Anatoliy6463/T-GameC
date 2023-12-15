#include <stdio.h>
/*Library for controls in T-GameC
Copyright (C) 2023  Andesaurus-Sesto*/
void movement(int X, int Y, int in)
{
  in = getchar();
  if (in == 'w') Y++;
  if (in == 'a') X++;
  if (in == 's') Y++;
  if (in == 'd') X++;
  return;
}
void persikinteract(int X, int Y, int persiki, int hunger, int in)
{
    if (X % 9 == 0 && X != 0 || Y % 9 == 0 && Y != 0) ++persiki;  
    if (in == 'p') printf("Количество персиков:%d\n", persiki);
    if (in == 'e' && persiki > 0) 
    {
	puts("Вы съели персик!\n");
	if (hunger <= 20) hunger = 0;
        if (hunger > 20) hunger = hunger - 20;
	persiki++;
    }
    if (in == 'e' && persiki == 0)
      puts("У вас нет персиков, найдите или купите их.\n");
}
