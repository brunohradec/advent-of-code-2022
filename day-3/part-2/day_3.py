from itertools import islice

def get_item_priority(item):
    if item.isupper():
        return ord(item) - 38
    elif item.islower():
        return ord(item) - 96

sum = 0

with open('./input.txt') as file:
    while(group := [rucksack.rstrip() for rucksack in islice(file, 3)]):
        common_items = set(group[0]) & set(group[1]) & set(group[2])
        
        for i in common_items:
            sum += get_item_priority(i)

print('result:', sum)

