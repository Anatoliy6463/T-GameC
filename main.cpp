#include <iostream>
#include <cstring>
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
int dragonhp = 1000;
void controlle();
void shop();
void dragon();
void controlle() {
    if (znak == 'w') Y++;
    if (znak == 'd') X++;
    if (znak == 's') Y--;
    if (znak == 'a') X--;
    return;
}
void shop() {
    string in = " ";
    cout<<"Добро пожаловать в магазин! Чтобы купить меч введите sword, чтобы купить броню, введите armor"<<endl;
    cin >> in;
    if (in == "sword") {
    	money-=25;
    	sword = true;
    	cout<<"Спасибо за покупку!"<<endl;
    }
    if (in == "armor") {
    	money-=30;
    	armor = true;
    	cout<<"Спасибо за покупку!"<<endl;
    }
}
void dragon() {
	cout<<"ЗДЕСЬ ЖИВЁТ ДРАКОН"<<endl;
	if (znak == 't') {
		if (sword == false) {
			dragonhp -= 10;
		}
		if (sword == true) {
			dragonhp -= 20;
		}
	}
	
	if (armor == false)
		hp-=15;
		
	if (armor == true)
		hp-=10;
}
int main() {
	cout <<"ЗАГРУЗКА..........\nT-GAME v0.0.2"<<endl;
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
	if (X >= 70 && Y <= 80 && X <= 100 && Y >= 0) {
		dragon();
	}
    }
}
