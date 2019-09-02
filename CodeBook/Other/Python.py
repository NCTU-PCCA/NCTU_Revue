// LatexBegin
# input
n = int(input())
a, b, c = map(int, input().split())
L = list(map(int, input().split()))

# EOF
while True:
  try:
    solve()
  except:
    break

# output
print(x, sep = ' ')
print(''.join(str(x) + ' ' for x in a))
print('{:5d}'.format(x))
print('{:.5f}'.format(x))

# sort
a.sort()

# list
a = [x for x in range(n)]
a = [0 for x in range(n)]
a.append(x)

# stack
stack = [3, 4, 5]
stack.append(6)
stack.pop()
stack[-1]
len(stack)

# queue
from collections import deque
queue = deque([3, 4, 5])
queue.append(6)
queue.popleft()
queue[0]
len(queue)
// LatexEnd
