#include "Comando.hpp"
#include "FilaEncadeadaComandos.hpp"
#include <iostream>

using namespace std;

class Robo 
{
    public:
        Robo();
        ~Robo();
        void AdicionarOrdemComando(bool prioridade, Comando comando);
        void Ativar();
        void Executar();
        void Relatorio();
        void Retornar();
        bool GetIndAtivo();

    private:
        bool indAtivo;
        int posicaoAtualX;
        int posicaoAtualY;
        int recursosColetados;
        int hostisEliminados;
        string historico[];
        FilaEncadeadaComandos filaComandos;
        void Mover(int x,int y);
        //Retorna 1 para sucesso e -1 para caso não hajam hostis
        int Eliminar();
        //Retorna 1 para sucesso e -1 para caso não hajam recursos
        int Coletar();

    friend class Mapa;
};