a = []
for i in range(0, 32):
    temp1 = "val[" + str(i) + "] = val[" + str(i) + "]*100"
    temp2 = "val[" + str(i) + "] = val[" + str(i) + "] ^ val[" + str(31-i) + "]" 
    temp3 = "val[" + str(i) + "] = val[" + str(i) + "] - 1337^int('0xdeadbeef', 16)"
    temp4 = "val[" + str(i) + "] = val[" + str(i) + "] + 455"
    a.append(temp1)
    a.append(temp2)
    a.append(temp3)
    a.append(temp4)
print(a)

for i in a:
    print(i)