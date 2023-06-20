def numero_para_vetor_binario(numero, tamanho):
    binario = format(numero, '0' + str(tamanho) + 'b')  # Obtém a representação binária com zeros à esquerda
    vetor_binario = [int(digito) for digito in binario]  # Converte cada dígito em um inteiro e cria uma lista
    return vetor_binario

n = int(input("Digite o valor de n: "))
ReprN = numero_para_vetor_binario(n,32)
print("Vetor binário:", ReprN)

