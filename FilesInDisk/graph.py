from collections import Counter
import matplotlib.pyplot as plt

# Leer los números del archivo sizes.txt
with open('/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/FilesInDisk/sizes2.txt', 'r') as file:
    numbers = [int(line.strip()) for line in file]

# Contar la frecuencia de cada número
counter = Counter(numbers)

# Preparar los datos para la gráfica
labels, values = zip(*sorted(counter.items()))

print(max(numbers))
# Crear la gráfica de líneas
plt.plot(labels, values, marker='o')

# Añadir título y etiquetas
plt.title('Frecuencia de Números en sizes.txt')
plt.xlabel('Número')
plt.ylabel('Frecuencia')

# Mostrar la gráfica
plt.savefig("sizes.png")
plt.show()
