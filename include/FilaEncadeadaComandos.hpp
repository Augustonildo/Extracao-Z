#include "CelulaComando.hpp"
#include <iostream>

using namespace std;

class FilaEncadeadaComandos 
{
    public:
        FilaEncadeadaComandos();
        ~FilaEncadeadaComandos();
        void InsereComando();
        void InsereComandoPrioritario();
        Comando RemoveComando();

    private:
        CelulaComando *primeiro;
        CelulaComando *ultimo;
};