#include<iostream>
#include<conio.h>
#include<Windows.h>

#define MAXGOTAS 201
#define GOTAS 10

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

/*
Texto Negro: FOREGROUND_BLACK
Texto Azul: FOREGROUND_BLUE
Texto Verde: FOREGROUND_GREEN
Texto Cyan (Azul claro/verde): FOREGROUND_CYAN
Texto Rojo: FOREGROUND_RED
Texto Magenta (Rojo claro/azul): FOREGROUND_MAGENTA
Texto Amarillo: FOREGROUND_YELLOW
Texto Blanco (Gris claro): FOREGROUND_WHITE

Fondo Negro: BACKGROUND_BLACK
Fondo Azul: BACKGROUND_BLUE
Fondo Verde: BACKGROUND_GREEN
Fondo Cyan: BACKGROUND_CYAN
Fondo Rojo: BACKGROUND_RED
Fondo Magenta: BACKGROUND_MAGENTA
Fondo Amarillo: BACKGROUND_YELLOW
Fondo Blanco: BACKGROUND_WHITE
*/

void limpiarConsola() {
	system("cls");
}
bool caidas() {
	return rand() % 501 < GOTAS;
}
void salir() {
	exit(0);
}
void cambiarColorAmarillo() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el identificador de la consola
	int textAndBackgroundColor = (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Código de color para texto en amarillo

	SetConsoleTextAttribute(hConsole, textAndBackgroundColor); // Establecer el color del texto y el fondo
}
void cambiarColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el identificador de la consola
	int textAndBackgroundColor = (color); // Código de color para texto en amarillo

	SetConsoleTextAttribute(hConsole, textAndBackgroundColor); // Establecer el color del texto y el fondo
}
void reiniciarColores() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el identificador de la consola
	SetConsoleTextAttribute(hConsole, 7); // 7 es el código de color predeterminado para texto blanco sobre fondo negro

}
void lluvia() {

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
			if (caidas() && num_gotas < MAXGOTAS) {
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
void bienvenida() {
	int x = 40, y = 20;
	system("cls");
	cambiarColorAmarillo();
	string bienvenido = "Bienvenido a Mars Rover";
	string presiona = "Presiona una tecla para comenzar";
	int velocidad = 1;
	Console::SetCursorPosition(x, y);
	for (int i = 0; i < bienvenido.length(); i++) {
		cout << bienvenido[i];
		_sleep(velocidad);
	}
	Console::SetCursorPosition(x, y + 2);
	for (int i = 0; i < presiona.length(); i++) {
		cout << presiona[i];
		_sleep(velocidad);
	}
	_getch();
}
void menuOpciones();
void creditos() {
	limpiarConsola();
	cout << "DISEÑO DE INTERFACES\t JUAN ANGULO\nDISEÑO FIGURAS ASCII\tMARCELO MILLA\nDESARROLLO DE FUNCIONALIDADES\tGIOVANNI OCAÑA\nDESARROLLO DE MECANICAS\tTIMOTHY DOCUMET";
	cout << "\n\nPresiona una tecla para volver al menu de inicio";
	_getch();
	menuOpciones();
}
void tutorial() {
	limpiarConsola();
	cout << "¿Como jugar?" << endl
		<< "En este juego, tomas el papel del Rover Perserverance,\nel cual debe tener un aterrizaje exitoso en la superficie marciana\npara poder enviarles muestras del planeta a la tierra.";
	cout << "\n\nTu objetivo es descender con exito al planeta rojo\nsin chocar con los meteoritos, ya que estos impediran tu aterrizaje\n";
	cout << "\n\nPresiona una tecla para volver al menu de inicio";
	_getch();
	menuOpciones();
}
int menu() {
	limpiarConsola();
	int opcion;
	cout << "MENU"
		<< endl
		<< "[1] INSTRUCCIONES"
		<< endl
		<< "[2] JUGAR"
		<< endl
		<< "[3] CREDITOS"
		<< endl
		<< "[4] SALIR" << endl;
	do {
		cout << "Selecciona una opcion: "; cin >> int(opcion);
	} while (opcion < 1 || opcion>4);
	return opcion;

}

void interfaz() {
	limpiarConsola();
	Console::SetCursorPosition(0, 0);
	int alto = 40;
	int largo = 80;
	//dibujar cuadrado inicial
	for (int i = 1; i <= alto; i++) {
		for (int j = 1; j <= largo; j++) {
			if (i == 1 || i == alto)cout << "~";
			else if (j == 1 || j == largo)cout << "|";
			else cout << " ";
		}
		cout << endl;
	}
	//primera linea horizontal
	Console::SetCursorPosition(1, 34);
	for (int i = 0; i <= largo-3; i++)cout << "_";

	//lineas horizontales
	int x = 20, y = 35;
	for (int i = 1; i < 5; i++) {
		Console::SetCursorPosition(x, y);
		cout << "|";
		y += 1;
	}
	x = 40;
	y = 35;
	for (int i = 1; i < 5; i++) {
		Console::SetCursorPosition(x, y);
		cout << "|";
		y += 1;
	}
	x = 60;
	y = 35;
	for (int i = 1; i < 5; i++) {
		Console::SetCursorPosition(x, y);
		cout << "|";
		y += 1;
	}

	//datos para mostrar:
	Console::SetCursorPosition(1, 36); cout << "Enviado";
	Console::SetCursorPosition(1, 37); cout << "~~~~~~~~~~~~~~~~~~~";

	Console::SetCursorPosition(1, 38); cout << "Recibido";

	Console::SetCursorPosition(22, 37); cout << "Velodidad";
	Console::SetCursorPosition(42, 37); cout << "Altura";
	Console::SetCursorPosition(62, 37); cout << "Tiempo";
}
void generarCrater() {
	Random r;
	Console::SetCursorPosition(0, 0);
	int nCrateres = r.Next(5,10);
	int x;
	int y;
	for (int i = 0; i < nCrateres; i++) {
		x = r.Next(2, 78);//1 + rand() % 79 - 1;
		y= r.Next(32, 34);//31 + rand() % 35;
		Console::SetCursorPosition(x, y);
		cout << char(r.Next('\'', '0' + 1));
	}
	
}
void generarMarte() {
	Console::SetCursorPosition(1, 30);
	cambiarColor(4);
	for (int i = 0; i <= 77; i++)cout << "~";
	generarCrater();

}
int generarMeteoritoX() {
	int generar = 1 + rand() % 77;
	return generar;
}
int generarMeteoritoY() {
	int generar = 5 + rand() % 29-5;
	return generar;
}
void juego() {
	Random r;
	int nMeteoritosEstaticos = 10;
	int* meteoritoX= new int[nMeteoritosEstaticos];
	int* meteoritoY=new int[nMeteoritosEstaticos];

	interfaz();
	for (int i = 0; i < nMeteoritosEstaticos; i++) {
		meteoritoX[i] = generarMeteoritoX();
		meteoritoY[i] = generarMeteoritoY();
		Console::SetCursorPosition(meteoritoX[i], meteoritoY[i]);
		cout << char(r.Next('*','.'+1));
	}
	generarMarte();

}
void menuOpciones() {
	int opcion = menu();
	switch (opcion)
	{
	case 1:
		tutorial();
		break;
	case 2:
		juego();
		break;
	case 3:
		creditos();
		break;
	case 4:
		salir();
		break;
	default:
		break;
	}

}

int main() {
	bienvenida();
	menuOpciones();
	Console::SetCursorPosition(81, 41);
	_getch();
}