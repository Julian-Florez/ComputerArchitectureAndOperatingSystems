from collections import Counter
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.pyplot import savefig
from pandas.plotting import table



with open('datadisckArqui','r') as file:
    numbers = [int(line.strip()) for line in file]
numbers.sort()

frecuencia = Counter(numbers)
for i in frecuencia:
    frecuencia[i] = frecuencia[i]/len(numbers)
numbersfrecu = list(frecuencia.keys())
frecu = list(frecuencia.values())

data = {
    'Number': numbersfrecu,
    'Frecuencia': frecu

    
}
df = pd.DataFrame(data)
df.to_csv('Tabla_de_frecuencia.csv', index=False)
plt.plot(numbersfrecu,frecu)
plt.ylabel('Frecuencia')
plt.xlabel('Tamaño de archivos')
plt.title('Grafico de Frecuencias')
savefig('Grafico')















# Plotting the data
