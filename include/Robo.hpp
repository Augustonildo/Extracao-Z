#include "FilaEncadeadaComandos.hpp"
#include <iostream>

using namespace std;

class Robo 
{
    public:
        Robo();
        ~Robo();
        void AdicionarOrdemComando(bool prioridade, Comando comando);

    private:
        int id;
        bool indAtivo;
        int posicaoAtualX;
        int posicaoAtualY;
        int recursosColetados;
        int hostisEliminados;
        string historico;
        FilaEncadeadaComandos filaComandos;
        void Mover(char **mapa, int x,int y);
        void Eliminar(char **mapa);
        void Coletar(char **mapa);
        void Limpar();

    friend class Base;
};