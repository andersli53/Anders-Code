import csv
import re

names = []
phones  = []

with open("data.csv", "r") as f:
    tempNames = []
    tempPhones = []
    data = csv.reader(f)
    for i in data:
        tempNames.append(i[0])
        tempPhones.append(i[1])

    names = tempNames[1:]
    phones = tempPhones[1:]

regexPhones = r"^1?[\s\.-]?\(?(\d{3})\)?[\s\.-]?(\d{3})[\s\.-]?(\d{4})$"
regexNames = r"(\w+),\s(\w+)\s?(\w\.)?"
regexNames1 = r"(\w+)\s(\w\.)\s(\w+)"
regexNames2 = r"^(\w+)\s(\w+)$"

matchNames = []
for data in names:
    matchNames.append(re.search(regexNames, data))

matchNames1 = []
for data in names:
    matchNames1.append(re.search(regexNames1, data))

matchNames2 = []
for data in names:
    matchNames2.append(re.search(regexNames2, data))

matchPhones = []
for data in phones:
    matchPhones.append(re.search(regexPhones, data))


with open("data2.csv", "w") as f:
    data = csv.writer(f, lineterminator='\n')
    data.writerow(["First"]+ ["M.I."]+["Last"]+["Number"])
    for i in range(len(matchNames)):
        if matchNames[i] and matchPhones[i]:
            data.writerow([matchNames[i].group(2)]+[matchNames[i].group(3)]+[matchNames[i].group(1)]+["("+matchPhones[i].group(1)+")"+" "+matchPhones[i].group(2)+"-"+matchPhones[i].group(3)])
        if matchNames1[i] and matchPhones[i]:
            data.writerow([matchNames1[i].group(1)]+[matchNames1[i].group(2)]+[matchNames1[i].group(3)]+["("+matchPhones[i].group(1)+")"+" "+matchPhones[i].group(2)+"-"+matchPhones[i].group(3)])
        if matchNames2[i] and matchPhones[i]:
            data.writerow([matchNames2[i].group(1)]+[""]+[matchNames2[i].group(2)]+["("+matchPhones[i].group(1)+")"+" "+matchPhones[i].group(2)+"-"+matchPhones[i].group(3)])
print "Done"
