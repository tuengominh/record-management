#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>

using namespace std;

bool run = true;
int ID = 0;
int deleteId, editId, searchId;
string searchName;
int opt;
string input;
fstream fileDB;

struct Person {
	int id;
	string name, apellidos, direccion, poblacion, provincia, codigoPostal, prefijo, telefono;
};

list <Person> persons;

void displayDatabase() {
	if (persons.empty()) { cout << "La base de datos esta vacia." << endl; return; }

	for (list<Person> ::iterator iterator_to_base = persons.begin(); iterator_to_base != persons.end(); iterator_to_base++) {
		cout << "ID: " << (iterator_to_base)->id << endl;
		cout << "Name: " << (iterator_to_base)->name << endl;
		cout << "Apellidos: " << (iterator_to_base)->apellidos << endl;
		cout << "Direccion: " << (iterator_to_base)->direccion << endl;
		cout << "Poblacion: " << (iterator_to_base)->poblacion << endl;
		cout << "Provincia: " << (iterator_to_base)->provincia << endl;
		cout << "Codigo postal: " << (iterator_to_base)->codigoPostal << endl;
		cout << "Telefono: (+" << (iterator_to_base)->prefijo << ") - " << (iterator_to_base)->telefono << endl;
		cout << endl;
	}
}

bool hasOnlyDigits(string s) {
	bool result = true;
	for (size_t n = 0; n < s.length(); n++) {
		if (!isdigit(s[n]))
		{
			result = false;
			break;
		}
	}
	return result;
}

string checkValid(string tmp, int longitud, bool digit) {
	string result;
	while (strlen(tmp) > longitud || tmp.empty()) {
		cout << "La entrada no es valida. Debe contener " << 5 << " caracteres." << endl;
		cout << "Otra vez:" << endl;
		cin >> result;
	}
	if (digit) {
		while (!hasOnlyDigits(tmp)) {
			cout << "La entrada no es valida. Debe contener solo dígitos." << endl;
			cout << "Otra vez:" << endl;
			cin >> result;
		}
	}
	input = "";
	return result;
}

void addPerson() {
	Person new_person;
	new_person.id = ID;

	cout << "Nombre:" << endl;
	cin >> input;
	new_person.name = checkValid(input, 15, 0);

	cout << "Apellidos:" << endl;
	cin >> input;
	new_person.apellidos = checkValid(input, 30, 0);
	
	cout << "Direccion:" << endl;
	cin >> input;
	new_person.direccion = checkValid(input, 30, 0);

	cout << "Poblacion:" << endl;
	cin >> input;
	new_person.poblacion = checkValid(input, 20, 0);

	cout << "Provincia:" << endl;
	cin >> input;
	new_person.provincia = checkValid(input, 20, 0);

	cout << "Codigo postal:" << endl;
	cin >> input;
	new_person.codigoPostal = checkValid(input, 5, 1);

	cout << "Prefijo telefono:" << endl;
	cin >> input;
	new_person.prefijo = checkValid(input, 5, 1);

	cout << "Prefijo telefono:" << endl;
	cin >> input;
	new_person.telefono = checkValid(input, 10, 1);

	persons.push_back(new_person);
	ID++;
	cout << endl;
}

void deletePerson(int id) {
	if (persons.empty()) { cout << "La base de datos esta vacia." << endl; return; }
	for (list<Person>::iterator iterator_begin = persons.begin(); iterator_begin != persons.end(); iterator_begin++)
	{
		if ((iterator_begin->id) == id)
		{
			persons.erase(iterator_begin);
			cout << "Eliminada!" << endl;
			return;
		}
	}
	cout << "No encontrada!" << endl;
}

void editPerson(int id) {
	if (persons.empty()) { cout << "La base de datos esta vacia." << endl; return; }

	int property = 0;
	for (list<Person>::iterator iterator_begin = persons.begin(); iterator_begin != persons.end(); iterator_begin++) {
		if ((iterator_begin->id) == id) {
			cout << "Que quieres editar?" << endl;
			cout << "1. Nombre" << endl;
			cout << "2. Apellidos" << endl;
			cout << "3. Direccion" << endl;
			cout << "4. Poblacion" << endl;
			cout << "5. Provincia" << endl;
			cout << "6. Codigo postal" << endl;
			cout << "7. Prefijo telefono" << endl;
			cout << "8. Telefono" << endl;

			cin >> property;
			switch (property) {
				case 1:
					{ cout << "Introducir un nuevo nombre:" << endl;
					cin >> input;
					(iterator_begin)->name = checkValid(input, 15, 0);
					return;}
				case 2:
					{ cout << "Introducir un nuevo apellidos:" << endl;
					cin >> input;
					(iterator_begin)->apellidos = checkValid(input, 30, 0);
					return;}
				case 3:
					{ cout << "Introducir un nueva direccion:" << endl;
					cin >> input;
					(iterator_begin)->direccion = checkValid(input, 30, 0);
					return;}
				case 4:
					{ cout << "Introducir un nueva poblacion:" << endl;
					cin >> input;
					(iterator_begin)->poblacion = checkValid(input, 20, 0);
					return;}
				case 5:
					{ cout << "Introducir un nueva provincia:" << endl;
					cin >> input;
					(iterator_begin)->provincia = checkValid(input, 20, 0);
					return;}
				case 6:
					{ cout << "Introducir un nuevo codigo:" << endl;
					cin >> input;
					(iterator_begin)->codigoPostal = checkValid(input, 5, 1);
					return;}
				case 7:
					{ cout << "Introducir un nuevo numero:" << endl;
					cin >> input;
					(iterator_begin)->prefijo = checkValid(input, 5, 1);
					return;}
				case 8:
					{ cout << "Introducir un nuevo numero:" << endl;
					cin >> input;
					(iterator_begin)->telefono = checkValid(input, 10, 1);
					return;}
			}
		}
	}
	cout << "No encontrada!" << endl;
	return;
}

void searchPerson() {
	if (persons.empty()) { cout << "La base de datos esta vacia." << endl; return; }

	int searchBy;
	cout << "Vas a buscar con:" << endl;
	cout << "1. ID" << endl;
	cout << "2. Apellidos" << endl;
	cin >> searchBy;

	switch (searchBy) {
		case 1: 
			{ cout << "Introducir la id que desea buscar:" << endl;
			cin >> searchId;
			for (list<Person>::iterator iterator_search = persons.begin(); iterator_search != persons.end(); iterator_search++) {
				if ((iterator_search->id) == searchId) {
					cout << "ID: " << (iterator_search)->id << endl;
					cout << "Name: " << (iterator_search)->name << endl;
					cout << "Apellidos: " << (iterator_search)->apellidos << endl;
					cout << "Direccion: " << (iterator_search)->direccion << endl;
					cout << "Poblacion: " << (iterator_search)->poblacion << endl;
					cout << "Provincia: " << (iterator_search)->provincia << endl;
					cout << "Codigo postal: " << (iterator_search)->codigoPostal << endl;
					cout << "Telefono: (+" << (iterator_search)->prefijo << ") - " << (iterator_search)->telefono << endl;
					cout << endl;
					return;
				}
			}
			cout << "No encontrada! " << endl; return; }

		case 2: 
			{ cout << "Introducir el apellidos que desea eliminar:" << endl;
			cin >> searchName;
			for (list<Person>::iterator iterator_search = persons.begin(); iterator_search != persons.end(); iterator_search++) {
				if ((iterator_search->name) == searchName) {
					cout << "ID: " << (iterator_search)->id << endl;
					cout << "Name: " << (iterator_search)->name << endl;
					cout << "Apellidos: " << (iterator_search)->apellidos << endl;
					cout << "Direccion: " << (iterator_search)->direccion << endl;
					cout << "Poblacion: " << (iterator_search)->poblacion << endl;
					cout << "Provincia: " << (iterator_search)->provincia << endl;
					cout << "Codigo postal: " << (iterator_search)->codigoPostal << endl;
					cout << "Telefono: (+" << (iterator_search)->prefijo << ") - " << (iterator_search)->telefono << endl;
					cout << endl;
				}
			} 
			cout << "No encontrada! " << endl; return; }
	} 
	cout << "No encontrada!" << endl;
}

void cleanDatabase() {
	fileDB.open("BaseDeDatos.txt", ios::out | ios::trunc);
	fileDB.clear();
	fileDB.close();
}

void updateDatabase() {
	cleanDatabase();
	fileDB.open("BaseDeDatos.txt", ios::out | ios::app);
	if (fileDB.good() == true) {
		for (list<Person> ::iterator iterator_to_base = persons.begin(); iterator_to_base != persons.end();
			iterator_to_base++)
		{
			fileDB << (iterator_to_base)->id << "," 
			<< (iterator_to_base)->name << "," 
			<< (iterator_to_base)->apellidos << "," 
			<< (iterator_to_base)->direccion << ","
			<< (iterator_to_base)->poblacion << ","
			<< (iterator_to_base)->provincia << ","
			<< (iterator_to_base)->codigoPostal << ","
			<< (iterator_to_base)->prefijo << ","
			<< (iterator_to_base)->telefono << endl;
		}
		fileDB.close();
	}
}

int main() {
	while (run) {
		cout << "Bienvenido a la Agenda de Telefonos!" << endl;
		cout << "Seleccione una opcion:" << endl;
		cout << "1. Mostrar la base de datos" << endl;
		cout << "2. Anadir persona" << endl;
		cout << "3. Eliminar persona" << endl;
		cout << "4. Modificar persona" << endl;
		cout << "5. Buscar persona" << endl;
		cout << "6. Actualizar la base de datos" << endl;
		cout << "7. Salir" << endl;

		cin >> opt;
		switch (opt) {
			case 1: { displayDatabase(); break; }
			case 2: {
				cout << "Introducir la informacion requerida:" << endl;
				addPerson(); break; }
			case 3: {
				cout << "Introducir la id que desea eliminar:" << endl;
				cin >> deleteId;
				deletePerson(deleteId); break;}
			case 4: {
				cout << "Introducir la id que desea modificar:" << endl;
				cin >> editId;
				editPerson(editId); break;}
			case 5: { searchPerson(); break; }
			case 6: { updateDatabase(); break; }
			case 7: { run = false; return 0; }
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}
