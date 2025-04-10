import pandas as pd
import numpy as np

df = pd.DataFrame({
    'John': [True, False, True, False, True, False, False, True, True, False],
    'Judy': [True, True, False, False, True, False, True, True, False, False]
})

party_days = (df['John'] & df['Judy']).values

days_til_party = np.full(len(df), fill_value=np.nan)

next_party = None
for i in reversed(range(len(df))):
    if party_days[i]:
        next_party = i
        days_til_party[i] = 0
    elif next_party is not None:
        days_til_party[i] = next_party - i

df['days_til_party'] = days_til_party.astype(int)

print(df)
