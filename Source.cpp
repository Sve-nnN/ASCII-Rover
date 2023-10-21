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

void lluvia() {
    const int MAXGOTAS = 201;
    const int GOTAS = 10;

    bool caidas= rand() % 501 < GOTAS;


    Random r;
    srand(time(NULL));
    int* x = new int[MAXGOTAS];
    int* y = new int[MAXGOTAS];
    //char* car = new char[MAXGOTAS];
    int num_gotas = 0;
    int dy = 1;
    for (;;)//while(true)
    {
        for (int i = 1; i <= 80; i++) {//el margen
            if (caidas && num_gotas < MAXGOTAS) {
                x[num_gotas] = i;//posición en x
                y[num_gotas] = 10;//posición en y
                ++num_gotas;//num_gotas++
            }
        }
        system("cls");
        for (int i = 0; i < num_gotas; i++) {
            if (y[i] < 29) {
                Console::SetCursorPosition(x[i], y[i]);
                Console::ForegroundColor = ConsoleColor(rand() % 16);
                cout << "*";
                y[i] += dy;
            }
            else {
                --num_gotas;
                x[i] = x[num_gotas];
                y[i] = y[num_gotas];
            }
        }
        _sleep(200);
    }
    delete[]x;
    delete[] y;
    _getch();
}
void creditos() {

}
void bienvenida() {
	int x = 40, y = 30;
	system("cls");
	system("color 8");
	string bienvenido = "Bienvenido a Mars Rover";
	string presiona = "Presiona una tecla para comenzar";
	int velocidad = 1;
    lluvia();
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

void interfaz() {
    int alto = 40;
    int largo = 80;
    //dibujar cuadrado inicial
    for (int i = 1; i <= alto; i++) {
        for (int j = 1; j <= largo; j++) {
            if (i == 1 || i == alto)cout << "_";
            else if(j == 1 || j == largo)cout << "|";
            else cout << " ";
        }
        cout << endl;
    }
    //primera linea horizontal
    Console::SetCursorPosition(0, 34);
    for (int i = 0; i <= largo; i++)cout << "_";

    //lineas horizontales
    int x = 20, y = 35;
    for (int i = 1; i < 6; i++) {
        Console::SetCursorPosition(x, y);
        cout << "|";
        y += 1;
    }    
     x =40;
     y = 35;
    for (int i = 1; i < 6; i++) {
        Console::SetCursorPosition(x, y);
        cout << "|";
        y += 1;
    }
    x=60;
    y = 35;
    for (int i = 1; i < 6; i++) {
        Console::SetCursorPosition(x, y);
        cout << "|";
        y += 1;
    }

    //datos para mostrar:
    Console::SetCursorPosition(1, 36); cout << "Enviado";
    Console::SetCursorPosition(1, 37); cout << "///////////////////";

    Console::SetCursorPosition(1, 38); cout << "Recibido";

    Console::SetCursorPosition(22, 37); cout << "Velodidad";
    Console::SetCursorPosition(42, 37); cout << "Altura";
    Console::SetCursorPosition(62, 37); cout << "Tiempo";
}


int main() {
    interfaz();
    
    Console::SetCursorPosition(81, 41);
    system("pause");
	
}