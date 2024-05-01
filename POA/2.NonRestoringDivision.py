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
    return carry, sumy[:length][-1::-1]

def RS(c, a, q):
    q = a[-1] + q[:len(q)-1]
    a = c + a[:len(a)-1]
    c = "0"
    return c, a, q

m_dec = int(input("Enter M : "))
q_dec = int(input("Enter Q : "))
m = bin(m_dec)[2:]
q = bin(q_dec)[2:]

count = (len(q) if q_dec>m_dec else len(m))

q = "0"*(count - len(q)) + q
m = "0"*(count - len(m)) + m
a = "0"*(count)
c = "0"

print("---------------------------")
print(c,a,q)
print("---------------------------")
for i in range(count):
    if q[-1] == "1":
        c, a = add(a, m)
        print(c,a,q, "\ta <- a + m")
    c, a, q = RS(c, a, q)
    print(c,a,q, "\tRS")
    print("---------------------------")