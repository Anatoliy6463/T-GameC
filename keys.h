#include <stdio.h>
/*Library for controls in T-GameC
Copyright (C) 2023  Andesaurus-Sesto*/
void movement(int X, int Y, int inp)
{
    if (inp == 'w') ++Y;
    if (inp == 'a') --X;
    if (inp == 's') --Y;
    if (inp == 'd') ++X;
}
void persikinteract(int X, int Y, int persiki, int hunger, int inp)
{
    if (X % 9 == 0 && X != 0 || Y % 9 == 0 && Y != 0) ++persiki;  
    if (inp == 'p') printf("Количество персиков:%d\n", persiki);
    if (inp == 'e' && persiki > 0) 
    {
	puts("Вы съели персик!\n");
	if (hunger <= 20) hunger = 0;
        if (hunger > 20) hunger = hunger - 20;
	--persiki;
    }
    if (inp == 'e' && persiki == 0)
      puts("У вас нет персиков, найдите или купите их.\n");
}
