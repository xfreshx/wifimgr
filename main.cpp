#include <boost/program_options.hpp>
#include <iostream>

int main(int argc, const char *argv[])
{
    try {
        boost::program_options::options_description desc{"WifiManager"};
        desc.add_options()
        ("help,h", "Help screen")
        ("ssid", value<std::string>(), "SSID")
        ("pass", value<std::string>(), "Password")
        ("sec", value<std::string>()->default_value("WPA2"), "WEP or WPA2")
        ("dev", value<std::string>(), "Device serial");

        boost::program_options::variables_map vm;
        boost::program_options::store(parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else if (vm.count("sec")) {
            auto sec_type = vm["sec"].as<std::string>();
            if (sec_type.compare("WEP") == 0) {
            } else if (sec_type.compare("WEP") == 0) {
            } else {
            }
        }

        else if (vm.count("pi"))
            std::cout << "Pi: " << vm["pi"].as<float>() << '\n';
    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
