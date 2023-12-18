#include <stdio.h>
/*Simple console game made for fun
Copyright (C) 2023  Andesaurus-Sesto*/
#include "keys.h"
#include "events.h"
int main(int argc, char** argv)
{
  int X; int Y; char input; int persiki; int hp; int hunger; int ta; int money; int result;
  X = 1;
  Y = 1;
  hp = 100;
  hunger = 0;
  ta = 0;
  money = 100;
  while (input != 'q')
  {
      scanf("%c", input);
      printf("Координаты:X=%d Y=%d\nЗдоровье:%d\nУровень голода:%d\nУ вас %d либрбаксов\n", X, Y, hp, hunger, money);
      movement(X, Y, input);
    if (input == 'p' || input == 'e')
    {
      persikinteract(X, Y, persiki, hunger, input);
    }
    if (hunger < 0)
    {
      heal(hunger, hp);
    }
    if (hunger > 100)
    {
      damage(hunger, hp);
    }
    if (X % 45 == 0 && Y % 10 == 0)
    {
      shop(money, ta, persiki);
    }
    if (X == 120 && Y == 100)
    {
      teleport(X, Y, result, money);
    }
    if (input == 't')
    {
      check(ta, result);
      if (result == 1)
      {
	teleport(X, Y, result, money);
      }
    }
    hunger++;
    if (input == ']')
    {
      die();
      break;
    }
    if (hp == 0)
    {
      die();
      break;
    }
  }
}
