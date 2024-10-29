import matplotlib.pyplot as plt

# Leer el archivo ping.txt
with open('ping.txt', 'r') as file:
    lines = file.readlines()

# Extraer los tiempos de cada ping
times = []
for line in lines:
    parts = line.split()
    for part in parts:
        if part.startswith('time='):
            time_str = part.split('=')[1]
            time_ms = float(time_str.replace('ms', ''))
            times.append(time_ms)
            break

# Crear la gráfica
plt.plot(times, marker='o')
plt.title('Tiempo de cada ping')
plt.xlabel('Número de ping')
plt.ylabel('Tiempo (ms)')
plt.grid(True)
plt.show()