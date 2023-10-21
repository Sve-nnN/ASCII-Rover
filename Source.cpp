#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;

//REQUISITOS:

//ROVER

//METEORITOS

//MEDIO DE TRANSPORTE DEL ROVER

//ENTORNO DEL VIDEOJUEGO

//PANEL DE CONTROL

//DINAMICA:
//	PANTALLA DE BIENVENIDA
//	PANTALLA DE CREDITOS
//	PANTALLA DE INSTRUCCIONES
//	NOMBRES DE LOS PERSONAJES
//	INICIO DE MISION
//	DESARROLLO DE MISION
//	FIN DE MISION


void bienvenida() {
	int x = 40, y = 30;
	system("cls");
	system("color 8");
	string bienvenido = "Bienvenido a Mars Rover";
	string presiona = "Presiona una tecla para comenzar";
	int velocidad = 1;
	Console::SetCursorPosition(x,y);
	for (int i = 0; i < bienvenido.length(); i++) {
		cout << bienvenido[i];
		_sleep(velocidad);
	}
	Console::SetCursorPosition(x,y+2);
	for (int i = 0; i < presiona.length(); i++) {
		cout << presiona[i];
		_sleep(velocidad);
	}
	_getch();
}

int main() {
	Console::SetWindowSize(80, 40);
	bienvenida();
	
}