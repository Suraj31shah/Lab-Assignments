import pandas as pd

s = pd.Series (['X', 'Y', 'T', 'Aaba', 'Baca', 'CABA', None, 'bird', 'horse', 'dog'])

upper_case=s.str.upper()
print("Upper case:\n",upper_case)

lower_case=s.str.lower()
print("Lower case:\n",lower_case)

string_length=s.str.len()
print("Length of each string:\n",string_length)