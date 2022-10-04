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
		Algoritmos::Berkeley();
	else if( type == CRISTIAN )
		Algoritmos::Cristian();
	else
		exit(0);
}

void Nodo::addConnection(Nodo client)
{
	this->clients.push_back(client);
}
