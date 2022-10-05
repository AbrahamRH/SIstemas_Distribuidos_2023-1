#include "../include/Nodo.hpp"


Nodo::Nodo(time_t time, bool master)
{
	this->master = master;
	this->localtime = time;
}

void Nodo::setLocaltime(time_t localtime)
{
	this->localtime = localtime;
}

time_t Nodo::getLocaltime()
{
	return this->localtime;
}

void Nodo::synchronization(SyncTypes type)
{
	if( type == BERKELEY )
	{
		int numClients = this->clients.size();
		int sumDifference = 0;
		std::vector<int> clientsTimeDiff;

		// Obteniendo una diferencia entre el tiempo del cliente y del servidor
		for( Nodo* client : this->clients )
		{
			clientsTimeDiff.push_back(client->getLocaltime() - this->getLocaltime());
			sumDifference += client->getLocaltime() - this->getLocaltime();
		}

		int promedio = sumDifference / numClients;

		//Asignamos este valor a la hora local del servidor y luego la repartimos a los clientes
		// 0 : Diferencia entre la hora del servidor y la hora del servidor
		this->setLocaltime(this->getLocaltime() + promedio - (0) );

		int c = 0;
		for( Nodo* client : this->clients )
		{
			// Ajuste de hora = Hora local + ( promedio - diferencia )
			client->setLocaltime(client->getLocaltime() + promedio - clientsTimeDiff[c]);
			c++;
		}


	}
	else if( type == CRISTIAN )
	{

	}
	else
		exit(0);
}

void Nodo::addConnection(Nodo* client)
{
	this->clients.push_back(client);
}

