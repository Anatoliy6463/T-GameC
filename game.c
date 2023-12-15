#include <stdio.h>
/*Simple console game made for fun
Copyright (C) 2023  Andesaurus-Sesto*/
#include "keys.h"
#include "events.h"
main()
{
  int in;
  int X = 1;
  int Y = 1;
  int persiki;
  int hp = 100;
  int hunger = 0;
  int ta = 0;
  int money = 100;
  int result;
  while (in != 'q')
  {
    in = getchar();
    movement(X, Y, in);
    persikinteract(X, Y, persiki, hunger, in);
    heal(hunger, hp);
    damage(hunger, hp);
    if (X % 45 == 0 && Y % 10 == 0)
    {
      shop(money, ta, persiki);
    }
    if (X == 120 && Y == 100)
    {
      teleport(X, Y, result, money);
    }
    if (in == 't')
    {
      check(ta, result);
      if (result == 1)
      {
	teleport(X, Y, result, money);
      }
    }
    hunger++;
    if (hp == ']')
    {
      die();
    }
    if (hp == 0)
    {
      die();
    }
    printf("Координаты:%d,%d\nЗдоровье:%d\nУровень голода:%d\nУ вас %d либрбаксов\n");
  }
}
