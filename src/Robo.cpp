#include "Robo.hpp"
#include <sstream>

string int_to_string(int i){
    ostringstream sstr;
    sstr << i;
    return sstr.str();
}

Robo::Robo(){
    this->indAtivo = false;
    this->posicaoAtualX = 0;
    this->posicaoAtualY = 0;
    this->recursosColetados = 0;
    this->hostisEliminados = 0;
    this->historico = "";
    this->filaComandos = new FilaEncadeadaComandos();
}

Robo::Robo(int id){
    this->id = id;
    this->indAtivo = false;
    this->posicaoAtualX = 0;
    this->posicaoAtualY = 0;
    this->recursosColetados = 0;
    this->hostisEliminados = 0;
    this->historico = "";
    this->filaComandos = new FilaEncadeadaComandos();
}

Robo::~Robo(){
    delete filaComandos;
}

void Robo::AdicionarOrdemComando(bool prioridade, Comando comando){
    if(prioridade){
        filaComandos->InsereComandoPrioritario(comando);
        return;
    }
    filaComandos->InsereComando(comando);
}

void Robo::Mover(char **mapa, int x, int y){
    if(mapa[x][y] == 'O'){
        historico = historico + "ROBO " + int_to_string(id) + ": IMPOSSIVEL MOVER PARA (" +
            int_to_string(x) + "," + int_to_string(y) + ")\n";
        return;
    }
    posicaoAtualX = x;
    posicaoAtualY = y;
    historico = historico + "ROBO " + int_to_string(id) + ": MOVEU PARA (" + 
        int_to_string(x) + "," + int_to_string(y) + ")\n";
}

void Robo::Eliminar(char **mapa){
    if(mapa[posicaoAtualX][posicaoAtualY] != 'H'){
        historico = historico + "ROBO " + int_to_string(id) + ": IMPOSSIVEL ELIMINAR ALIEN EM ("
            + int_to_string(posicaoAtualX) + "," + int_to_string(posicaoAtualY) + ")\n";
        return;
    }

    hostisEliminados++;
    mapa[posicaoAtualX][posicaoAtualY] = '.';
    historico = historico + "ROBO " + int_to_string(id) + ": ALIEN ELIMINADO EM ("
        + int_to_string(posicaoAtualX) + "," + int_to_string(posicaoAtualY) + ")\n";
}

void Robo::Coletar(char **mapa){
    if(mapa[posicaoAtualX][posicaoAtualY] != 'R'){
        historico = historico + "ROBO " + int_to_string(id) + ": IMPOSSIVEL COLETAR RECURSOS EM ("
            + int_to_string(posicaoAtualX) + "," + int_to_string(posicaoAtualY) + ")\n";
        return;
    }

    recursosColetados++;
    mapa[posicaoAtualX][posicaoAtualY] = '.';
    historico = historico + "ROBO " + int_to_string(id) + ": RECURSOS COLETADOS EM ("
        + int_to_string(posicaoAtualX) + "," + int_to_string(posicaoAtualY) + ")\n";
}

void Robo::Limpar(){
    historico = "";
    hostisEliminados = 0;
    recursosColetados = 0;
    indAtivo = false;
}