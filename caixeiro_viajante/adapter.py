from guloso import rotaMinima
class Adapter:
    @staticmethod
    def adaptar_matriz(grafo,adotado=0,adaptado=-1):
        for i in range(len(grafo)):
            for j in range(len(grafo[i])):
                    if grafo[i][j]==adotado:
                        grafo[i][j]=adaptado
        return grafo
    @staticmethod
    def adaptar_rota(matriz_i):
        rota,custo=rotaMinima(matriz_i)
        rota.insert(0,1)
        rota.append(rota[0])
        for i in range(len(rota)):
            rota[i]=str(rota[i])
        return rota,custo