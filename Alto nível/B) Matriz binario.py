def numero_para_vetor_binario(numero, tamanho):
    binario = format(numero, '0' + str(tamanho) + 'b')  # Obtém a representação binária com zeros à esquerda
    vetor_binario = [int(digito) for digito in binario]  # Converte cada dígito em um inteiro e cria uma lista
    return vetor_binario
def construir_matriz(n, m):

    ReprN = numero_para_vetor_binario(n, m.bit_length())
    ReprM = numero_para_vetor_binario(m, n.bit_length())
    print(ReprN)
    print(ReprM)
    matriz = []
    for i in range(len(ReprN)):
        linha = []
        for j in range(len(ReprM)):
            if ReprN[i] == 1 and ReprM[j] == 1:
                linha.append('*')
            else:
                linha.append("'")
        matriz.append(linha)

    return matriz


n = int(input("Digite o valor de n: "))
m = int(input("Digite o valor de m: "))


matriz_a = construir_matriz(n, m)
for linha in matriz_a:
    print(' '.join(linha))

