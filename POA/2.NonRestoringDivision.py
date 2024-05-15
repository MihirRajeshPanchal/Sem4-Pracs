# def add(a, m):
#     sumy = ''
#     carry = '0'
#     length = len(a)
#     for i in range(length -1, -1, -1):
#         val = str(int(a[i]) + int(m[i]) + int(carry))
#         if val < "2":
#             sumy += val
#             carry = '0'
#         elif val == "2":
#             sumy += '0'
#             carry = '1'
#         elif val == "3":
#             sumy += '1'
#             carry = '1'
#     return carry, sumy[:length][-1::-1]

# def RS(c, a, q):
#     q = a[-1] + q[:len(q)-1]
#     a = c + a[:len(a)-1]
#     c = "0"
#     return c, a, q

# m_dec = int(input("Enter M : "))
# q_dec = int(input("Enter Q : "))
# m = bin(m_dec)[2:]
# q = bin(q_dec)[2:]

# count = (len(q) if q_dec>m_dec else len(m))

# q = "0"*(count - len(q)) + q
# m = "0"*(count - len(m)) + m
# a = "0"*(count)
# c = "0"

# print("---------------------------")
# print(c,a,q)
# print("---------------------------")
# for i in range(count):
#     if q[-1] == "1":
#         c, a = add(a, m)
#         print(c,a,q, "\ta <- a + m")
#     c, a, q = RS(c, a, q)
#     print(c,a,q, "\tRS")
#     print("---------------------------")

def binary_add(a, b):
    result = ''
    carry = 0
    for i in range(len(a) - 1, -1, -1):
        sum_bits = int(a[i]) + int(b[i]) + carry
        result = str(sum_bits % 2) + result
        carry = sum_bits // 2
    return str(carry) + result if carry else result

def right_shift(c, a, q):
    q = a[-1] + q[:len(q) - 1]
    a = c + a[:len(a) - 1]
    c = "0"
    return c, a, q

m_decimal = int(input("Enter M : "))
q_decimal = int(input("Enter Q : "))
m_binary = bin(m_decimal)[2:]
q_binary = bin(q_decimal)[2:]

count = max(len(q_binary), len(m_binary))

q_binary = "0" * (count - len(q_binary)) + q_binary
m_binary = "0" * (count - len(m_binary)) + m_binary
a_binary = "0" * count
c_binary = "0"

print("---------------------------")
print(c_binary, a_binary, q_binary)
print("---------------------------")
for _ in range(count):
    if q_binary[-1] == "1":
        a_binary = binary_add(a_binary, m_binary)
        print(c_binary, a_binary, q_binary, "\ta <- a + m")
    c_binary, a_binary, q_binary = right_shift(c_binary, a_binary, q_binary)
    print(c_binary, a_binary, q_binary, "\tRS")
    print("---------------------------")