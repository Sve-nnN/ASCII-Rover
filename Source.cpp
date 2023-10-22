#include <iostream>
#include <conio.h>
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
//  PANTALLA DE BIENVENIDA
//  PANTALLA DE CREDITOS
//  PANTALLA DE INSTRUCCIONES
//  NOMBRES DE LOS PERSONAJES
//  INICIO DE MISION
//  DESARROLLO DE MISION
//  FIN DE MISION

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
void ubica(int x, int y)
{
	Console::SetCursorPosition(x, y);
}

void limpiarConsola() {
	system("cls");
}

bool caidas(int probabilidad) {
	return rand() % 501 < probabilidad;
}

void salir() {
	exit(0);
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
	reiniciarColores();
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
	for (int i = 1; i <= alto; i++) {
		for (int j = 1; j <= largo; j++) {
			if (i == 1 || i == alto) cout << "~";
			else if (j == 1 || j == largo) cout << "|";
			else cout << " ";
		}
		cout << endl;
	}
	Console::SetCursorPosition(1, 34);
	for (int i = 0; i <= largo - 3; i++) cout << "_";

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


}

void generarCrater() {
	Random r;
	Console::SetCursorPosition(0, 0);
	int nCrateres = r.Next(5, 10);
	int x;
	int y;
	for (int i = 0; i < nCrateres; i++) {
		x = r.Next(2, 78);
		y = r.Next(32, 34);
		Console::SetCursorPosition(x, y);
		cout << char(r.Next('\'', '0' + 1));
	}
}

void generarMarte() {
	Console::SetCursorPosition(1, 30);
	cambiarColor(4);
	for (int i = 0; i <= 77; i++) cout << "~";
	generarCrater();
	reiniciarColores();
}

int generarMeteoritoX() {
	int generar = 5 + rand() % 77;
	return generar;
}

int generarMeteoritoY() {
	int generar = 5 + rand() % 29 - 5;
	return generar;
}

void dibujarMeteoritoEstatico(int x, int y) {
	Console::SetCursorPosition(x, y);
	cout << "*";
}

void dibujarMeteoritoMovil(int& x, int& y) {
	Random r;
	//borro
	Console::SetCursorPosition(x, y);
	cout << " ";
	//muevo
	y++;
	//imprimo y cambio de color
	Console::ForegroundColor = ConsoleColor(rand() % 16);
	Console::SetCursorPosition(x, y);
	cout << char(r.Next('*', '.' + 1));
	//reinicio al color estandar
	reiniciarColores();

}

void borrarRover(int x, int y) {
	ubica(x, y);     cout << "    ";
	ubica(x, y + 1); cout << "    ";
}

void dibujarRover(int x, int y) {
	ubica(x, y);     cout << "/ \\";
	ubica(x, y + 1); cout << "o=o";
}

void borrarTransporte(int xt, int yt) {
	ubica(xt, yt);     cout << "     ";
}

void dibujarTransporte(int xt, int yt) {
	ubica(xt, yt); cout << "O---O";
}
void verificarColision(int x, int y, int* meteoritoX, int* meteoritoY, int numMeteoritos, int& puntaje, int puntajeColision) {
	for (int i = 0; i < numMeteoritos; i++) {
		if ((x == meteoritoX[i] && y == meteoritoY[i]) || (x + 1 == meteoritoX[i] && y == meteoritoY[i]) || (x + 2 == meteoritoX[i] && y == meteoritoY[i]) || (x + 3 == meteoritoX[i] && y == meteoritoY[i]) || (x + 4 == meteoritoX[i] && y == meteoritoY[i]) ||
			(x == meteoritoX[i] && y + 1 == meteoritoY[i]) || (x + 1 == meteoritoX[i] && y + 1 == meteoritoY[i]) || (x + 2 == meteoritoX[i] && y + 1 == meteoritoY[i]) || (x + 3 == meteoritoX[i] && y + 1 == meteoritoY[i]) || (x + 4 == meteoritoX[i] && y + 1 == meteoritoY[i]) ||
			(x == meteoritoX[i] && y - 1 == meteoritoY[i]) || (x + 1 == meteoritoX[i] && y - 1 == meteoritoY[i]) || (x + 2 == meteoritoX[i] && y - 1 == meteoritoY[i]) || (x + 3 == meteoritoX[i] && y - 1 == meteoritoY[i]) || (x + 4 == meteoritoX[i] && y - 1 == meteoritoY[i]))
		{
			// Se detectó una colisión entre el rover y un meteorito.
			puntaje -= puntajeColision;
			_getch();
			meteoritoX[i] = generarMeteoritoX();
			meteoritoY[i] = generarMeteoritoY();
		}
	}
}
void tomaMuestra(int& x, int& y, int& puntaje, int& puntajeTomaMuestra, int& muestraAlmacenada) {
	for (int i = 1; i <= 4; i++) {
		Console::SetCursorPosition(x, y + i);
		if (i == 1)cout << "_";
		Console::SetCursorPosition(x, y + i);
		if (i <= 3 && i > 1)cout << "||" << endl;
		Console::SetCursorPosition(x, y + i);
		if (i == 4)cout << "V" << endl;
		_sleep(50);
	}
	puntaje += puntajeTomaMuestra;
	muestraAlmacenada++;

}



void juego() {
	Random r;
	int enviado = 0, recibido = 0, altura = 200, velocidad = r.Next(1, 5), tiempo = altura / velocidad, puntaje = 0;
	int muestraAlmacenada = 0;
	int puntajeColision = 50;
	int puntajeTomaMuestra = 20;
	int puntajeMuestra = 150;
	int puntajeAterrizaje = 200;
	int x, y;
	int xMuestra, yMuestra;
	int xt = 3, yt = 1;
	int nMeteoritosEstaticos = r.Next(7, 16);
	int nMeteoritosMoviles = r.Next(3, 6);
	//array para la posicion de los meteoritos estaticos
	int* meteoritoEstaticoX = new int[nMeteoritosEstaticos];
	int* meteoritoEstaticoY = new int[nMeteoritosEstaticos];
	//array para meteoritos moviles
	int* meteoritoMovilX = new int[nMeteoritosMoviles];
	int* meteoritoMovilY = new int[nMeteoritosMoviles];
	int dMeteorito = 1;
	int dyMeteorito = 1;
	bool colision = false;
	interfaz();
	//imprime los meteoritos estaticos
	for (int i = 0; i < nMeteoritosEstaticos; i++) {
		meteoritoEstaticoX[i] = generarMeteoritoX();
		meteoritoEstaticoY[i] = generarMeteoritoY();
		dibujarMeteoritoEstatico(meteoritoEstaticoX[i], meteoritoEstaticoY[i]);
	}
	//imprime los meteoritos dinamicos
	for (int i = 0; i < nMeteoritosMoviles; i++) {
		meteoritoMovilX[i] = generarMeteoritoX();
		meteoritoMovilY[i] = generarMeteoritoY();
		dibujarMeteoritoMovil(meteoritoMovilX[i], meteoritoMovilY[i]);
	}
	generarMarte();
	Console::SetCursorPosition(1, 1);
	int dx = 1, dy = 1;
	bool transporteDesplegado = false;
	bool caidaLibre = false;
	bool colisionMuestra = false;
	while (1) {
		dibujarTransporte(xt, yt);
		if (_kbhit()) {
			//borrar
			tiempo--;
			borrarTransporte(xt, yt);
			//mover
			char tecla = _getch();
			if (transporteDesplegado == false) {
				if (tecla == char(77)) xt++;
				if (tecla == char(75)) xt--;
				//barra espaciadora suelta el rover
				if (tecla == char(32)) {
					x = xt;
					y = yt + 1;
					transporteDesplegado = true;
					caidaLibre = true;
				}
			}
			if (transporteDesplegado == true) {
				//borrar
				borrarRover(x, y);
				if (caidaLibre == true) {
					//velocidad en caida libre
					y += dy;
					//modifico altura
					altura -= velocidad;
					if (tecla == char(77) && x + 4 < 77) x++;
					if (tecla == char(75) && x > 3) x--;
					if (y == 28) {
						caidaLibre = false;
						puntaje += puntajeAterrizaje;
					}
				}
				if (caidaLibre == false) {
					if (tecla == char(77) && x + 4 < 79) x++;
					if (tecla == char(75) && x > 3) x--;
					if (tecla == char(32)) {
						tomaMuestra(x, y, puntaje, puntajeTomaMuestra, muestraAlmacenada);
					}
					if (tecla == 'm') {
						if (muestraAlmacenada == 0) {
							Console::SetCursorPosition(1, 1);
							cout << "No tienes muestras tomadas. Toma una con espacio";
							_sleep(1500);
							Console::SetCursorPosition(1, 1);
							cout << "                                                ";
						}
						else {
							xMuestra = x + 1;
							yMuestra = y;
							if (yMuestra > 1) {
								for (int i = 0; i < 27; i++) {
									Console::SetCursorPosition(xMuestra, yMuestra);
									cout << " ";
									yMuestra -= dy;
									Console::SetCursorPosition(xMuestra, yMuestra);
									cout << "I";
									_sleep(5);
								}
								if (yMuestra == 1) {
									recibido++;
										puntaje += puntajeMuestra;
										Console::SetCursorPosition(xMuestra, yMuestra);
										cout << " ";
								}

							}
							muestraAlmacenada--;
							enviado++;

						}
					}
				}
				verificarColision(x, y, meteoritoEstaticoX, meteoritoEstaticoY, nMeteoritosEstaticos, puntaje, puntajeColision);
				verificarColision(x, y, meteoritoMovilX, meteoritoMovilY, nMeteoritosMoviles, puntaje, puntajeColision);
				dibujarRover(x, y);
			}

			dibujarTransporte(xt, yt);

		}
		for (int i = 0; i < nMeteoritosMoviles; i++) {

			if (meteoritoMovilY[i] < 30) {

				if (meteoritoMovilY[i] > yt && meteoritoMovilY[i] < yt + 4) {

					if (meteoritoMovilX[i] > xt && meteoritoMovilX[i] < xt + 7) {

						puntaje -= puntajeColision;
					}
				}
				dibujarMeteoritoMovil(meteoritoMovilX[i], meteoritoMovilY[i]);
			}
			else {
				meteoritoMovilX[i] = generarMeteoritoX();
				meteoritoMovilY[i] = generarMeteoritoY();
			}
		}
		//datos para mostrar:
		//borro
		Console::SetCursorPosition(1, 36); cout << "Enviado: " << "      ";
		//imprimo
		Console::SetCursorPosition(1, 36); cout << "Enviado: " << enviado;
		Console::SetCursorPosition(1, 37); cout << "~~~~~~~~~~~~~~~~~~~";
		//borro
		Console::SetCursorPosition(1, 38); cout << "Recibido: " << "     ";
		//imprimo
		Console::SetCursorPosition(1, 38); cout << "Recibido: " << recibido;
		//borro
		Console::SetCursorPosition(22, 36); cout << "Velocidad: " << "       ";
		//imprimo
		Console::SetCursorPosition(22, 36); cout << "Velocidad: " << velocidad;
		Console::SetCursorPosition(21, 37); cout << "~~~~~~~~~~~~~~~~~~~";
		//borro
		Console::SetCursorPosition(22, 38); cout << "Altura: " << "        ";
		//imprimo
		Console::SetCursorPosition(22, 38); cout << "Altura: " << altura;
		//borro
		Console::SetCursorPosition(42, 38); cout << "Puntos: " << "       ";
		//imprimo
		Console::SetCursorPosition(42, 38); cout << "Puntos: " << puntaje;
		Console::SetCursorPosition(41, 37); cout << "~~~~~~~~~~~~~~~~~~~";
		Console::SetCursorPosition(42, 36); cout << "M en rover " << "          ";
		//imprimo
		Console::SetCursorPosition(42, 36); cout << "M en Rover: " << muestraAlmacenada;
		//borro
		Console::SetCursorPosition(62, 37); cout << "Tiempo: " << "        ";

		Console::SetCursorPosition(62, 37); cout << "Tiempo: " << tiempo;
		_sleep(100);
	}

	delete[] meteoritoEstaticoX;
	delete[] meteoritoEstaticoY;
	delete[] meteoritoMovilX;
	delete[] meteoritoMovilY;

	_getch();
}

void menuOpciones() {
	int opcion = menu();
	switch (opcion) {
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