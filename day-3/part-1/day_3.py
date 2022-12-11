def get_item_priority(item):
    if item.isupper():
        return ord(item) - 38
    elif item.islower():
        return ord(item) - 96

sum = 0

with open('./input.txt') as file:
    while (rucksack := file.readline().rstrip()):
        first_compartment = rucksack[:len(rucksack)//2]
        second_compartment = rucksack[len(rucksack)//2:]

        common_items = set(first_compartment) & set(second_compartment)

        for i in common_items:
            sum += get_item_priority(i)

print('result:', sum)

