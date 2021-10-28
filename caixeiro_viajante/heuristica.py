from funcoes import *
def minimo_percurso(grafo,rota):
    c=0
    for i in range(len(rota)):
        if i==len(rota)-1:
            break
        c=grafo[rota[i]][rota[i+1]]+c
    return c
def mudar(lista,index1,index2):
        lista[index1],lista[index2]=lista[index2],lista[index1]
        return lista
def sortear_numero(rota,start=None,end=None):
        if start==None and end==None:
            start,end=1,len(rota)-1
        n1,n2=random.sample(range(start,end),2)
        return n1,n2
def melhor_rota(rota_atual,rota_nova,custo_atual,custo_novo):
    if custo_novo<custo_atual:
        return rota_nova,custo_novo
    else:
        return rota_atual,custo_atual
#dicionario dij.grafo={}
#lista string dij.vertices=[]
class HeuristicaBuscaLocal:
    def __init__(self,dij=None,rota_inicial=None,custo_obtido=None):
        self.dij=dij
        self.rota_inicial=rota_inicial
        self.custo_obtido=custo_obtido
    def mudar_rota(self,nova_rota):
        self.rota_inicial=nova_rota
        return self.rota_inicial
    def obter_solucao(self,depth=None,custo_otimo=None,custo_obtido=None):
        rota_atual=self.rota_inicial[0:]
        custo_atual=self.custo_obtido
        c=0
        p=custo_atual
        for i in range(depth):
            n1,n2=sortear_numero(rota_atual)
            rota_nova=rota_atual[0:]
            mudar(rota_nova,n1,n2)
            custo_novo=minimo_percurso(self.dij.grafo,rota_nova)
            print(f'interação {i}: custo novo obtido:{custo_novo}')
            print(f'Caminho {" -> ".join(rota_nova)}')
            print("_"*150)
            rota_atual,custo_atual=melhor_rota(rota_atual,rota_nova,custo_atual,custo_novo)
            if custo_atual<=custo_otimo+10:
                print("Solução ideal:{} e {}.".format(custo_otimo,custo_atual))
                break
            if custo_atual<custo_obtido:
                print("Custo encontrado tem um valor mais otimizado do que obtido:{} e {}.".format(custo_obtido,custo_atual))
                break
            if custo_atual==p:
                c=c+1
            if c==50:
                print("50 valores localizados parando.")
                break
        print(c)
        return rota_atual,custo_atual
class HeuristicaGulosaAleatoria:
    def __init__(self,dij):
        self.dij=dij
    def obter_solucao(self,custo_otimo):
        rota=['1']
        