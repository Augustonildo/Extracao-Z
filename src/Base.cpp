#include "Base.hpp"

Base::Base(char **mapa, int tamanhoMapaX, int tamanhoMapaY){
    for(int i = 0; i < 50; i++){
        this->robos[i] = new Robo(i);
    }
    this->tamanhoMapaX = tamanhoMapaX;
    this->tamanhoMapaY = tamanhoMapaY;
    this->mapa = mapa;
    this->contadorBaseAliens = 0;
    this->contadorBaseRecursos = 0;
}

Base::~Base(){
    for(int i = 0; i < 50; i++){
        delete robos[i];
    }

    for(int i = 0; i < tamanhoMapaX; i++){
        free(mapa[i]);
    }
    free(mapa);
}

Robo* Base::GetRobo(int k){
    return robos[k];
}

void Base::Ativar(int k){
    if(robos[k]->indAtivo){
        cout << "BASE: ROBO " << k << " JA ESTA EM MISSAO" << endl;
        return;
    }

    cout << "BASE: ROBO " << k << " SAIU EM MISSAO" << endl;
    robos[k]->indAtivo = true;
}

void Base::Executar(int k){
    Comando comando;
    while(!robos[k]->filaComandos->FilaVazia()){
        comando = robos[k]->filaComandos->RemoveComando();
        switch (comando.tipoComando)
        {
            case Mover:
                robos[k]->Mover(mapa, comando.x, comando.y);
                break;
            case Coletar:
                robos[k]->Coletar(mapa);
                break;
            case Eliminar:
                robos[k]->Eliminar(mapa);
                break;
            default:
                throw "Erro! Comando desconhecido";
                break;
        }
    }
}

void Base::Relatorio(int k){
    cout << robos[k]->historico;
}

void Base::Retornar(int k){
    if(!robos[k]->indAtivo){
        cout << "BASE: ROBO " << k << " NAO ESTA EM MISSAO" << endl;
        return;
    }
    cout << "BASE: ROBO " << k << " RETORNOU ALIENS " << robos[k]->hostisEliminados
        << " RECURSOS " << robos[k]->recursosColetados << endl;
    contadorBaseAliens += robos[k]->hostisEliminados;
    contadorBaseRecursos += robos[k]->recursosColetados;
    robos[k]->Limpar();
}

void Base::ImprimirDadosFinais(){
    cout << "BASE: TOTAL DE ALIENS " << contadorBaseAliens << " RECURSOS " << contadorBaseRecursos << endl;
}