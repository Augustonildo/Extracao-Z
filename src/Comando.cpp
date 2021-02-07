#include "Comando.hpp"

Comando::Comando(){}

Comando::Comando(TipoComando tipoComando){
    this->tipoComando = comando;
    this->x = -1;
    this->y = -1;
}

Comando::Comando(TipoComando comando, int x, int y){
    this->tipoComando = comando;
    this->x = x;
    this->y = y;
}