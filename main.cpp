#include <iostream>
using namespace std;
int X = 1;
int Y = 1;
char znak = '\0';
int money = 100;
int hp = 100;
double hunger = 0;
int hungerMAX = 100;
bool armor = false;
bool sword = false;
int persiki = 0;
void controlle();
void controlle() {
    if (znak == 'w') Y++;
    if (znak == 'd') X++;
    if (znak == 's') Y--;
    if (znak == 'a') X--;
    return;
}
int main() {
    while (znak != 'q') {
        cin >> znak;
        controlle();
        cout <<"Ваши координаты: "<<X<<';'<<Y<<"Ваше HP: "<<hp<<" Уровень голода:"<<hunger<<endl;
        if (X % 6 == 0 || Y % 6 == 0 || X % 6 == 0 && Y % 6 == 0) {
            cout<<"Вы нашли персик!"<<endl;
        }
        if (X == 15 && Y == 20) {
            cout <<"МАГАЗИН ЗАКРЫТ!!!"<<endl;
        }
        hunger+=0.25;
	if (hunger > hungerMAX) {
		hp-=15;
	}
	if (hp < 0) {
	    cout <<"GAME OVER!"<<endl;
	    break;
	    return 0;
	}
    }
}
