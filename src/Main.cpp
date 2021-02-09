#include "Base.hpp"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    istringstream stream;

    if(argc < 3){
        cout << "Erro! Não foram informados os arquivos de texto necessários para a execução do sistema" << endl;
        return -1;
    }

    ifstream arqMapa(argv[1]); 
    string linha_mapa = "";
    char **mapa;
    int tamanhoX, tamanhoY;

    if(arqMapa.is_open()){
        getline(arqMapa, linha_mapa);
        stream = istringstream(linha_mapa);
        stream >> tamanhoX >> tamanhoY;

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
        arqMapa.close();
    } else {
        cout << "Erro! Arquivo " << argv[1] << " não foi encontrado" << endl;
        return -1;
    }
    Base base = Base(mapa, tamanhoX, tamanhoY);

    ifstream arqComandos(argv[2]);
    string linha_comandos;
    
    if(arqComandos.is_open()){
        try{
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
                        ->AdicionarOrdemComando(comandoPrioritario, Comando(Coletar));
                }else if(nomeComando == "ELIMINAR"){
                    base.GetRobo(atoi(idRobo.c_str()))
                        ->AdicionarOrdemComando(comandoPrioritario, Comando(Eliminar));
                }else if(nomeComando == "MOVER"){
                    string x, y;
                    stream.ignore(2);
                    getline(stream, x, ',');
                    getline(stream, y, ')');
                    base.GetRobo(atoi(idRobo.c_str()))->AdicionarOrdemComando
                        (comandoPrioritario, Comando(Mover, atoi(x.c_str()), atoi(y.c_str())));
                }else{
                    string mensagemErro = "Erro! Comando " + nomeComando + " desconhecido"; 
                    throw mensagemErro;
                    return -1;
                }
            }
        }catch(const string e){
            cout << e << endl;
            return -1;
        }
        base.ImprimirDadosFinais();
        arqComandos.close();
    }else{
        cout << "Erro! Arquivo " << argv[2] << " não foi encontrado" << endl;
        return -1;
    }
    return 0;
}