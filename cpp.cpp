// Copyright 2025 ATSL

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>


// @doc declare a class
class Foo {
    // class variables
    int id;
    unsigned int seed;

    // @doc class methods
 public:
    Foo() {
        seed = static_cast<unsigned int>(time(nullptr));
        id = rand_r(&seed);
        std::cout << id << " construct\n";
    }
    ~Foo() {
        std::cout << id << " deconstruct\n";
    }

    // public
    /**
    int load(string filename){
        int nsize = 10;
        std::vector<char> somedata(nsize);
        ifstream myfile;
        myfile.open("<path to file>");
        myfile.read(somedata.data(), nsize);
        myfile.close();
    }
*/

    float sine(float angle) {
        return sin(angle/360 * M_PI*2);
    }

    // @doc Generate warning
    float dbz() {
        return 1/0;
    }
};


int main(int argc, char * argv[]) {
    Foo f1;
    Foo * f2 = new Foo();

    float sin45 = f1.sine(45.0);
    std::cout << sin45 << "\n";

    delete f2;
}
