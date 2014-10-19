import random, sys

def invert(s):
	return ''.join(['a' if x == 'b' else 'b' for x in s])

def Thue_Morse_Sequence(N, typ='a'):
	cur = typ
	while len(cur)*2 <= N:
		cur += invert(cur)
	return cur

if __name__ == '__main__':
	