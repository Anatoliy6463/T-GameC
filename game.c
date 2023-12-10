#include <stdio.h>
__int16_t X = 1;
__int16_t Y = 1;
int money = 100;
int ta = 0;
int result;
void check();
void check()
{
	if (ta = 0)	result = 0;
	if (ta = 1)	result = 1;
}
void teleport()
{
	printf("Добро пожаловать в телепортатор! Введите координаты телепортации");
	scanf("%d%d", &X, &Y);
	puts("Teleport activating\n");
	getchar();
	puts("Телепортация прошла успешно\n");
	if (result == 1) money -= 1;
}
void shop();
void shop()
{
	puts("Добро пожаловать в магазин! Что бы вы хотели купить? Телепортатор = 1, персики = 2");
	int shopin;
	scanf("%d", &shopin);
	if (shopin == 1)
	{
		money -= 45;
		ta = 1;
	}
	if (shopin == 2)
	{
		puts("Сколько персиков вы бы хотели купить?");
		scanf("%d", &shopin);
		money = money - 1 * shopin;
	}
}
int main()
{
	int in;
	__int8_t persiki = 0;
	__int8_t hp = 100;
	double hunger = 0;
	while (in != 'q')
	{
		in = getchar();
		printf("Ваши координаты: %d;%d\nУровень голода:%f\nЗдоровье:%d\n", X, Y, hunger, hp);
		if (in == 'w') ++Y;
		if (in == 'a') --X;
		if (in == 's') --Y;
		if (in == 'd') ++X;
		if (in == 'p') printf("Количество персиков:%d\n", persiki);
		if (in == 'e') 
		{
			puts("Вы съели персик!\n");
			if (hunger <= 20) hunger = 0;
			if (hunger > 20) hunger = hunger - 20;
		}
		if (in == 't')
		{
			check();
			if (result == 1) teleport();
		}
		if (X % 6 == 0 && X != 0 || Y % 6 == 0 && Y != 0 || X % 6 == 0 && Y % 6 == 0 && X != 0 && Y != 0)
		{
			persiki++;
		}
		if (hunger > 100)
		{
			hp-=25;
		}	
		if (hp < 0)
		{
			puts("GAME OVER!\n");
			break;
		}
		if (X == 35 && Y == 48)
		{
			teleport();
		}
		if (X % 20 == 0 && Y % 20 == 0)
		{
			shop();
		}
		hunger = hunger + 0.25;
	}
}
