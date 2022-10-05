#include "../include/Nodo.hpp"

Nodo::Nodo(time_t time)
{
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

void Nodo::incTimer()
{
	this->localtime++;
}

/* -------------------------------*/
/**
 * @brief Algoritmo de Berkeley
 */
/* -------------------------------*/
void Server::synchronization()
{
	int numClients = this->clients.size();
	int sumDifference = 0;
	std::vector<int> clientsTimeDiff;

	// Obteniendo una diferencia entre el tiempo del cliente y del servidor
	for( Client* client : this->clients )
	{
		clientsTimeDiff.push_back(client->getLocaltime() - this->getLocaltime());
		sumDifference += client->getLocaltime() - this->getLocaltime();
	}

	//Obtenemos el promedio de las diferencias
	int promedio = sumDifference / numClients;

	//Asignamos este valor a la hora local del servidor y luego la repartimos a los clientes
	// 0 : Diferencia entre la hora del servidor y la hora del servidor
	this->setLocaltime(this->getLocaltime() + promedio - (0) );

	int c = 0;
	for( Client* client : this->clients )
	{
		// Ajuste de hora = Hora local + ( promedio - diferencia )
		client->setLocaltime(client->getLocaltime() + promedio - clientsTimeDiff[c]);
		c++;
	}
}

void Server::addConnection(Client* client)
{
	this->clients.push_back(client);
}


/* -------------------------------*/
/**
 * @brief Algoritmo de Cristian
 *
 * @param servidor* Apuntor al servidor que le brindará la hora actual
 */
/* -------------------------------*/
int Client::requestTime(Server* servidor)
{
	time_t serverTime = servidor->getLocaltime(); //Tiempo perfecto

	//Tomamos el tiempo perfecto del servidor y le sumameos el incremento entre los tiempo del cliente
	time_t newTime = serverTime + (time(NULL) - this->getLocaltime())/2;

	int pause = this->getLocaltime() - newTime;

	//Simulamos que paso un tiempo entre la respuesta y la entrega del mensaje
	while( servidor->getLocaltime() <= newTime )
		servidor->incTimer();

	//Si es menor se le asigna el valor calculado, si no lo ponemos en pausa
	if( newTime > this->getLocaltime() )
	{
		this->setLocaltime(newTime);
		return 0;
	} else if( newTime < this->getLocaltime() ) {
		return pause;
	}
	return 0;
}

