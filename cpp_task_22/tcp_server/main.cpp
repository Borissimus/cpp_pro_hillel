#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Створюємо об'єкт acceptor для прийняття підключень
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "TCP сервер запущено. Очікуємо підключень на порті 12345..." << std::endl;

        while (true) {
            // Приймаємо нове підключення
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::cout << "Клієнт підключився: " << socket.remote_endpoint() << std::endl;

            // Відправляємо відповідь клієнту
            std::string message = "Hello from Boost TCP Server!\n";
            boost::asio::write(socket, boost::asio::buffer(message));

            // Закриваємо з'єднання
            socket.close();
        }
    } catch (std::exception &e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}

