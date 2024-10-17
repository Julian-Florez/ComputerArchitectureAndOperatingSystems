import subprocess
import matplotlib.pyplot as plt
import pandas as pd

# Run runner.py
subprocess.run(['python', 'runner.py'])

# Run runner.exe
subprocess.run(['runner.exe'])

# Write to time.txt
with open('time.txt', 'r+') as file:
    lines = file.readlines()
    file.seek(0, 0)
    file.write("numbers, Iterative on Python, Recursive on Python, Iterative on C, Recursive on C\n" + ''.join(lines))

# Read times from time.txt
times = []
with open('time.txt', 'r') as file:
    for line in file.readlines()[1:]:
        times.append(list(map(float, line.strip().split(',')[1:])))

# Prepare data for plotting
numbers = list(range(1, len(times) + 1))
iterative_python = [time[0] for time in times]
recursive_python = [time[1] for time in times]
iterative_c = [time[2] for time in times]
recursive_c = [time[3] for time in times]

# Calculate differences
iterative_diff = [iterative_c[i] - iterative_python[i] for i in range(len(iterative_python))]
recursive_diff = [recursive_c[i] - recursive_python[i] for i in range(len(recursive_python))]
c_faster_iterative = [iterative_python[i] / iterative_c[i] for i in range(len(iterative_python))]
c_faster_recursive = [recursive_python[i] / recursive_c[i] for i in range(len(recursive_python))]

# Create a DataFrame for the table
data = {
    'Number': numbers,
    'Iterative on Python': iterative_python,
    'Recursive on Python': recursive_python,
    'Iterative on C': iterative_c,
    'Recursive on C': recursive_c,
    'Iterative Diff (C - Python)': iterative_diff,
    'Recursive Diff (C - Python)': recursive_diff,
    'C Faster Iterative (times)': c_faster_iterative,
    'C Faster Recursive (times)': c_faster_recursive
}
df = pd.DataFrame(data)
df.to_csv('time_comparison.csv', index=False)



# Plotting the data
plt.plot(numbers, iterative_python, label='Iterative on Python')
plt.plot(numbers, recursive_python, label='Recursive on Python')
plt.plot(numbers, iterative_c, label='Iterative on C')
plt.plot(numbers, recursive_c, label='Recursive on C')

plt.xlabel('Numbers')
plt.ylabel('Time (s)')
plt.title('Comparison of Execution Times (10 million iterations)')
plt.legend()
plt.savefig('time.png', dpi=300)

# Create a table image using the DataFrame
fig, ax = plt.subplots(figsize=(10, 6))  # set size frame
ax.axis('tight')
ax.axis('off')
table = ax.table(cellText=df.values, colLabels=df.columns, cellLoc='center', loc='center')

# Save the table as an image
plt.savefig('time_comparison_table.png', bbox_inches='tight', dpi=300)