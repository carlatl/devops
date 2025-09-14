#include <iostream>
#include <cstdlib>
#include <fstream>


// declare a class
class Foo {

    // class variables
    int id;

    // class methods
    public:
    Foo(){
        id = rand();
        std::cout << id << " construct\n";
    }
    ~Foo(){
        std::cout << id << " deconstruct\n";
    }

    // public
    int load(string filename){
        int nsize = 10;
        std::vector<char> somedata(nsize);
        ifstream myfile;
        myfile.open("<path to file>");
        myfile.read(somedata.data(), nsize);
        myfile.close();
    }

    float sine(float angle){
        return math::sin(angle);
    }

};


int main(int argc, char * argv[]){
    Foo f1;
    Foo * f2 = new Foo();
    delete f2;
}
