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
void cambiarColorLetra(char color) {
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
void derrotaTiempo() {
	int x = 40, y = 20;
	system("cls");
	cambiarColor(4);
	string bienvenido = "PERDISTE";
	string presiona = "No lograste enviar la cantidad suficiente de muestras a la tierra.";
	string salirJuego = "El juego se cerrará.";


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

	Console::SetCursorPosition(x, y + 6);
	for (int i = 0; i < salirJuego.length(); i++) {
		cout << salirJuego[i];
		_sleep(velocidad);
	}

	reiniciarColores();
	_sleep(1500);
	salir();
}
void derrotaoPuntos() {
	int x = 40, y = 20;
	system("cls");
	cambiarColor(4);
	string bienvenido = "PERDISTE";
	string presiona = "Tu nave ha explotado por los impactos de asteroides.";
	string salirJuego = "El juego se cerrará.";


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
	Console::SetCursorPosition(x, y + 6);
	for (int i = 0; i < salirJuego.length(); i++) {
		cout << salirJuego[i];
		_sleep(velocidad);
	}

	reiniciarColores();
	_sleep(1500);
	salir();

}
void victoria() {
	int x = 40, y = 20;
	system("cls");
	cambiarColor(2);
	string bienvenido = "GANASTE";
	string presiona = "Conseguiste superar la mision. Devolveremos el rover a casa.";
	string salirJuego = "El juego se cerrará.";


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
	Console::SetCursorPosition(x, y + 6);
	for (int i = 0; i < salirJuego.length(); i++) {
		cout << salirJuego[i];
		_sleep(velocidad);
	}

	reiniciarColores();
	_sleep(1500);
	salir();

}
int generarMeteoritoX() {
	int generar = 5 + rand() % 74;
	return generar;
}

int generarMeteoritoY() {
	int generar = 5 + rand() % 29 - 5;
	return generar;
}

void dibujarEstrellas() {
	Random r;
	int x = generarMeteoritoX();
	int y = generarMeteoritoY();
	int cant =r.Next(20,50+1);
	for (int i = 0; i < cant; i++) {
		Console::SetCursorPosition(x, y);
		cout << "^";
	}
}
void interfaz() {
	limpiarConsola();
	Console::SetCursorPosition(0, 0);
	cambiarColor(8);
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
	Console::SetCursorPosition(1, 35);
	for (int i = 0; i <= largo - 3; i++) cout << "_";

	//lineas horizontales
	int x = 20, y = 36;
	for (int i = 1; i < 4; i++) {
		Console::SetCursorPosition(x, y);
		cout << "|";
		y += 1;
	}
	x = 40;
	y = 36;
	for (int i = 1; i < 4; i++) {
		Console::SetCursorPosition(x, y);
		cout << "|";
		y += 1;
	}
	x = 60;
	y = 36;
	for (int i = 1; i <4; i++) {
		Console::SetCursorPosition(x, y);
		cout << "|";
		y += 1;
	}
	dibujarEstrellas();
	Console::SetCursorPosition(1, 37); cout << "~~~~~~~~~~~~~~~~~~~";
	Console::SetCursorPosition(1, 37); cout << "~~~~~~~~~~~~~~~~~~~";
	Console::SetCursorPosition(21, 37); cout << "~~~~~~~~~~~~~~~~~~~";
	Console::SetCursorPosition(41, 37); cout << "~~~~~~~~~~~~~~~~~~~";




	reiniciarColores();


}

void generarCrater() {
	Random r;
	Console::SetCursorPosition(0, 0);
	int nCrateres = r.Next(45, 45);
	int x;
	int y;
	for (int i = 0; i < nCrateres; i++) {
		x = r.Next(1, 78);
		y = r.Next(31, 35);
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
int verificarColisionM(int x, int y, int* meteoritoX, int* meteoritoY, int numMeteoritos, int& puntaje, int puntajeColision) {
	int c = 0;
	for (int i = 0; i < numMeteoritos; i++) {
		if (x == meteoritoX[i] && y == meteoritoY[i]) {
			// Se detectó una colisión entre la muestra y un meteorito.
			Console::SetCursorPosition(x, y); cout << " ";
			_getch();

			meteoritoX[i] = generarMeteoritoX();
			meteoritoY[i] = generarMeteoritoY();
			c = 1;
		}
	}
	return c;
}

void tomaMuestra(int& x, int& y, int& puntaje, int& puntajeTomaMuestra, int& muestraAlmacenada) {
	for (int i = 1; i <= 4; i++) {
		Console::SetCursorPosition(x, y + i);
		if (i == 1)cout << "__";
		Console::SetCursorPosition(x, y + i);
		if (i <= 3 && i > 1)cout << "||" << endl;
		Console::SetCursorPosition(x, y + i);
		if (i == 4)cout << "VV" << endl;
		_sleep(50);
	}
	puntaje += puntajeTomaMuestra;
	muestraAlmacenada++;

}
void borraMuestra(int& x, int& y, int& puntaje, int& puntajeTomaMuestra, int& muestraAlmacenada) {
	for (int i = 1; i <= 4; i++) {
		Console::SetCursorPosition(x, y + i);
		if (i == 1)cout << "  ";
		Console::SetCursorPosition(x, y + i);
		if (i <= 3 && i > 1)cout << "  " << endl;
		Console::SetCursorPosition(x, y + i);
		if (i == 4)cout << "  " << endl;
		_sleep(50);
	}

}


void juego() {
	Random r;
	int enviado = 0, recibido = 0, altura = 200, velocidad = r.Next(1, 5), tiempo = 100000, puntaje = 0;
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
	generarMarte();
	Console::SetCursorPosition(1, 1);
	int dx = 1, dy = 1;
	bool transporteDesplegado = false;
	bool caidaLibre = false;
	int c = 0;
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
					altura -= 8;
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
						borraMuestra(x, y, puntaje, puntajeTomaMuestra, muestraAlmacenada);
					}
					if (tecla == 'm') {
						if (muestraAlmacenada == 0) {
							Console::SetCursorPosition(1, 1);
							cambiarColor(6);
							cout << "No tienes muestras tomadas. Toma una con espacio";
							reiniciarColores();
							_sleep(1500);
							Console::SetCursorPosition(1, 1);
							cout << "                                                ";
						}
						else {
							xMuestra = x + 1;
							yMuestra = y;
							if (yMuestra > 1&&c!=1) {
								for (int i = 0; i < 27; i++) {
									if (c != 1) {
										Console::SetCursorPosition(xMuestra, yMuestra);
										cout << " ";
										yMuestra -= dy;
										Console::SetCursorPosition(xMuestra, yMuestra);
										cout << "I";
										verificarColisionM(xMuestra, yMuestra, meteoritoEstaticoX, meteoritoEstaticoY, nMeteoritosEstaticos, puntaje, puntajeColision);
										verificarColisionM(xMuestra, yMuestra, meteoritoMovilX, meteoritoMovilY, nMeteoritosMoviles, puntaje, puntajeColision);

										_sleep(25);
									}
									else {
										recibido--;
										Console::SetCursorPosition(xMuestra, yMuestra);
										cout << " ";
										yMuestra -= dy;
										Console::SetCursorPosition(xMuestra, yMuestra);
										cout << " ";
									}
								}
								if (yMuestra == 1&&c==0) {
									Console::SetCursorPosition(xMuestra, yMuestra);
									cout << " ";
									recibido++;
									puntaje = puntaje + (recibido * puntajeMuestra);
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
		//lluvia de meteoritos
		for (int i = 0; i < nMeteoritosMoviles; i++) {

			if (meteoritoMovilY[i]>0&&meteoritoMovilY[i] <= 29 && meteoritoMovilX[i]<78) {

				if (meteoritoMovilY[i] > yt && meteoritoMovilY[i] < yt + 4) {

					if (meteoritoMovilX[i] > xt && meteoritoMovilX[i] < xt + 7) {

						puntaje -= puntajeColision;
					}
				}
				if (meteoritoMovilY[i] == 29) {
					Console::SetCursorPosition(meteoritoMovilX[i], meteoritoMovilY[i]);
					cout << " ";
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
		Console::SetCursorPosition(1, 36); cout << "Enviado: " << enviado << " Mtras";
		//borro
		Console::SetCursorPosition(1, 38); cout << "Recibido: " << "     ";
		//imprimo
		Console::SetCursorPosition(1, 38); cout << "Recibido: " << recibido<<" Mtras";
		//borro
		Console::SetCursorPosition(22, 36); cout << "Velocidad: " << "       ";
		//imprimo
		Console::SetCursorPosition(22, 36); cout << "Velocidad: " << velocidad<<"Km/h";
		//borro
		Console::SetCursorPosition(22, 38); cout << "Altura: " << "        ";
		//imprimo
		Console::SetCursorPosition(22, 38); cout << "Altura: " << altura+8<<"Km";
		//borro
		Console::SetCursorPosition(42, 38); cout << "Puntos: " << "       ";
		//imprimo
		Console::SetCursorPosition(42, 38); cout << "Puntos: " << puntaje;
		Console::SetCursorPosition(42, 36); cout << "Mtras en rover " << "  ";
		//imprimo
		Console::SetCursorPosition(42, 36); cout << "Mtras en Rover: " << muestraAlmacenada;
		//borro
		Console::SetCursorPosition(62, 37); cout << "Tiempo: " << "        ";

		Console::SetCursorPosition(62, 37); cout << "Tiempo: " << tiempo << " s";

		if (puntaje >= 5000) {
			victoria();
		}
		if (puntaje < -700) {
			derrotaoPuntos();
		}
		if (tiempo == 0) {
			derrotaTiempo();
		}
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
	Console::CursorVisible = false;
	Console::SetWindowSize(80, 40);
	bienvenida();
	menuOpciones();
	Console::SetCursorPosition(81, 41);
	_getch();
}