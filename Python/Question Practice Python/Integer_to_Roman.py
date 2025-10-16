num = input("Enter the number: ")
list1 = []

for i in num:
    list1 += [i,]

mult = 10**(len(list1)-1)
for i in list1:
    list1[list1.index(i)] = int(i)*mult
    mult //= 10

list1 = list1[::-1]

# Roman Symbols
roman = ""
one = "I"
five = "V"
ten = "X"
fifty = "L"
hund = "C"
fhund = "D"
thous = "M"

# Conversion
if (int(num) < 4000):
    for i in list1:
        if list1.index(i) == 0:
            if i == 4:
                roman += one+five
            elif i == 9:
                roman += one+ten
            elif i == 5:
                roman += five
            elif i < 4:
                roman += one*i
            elif i > 5:
                roman += five+(one*(i-5))

            list1[0] = roman

        elif list1.index(i) == 1:
            roman = ""
            if i == 40:
                roman += ten+fifty
            elif i == 90:
                roman += ten+hund
            elif i == 50:
                roman += fifty
            elif i < 40:
                roman += ten*(i//10)
            elif i > 50:
                roman += fifty+(ten*((i-50)//10))
            
            list1[1] = roman[::-1]

        elif list1.index(i) == 2:
            roman = ""
            if i == 400:
                roman += hund+fhund
            elif i == 900:
                roman += hund+thous
            elif i == 500:
                roman += fhund
            elif i < 400:
                roman += hund*(i//100)
            elif i > 500:
                roman += fhund+(hund*((i-500)//100))

            list1[2] = roman[::-1]

        elif list1.index(i) == 3:
            roman = ""
            roman += thous*(i//1000)
            list1[3] = roman[::-1]

    roman = ""

    for i in list1:
        roman += i

    roman = roman[::-1]  

    print(f"Number in Roman: {roman}")

else:
    print("Enter Number in Range 1-3999")