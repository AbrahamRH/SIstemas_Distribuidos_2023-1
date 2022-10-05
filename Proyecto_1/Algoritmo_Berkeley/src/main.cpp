#include <iostream>
#include "../include/Nodo.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Nodo cliente1(time(NULL)+10);
	Nodo cliente2(time(NULL)-20);

	Nodo servidor(time(NULL), true);

	cout << "Antes del algoritmo de Berkeley" << endl;
	cout << cliente1.getLocaltime() << endl;
	cout << cliente2.getLocaltime() << endl;
	cout << servidor.getLocaltime() << endl;


	servidor.addConnection(&cliente1);
	servidor.addConnection(&cliente2);

	servidor.synchronization(BERKELEY);

	cout << "===================" << endl;

	cout << cliente1.getLocaltime() << endl;
	cout << cliente2.getLocaltime() << endl;
	cout << servidor.getLocaltime() << endl;

}

