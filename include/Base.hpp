#include "Robo.hpp"

class Base
{
    public:
        Base();
        Base(char **mapa, int tamanhoX, int tamanhoY);
        ~Base();
        Robo* GetRobo(int k);
        void Ativar(int k);
        void Executar(int k);
        void Relatorio(int k);
        void Retornar(int k);
        void ImprimirDadosFinais();

    private:
        Robo* robos[50];
        int tamanhoMapaX;
        int tamanhoMapaY;
        char **mapa;
        int contadorBaseAliens;
        int contadorBaseRecursos;
};