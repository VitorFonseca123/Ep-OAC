numero = int(input("Digite um número inteiro: "))
binario = bin(numero)[2:]
print(binario)
vetor_binario = []

for digito in binario:
    vetor_binario.append(digito)

print("Vetor binário:", vetor_binario)