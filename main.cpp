#include "encadeada.h"
#include <iostream>
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
    else if (op==7)
        return 999;
    else if(op==6)
    {
        numero=handle_exception();
        if(inLista(lista,numero))
        {
            std::cout<<"Elemento na lista:"<<numero<<std::endl;
        }
        else
            std::cout<<"Elemento nao existe na lista:"<<numero<<std::endl;
    }
    else if(op==8)
    {
        orderLista(lista);
    }
    else if(op==9)
    {
        deleteLista(lista);
    }
    else
    {
        std::cout<<"Error 1:Opção inválida, Digite novamente"<<std::endl;
        return 1;
    }
    return 0;
}
int q1()
{
    int op=0;
    Lista lista;
    createLista(&lista);
    do
    {
        std::cout<<"\nDigite 1: Adiciona número no começo\nDigite 2:Adicionar número no fim\nDigite 3: Remover um número\nDigite 4:Mostrar Lista\nDigite 5:Mostrar tamanho da lista\nDigite 6:Para verificar se um elemento está na lista\nDigite 7:Para encerrar\nDigite 8:Para ordenar a lista\n\Digite 9:Para excluir a lista\n"<<std::endl;
        op=handle_exception();
        op=menu(&lista,op);
        if (op==999)
            break;

    } while (op!=999);
    return 0;
}
int q2()
{
    std::cout<<"Parta a modo recursivo!"<<std::endl;
    std::vector<int>usagi={1,2,40,10,30,2,34,1,23,1,31,31,3,3,4,5,89};
    quick_sort(usagi,0,usagi.size()-1);
    mostrarVetor(usagi);
    std::cout<<"Parta b modo imperativo!"<<std::endl;
    std::vector<int> usagi1={1,25,3,142,312};
    quick_sortImperativo(usagi1,0,usagi.size()-1);
    mostrarVetor(usagi1);
    return 0;
}
int q3()
{
    int v1[] = {1, 3, 5, 6, 9, 12, 15, 20, 25};
    std::cout<<"Parte a modo imperativo";
    int n=buscaBinariaImperativa(9,v1,20);
    std::cout<<"Parte b modo recursivo";
    int n1=buscaBinariaRecursiva(0,9,v1,20);
    std::cout<<"Numero encontrado em:"<<n<<std::endl;
    std::cout<<"Numero encontrado em:"<<n1<<std::endl;
    return 0;
}

int main()
{
    q1();
    q2();
    q3();
    return 0;
}
