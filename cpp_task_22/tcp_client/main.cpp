#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Підключення до сервера
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "12345");
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::cout << "Підключено до сервера!" << std::endl;

        // Отримання повідомлення від сервера
        char data[1024];
        size_t length = socket.read_some(boost::asio::buffer(data));
        std::cout << "Отримано: " << std::string(data, length) << std::endl;

        // Закриття з'єднання
        socket.close();
    } catch (std::exception &e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}

