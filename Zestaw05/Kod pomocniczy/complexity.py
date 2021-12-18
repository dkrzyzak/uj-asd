executionTimeListFromFile = open('averageTimeForBS.txt', 'r')
complexityListFromFile = open('averageComplexityForBS.txt', 'r')

executionTime = []
swapOperations = []
compareOperations = []

for line in executionTimeListFromFile:
    _, time = line.split()
    executionTime.append(float(time))

for line in complexityListFromFile:
    compare, swap = line.split()
    compareOperations.append(int(compare))
    swapOperations.append(int(swap))


print("wrażliwość: ", max(executionTime) - min(executionTime))
print("Złożoność oczekiwana operacji porównywania: ", sum(compareOperations) / len(compareOperations))
print("Złożoność oczekiwana operacji zamieniania: ", sum(swapOperations) / len(swapOperations))