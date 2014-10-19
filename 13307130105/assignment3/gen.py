#!/usr/bin/python

import random, sys, string

def invert(s):
	return ''.join(['a' if x == 'b' else 'b' for x in s])

def Thue_Morse_Sequence(N, typ='a'):
	cur = typ
	while len(cur)*2 <= N:
		cur += invert(cur)
	return cur

def polyHash(P, seed, s):
	h = 0
	for c in s:
		h = (h * seed + ord(c)) % P
	return h

def Meaningless_Collision(P, seed, length):
	haz = {}
	cur = []
	h = 0
	reverty = pow(seed, length, P)
	while True:
		ch = random.choice(string.lowercase + string.uppercase + string.digits)
		cur.append(ch)
		d = ord(ch)
		h = (h * seed + d) % P
		if len(cur) > length:
			h = (h - reverty * ord(cur[-length-1])) % P
		if haz.has_key(h):
			pos = haz[h]
			if cur[pos:pos+length] != cur[-length:]:
				# bye~
				return ''.join(cur[pos:pos+length]), ''.join(cur[-length:])
		haz[h] = len(cur)-length

if __name__ == '__main__':
	# kill some REALLY badly implemented Boyer-Moore
	print 'a'*500000, 'a'*499999 + 'b' + 'a'*1000000, 500000

	# evil tricks against your bad polynomial hash (modulo 2^x)
	print Thue_Morse_Sequence(4096, 'a'), Thue_Morse_Sequence(4096, 'b'), -1

	# brand new birthday gifts for those who are too lazy to compare their strings
	for i in [256,307,127,137,233,27,26,2,999983]:
		print >>sys.stderr, 'collision %d' % i
		a, b = Meaningless_Collision(int(1e9)+7, i, 9)
		print a, b, -1
