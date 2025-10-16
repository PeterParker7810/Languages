user = input("Enter the String: ")
dict1 = {}
for i in user:
    dict1[i] = str(user.count(i))+i

out = ""
for i in dict1:
    out += dict1[i]

print(f"Output String: {out}")