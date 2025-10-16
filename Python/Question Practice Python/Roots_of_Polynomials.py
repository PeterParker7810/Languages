import numpy as np # type: ignore

user = int(input("Enter the no of Coefficients: "))
list1 = []
eq = ""
for i in range(user+1):
    user1 = int(input("Enter the Coefficient: "))
    list1 += [user1,]
    eq += str(user1)+"x^"+str(user-i)+" "

roots = np.roots(list1)
print(f"Equation: {eq}")

for i in range(len(roots)):
    roots[i] = round(roots[i],3)

print(f"Roots: {roots}")