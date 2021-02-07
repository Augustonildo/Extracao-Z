#include "Base.hpp"
#include "Comando.hpp"
using namespace std;

Base::Base(){
    contadorBaseAliens = 0;
    contadorBaseRecursos = 0;
}

void Base::Ativar(int k){
    if(robos[k]->indAtivo){
        cout << "BASE: ROBO " << k << " JA ESTA EM MISSAO";
        return;
    }

    cout << "BASE: ROBO " << k << " SAIU EM MISSAO";
    robos[k]->indAtivo = true;
}

void Base::Executar(int k){
    Comando comando;
    while(!robos[k]->filaComandos.FilaVazia()){
        comando = robos[k].filaComandos.ExecutaComando();

        switch (comando.tipoComando)
        {
            case Mover:
                robos[k].Mover(comando.x, comando.y);
                break;
            case Coletar:
                robos[k].Coletar();
                break;
            case Eliminar:
                robos[k].Eliminar();
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
    if(!robos[k]->indAtivo){
        cout << "BASE: ROBO " + to_string(k) + " NAO ESTA EM MISSAO\n";
        return;
    }
    cout << "BASE: ROBO " + to_string(k) + " RETORNOU ALIENS " + to_string(robos[k].hostisEliminados) 
        + " RECURSOS " + to_string(robos[k].recursosColetados);
    contadorBaseAliens += robos[k].hostisEliminados;
    contadorBaseRecursos += robos[k].recursosColetados;
    robos[k].Limpar();
}