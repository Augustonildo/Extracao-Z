#include "FilaEncadeadaComandos.hpp"

class Robo 
{
    public:
        Robo();
        Robo(int id);
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
        FilaEncadeadaComandos* filaComandos;
        void Mover(char **mapa, int x,int y);
        void Eliminar(char **mapa);
        void Coletar(char **mapa);
        void Limpar();

    friend class Base;
};