import random
from utills import Dijkstra,caminhoMinimo
def sortearVertices(vertices,real=None):
    n=random.choice(vertices)
    if real==None and n=='h1' or n=='h2' or n=='h3' or n=='samu':
            sortearVertices(vertices,real)
    return n
def caminho_samu_acidente(dij,samu,acidente):
    geradores,distancias=dij.find_route(samu,acidente)
    c=caminhoMinimo(dij,geradores,distancias,[samu,acidente])
    return c,distancias[acidente]
def caminho_acidente_hospital(dij,acidente,hospital):
    geradores,distancias=dij.find_route(acidente,hospital)
    caminho=caminhoMinimo(dij,geradores,distancias,[acidente,hospital])
    return caminho,distancias[hospital]
def menor(x,y):
    if x<y:
        return x
    else:
        return y
def menor_acidente_hospital(dij,acidente):
    c1,h1=caminho_acidente_hospital(dij,acidente,'h1')
    c2,h2=caminho_acidente_hospital(dij,acidente,'h2')
    c3,h3=caminho_acidente_hospital(dij,acidente,'h3')
    d=menor(menor(h1,h2),h3)
    if d==h1:
        print("Melhor caminho hospital 1")
        return c1,d
    elif d==h2:
        print("Melhor Caminho hostital 2")
        return c2,d
    elif d==h3:
        print("Melhor Caminho hospital 3")
        return c3,d
def exibirDados(a1,c1,d1,ah1,ad1):
    print(f'Acidente {a1}: Custo mínimo {d1} e caminho mínimo:{" -> ".join(c1)} do acidente até o hospital custou {ad1} e caminho {" -> ".join(ah1)}')
    print(f'Custo total:{d1+ad1} e caminho {" -> ".join(c1+ah1)}')
def lerFile(nome):
    grafo=[]
    vertices=None
    c=0
    with open(nome) as f:
        for line in f:
            if c==0:
                vertices=line.split()
                c=c+1
            else:
                a=[int(i) for i in line.split()]
                grafo.append(a)
    return grafo,vertices
def lerDat(nome):
    grafo=[]
    vertices=[]
    c=0
    with open(nome) as f:
        for line in f:
            if c==0:
                c=int(line.split()[0])
            else:
                a=[]
                for i in line.split():
                    if i=='-1':
                        break
                    a.append(int(i))
                if a!=[]:
                    grafo.append(a)
    for i in range(1,c+1):
        if i==40:
            vertices.append('h1')
        elif i==19:
            vertices.append('h2')
        elif i==82:
            vertices.append('h3')
        elif i==83:
            vertices.append('samu')
        else:
            vertices.append(str(i))
    return grafo,vertices
def toDict(grafo,vertices):
    d={}
    for i in range(len(vertices)):
        p=vertices[i]
        d[p]={}
        for j in range(len(vertices)):
            a=vertices[j]
            valor=grafo[i][j]
            d[p][a]=valor
    return d