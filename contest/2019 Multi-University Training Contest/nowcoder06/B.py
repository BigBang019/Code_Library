for _ in range(int(input())):
    b = input()
    a = []
    for i in range(8):
        a.append(hex(int(b[i * 16: i * 16 + 16], 2))[2::])
    s = []
    s.append(':'.join(a))
    for i in range(8):
        for j in range(i + 1, 8):
            if all(map(lambda x: x == '0', a[i: j + 1])):
                s.append(':'.join(a[:i]) + '::' + ':'.join(a[j + 1:]))
    s.sort(key=lambda x: (len(x), x))
    print('Case #%d: %s' % (_ + 1, s[0]))
