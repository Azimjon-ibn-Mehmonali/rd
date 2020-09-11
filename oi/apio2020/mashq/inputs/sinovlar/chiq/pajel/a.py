from sys import stdin
for l in stdin:
	s = ''
	for i in range(len(l)):
		if l[i] == '`':
			s += ('-')
		else:
			s += (l[i])
	print(s)
