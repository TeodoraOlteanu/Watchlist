#include <exception>
#include <string>
using namespace std;

class FileNotFoundException : exception{
private:
    string fileName;
public:
    explicit FileNotFoundException(string fileName): exception(){
        this->fileName = std::move(fileName);
    }
    const char* what() const noexcept override{
        return ("File " + fileName + " was not found").c_str();
    }
};
