def twos_compliment(n):
    ones = ''
    for i in n:
        ones += str(1 - int(i))
    twos = ''
    carry = '1'
    for i in ones[-1::-1]:
        val = str(int(i) + int(carry))
        if val < "2":
            twos += val
            carry = '0'
        else:
            carry = '1'
            twos += '0'
    return twos[-1::-1]

def LS(a, q):
    a = a[1:] + q[0]
    q = q[1:] + '_'
    return a, q

def add(a, m):
    sumy = ''
    carry = '0'
    length = len(a)
    for i in range(length -1, -1, -1):
        val = str(int(a[i]) + int(m[i]) + int(carry))
        if val < "2":
            sumy += val
            carry = '0'
        elif val == "2":
            sumy += '0'
            carry = '1'
        elif val == "3":
            sumy += '1'
            carry = '1'
    return sumy[:length][-1::-1]

m_dec = int(input("Enter M : "))
q_dec = int(input("Enter Q : "))
m = bin(m_dec)[2:]
q = bin(q_dec)[2:]

count = (len(q) if q_dec>m_dec else len(m))
count += 1

q = "0"*(count - len(q)) + q
m = "0"*(count - len(m)) + m
m_minus = twos_compliment(m)
a = "0"*(count)

print("------------------------")
print(a,q)
print("------------------------")
for i in range(count):
    a, q = LS(a, q)
    print(a, q, "\tLS")
    a = add(a, m_minus)
    print(a, q, "\ta <- a - m")
    if a[0] == "1":
        a = add(a, m)
        print(a, q, "\ta <- a + m")
        q = q[:count-1] + "0"
        print(a, q, "\tq[0] = 0")
    else:
        q = q[:count-1] + "1"
        print(a, q, "\tq[0] = 1")
    print("------------------------")