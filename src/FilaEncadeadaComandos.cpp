#include "FilaEncadeadaComandos.hpp"

FilaEncadeadaComandos::FilaEncadeadaComandos(){
    frente = new CelulaComando;
    tras = frente;
}

FilaEncadeadaComandos::~FilaEncadeadaComandos(){
    Limpa();
    delete frente;
}

void FilaEncadeadaComandos::InsereComando(Comando comando){
    CelulaComando *nova;
    nova = new CelulaComando;
    nova->item = comando;
    tras->prox = nova;
    tras = nova;
}

void FilaEncadeadaComandos::InsereComandoPrioritario(Comando comando){
    CelulaComando *nova;
    nova = new CelulaComando;
    nova->item = comando;
    if(frente == tras){
        tras = nova;
    }
    frente->prox = nova;
}

Comando FilaEncadeadaComandos::RemoveComando(){
    CelulaComando *primeira;

    if(frente == tras){
        throw "Erro! Fila de comandos está vazia";
    }

    Comando comando = frente->prox->item;
    primeira = frente;
    frente = frente->prox;
    delete primeira;
    return comando;
}

bool FilaEncadeadaComandos::FilaVazia(){
    return frente == tras;
}

void FilaEncadeadaComandos::Limpa(){
    CelulaComando *c;
    c = frente->prox;
    while(c!=NULL){
        frente->prox = c->prox;
        delete c;
        c = frente->prox;
    }
    tras = frente;
}