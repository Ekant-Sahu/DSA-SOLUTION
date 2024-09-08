import csv
first = ["Car.FxRL","Car.FxRR","Car.v"],

with open('final.CSV', newline = '') as file:
    reader = csv.reader(file, quoting = csv.QUOTE_NONNUMERIC,
                        delimiter = ' ')
    diff = float(0.4)
    output = []
    for row in reader:
        output.append(row[:])
    start = output[1][2];
    size = len(output)




with open('f_1.csv', 'w', newline = '') as file:
    writer = csv.writer(file, quoting = csv.QUOTE_NONNUMERIC,
                        delimiter = ' ')
    writer.writerow(first)
    writer.writerow(output[0])
    i = 1;
    while(i<size):
        for j in output:
            if(j[2]-start>diff):
                # print("wrote")
                writer.writerow(j)
                start = j[2]
        i= i + 1