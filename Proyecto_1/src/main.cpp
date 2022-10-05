#include <iostream>
#include <unistd.h>
#include "../include/Nodo.hpp"

using namespace std;

string formatDate(time_t timestamp);

/* -------------------------------*/
/**
 * @brief Simulación para realizar el algoritmo Berkeley de sincronización
 */
/* -------------------------------*/
void simulationBerkeley();

/* -------------------------------*/
/**
 * @brief Simulación para realizar la sincronización de un cliente con el algoritmo Cristian
 */
/* -------------------------------*/
void simulationCristian();

int main(int argc, char** argv)
{

	if (argc < 2 )
		exit(EXIT_FAILURE);

	if ( atoi(argv[1]) == 0 ) 
		simulationBerkeley();
	else 
		simulationCristian();
}

void simulationCristian()
{
	Server servidor(time(NULL));
	Client cliente1(time(NULL)+5);
	int inc = 0;

	cout << "===============================" << endl;
	cout << "Antes del algoritmo de Cristian" << endl;
	cout << "===============================" << endl;
	cout << endl;
	cout <<"Servidor:  "<< formatDate(servidor.getLocaltime()) << endl;
	cout <<"Cliente 1: "<< formatDate(cliente1.getLocaltime()) << endl;

	int detener = cliente1.requestTime(&servidor);

	cout << "=================================" << endl;
	cout << "Tiempo de espera a la sincronización del reloj cliente" << endl;
	cout << "=================================" << endl;
	cout << endl;
	//Simulamos que detenemos el timer del cliente hasta sincronizarse con el servidor
	while (inc < detener-2)
	{
		servidor.incTimer();

		cout <<"Servidor:  "<< formatDate(servidor.getLocaltime()) << endl;
		cout <<"Cliente 1: "<< formatDate(cliente1.getLocaltime()) << endl;
		cout << endl;
		inc++;
	}

	cout << "=================================" << endl;
	cout << "Después del algoritmo de Cristian" << endl;
	cout << "=================================" << endl;
	cout << endl;
	cout <<"Servidor:  "<< formatDate(servidor.getLocaltime()) << endl;
	cout <<"Cliente 1: "<< formatDate(cliente1.getLocaltime()) << endl;

}

void simulationBerkeley()
{
	/*
	 * Creando los nodos que simularán los clientes y el servidor
	 */
	Client cliente1(time(NULL)+10);
	Client cliente2(time(NULL)-200);
	Server servidor(time(NULL));

	cout << "===============================" << endl;
	cout << "Antes del algoritmo de Berkeley" << endl;
	cout << "===============================" << endl;
	cout << endl;
	cout <<"Servidor:  "<< formatDate(servidor.getLocaltime()) << endl;
	cout <<"Cliente 1: "<< formatDate(cliente1.getLocaltime()) << endl;
	cout <<"Cliente 2: "<< formatDate(cliente2.getLocaltime()) << endl;


	servidor.addConnection(&cliente1);
	servidor.addConnection(&cliente2);

	//Realizamos la sincronización con el algoritmo
	servidor.synchronization();

	cout << "=================================" << endl;
	cout << "Después del algoritmo de Berkeley" << endl;
	cout << "=================================" << endl;
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

