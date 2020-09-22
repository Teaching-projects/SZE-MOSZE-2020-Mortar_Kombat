import json
import sys

with open(sys.argv[1] + '.json') as sourceFile:
    data = json.load(sourceFile)
sourceFile.close()

with open((sys.argv[1] + '.txt'),"w+") as outputFile:
    for line in data.values():
        outputFile.write(str(line) + '\n')
outputFile.close()
