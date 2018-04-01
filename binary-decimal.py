def reverse_bin(x):
  bin = ''
  for i in range(len(x)-1, -1, -1):
    bin+=x[i]
  return bin

def first (x):
  bin = ''
  while x>=1:
    bin+=str(int(x%2))
    x/=2
  return reverse_bin(bin)

def second(x):
  new = reverse_bin(str(x))
  sum = 0
  for i in range (len(new)-1, -1, -1):
   sum+=(2**i)*int(new[i])
  return sum

ask = int(input("Which conversion do you want?\nWrite 0 for Decimal to Binary and 1 for Binary to Decimal: "))
num = int(input("Write the integer that you want to convert: "))

if ask == 0:
  print('Your decimal number in binary is: {}'.format(first(num)))
else:
  print('Your binary number in decimal is: {}'.format(second(num)))
