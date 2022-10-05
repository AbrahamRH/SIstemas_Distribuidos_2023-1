#include <iostream>
#include "../include/Nodo.hpp"

using namespace std;

string formatDate(time_t timestamp);

int main()
{

	/*
	 * Creando los nodos que simularan los clientes y el servidor
	 */
	Nodo cliente1(time(NULL)+10);
	Nodo cliente2(time(NULL)-20);
	Nodo servidor(time(NULL), true);

	cout << "===============================" << endl;
	cout << "Antes del algoritmo de Berkeley" << endl;
	cout << "===============================" << endl;
	cout << endl;
	cout <<"Servidor:  "<< formatDate(servidor.getLocaltime()) << endl;
	cout <<"Cliente 1: "<< formatDate(cliente1.getLocaltime()) << endl;
	cout <<"Cliente 2: "<< formatDate(cliente2.getLocaltime()) << endl;


	servidor.addConnection(&cliente1);
	servidor.addConnection(&cliente2);
	servidor.synchronization(BERKELEY);

	cout << "================================" << endl;
	cout << "Después del algoritmo de Berkeley" << endl;
	cout << "================================" << endl;
	cout << endl;
	cout <<"Servidor:  "<< formatDate(servidor.getLocaltime()) << endl;
	cout <<"Cliente 1: "<< formatDate(cliente1.getLocaltime()) << endl;
	cout <<"Cliente 2: "<< formatDate(cliente2.getLocaltime()) << endl;

}


string formatDate(time_t timestamp)
{
	struct tm* timeinfo;
	time_t fecha = timestamp;
	timeinfo = localtime(&fecha);
	return asctime(timeinfo);

}
