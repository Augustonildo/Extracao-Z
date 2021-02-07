#include "Robo.hpp"

Robo::Robo(){
    this->indAtivo = false;
    this->posicaoAtualX = 0;
    this->posicaoAtualY = 0;
    this->recursosColetados = 0;
    this->hostisEliminados = 0;
    this->historico = "";
    this->filaComandos = FilaEncadeadaComandos();
}

Robo::Robo(int id){
    this->id = id;
    this->indAtivo = false;
    this->posicaoAtualX = 0;
    this->posicaoAtualY = 0;
    this->recursosColetados = 0;
    this->hostisEliminados = 0;
    this->historico = "";
    this->filaComandos = FilaEncadeadaComandos();
}

void Robo::AdicionarOrdemComando(bool prioridade, Comando comando){
    if(prioridade){
        filaComandos.InsereComandoPrioritario(comando);
        return;
    }

    filaComandos.InsereComando(comando);
}

void Robo::Mover(char **mapa, int x, int y){
    if(mapa[x][y] != 'O'){
        historico = historico + "ROBO: " + to_string(id) + " IMPOSSIVEL MOVER PARA (" +
            to_string(posicaoAtualX) + "," + to_string(posicaoAtualY) + ")\n";
        return;
    }

    historico = historico + "ROBO: " + to_string(id) + " MOVEU PARA (" + 
        to_string(posicaoAtualX) + "," + to_string(posicaoAtualY) + ")\n";
    posicaoAtualX = x;
    posicaoAtualY = y;
}

void Robo::Eliminar(char **mapa){
    if(mapa[posicaoAtualX][posicaoAtualY] != 'H'){
        historico = historico + "ROBO: " + to_string(id) + " IMPOSSIVEL ELIMINAR ALIEN EM ("
            + to_string(posicaoAtualX) + "," + to_string(posicaoAtualY) + ")\n";
    }

    hostisEliminados++;
    mapa[posicaoAtualX][posicaoAtualY] = '.';
    historico = historico + "ROBO: " + to_string(id) + " ALIEN ELIMINADO EM ("
        + to_string(posicaoAtualX) + "," + to_string(posicaoAtualY) + ")\n";
}

void Robo::Coletar(char **mapa){
    if(mapa[posicaoAtualX][posicaoAtualY] != 'R'){
        historico = historico + "ROBO: " + to_string(id) + " IMPOSSIVEL COLETAR RECURSOS EM ("
            + to_string(posicaoAtualX) + "," + to_string(posicaoAtualY) + ")\n";
    }

    recursosColetados++;
    mapa[posicaoAtualX][posicaoAtualY] = '.';
    historico = historico + "ROBO: " + to_string(id) + " RECURSOS COLETADOS EM ("
        + to_string(posicaoAtualX) + "," + to_string(posicaoAtualY) + ")\n";
}

void Robo::Limpar(){
    historico = "";
    hostisEliminados = 0;
    recursosColetados = 0;
    indAtivo = false;
}