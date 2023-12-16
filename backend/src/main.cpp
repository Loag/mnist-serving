#include <iostream>
#include "onnxruntime/onnxruntime_cxx_api.h"

using namespace std;

int main(int argc, char* argv[]) {
    try {
        cout << 'hello' << endl;

    } catch (const exception& err) {
        cerr << "Error: " << err.what() << endl;
        return 1;
    }

    return 0;
}
