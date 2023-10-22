
#include <iostream>
#include <conio.h>
#include<Windows.h>
#define MAXGOTAS 501
#define GOTAS 5

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
void ubica(int x, int y)
{
	Console::SetCursorPosition(x, y);
}

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

}
void bienvenida() {
	int x = 40, y = 20;
	system("cls");
	/*cambiarColorAmarillo();*/
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
	for (int i = 0; i <= largo - 3; i++)cout << "_";

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
	int nCrateres = r.Next(5, 10);
	int x;
	int y;
	for (int i = 0; i < nCrateres; i++) {
		x = r.Next(2, 78);//1 + rand() % 79 - 1;
		y = r.Next(32, 34);//31 + rand() % 35;
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
	int generar = 5 + rand() % 77;
	return generar;
}
int generarMeteoritoY() {
	int generar = 5 + rand() % 29 - 5;
	return generar;
}
void movimientoMeteorito(int& x, int& y) {

}
void borrar_rover(int x, int y)
{
	ubica(x, y);     cout << "    ";
	ubica(x, y + 1); cout << "    ";

}


void dibujar_rover(int x, int y)
{
	ubica(x, y);     cout << "***";
	ubica(x, y + 1); cout << "***";

}
void borrar_transporte(int xt, int yt)
{
	ubica(xt, yt);     cout << "     ";


}


void dibujar_transporte(int xt, int yt)
{
	ubica(xt, yt); cout << "O---O";


}
void juego() {
	int x, y;
	int xt = 3, yt = 1;
	Random r;
	srand(time(NULL));

	int nMeteoritosEstaticos = r.Next(7, 16);
	int nMeteoritosMoviles = r.Next(3, 6);
	//array para la posicion de los meteoritos estaticos
	int* meteoritoEstaticoX = new int[nMeteoritosEstaticos];
	int* meteoritoEstaticoY = new int[nMeteoritosEstaticos];
	//array para meteoritos moviles
	int* meteoritoMovilX = new int[nMeteoritosMoviles];
	int* meteoritoMovilY = new int[nMeteoritosMoviles];
	int dMeteorito = 1;
	//variables para la lluvia de meteoritos multicolor:
	int* xGota = new int[MAXGOTAS];
	int* yGota = new int[MAXGOTAS];
	//char* car = new char[MAXGOTAS];
	int num_gotas = 0;
	int dy = 1;
	for (int i = 1; i <= 77; i++) {//el margen
		if (caidas() && num_gotas < MAXGOTAS) {
			xGota[num_gotas] = i;//posición en x
			yGota[num_gotas] = 10;//posición en y
			++num_gotas;//num_gotas++
		}
	}
	interfaz();
	//imprime los meteoritos estaticos
	for (int i = 0; i < nMeteoritosEstaticos; i++) {
		meteoritoEstaticoX[i] = generarMeteoritoX();
		meteoritoEstaticoY[i] = generarMeteoritoY();
		Console::SetCursorPosition(meteoritoEstaticoX[i], meteoritoEstaticoY[i]);
		cout << char(r.Next('*', '.' + 1));
	}
	//imprime los meteoritos dinamicos
	for (int i = 0; i < nMeteoritosMoviles; i++) {
		meteoritoMovilX[i] = generarMeteoritoX();
		meteoritoMovilY[i] = generarMeteoritoY();
		Console::SetCursorPosition(meteoritoMovilX[i], meteoritoMovilY[i]);
		cout << char(244);
	}
	generarMarte();
	Console::SetCursorPosition(1, 1);
	int d = 0;
	while (1)
	{

		if (_kbhit())
		{
			//borrar
			borrar_transporte(xt, yt);

			//mover
			char tecla = _getch();
			if (d == 0) {
				if (tecla == char(77)) xt++;
				if (tecla == char(75)) xt--;
				if (tecla == char(32)) { x = xt; y = yt + 1; d = 1; }
			}
			if (d == 1) {

				//borrar
				borrar_rover(x, y);



				if (tecla == char(77) && x + 4 < 79) x++;

				if (tecla == char(75) && x > 3) x--;

				if (tecla == char(72) && y > 2)  y--;

				if (tecla == char(80) && y + 3 < 32) y++;

				dibujar_rover(x, y);
			}
			dibujar_transporte(xt, yt);
			for (int i = 0; i < num_gotas; i++) {
				if (yGota[i] < 29) {
					Console::SetCursorPosition(x[i], y[i]);
					cout << " ";
					yGota[i] += dy;
					Console::SetCursorPosition(x[i], y[i]);
					Console::ForegroundColor = ConsoleColor(rand() % 16);
					cout << "*";
				}
				else if (y[i] == 29) {
					Console::SetCursorPosition(x[i], y[i]);
					cout << " ";
				}
				else {
					--num_gotas;
					xGota[i] = x[num_gotas];
					yGota[i] = y[num_gotas];
				}
			}
			_sleep(200);

		}
	}
	delete[]x;
	delete[] y;
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