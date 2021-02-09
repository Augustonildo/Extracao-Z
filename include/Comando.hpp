#include <iostream>
using namespace std;

enum TipoComando{
    Mover,
    Coletar,
    Eliminar,
    Ativar,
    Executar,
    Relatorio,
    Retornar
};

class Comando 
{
    public:
        Comando();
        Comando(TipoComando tipoComando);
        Comando(TipoComando tipoComando, int x, int y);

    private:
        TipoComando tipoComando;
        int x;
        int y;

    friend class Base;
};