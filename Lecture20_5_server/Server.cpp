#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <mutex>
#include <thread>

using boost::asio::ip::tcp;

int main()
{
	try
	{
		boost::asio::io_service io_service;

		tcp::endpoint endpoint(tcp::v4(), 13);
		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Server started" << std::endl;

		boost::asio::ip::tcp::iostream stream;
		boost::system::error_code ec;

		acceptor.accept(*stream.rdbuf(), ec);
		std::cout << "acceptor check" << std::endl;

		/*if (!ec)
		{
			std::cout << "error is not occurred" << std::endl;

			std::string line;
			std::getline(stream, line);
			std::cout << line << std::endl;
			
			std::string message_to_client;
			std::cin >> message_to_client;
			stream << message_to_client;
			stream << std::endl;

		}*/
		/*if (!ec)
		{
			std::cout << ec.message() << std::endl;
			exit(1);
		}*/
		std::thread t1([&]() {
			while (1) {
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl;
			}});

		std::thread t2([&]() {
			while (1) {
				std::string message_to_client;
				//std::cin >> message_to_client;
				std::getline(std::cin, message_to_client);
				stream << message_to_client;
				stream << std::endl;
			}});
		
		t1.join();
		t2.join();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}