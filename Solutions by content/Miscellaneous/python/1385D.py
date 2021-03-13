import copy

def solve(l, r, c, f, s):
	if l == r:
		if(s[l] != c):
			return 1
		else:
			return 0
	x = 1e9
	y = 1e9
	if f == 0:
		x = solve(l,(l+r)//2,c,1,s)+solve((l+r)//2+1,r,chr(ord(c)+1),2,s)
		y = solve(l,(l+r)//2,chr(ord(c)+1),2,s)+solve((l+r)//2+1,r,c,1,s)
	elif f == 1:
		x = solve(l,(l+r)//2,c,1,s)+solve((l+r)//2+1,r,c,1,s)
		y = x
	elif f == 2:
		x = solve(l,(l+r)//2,c,1,s)+solve((l+r)//2+1,r,chr(ord(c)+1),2,s)
		y = solve(l,(l+r)//2,chr(ord(c)+1),2,s)+solve((l+r)//2+1,r,c,1,s)
	return min(x,y)
		
def main():
	for _ in range(int(input())):
		n = int(input())
		s = input()
		print(solve(0,n-1,'a',0,s))

main()
