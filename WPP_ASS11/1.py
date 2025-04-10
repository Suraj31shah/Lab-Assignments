import pandas as pd
from datetime import datetime

dt_a=pd.Timestamp('2012-01-15')
print("Date time object for Jan 15 2012:",dt_a)

dt_b=pd.Timestamp('2025-04-09 21:20')
print("Specific date and time of 9:20 pm:",dt_b)


dt_c=pd.Timestamp.now()
print("Local date and time:",dt_c)

dt_d=pd.to_datetime('2025-04-09').date()
print("A date without time:",dt_d)

dt_e=pd.Timestamp.today().date()
print("Current date:",dt_e)

dt_f=pd.Timestamp.now().time()
print("Time from a date time:",dt_f)

dt_g=datetime.now().time()
print("Current local time:",dt_g)