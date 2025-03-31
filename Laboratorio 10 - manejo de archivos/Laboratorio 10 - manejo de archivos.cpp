// Laboratorio 10 - manejo de archivos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MiembroClub {
private:
	string nombre;
	int edad;
	string correo;

public:
	MiembroClub(string _n, int _e, string _c) {
		nombre = _n;
		edad = _e;
		correo = _c;
	}
	//-----------------------------------------------------------------------------------------------------------------
void guardarEnArchivo() {
		ofstream archivo("club.txt ", ios::app);
		if (archivo.is_open()) {
			archivo << nombre << " " << edad << " " << correo << endl;
			archivo.close();
			cout << "Datos guardados exitosamente.\n";
		}
		else {
			cout << "Error al abrir el archivo.\n";
		}
	}
//-----------------------------------------------------------------------------------------------------------------
static void leerDesdeArchivo() {
	ifstream archivo("club.txt");
	string n, c;
	int e;
	if (archivo.is_open()) {
		cout << "\nLista de Miembros:\n";
		while (archivo >> n >> e >> c) {
			cout << "Nombre: " << n << ", Edad: " << e << ", Correo: " << c << endl;
		}
		archivo.close();
	}
	else {
		cout << "Error al abrir el archivo o el archivo no existe.\n";
	}
}
//-----------------------------------------------------------------------------------------------------------------
static void actualizarMiembros(string nombreBuscar,int nuevaEdad, string correoNuevo) {
	ifstream archivo("club.txt");
	ofstream archivoTemp("temp.txt");
	string n, c;
	int e;
	bool encontrado = false;

	if (archivo.is_open() && archivoTemp.is_open()) {
		while (archivo >> n >> e >> c) {
			if (n == nombreBuscar) {
				archivoTemp << n << " " << nuevaEdad << " " << correoNuevo << endl;
				encontrado = true;
			}
			else {
				archivoTemp << n << " " << e << " " << c << endl;
			}
		}

		archivo.close();
		archivoTemp.close();
		remove("club.txt");
		rename("temp.txt", "club.txt");
		if (encontrado) {
			cout << "Miembro actualizado exitosamente.\n";
		}
		else {
			cout << "Miembro no encontrado.\n";
		}

	}
	else {
		cout << "Error al abrir el archivo.\n";

	}
}
//-----------------------------------------------------------------------------------------------------------------
static void eliminarMiembro(string nombreBuscar) {
	ifstream archivo("club.txt");
	ofstream archivoTemp("temp.txt");
	string n, c;
	int e;
	bool eliminado = false;
	
	if (archivo.is_open() && archivoTemp.is_open()) {
		while (archivo >> n >> e >> c) {
			if (n == nombreBuscar) {
				eliminado = true;
			}
			else {
				archivoTemp << n << " " << e << " " << c << endl;
			}
		}

		archivo.close();
		archivoTemp.close();
		remove("club.txt");
		rename("temp.txt", "club.txt");
		if (eliminado) {
			cout << "miembro eliminado exitosamente." << endl;
		}
		else {
			cout << "Miembro no enconstrado " << endl;
		}
	}
	else {
		cout << "Error al abrir el archivo." << endl;
	}
}
};

