s = raw_input()
numbers = map(int, s.split())

s = raw_input()
known_angles = map(int, s.split())
known_angles.sort()
ang = {}

for angle in known_angles:
	ang[angle] = 1
	i = 1
	while 1:
		for x in range(numbers[0]):
			p = angle + i*known_angles[x]
			if p<=360:
				ang[p] = 1
				ang[360-p] = 1
			else:
				break
		if i*known_angles[0]>360:
			break
		i += 1

for angle in ang.keys():
	print angle

s = raw_input()
given_angles = map(int, s.split())

for angle in given_angles:
	if angle in ang.keys():
		print "YES"
	else:
		print "NO"