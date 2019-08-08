def reverse(x):
    if -10 < x < 10:
        return x
    str_x = str(x)
    if str_x[0] != "-":
        str_x = str_x[::-1]
        x = int(str_x)
    else:
        str_x = str_x[1:][::-1]
        x = int(str_x)
        x = -x
    return x
 
 
t = int(input())
while t > 0:
    t -= 1
    a, b = map(int, input().split())
    a = reverse(a)
    b = reverse(b)
    a = a + b
    a = reverse(a)
    print(a)
