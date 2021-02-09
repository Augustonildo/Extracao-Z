#include "FilaEncadeadaComandos.hpp"

FilaEncadeadaComandos::FilaEncadeadaComandos(){
    frente = new CelulaComando;
    tras = frente;
    tamanho = 0;
}

FilaEncadeadaComandos::~FilaEncadeadaComandos(){
    Limpa();
    delete frente;
}

void FilaEncadeadaComandos::InsereComando(Comando comando){
    CelulaComando *nova = new CelulaComando();
    nova->item = comando;
    nova->prox = NULL;
    tras->prox = nova;
    tras = nova;
    tamanho++;
}

void FilaEncadeadaComandos::InsereComandoPrioritario(Comando comando){
    CelulaComando *nova = new CelulaComando();
    nova->item = comando;
    nova->prox = frente->prox;
    frente->prox = nova;
    tamanho++;
}

Comando FilaEncadeadaComandos::RemoveComando(){
    CelulaComando *primeira;
    Comando comando;
    
    if(FilaVazia()){
        throw "Erro! Fila de comandos está vazia";
    }
    comando = frente->prox->item;
    primeira = frente;
    frente = frente->prox;
    delete primeira;
    tamanho--;
    return comando;
}

bool FilaEncadeadaComandos::FilaVazia(){
    return tamanho == 0;
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