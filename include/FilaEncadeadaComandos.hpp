#include "CelulaComando.hpp"
#include <iostream>

using namespace std;

class FilaEncadeadaComandos 
{
    public:
        FilaEncadeadaComandos();
        ~FilaEncadeadaComandos();
        void InsereComando(Comando comando);
        void InsereComandoPrioritario(Comando comando);
        Comando ExecutaComando();
        bool FilaVazia();

    private:
        CelulaComando *primeiro;
        CelulaComando *ultimo;
};