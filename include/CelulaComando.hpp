#include "Comando.hpp"

class CelulaComando
{
    public:
        CelulaComando();
    private:
        Comando item;
        CelulaComando *prox;
        
    friend class FilaEncadeadaComandos;
};