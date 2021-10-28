def rotaMinima(tsp):
    soma = 0
    counter = 0
    j = 0
    i = 0
    minimo = 9999
    cidades_visitadas = {}

    for x in range(len(tsp)):
        cidades_visitadas[x] = 0
    
    cidades_visitadas[0] = 1
    rota = [0 for x in range(len(tsp))]

    while i < len(tsp) and j < len(tsp[i]):
    
        if counter >= len(tsp[i]) - 1:
            break

        if j != i and cidades_visitadas[j] == 0:

            if tsp[i][j] < minimo:
                minimo = tsp[i][j]
                rota[counter] = j + 1
        j += 1

        if j == len(tsp[i]):
            soma += minimo
            minimo = 9999
            cidades_visitadas[rota[counter] - 1] = 1
            j = 0
            i = rota[counter] - 1
            counter += 1

    i = rota[counter - 1] - 1

    for k in range(len(tsp)):
        if (i != k) and (tsp[i][k] < minimo):
            minimo = tsp[i][k]
            rota[counter] = k + 1
    
    soma += minimo
    return rota, soma

    #tsp = [[-1, 10, 15, 20],[10, -1, 35, 25],[15, 35, -1, 30],[20, 25, 30, -1]]
    #rota, soma = rotaMinima(tsp)
    #print(f'O custo mínimo é {soma}')
    #print('->'.join(str(vertice) for vertice in rota))
    


