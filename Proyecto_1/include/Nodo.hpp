#ifndef __NODO_HPP__
#define __NODO_HPP__

#include <iostream>
#include <vector>
#include <ctime>
//#include "Algoritmos.hpp"
//
enum SyncTypes {BERKELEY, CRISTIAN};

class Nodo {
		private:
			std::vector<Nodo*> clients;
			bool master;
			time_t localtime;
		public:
			Nodo() = default;
			Nodo(time_t time = 0, bool master = false);
			void synchronization(SyncTypes type);
			void setLocaltime(time_t localtime);
			time_t getLocaltime();
			void addConnection(Nodo* client);
};



#endif //!__NODO_HPP__
