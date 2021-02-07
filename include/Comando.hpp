#include <iostream>
using namespace std;

class Comando 
{
    public:
        Comando(string nomeComando);
        Comando(string nomeComando, int x, int y);
        ~Comando();

    private:
        string nomeComando;
        int x;
        int y;
};