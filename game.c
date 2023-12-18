#include <stdio.h>
#include "keys.h"
#include "events.h"
/*Simple console game in C made for fun
Copyright (C) 2023  Andesaurus-Sesto*/
int main()
{
  int X = 1;
  int Y = 1;
  int inp;
  int persiki = 0;
  int hunger = 0;
  int hp = 100;
  int money = 50;
  int ta = 0;
  int result;
  while (inp != 'q')
  {
    inp = getchar();
    printf("Координаты:%d;%d\nГолод:%d\nЗдоровье:%d\nКоличество либрбаксов:%d\n", X, Y, hunger, hp, money);
    if (inp == 'w') Y++;
    if (inp == 'a') X--;
    if (inp == 's') Y--;
    if (inp == 'd') X++;
    persikinteract(X, Y, persiki, hunger, inp);
    if (X % 15 == 0 && Y % 15 == 0)
    {
      break;
      shop(money, ta, persiki);
      continue;
    }
    if (hunger < 0) heal(hunger, hp);
    if (hunger > 100) damage(hunger, hp);
    if (hp < 0) 
    {
      die();
      break;
    }
    if (inp == 't') 
    {
      check(ta, result);
      if (result == 1) teleport(X, Y, result, money);  
    }
  }
}
