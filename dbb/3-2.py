n,m,k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()

count = int(m / (k + 1)) * k + m % (k + 1)
result = count * data[n - 1] + (m - count) * data[n - 2]

print(result)
