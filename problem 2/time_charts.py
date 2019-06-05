from matplotlib import pyplot as plt
import numpy as np


x, y1, y2, y3, y4, y5 = np.loadtxt("vec_int.csv", unpack = True, delimiter = ",")

plt.plot(x, y1, label = u"Insertion Sort Vector")
plt.plot(x, y2, label = u"Merge Sort Vector")
plt.plot(x, y3, label = u"Quick Sort Vector")
plt.plot(x, y4, label = u"Counting Sort Vector")
plt.plot(x, y5, label = u"Radix Sort Vector")

plt.title("Comparison of different sorting algorythms for vectors with integers")
plt.xlabel("Number of elements in sequence")
plt.ylabel("Time")
plt.legend()
plt.show()


x, y1, y2, y3, y4 = np.loadtxt("list_int.csv", unpack = True, delimiter = ",")

plt.plot(x, y1, label = u"Insertion Sort Vector")
plt.plot(x, y2, label = u"Merge Sort Vector")
plt.plot(x, y3, label = u"Quick Sort Vector")
plt.plot(x, y4, label = u"Counting Sort Vector")

plt.title("Comparison of different sorting algorythms for L-Lists with integers")
plt.xlabel("Number of elements in sequence")
plt.ylabel("Time")
plt.legend()
plt.show()


x, y1, y2, y3, y4 = np.loadtxt("vec_str.csv", unpack = True, delimiter = ",")

plt.plot(x, y1, label = u"Insertion Sort Vector")
plt.plot(x, y2, label = u"Merge Sort Vector")
plt.plot(x, y3, label = u"Quick Sort Vector")
plt.plot(x, y4, label = u"Radix Sort Vector")

plt.title("Comparison of different sorting algorythms for vectors with strings")
plt.xlabel("Number of elements in sequence")
plt.ylabel("Time")
plt.legend()
plt.show()


x, y1, y2, y3 = np.loadtxt("list_str.csv", unpack = True, delimiter = ",")

plt.plot(x, y1, label = u"Insertion Sort Vector")
plt.plot(x, y2, label = u"Merge Sort Vector")
plt.plot(x, y3, label = u"Quick Sort Vector")

plt.title("Comparison of different sorting algorythms for L-Lists with strings")
plt.xlabel("Number of elements in sequence")
plt.ylabel("Time")
plt.legend()
plt.show()
