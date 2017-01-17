line1 = input()
line1 = line1.split(" ")


a = {}
b = set()
c = set()
persons = set()

for x in range(int(line1[0])):
	a[x] = set()
	b.add(x)
for i in range(int(line1[1])):
	lines = input()
	lines = lines.split(" ")
	a[int(lines[0])].add(int(lines[0]))
	a[int(lines[0])].add(int(lines[1]))
	a[int(lines[1])].add(int(lines[0]))
	a[int(lines[1])].add(int(lines[1]))

while b != c :
	m = 0
	for x in range(1,int(line1[1])-1):
		if x not in persons:
			if len(a[x]) > len(a[m]) :
				m = x
	c |= a[m]
	persons.add(m)
	print(c)
	

print(a)
print(b)
print(persons)