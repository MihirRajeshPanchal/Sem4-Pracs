def twos_complement(n):
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

def add(a, m):
    sumy = ''
    carry = '0'
    length = len(a)
    for i in range(length - 1, -1, -1):
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

def ARS(a, q, q_): 
    q_ = q[-1]
    q = a[-1] + q[:len(q) - 1] 
    a = a[0] + a[:len(a) - 1]
    return a, q, q_

m_dec = int(input("Enter M : "))
q_dec = int(input("Enter Q : "))

f1, f2 = False, False
if m_dec < 0:
    m = bin(m_dec)[3:]
    f1 = True
else:
    m = bin(m_dec)[2:]
if q_dec < 0:
    q = bin(q_dec)[3:]
    f2 = True
else:
    q = bin(q_dec)[2:]

count = (len(q) if q_dec > m_dec else len(m))
count += 1

q = "0" * (count - len(q)) + q
m = "0" * (count - len(m)) + m

if f1:
    m = twos_complement(m)
if f2:
    q = twos_complement(q)
m_minus = twos_complement(m)

a = "0" * (count)
q_ = "0"

print("---------------------------")
print(a, q, q_)
print("---------------------------")

for i in range(count):
    if (q[-1], q_) == ("0", "0") or (q[-1], q_) == ("1", "1"):
        a, q, q_ = ARS(a, q, q_)
        print(a, q, q_, "\tARS")
    elif (q[-1], q_) == ("0", "1"):
        a = add(a, m)
        print(a, q, q_, "\ta <- a + m")
        a, q, q_ = ARS(a, q, q_)
        print(a, q, q_, "\tARS")
    elif (q[-1], q_) == ("1", "0"):
        a = add(a, m_minus)
        print(a, q, q_, "\ta <- a - m")
        a, q, q_ = ARS(a, q, q_)
        print(a, q, q_, "\tARS")
    print("---------------------------")