from matplotlib import pyplot as plt

resultsBubble = open('resultsBS.txt', 'r')
resultsInsertion = open('resultsIS.txt', 'r')
resultsSelection = open('resultsSS.txt', 'r')

nArray = []
timeBubble = []
timeInsertion = []
timeSelection = []


for line in resultsBubble:
    n, time = line.split()
    nArray.append(int(n))
    timeBubble.append(float(time) * 0.001)

for line in resultsSelection:
    _, time = line.split()
    timeSelection.append(float(time) * 0.001)

for line in resultsInsertion:
    _, time = line.split()
    timeInsertion.append(float(time) * 0.001)


plt.plot(nArray, timeBubble)
plt.plot(nArray, timeSelection)
plt.plot(nArray, timeInsertion)
plt.title('Szybkość algorytmów sortowania')
plt.xlabel("rozmiar danych wejściowych (n)")
plt.ylabel('czas sortowania (s)')
plt.grid(True)
plt.legend(['bąbelkowe', 'wybieranie', 'wstawianie'])

plt.show()
