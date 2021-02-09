#include "Comando.hpp"

Comando::Comando(){}

Comando::Comando(TipoComando tipoComando){
    this->tipoComando = tipoComando;
    this->x = -1;
    this->y = -1;
}

Comando::Comando(TipoComando tipoComando, int x, int y){
    this->tipoComando = tipoComando;
    this->x = x;
    this->y = y;
}