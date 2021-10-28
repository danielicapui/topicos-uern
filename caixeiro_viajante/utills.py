import json
from collections import defaultdict
class Deque:
    def __init__(self,lista=None):
        self.lista=lista or []
    def setLista(self,lista):
        self.lista=lista
    def addRight(self,item):
        self.lista.append(item)
    def addLeft(self,item):
        self.lista.insert(0,item)
    def removerRight(self):
        return self.lista.pop()
    def removerLeft(self):
        return self.lista.pop(0)
    def clear(self):
        self.setLista([])
    def isVazia(self):
        return self.lista==[]
    def tamanho(self):
        return len(self.lista)
    def __str__(self):
        return str(self.lista)
    def __repr__(self):
        return str(self.lista)
class Grafo:
    def __init__(self,arestas=None,vertices=None):
        self.arestas=arestas or []
        self.vertices=vertices or []
    def addAresta(self,aresta):
        if aresta not in self.arestas:
            self.arestas.append(aresta)
    def addVertice(self,vertice):
        if vertice not in self.vertices:
            self.vertices.append(vertice)
    def toDict(self):
        d={}
        for i in range(len(self.vertices)):
            p=self.vertices[i]
            d[p]={}
            for j in range(len(self.vertices)):
                a=self.vertices[j]
                valor=self.arestas[i][j]
                d[p][a]=valor
        return d


class Dijkstra:
    def __init__(self, vertices=None, grafo=None):
        self.vertices = vertices 
        self.grafo = grafo 
    def find_route(self, inicial, final):
        caminhos = {n: float("inf") for n in self.vertices} #coloca infinito para os vertices
        caminhos[inicial] = 0  # adiciona 0 ao custo do vertice inicial
        visitados = {}  # dicionario de nós visitados
        geradores = {}  # predecessors
        while caminhos:
            minimo = min(caminhos, key=caminhos.get) 
            #usamos a função mínimo para pegar a chave com o menor valor
            valores=self.grafo.get(minimo, {}).items()
            for vizinho,_ in valores:
                #usamos o minimo para pegar os items com o menor custo
                if vizinho in visitados:
                    continue
                nova_distancia = caminhos[minimo] + self.grafo[minimo].get(vizinho, float("inf"))
                if caminhos[vizinho]>nova_distancia:
                    caminhos[vizinho] = nova_distancia
                    geradores[vizinho] = minimo
            visitados[minimo] = caminhos[minimo]
            caminhos.pop(minimo)
            if minimo == final:
                break
        return geradores, visitados
    @staticmethod
    def path_finder(inicial,final,geradores):
        path = [final]
        while True:
            key = geradores[path[0]]
            path.insert(0, key)
            if key == inicial:
                break
        return path
class BelmannFord:
    def __init__(self,vertices,grafo):
        self.vertices=vertices
        self.grafo=grafo
    def relaxar(self):
        for _ in range(len(self.vertices)-1):
            for ponto in self.grafo:
                for vizinho in self.grafo[ponto]:
                # se a distancia é menor
                    if self.caminhos[ponto] + self.grafo[ponto][vizinho]<self.caminhos[vizinho]:
                        self.caminhos[vizinho]=self.caminhos[ponto] + self.grafo[ponto][vizinho]
                        self.geradores[vizinho]=ponto

    def verificarCiclo(self):
        for ponto in self.grafo:
            for vizinho in self.grafo[ponto]:
                if self.caminhos[vizinho] != float("Inf") and self.grafo[ponto][vizinho] + self.caminhos[ponto] >= self.caminhos[vizinho]:
                    print("gráfico possuí um ciclo negativo")
                    return True
        return False
    def finder_route(self,inicial):
        #preencher com infinito e colocar 0 no vertice inicial
        self.caminhos = {n: float("inf") for n in self.vertices} 
        self.caminhos[inicial]=0
        self.geradores={}
        self.relaxar()
        self.verificarCiclo()
        return self.caminhos,self.geradores
    def path_finder(self,origem,destino,caminhos=None,geradores=None):
        self.distancia=caminhos or self.caminhos
        self.rotas=geradores or self.geradores
        caminho=[destino]
        atual=destino
        while atual!=origem:
            atual=self.rotas[atual]
            caminho.append(atual)
        caminho.reverse()
        return caminho
 
def custoMinimo(grafo,vertice,testes=1):
    fila = Deque([vertice])
    custo = {vertice: 0}
    c=0
    while not fila.isVazia():
        atual = fila.removerLeft()
        if grafo[atual]=={}:
            break
        if(c==0):
            print("Visitando o vértice: " + str(atual))
        else:
            print("Testando em busca de menores caminhos")
        for vizinho in grafo[atual]:
                fila.addRight(vizinho)
                novo_custo = custo[atual] + grafo[atual][vizinho]
                if (vizinho not in custo or novo_custo < custo[vizinho]):
                    custo[vizinho] = novo_custo
                    print("O vértice " + str(vizinho) + " foi atualizado com o custo: " + str(novo_custo))
                    
    return custo

#grafo em dicionário 
def lerArquivo(nome):  
    grafo=Grafo()
    c=0
    with open(nome) as f:
        for line in f:
            if c==0:
                for i in line.split():
                    grafo.addVertice(i)
                c=c+1
            else:
                l=line.split()
                grafo.addAresta([l[0],l[1],int(l[2])])
    return grafo
def lerJson(nome):
    grafo=json.load(open(nome))
    vertices=[i for i in grafo.keys()]
    print("Vertices:",vertices)
    print("Grafo:",grafo)
    return vertices,grafo
def caminhoMinimo(dij,geradores,distancias,pontos):
    print("Distancia de {} para {} é: {:.3f}".format(pontos[0],pontos[1],distancias[pontos[1]]))
    caminho= dij.path_finder(pontos[0],pontos[1],geradores)
    print("O caminho de {} para {} é: {}".format(pontos[0],pontos[1]," -> ".join(caminho)))
    return caminho
