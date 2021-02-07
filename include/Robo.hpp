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
        void Mover(int x,int y);
        void Eliminar();
        void Coletar();

    friend class Base;
};