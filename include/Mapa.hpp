#include <iostream>

using namespace std;

class Mapa 
{
    public:
        Mapa(char **matriz);
        ~Mapa();
        void HostilEliminado(int x, int y);
        void RecursoColetado(int x, int y);

    private:
        char **matriz;
};