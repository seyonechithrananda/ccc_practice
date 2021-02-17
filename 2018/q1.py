n = int(input())
v = []
for i in range(n):
  v.append(float(input()))
v.sort()
#print(v)
smalldist = 0
for i in range(n):
  if i != 0 and i != n-1:
    dist = (v[i] - (v[i-1]+v[i])/2) + ((v[i+1]+v[i])/2 - v[i])
    if i == 1:
      smalldist = dist
    if dist < smalldist:
      smalldist = dist
print(smalldist)