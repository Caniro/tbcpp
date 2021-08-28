#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage : client <host>" << std::endl;
			return (1);
		}
		cout << "argc check!" << endl;

		tcp::iostream stream(argv[1], std::to_string(int(13)));
		if (!stream)
		{
			std::cout << "Unable to connect: " << stream.error().message() << std::endl;
			return (1);
		}
		cout << "connection check!" << endl;

		/*std::string message_to_server;
		std::cin >> message_to_server;
		stream << message_to_server;
		stream << std::endl;

		std::string line;
		std::getline(stream, line);
		std::cout << line << std::endl;*/

		std::thread t3([&]() {
			while (1) {
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl; }});

		std::thread t4([&]() {
			while (1) {
				std::string message_to_server;
				std::getline(std::cin, message_to_server);
				stream << message_to_server;
				stream << std::endl; }});

		t3.join();
		t4.join();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}