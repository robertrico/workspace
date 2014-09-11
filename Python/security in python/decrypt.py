#! /usr/bin/env python
alpha = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',' ']
number = ['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25']
alpha2 = ["*"] * 26
alpha3 = ["*"] * 26
message = raw_input('Enter the message: ')
print("\r\n")
print("Message length: "+str(len(message)))
print("\r\n")
#shift = input('Enter a shift. Enter "q" to quit ')
"""
key = raw_input('Enter the key: ')
while (len(key) > len(message) or len(key) < len(message)):
    key = raw_input('Key must be the same length as the message. Reenter key: ')
print("\r\n")
"""
key = "=d;#opw845s"
enmsg = ["*"] * len(message)


#q = ""
#if shift == q:
#	quit()

def encrypt(msg,key):
    overage = 0
    nkey = list(key)
    x = len(msg)
    for k in range (0,x):
        enmsg[k] = nkey[overage]
        alpha2[k] = alpha.index(msg[k])
        print alpha2[k],
        overage += 1
        if overage == len(nkey):
            overage = 0
    return enmsg

encrypt = encrypt(message,key)

print encrypt

"""
def rotate(key,encrypt):
    r = 0
    for j in range (0,len(encrypt)):
            r += 1 
            if r == 26:
                r = 0
            alpha2[r] = alpha[r-key]
            alpha3[r] = alpha[r-key]
            #print alpha2[r], 
            #print alpha3[r], 
            #print number[r], 
            print encrypt[j],
rotate(key,encrypt)"""
print("\r\n")


