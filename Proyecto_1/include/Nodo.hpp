#ifndef __NODO_HPP__
#define __NODO_HPP__

#include <iostream>
#include <vector>
#include <ctime>



/* -------------------------------*/
/**
 * @brief Clase Nodo que tiene los elementos básicos de nuestros clientes/servidores
 */
/* -------------------------------*/
class Nodo {
	public:
		time_t localtime;
		Nodo() = default;
		Nodo(time_t time = 0);
		void setLocaltime(time_t localtime);
		time_t getLocaltime();
		void incTimer();
};

class Server;

/* -------------------------------*/
/**
 * @brief Clase Client 
 */
/* -------------------------------*/
class Client : public Nodo {
	public:
		Client(time_t time):Nodo(time){}
		int requestTime(Server* servidor);
};

/* -------------------------------*/
/**
 * @brief Clase Server
 */
/* -------------------------------*/
class Server : public Nodo {
	private:
		std::vector<Client*> clients; // Lista de los clientes conectados
	public:
		Server(time_t time):Nodo(time){}
		void addConnection(Client* client);
		void synchronization();
};


#endif //!__NODO_HPP__
