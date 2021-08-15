#ifndef UTILLS_H
#define UTILLS_H
#include <vector>
#include <iostream>
/**
 * define um tipo de struct no que armazena inteiros e o proximo no
 *
 * Example:
 * no* aux=lista->start;
 * aux->dado;
 * aux->prox;
 */
typedef struct no
{
    int dado;
    no *prox;
} no;
/**
 * define um tipo Lista que guarda o começo e o fim como também o tamanho dela dinamicamente
 *
 * Example:
 * Lista lista;
 * lista->tam=0;
 * lista->start=NULL;
 * lista->end=NULL;
 */
typedef struct Lista
{
    no *start, *end;
    int tam;
} Lista;
/**
 * iniciar uma lista, primeira operação
 * Example:
 * createLista(&lista);
 */
void createLista(Lista *);
//uma função que gera inteiros seguros
int handle_exception();
/**
 * inserção no começo
 *
 * Example:
 * addStart(&lista,5);
 */
void addStart(Lista *, int);
/**
 * inserção no fim
 *
 * Example:
 * addEnd(&lista,5);
 */
void addEnd(Lista *, int);
/**
 * exibe o conteudo de uma lista
 * Example:
 * showLista(&lista);
 */
void showLista(Lista *);
/**
 * exibe o tamanho da lista
 *
 * Example:
 * tamlista(&lista);
 */
void tamLista(Lista *);
/**
 * remove um elemento
 *
 * Example:
 * removeLista(&lista,5);
 */
void removeLista(Lista *, int);
/**
 * verifica se um elemento está na lista e retorna true ou false
 *
 * Example:
 * inLista(&lista,2);
 */
bool inLista(Lista *, int);
/**
 * verifica se um elemento está na lista e retorna o no
 *
 * Example:
 * findElement(&lista,2);
 */
no *findElement(Lista *, int);
/**
 * transforma uma lista em vetor de mesmo tamanho
 *
 * Example:
 * toVector(&lista);
 */
std::vector<int> toVector(Lista *);
/**
 * transforma em lista a partir de um std::vector<int>
 *
 * Example:
 * toLista(vetor,&lista);
 */
void toLista(std::vector<int> &, Lista *);
/**
 * exibe um vetor std::vector<int>
 *
 * Example:
 * mostrarVetor(vetor);
 */
void mostrarVetor(std::vector<int> &);
/**
 * particiona um vetor função do quick_sort
 *
 * Example:
 * particao(vetor,inicio,fim);
 */
int particao(std::vector<int> &, int, int);
/**
 * ordenar um elemento std::vector<int> um array primitivo tambem é possivel com uma pequena alteração;
 *
 * Example:
 * quick_sort(vetor,0,vetor.size()-1);
 */
void quick_sort(std::vector<int> &, int, int);
/**
 * troca a posição de dois números em um vetor
 * Example:
 * trocar(vetor,4,5);
 */
void trocar(std::vector<int> &, int, int);
/**
 * particiona um vetor função do quick_sort
 *
 * Example:
 * particao(vetor,inicio,fim);
 */
int particiona(std::vector<int> &, int, int);
/**
 * ordenar um elemento std::vector<int> um array primitivo tambem é possivel com uma pequena alteração;
 * de modo imperativo ou interado
 * Example:
 * quick_sort(vetor,0,vetor.size()-1);
 */
void quick_sortImperativo(std::vector<int> &, int, int);
/**
 * excluir os elementos de uma lista e deixa vazia
 * Example:
 * deleteLista(&lista);
 */
void deleteLista(Lista *);
/**
 * ordenar uma lista utilizando a classe de std::vector como controle, todos os elementos serão excluidos e será
 * chamado a função de ordenação quick_sort o resultado será transformado em uma lista e adicionado na lista original.
 * Example:
 * orderLista(&lista);
 */
void orderLista(Lista *);
/**
 * busca um número em um vetor e retorna sua posição de forma recursiva
 * Example:
 * buscaBinariaRecursiva(primeiro,ultimo,vetor,numero_desejado);
 */
int buscaBinariaRecursiva(int, int, int *, int);
/**
 * busca um número em um vetor e retorna sua posição de forma imperativa
 * Example:
 * buscaBinariaImperativa(tamanho_vetor,vetor,numero_desejado);
 */
int buscaBinariaImperativa(int, int *, int);

#endif
