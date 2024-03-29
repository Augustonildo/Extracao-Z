#include "CelulaComando.hpp"

class FilaEncadeadaComandos 
{
    public:
        FilaEncadeadaComandos();
        ~FilaEncadeadaComandos();
        void InsereComando(Comando comando);
        void InsereComandoPrioritario(Comando comando);
        Comando RemoveComando();
        bool FilaVazia();

    private:
        void Limpa();
        int tamanho;
        CelulaComando *frente;
        CelulaComando *tras;
};