#calcular fibonacci con bottom up

def fibonacci_bottom_up(numero):
    f_parciales = [0, 1, 1] 
    while len(f_parciales) < numero:
        f_parciales.append(f_parciales[-1] + f_parciales[-2])
        print(f_parciales)  #muestra como se va llenando
    return f_parciales[numero-1]

print("Resultado:", fibonacci_bottom_up(5))