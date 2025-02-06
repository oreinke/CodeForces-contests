import sys
def solve():
    n = int(input())
    prev = 0
    ops = 0
    for _ in range(n):
        num = int(input)
        while num < prev:
            num = num * num
            ops = ops + 1
        prev = num
        
    print(ops)

input = sys.stdin.readline
t = int(input())
for _ in range(t):
    solve()