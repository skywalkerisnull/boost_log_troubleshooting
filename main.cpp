// Standard Libs
#include <iostream>

// InFarm libs
#include <Logging/Logging.h>

// External Libs
//#include <boost/filesystem.hpp>
//#include <boost/program_options.hpp>

// Namespaces
using namespace std;

int main(int, char *[])
{
    // Start the application logging as soon as the application start
    init_logging();
    BOOST_LOG_TRIVIAL(info) << "Debayer Service started: " << endl;

    return 0;
}