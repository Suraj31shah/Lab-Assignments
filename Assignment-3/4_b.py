list1=['acdb']
s=list1[0]
print({c.upper(): c*3 for c in s[:len(s)//2]+s[:len(s)//2-1:-1]})