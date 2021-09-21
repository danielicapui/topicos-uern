import sys
from utills import *
def menu(op,vertices,grafo,pontos):
    if op==1:
        dij=Dijkstra(vertices,grafo)
        geradores,distancia= dij.find_route(pontos[0],pontos[1])
        caminhoMinimo(dij,geradores,distancia,pontos)
        custo=custoMinimo(grafo,pontos[0])
        print("-"*40)
        print("custo minimo de cada vertice:",custo)
    if op==2:
        ino=BelmannFord(vertices,grafo)
        distancias,geradores=ino.finder_route(pontos[0])
        print("caminhos:",distancias)
        print("predecessor:",geradores)
        caminhoMinimo(ino,geradores,distancias,pontos)
def main(nome=None,pontos=None):
    nome=nome or input("digite o nome do arquivo:")
    vertices,grafo=lerJson(nome)
    pontos=pontos or input("digite o ponto de origem e destino:").split()
    op=int(input("Digite 1 para dijkstra e 2 para BelmmanFord"))
    menu(op,vertices,grafo,pontos)
if __name__=='__main__':
    try:
        main(sys.argv[1],[sys.argv[2],sys.argv[3]])
    except IndexError:
        main(sys.argv[1])