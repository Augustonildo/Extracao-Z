#include "Base.hpp"

Base::Base(char **mapa){
    for(int i = 0; i < 50; i++){
        this->robos[i] = Robo(i);
    }
    this->mapa = mapa;
    this->contadorBaseAliens = 0;
    this->contadorBaseRecursos = 0;
}

Base::~Base(){}

Robo Base::GetRobo(int k){
    return robos[k];
}

void Base::Ativar(int k){
    if(robos[k].indAtivo){
        cout << "BASE: ROBO " << k << " JA ESTA EM MISSAO";
        return;
    }

    cout << "BASE: ROBO " << k << " SAIU EM MISSAO";
    robos[k].indAtivo = true;
}

void Base::Executar(int k){
    Comando comando;
    while(!robos[k].filaComandos.FilaVazia()){
        comando = robos[k].filaComandos.RemoveComando();

        switch (comando.tipoComando)
        {
            case Mover:
                robos[k].Mover(mapa, comando.x, comando.y);
                break;
            case Coletar:
                robos[k].Coletar(mapa);
                break;
            case Eliminar:
                robos[k].Eliminar(mapa);
                break;
            
            default:
                throw "Erro! Comando desconhecido";
                break;
        }
    }
}

void Base::Relatorio(int k){
    cout << robos[k].historico;
}

void Base::Retornar(int k){
    if(!robos[k].indAtivo){
        cout << "BASE: ROBO " << k << " NAO ESTA EM MISSAO\n";
        return;
    }
    cout << "BASE: ROBO " << k << " RETORNOU ALIENS " << robos[k].hostisEliminados
        << " RECURSOS " << robos[k].recursosColetados;
    contadorBaseAliens += robos[k].hostisEliminados;
    contadorBaseRecursos += robos[k].recursosColetados;
    robos[k].Limpar();
}