#ifndef __NODO_HPP__
#define __NODO_HPP__

#include <iostream>
#include <vector>
#include <ctime>
//#include "Algoritmos.hpp"
//
enum SyncTypes {BERKELEY, CRISTIAN};

class Nodo {
		public:
			time_t localtime;
			Nodo() = default;
			Nodo(time_t time = 0);
			void setLocaltime(time_t localtime);
			time_t getLocaltime();
};

class Client : public Nodo {
	public:
		Client(time_t time):Nodo(time){}
		void requestTime();
};

class Server : public Nodo {
	private:
		std::vector<Client*> clients;
	public:
		Server(time_t time):Nodo(time){}
		void addConnection(Client* client);
		void synchronization(SyncTypes type);
};


#endif //!__NODO_HPP__
