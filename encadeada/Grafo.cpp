#include<iostream>
#include<vector>
#include <fstream>
#include<string>
class Aresta
{
    private:
        std::string origem,destino;
        int custo;
    public:
        Aresta(std::string o1,std::string df,int c1)
        {
            origem=o1;
            destino=df;
            custo=c1;
        }
        std::string getOrigem()
        {
            return origem;
        }
        std::string getDestino()
        {
            return destino;
        }
        int getCusto()
        {
            return custo;
        }
        void setOrigem(std::string o1)
        {
            origem=o1;
        }
         void setDestino(std::string df)
        {
            destino=df;
        }
         void setCusto(int c1)
        {
            custo=c1;
        }
        void show()
        {
            std::cout<<"origem:"<<getOrigem()<<" destino:"<<getDestino()<<" custo:"<<getCusto()<<std::endl;
        }
};
class Vertice
{
    private:
        std::vector<Aresta> arestas;
    public:
        Vertice(std::vector<Aresta> a1)
        {
            arestas=a1;
        }
        Aresta getAresta(int pos)
        {
            return arestas[pos];
        }
        std::vector<Aresta> getAresta()
        {
            return arestas;
        }
        void addAresta(Aresta a1)
        {
            arestas.push_back(a1);
        }
        bool isStep(Aresta a,std::vector<std::string> visitados)
        {
            for(auto v:visitados)
                if (v==a.getDestino())
                    return true;
            return false;
        }
        int minCusto(std::vector<std::string> visitados)
        {
            int minimo=9999999;
            for(auto a:getAresta())
            {
                if(!isStep(a,visitados))
                {
                    if (a.getCusto()<=minimo)
                        minimo=a.getCusto();
                }
            }
            return minimo;
        }
        std::vector<Aresta> getForCusto(int c1,std::vector<std::string> visitados)
        {
            std::vector<Aresta> aux;
            for(auto a:getAresta())
            {
                if(a.getCusto()==c1 && !isStep(a,visitados))
                {
                    aux.push_back(a);
                }
            }
            return aux;
        }
        void showAresta()
        {
            for(auto a:getAresta())
                a.show();
        }
};
class Grafo
{
    private:
        std::vector<Vertice> pontos;
    public:
        Grafo(std::vector<Vertice>p1)
        {
            pontos=p1;
        }
        Vertice getPontos(int pos)
        {
            return pontos[pos];
        }
        Vertice getPontos(std::string nome)
        {
            for(auto p:pontos)
            {
                if (p.getAresta(0).getOrigem()==nome)
                    return p;
            }
        }
        Vertice andarVertice(std::string destino)
        {
            for(auto p:getPontos())
            {
                if (p.getAresta(0).getOrigem()==destino)
                    return p;
            }
        }
        Vertice findPontos(std::string inicio,std::string fim)
        {
            for(auto p:pontos)
            {
                if (p.getAresta(0).getOrigem()==inicio && p.getAresta(0).getDestino()==fim)
                    return p;
            }
        }
        std::vector<Vertice> getPontos()
        {
            return pontos;
        }
        void setPontos(std::vector<Vertice> p1)
        {
            pontos=p1;
        }
        void addPontos(Vertice p1)
        {
            pontos.push_back(p1);
        }
        void showPontos()
        {
            for(auto p:getPontos())
            {
                std::cout<<"Mostrando do ponto:"<<p.getAresta(0).getOrigem()<<std::endl;
                p.showAresta();
                std::cout<<"Fim das arestas.\n"<<std::endl;
            }
        }
        int minimoCaminho(std::string inicial,std::string final)
        {
            int valor=0;
            Vertice ini=getPontos(inicial);
            Vertice fin=getPontos(final);
            Vertice atual=ini;
            std::vector<Aresta> rota;
            std::vector<std::string>visitados;
            visitados.push_back(atual.getAresta(0).getOrigem());
            bool visitado=false;
            while(!visitado)
            {
                if(atual.getAresta(0).getOrigem()==fin.getAresta(0).getOrigem())
                {
                    std::cout<<"distância mínima:"<<valor<<" caminho:"<<std::endl;
                    std::cout<<ini.getAresta(0).getOrigem()<<" ";
                    for(auto m:rota)
                    {
                        std::cout<<m.getDestino()<<" ";
                    }
                    break;
                }
                int t=atual.minCusto(visitados);
                valor=valor+t;
                std::cout<<valor<<std::endl;
                std::vector<Aresta> caminhos=atual.getForCusto(t,visitados);
                rota.push_back(caminhos[0]);
                atual=andarVertice(caminhos[0].getDestino());
                visitados.push_back(atual.getAresta(0).getOrigem());
            }
            return valor;
        }
};

std::vector<Vertice>lerArquivo(std::string nome)
{
    std::ifstream infile;
    std::string origem,destino,custo,anterior;
    infile.open(nome);
    std::vector<Aresta> aux;
    std::vector<Vertice> pontos;
    int n=0;
    if (infile.is_open() && infile.good())
    { 
        while(infile>>origem>>destino>>custo)
        { 
            if(n==0)
            {
                anterior=origem;
                n=1;
            }
            if(origem!=anterior)
            {
                pontos.push_back(aux);
                aux.clear();
                anterior=origem;  
            }
            std::cout<<"origem:"<<origem<<" destino:"<<destino<<" custo:"<<custo<<std::endl;
            Aresta a(origem,destino,stoi(custo));
            aux.push_back(a);   
        }
        pontos.push_back(aux);
        infile.close();
    }
    return pontos;
}

int main()
{
    Grafo g(lerArquivo("entrada.txt"));
    g.minimoCaminho("a","d");
    return 0;
}
