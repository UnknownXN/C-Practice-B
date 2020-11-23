import sys
import csv

#give comments later
if len(sys.argv) != 3:
    print("Usage: python dna.py database sequences")
    sys.exit()
filename = sys.argv[1]
searchfile = sys.argv[2]
x = 0
#opens file containing dna sequence and stores the sequence in a variable
with open(searchfile, "r") as searchedfile:
    searched = csv.reader(searchedfile)
    for i in searched:
        for seq in i:
            sequence = seq

with open(filename, 'r') as database:
    databases = csv.reader(database)
    counter = -1
    longest = 0
    current_longest = 0
    longest_list = []
    for i in databases:
        if i[0] == 'name':
            sequence_list = i
            sequence_list.remove('name')
            length = len(i)
        
            for searched_sequence in sequence_list:
                for k in range(0, round(len(sequence) - len(searched_sequence))):
                    if k == 0:
                        y = len(searched_sequence)
                        x = 0
                    if sequence[x:y] != searched_sequence:
        
                        y += 1
                        x += 1
                    else:
                        while sequence[x : y] == searched_sequence:
                            
                            x += len(searched_sequence)
                            y += len(searched_sequence)
                            current_longest += 1
                        if current_longest > longest:
                            longest = current_longest
                        current_longest = 0
                longest_list.append(longest)
                longest = 0
                temp_list = longest_list

longest_list = []
for i in temp_list:
    longest_list.append(str(i))

for i in longest_list:
    if type(i) == int:
        longest_list.remove(i)
names = []
final_counter = 0
with open(filename, 'r') as data:
    dataset = csv.reader(data)
    for i in dataset:
        if i[0] == 'name':
            pass
        else:
            final_counter += 1
            names.append(i.pop(0))
            if i == longest_list:
                print(names[final_counter - 1])
                sys.exit()
print('No match')
                