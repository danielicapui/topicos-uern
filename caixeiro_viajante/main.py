import sys
from heuristica import *
from adapter import Adapter
from guloso import rotaMinima
def mostrar_guloso(matriz):
    global rota_inicial,custo_inicial
    rota_inicial,custo_inicial=Adapter.adaptar_rota(Adapter.adaptar_matriz(matriz,0,-1))
    print("Algoritmo guloso")
    print(f'Custo total:{custo_inicial} e caminho {" -> ".join(rota_inicial)}')
    print(f'Custo minimo:{(custo_inicial-13)}')
    print("-"*150)
def mostrar_busca_local(dij):
    h=HeuristicaBuscaLocal(dij,rota_inicial,custo_inicial)
    r,c=h.obter_solucao(1000,2085,custo_inicial)
    print(f'Custo total:{c} e caminho {" -> ".join(r)}')
    print(f"Custo sem a cidade inicial:{c-13}")
def main(argv):
    #carregando arquivo
    matriz,vertices=lerDat(argv[1])
    grafo=toDict(matriz,vertices)
    dij=Dijkstra(vertices,grafo)
    #Procesamento de dados e calculos de guloso
    mostrar_guloso(matriz)
    #Processamento de dados e calculos de busca local
    mostrar_busca_local(dij)
if __name__=='__main__':
    main(sys.argv)