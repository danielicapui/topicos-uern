#ifndef ENCADEADA_H
#define ENCADEADA_H
#include<vector>
//g++ -c encadeada.cpp
//ar crv encadeada.a encadeada.o
//g++ main.cpp -o programa encadeada.a
//Cria biblioteca
//g++ -c -fpic encadeada.cpp
//g++ -shared -o encadeada.so encadeada.o
//teste
//g++ -L. -Wl,-rpath=. -Wall -o programa main.cpp -lencadeada

//Já tinha feito implementação em c, c++ e em python dela mas essa é baseado no modelo do professor. Só que utilizando dois struct
//Esse struct usamos para os nós da lista
    typedef struct no
    {
        int dado;
        no *prox;
    }no;
    //A lista propriamente dita, veja que tem dois ponteiros que guardam a posição do começo e fim da lista
    //Como também o tamanho da lista
    typedef struct Lista{
        no *start, *end;
        int tam;
    }Lista;
    void createLista(Lista *);
    int handle_exception();
    void addStart(Lista *,int);
    void addEnd(Lista *,int);
    void showLista(Lista *);
    void tamLista(Lista *);
    void removeLista(Lista *,int);
    bool inLista(Lista *,int);
    no* findElement(Lista *,int);
    std::vector<int> toVector(Lista *);
    void toLista(std::vector<int>&,Lista *);
    void mostrarVetor(std::vector<int>&);
    int particao(std::vector<int>&,int,int);
    //vetor,0,tamanho-1
    void quick_sort(std::vector<int>&,int,int);
    void trocar(std::vector<int>&,int,int);
    int particiona(std::vector<int>&,int,int,int);
    void quick_sortImperativo(std::vector<int>&,int,int);
    void deleteLista(Lista *);
    void orderLista(Lista *);
    int buscaBinariaRecursiva(int,int,int*,int);
    int buscaBinariaImperativa(int,int*,int);

#endif
