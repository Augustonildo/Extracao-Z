#include "Base.hpp"

Base::Base(){
    for(int i = 0; i < 50; i++){
        robos[i] = Robo(i);
    }
    contadorBaseAliens = 0;
    contadorBaseRecursos = 0;
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
        cout << "BASE: ROBO " + to_string(k) + " NAO ESTA EM MISSAO\n";
        return;
    }
    cout << "BASE: ROBO " + to_string(k) + " RETORNOU ALIENS " + to_string(robos[k].hostisEliminados) 
        + " RECURSOS " + to_string(robos[k].recursosColetados);
    contadorBaseAliens += robos[k].hostisEliminados;
    contadorBaseRecursos += robos[k].recursosColetados;
    robos[k].Limpar();
}