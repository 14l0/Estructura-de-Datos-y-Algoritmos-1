from string import digits
from itertools import product
from time import time

def buscador(contrasena):
    caracteres = digits  #solo se usa numeros
    archivo = open("combinaciones.txt", "w")  #aca se guardan las combinaciones

    if len(contrasena) in [4, 8, 10]:
        for comb in product(caracteres, repeat=len(contrasena)):
            prueba = "".join(comb)
            archivo.write(prueba + "\n")  
            if prueba == contrasena:
                print("Tu contraseña es:", prueba)
                break
    else:
        print("La contraseña debe tener 4, 8 o 10 dígitos")

    archivo.close()

t0 = time()
buscador("0987654321")   #aca probamos con 4, 8 y 10 digitos
print("Tiempo de ejecución:", round(time() - t0, 6))