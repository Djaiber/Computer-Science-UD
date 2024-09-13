imput = input()

while imput != None:
    cont = 0
    size = int(input())
    start = list(map(int, input().split()))
    end = list(map(int, input().split()))
    for i in range (size):
        value = start[i]
        index_end = end.indexOf(value)
        if i > index.end:
            cont += (i -index_end)
        if i > 0 and i == index_end and start[i-1]!=end[i-1]:
            cont += 1
    try:
        size = int(input(0))
    except:
        break
