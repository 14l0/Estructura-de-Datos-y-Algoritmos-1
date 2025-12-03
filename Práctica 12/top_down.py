memoria = {1: 0, 2: 1, 3: 1} #memoria inicial

def fibonacci_iterativo_v2(numero):
    f1, f2 = 0, 1
    for i in range(1, numero-1):
        f1, f2 = f2, f1 + f2
    return f2

def fibonacci_top_down(numero):
    if numero in memoria:
        return memoria[numero]
    f = fibonacci_iterativo_v2(numero-1) + fibonacci_iterativo_v2(numero-2)
    memoria[numero] = f
    return memoria[numero]

print("Resultado:", fibonacci_top_down(12))
print("Memoria:", memoria)