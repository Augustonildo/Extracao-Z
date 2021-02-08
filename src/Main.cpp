#include "Base.hpp"
#include <fstream>
#include <sstream>

int main() {
    istringstream stream;
    fstream arqMapa("mapa.txt"); 
    string linha_mapa = "";
    char **mapa;
    int tamanhoX, tamanhoY;

    if(arqMapa.is_open()){
        getline(arqMapa, linha_mapa);
        
        //TODO: tamanhoX = linha_mapa; tamanhoY = linha_mapa
        tamanhoX = 2;
        tamanhoY = 2;

        mapa = (char **) malloc(tamanhoX * sizeof(char*));
        for(int i = 0; i < tamanhoX; i++){
            mapa[i] = (char *) malloc(tamanhoY * sizeof(char));  
        }
        int linhaArquivo = 1;
        while(getline(arqMapa, linha_mapa)){
            stream = istringstream(linha_mapa);
            for(int j = 0; j < tamanhoY; j++){
                stream >> mapa[linhaArquivo-1][j];
            }
            linhaArquivo++;
        }
    }else{
        throw "Erro! Arquivo mapa.txt não foi encontrado";
    }
    arqMapa.close();
    Base base = Base(mapa);

    fstream arqComandos("comandos.txt");
    string linha_comandos;
    
    if(arqComandos.is_open()){
        while(getline(arqComandos, linha_comandos)){
            stream = istringstream(linha_comandos);
            string nomeComando, idRobo;
            stream >> nomeComando;
            stream >> idRobo;

            bool comandoPrioritario = false;
            if(nomeComando[0] == '*'){
                comandoPrioritario = true;
                nomeComando.erase(0,1);
            }

            if(nomeComando == "ATIVAR"){
                base.Ativar(atoi(idRobo.c_str()));
            }else if(nomeComando == "EXECUTAR"){
                base.Executar(atoi(idRobo.c_str()));
            }else if(nomeComando == "RELATORIO"){
                base.Relatorio(atoi(idRobo.c_str()));
            }else if(nomeComando == "RETORNAR"){
                base.Retornar(atoi(idRobo.c_str()));
            }else if(nomeComando == "COLETAR"){
                base.GetRobo(atoi(idRobo.c_str()))
                    .AdicionarOrdemComando(comandoPrioritario, Coletar);
            }else if(nomeComando == "ELIMINAR"){
                base.GetRobo(atoi(idRobo.c_str()))
                    .AdicionarOrdemComando(comandoPrioritario, Eliminar);
            }else if(nomeComando == "MOVER"){
                //TODO GET X,Y
                base.GetRobo(atoi(idRobo.c_str()))
                    .AdicionarOrdemComando(comandoPrioritario, Comando(Mover, 0, 0));
            }else{
                throw "Erro! Comando desconhecido";
            }
        }
    }else{
        throw "Erro! Arquivo comandos.txt não foi encontrado";
    }
    arqComandos.close();
    
    return 0;
}