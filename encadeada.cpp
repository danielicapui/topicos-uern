#include <iostream>
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
//Tratar alguns erros de inputs de usuários 
int handle_exception()
{
    int numero;
    while (true)
    {
        std::cout<<"Digite um inteiro válido:"<<std::endl;
        try
        {
            std::cin>>numero;
            return numero;
        }
        catch (const char* err)
        {
            std::cerr<<"Erro:"<<err<<std::endl;
        }
        catch (...)
        {
            std::cerr<<"Erro não tratado"<<std::endl;
        }    
        
    }
}
//Função de adiciona no começo
void addStart(Lista *lista,int numero)
{
    //ponteiro auxilar do numero
    no *aux=(no*)malloc(sizeof(no));
    aux->dado=numero;
    //Verifica se o começo é nulo 
    if (lista->start!=NULL)
    {
        //atribui o numero e muda o ponteiro.
        aux->prox=lista->start;
        lista->start=aux;
    }
    else
    {
        //como é nulo basta apontar para nulo e atribuir os valores da variavel auxiliar para a lista 
        aux->prox=NULL;
        lista->start=aux;
        lista->end=aux;
    }
    //Importante aqui é para controlar o tamanho da lista
    lista->tam++;
}
//Função de adicionar no final, perceba as diferenças? Encontrou alguma? 
void addEnd(Lista *lista,int numero)
{
    //aqui para quem usa c, sabe que precisa alocar
    no *aux=(no*)malloc(sizeof(no));
    aux->dado=numero;
    aux->prox=NULL;
    if (lista->start!=NULL)
    {
        lista->end->prox=aux;
        lista->end=aux;
    }
    else
    {
        lista->start=aux;
        lista->end=aux;
    }
    lista->tam++;
}
//Função para mostrar a lista
void showLista(Lista *lista)
{
    no *start=lista->start;
    for(int i=0;i<lista->tam;i++)
    {
        std::cout<<"index: "<<i<<" "<<start->dado<<std::endl;
        start=start->prox;
    }
}
void tamLista(Lista *lista)
{
    std::cout<<"Tamanho da lista: "<<lista->tam<<std::endl;
}
void removeLista(Lista *lista, int numero)
{
    //ponteiros auxiliares
    no *start= lista->start;
    no *ptrash=NULL;
    //Caso o elemento a ser removido seja o primeiro
    if (lista->start->dado==numero && start!=NULL)
    {
        ptrash=lista->start;
        lista->start=ptrash->prox;
        //Apontamos nosso fim para nulo
        if (lista->start==NULL)
        {
            lista->end= NULL;
        }
    }
    else
    {
        //movemos o ponteiro//lista até encontrar o elemento 
        while(start->prox !=NULL && start->prox->dado !=numero && start !=NULL)
        {
            start=start->prox;
        }
        if (start !=NULL && start->prox !=NULL)
        {
            ptrash= start->prox;
            start->prox=ptrash->prox;
            //Caso o último elemento for removido
            if (start->prox==NULL)
            {
                lista->end=start;
            }
        }
    }
    //limpamos o lixo e diminuimos o tamanho da lista
    if (ptrash)
    {
        free(ptrash);
        lista->tam--;
    }
}
int menu(Lista *lista,int op)
{
    int numero;
    if (op==1 || op==2 || op==3)
    {
        numero=handle_exception();
        if (op==1)
            addStart(lista,numero);
        else if (op==2)
            addEnd(lista,numero);
        else
            removeLista(lista,numero);
    }
    else if (op==4)
        showLista(lista);
    else if (op==5)
        tamLista(lista);
    else if (op==6)
        return 999;
    else
    {
        std::cout<<"Error 1:Opção inválida, Digite novamente"<<std::endl;
        return 1;
    }
    return 0;
}
//função para iniciar  listas com valores padrão
void createLista(Lista *lista)
{
    lista->start=NULL;
    lista->end=NULL;
    lista->tam=0;
}
int main()
{
    int op=0;
    Lista lista;
    createLista(&lista);
    do
    {
        std::cout<<"Digite 1: Adiciona número no começo\nDigite 2:Adicionar número no fim\nDigite 3: Remover um número\nDigite 4:Mostrar Lista\nDigite 5:Mostrar tamanho da lista\nDigite 6:Para encerrar"<<std::endl;
        op=handle_exception();
        op=menu(&lista,op);
        if (op==999)
            break;
    } while (op!=999);
    
    return 0;
}
