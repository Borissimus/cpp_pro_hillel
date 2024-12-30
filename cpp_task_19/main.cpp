#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char* argv[]) {
    try {
        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "Print help message")
            ("name,n", boost::program_options::value<std::string>(), "Your name")
            ("age,a", boost::program_options::value<int>(), "Your age")
			("test,t", "Your name");
			
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 0;
        }

        if (vm.count("name")) {
            std::cout << "Name: " << vm["name"].as<std::string>() << "\n";
        }

        if (vm.count("age")) {
            std::cout << "Age: " << vm["age"].as<int>() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
