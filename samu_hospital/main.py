from funcoes import *
def q1b1(grafo):
    s=sortearVertices(grafo)
    t=s
    while(t==s):
        t=sortearVertices(grafo)
    print(f'Foi sorteado {t} e {s}')
    return s,t
#poderia deixar só uma mas só para enumerar
def q1b2(dij,a1=None,a2=None):
    if a1==None and a2==None:
        a1,a2=q1b1(dij.vertices)
    c1,d1=caminho_samu_acidente(dij,'samu',a1)
    c2,d2=caminho_samu_acidente(dij,'samu',a2)
    return c1,d1,c2,d2
#parecida com a q1b2
def q1b3(dij,a1=None,a2=None):
    if a1==None and a2==None:
        a1,a2=q1b2(dij.vertices,a1,a2)
    c1,d1=menor_acidente_hospital(dij,a1)
    c2,d2=menor_acidente_hospital(dij,a2)
    return c1,d1,c2,d2
def q2(a1,c1,d1,ah1,ad1,a2,c2,d2,ah2,ad2):
    exibirDados(a1,c1,d1,ah1,ad1)
    exibirDados(a2,c2,d2,ah2,ad2)
def main():
    dij=None
    a1,a2=None,None
    c1,d1,c2,d2=None,None,None,None
    ah1,ad1,ah2,ad2=None,None,None,None
    #h1,h2,h3=40,19,82
    #samu=83
    while True:
        op=int(input("Digite 1 para sortear dois locais de acidente:\nDigite 2 para calcular distância de samu ao local dos acidentes:\nDigite 3 para ler txt e 4 para ler dat:\nDigite 5 para ver o caminho e distancia entre os acidentes e os hospitas\nDigite 6 para encontrar o melhor caminho+ custo da samu->acidente->hospital\nDigite 666 para encerrar:\n"))
        if op==666:
            break
        elif dij!=None and op==1:
            a1,a2=q1b1(dij.vertices)
        elif dij!=None and op==2:
            c1,d1,c2,d2=q1b2(dij)
        elif op==3:
            file=input("digite o nome do arquivo:")
            grafo,vertices=lerFile(file)
            d=toDict(grafo,vertices)
            dij=Dijkstra(vertices,d)
        elif op==4:
            file=input("digite o nome do dat:")
            grafo,vertices=lerDat(file)
            d=toDict(grafo,vertices)
            dij=Dijkstra(vertices,d)
        elif op==5:
            ah1,ad1,ah2,ad2=q1b3(dij,a1,a2)          
        elif op==6:
            q2(a1,c1,d1,ah1,ad1,a2,c2,d2,ah2,ad2)
        print("\n")
    return 0
if __name__=='__main__':
    main()