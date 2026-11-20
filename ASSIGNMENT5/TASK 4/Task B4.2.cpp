
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource created\n";
    }

    ~Resource() {
        cout << "Resource destroyed\n";
    }
};

int main() {
    try {
        unique_ptr<Resource> r =
            make_unique<Resource>();

        throw runtime_error("Testing exception");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << '\n';
    }

    cout << "Program completed\n";

    return 0;
}
