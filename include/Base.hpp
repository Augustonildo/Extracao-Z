#include "Robo.hpp"

class Base
{
    public:
        Base();
        ~Base();
        void Ativar(int k);
        void Executar(int k);
        void Relatorio(int k);
        void Retornar(int k);
    
    private:
        Robo robos[50];
        char **mapa;
        int contadorBaseAliens;
        int contadorBaseRecursos;
};