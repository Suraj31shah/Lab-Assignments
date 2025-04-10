import pandas as pd

asking_prices=pd.Series([13000, 15000, 18000, 12000, 16000])
fair_prices=pd.Series([14000, 15500, 17500, 12500, 15000])

good_deals=asking_prices<fair_prices

good_deals_indices=good_deals[good_deals].index.tolist()

print("Indice of good deals:", good_deals_indices)