import matplotlib.pyplot as plt
import csv

sample_number= []
ibat = []
vbat = []
second = []
minute = []
hour = []

time = []

with open('out.csv','r') as csvdata:
    plots = csv.reader(csvdata,delimiter = ',')

    for row in plots:
        sample_number.append(int(row[0]))
        ibat.append( int( row[1] ))
        second.append(int(row[2]))
        minute.append(int(row[3]))
        hour.append(int(row[4]))



plt.plot(sample_number,ibat)
plt.show()


