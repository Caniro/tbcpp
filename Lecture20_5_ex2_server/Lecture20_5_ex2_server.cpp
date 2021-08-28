//#include <ctime>
//#include <iostream>
//#include <string>
//#include <boost/asio.hpp>
//#include <mutex>
//#include <thread>
//#include <vector>
//
//using boost::asio::ip::tcp;
//
//std::mutex mtx;
//
//int main()
//{
//	try
//	{
//		boost::asio::io_service io_service;
//
//		tcp::endpoint endpoint(tcp::v4(), 13);
//		tcp::acceptor acceptor(io_service, endpoint);
//
//		std::cout << "Server started" << std::endl;
//
//		//std::vector<boost::asio::ip::tcp::iostream> stream;
//		//stream.resize(10);
//
//		boost::asio::ip::tcp::iostream stream[10];
//		boost::system::error_code ec;
//		std::thread thread_get[10];
//		std::thread thread_send[10];
//
//		for (int i = 0; i < 10 ; ++i)
//		{
//			acceptor.accept(*(stream[i].rdbuf()), ec);
//
//			std::cout << "acceptor accepts " << i << "th client" << std::endl;
//
//			thread_get[i] = std::thread([&](){while (1) {
//				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//				std::cout << "thread_get[" << i << "]" << std::endl;
//				std::string line;
//				std::getline(stream[i], line);
//				mtx.lock();
//				std::cout << line << std::endl;
//				mtx.unlock();
//			}});
//
//			thread_send[i] = std::thread([&]() {while (1) {
//				std::cout << "thread_send[" << i << "]" << std::endl;
//				std::string message_to_client;
//				std::getline(std::cin, message_to_client);
//				stream[i] << message_to_client;
//				stream[i] << std::endl;
//			}});
//		}
//		for (int i = 0; i < 10; ++i)
//		{
//			thread_get[i].join();
//			thread_send[i].join();
//		}
//	}
//	catch (std::exception & e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//
//	return (0);
//}