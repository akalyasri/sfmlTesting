
#include <SFML/Network.hpp>
#include <iostream>


// figuring out how to use sockets:

int socketMain(void) {

	// Create a TCP socket to listen for incoming connections
	sf::TcpListener listener;

	if (listener.listen(5000) != sf::Socket::Done) {

		std::cerr << "Failed to start server" << std::endl;

		return -1;
	}

	std::cout << "Server started" << std::endl;

	// Wait for a client to connect
	sf::TcpSocket socket;

	if (listener.accept(socket) != sf::Socket::Done) {

		std::cerr << "Failed to accept client connection" << std::endl;
		return -1;
	}

	std::cout << "Client connected" << std::endl;

	// Send a welcome message to the client
	std::string message = "Welcome to the Battleship game!";
	socket.send(message.c_str(), message.size() + 1);

	// Receive data from the client
	char buffer[1024];
	std::size_t received;
	if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
		std::cerr << "Failed to receive data from client" << std::endl;
		return -1;
	}

	std::cout << "Received data: " << buffer << std::endl;

	// Close the connection
	socket.disconnect();

	std::cout << "Connection closed" << std::endl;


}

//update