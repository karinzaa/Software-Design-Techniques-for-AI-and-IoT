# A function that returns the 'year' value:
def YearRort(e):
	return e['year']
  
def PriceRort(e):
	return e['price']

cars = [
  {'model': 'Ford', 'year': 2005 , 'price': 100000},
  {'model': 'Mitsubishi', 'year': 2000, 'price': 90000},
  {'model': 'BMW', 'year': 2019, 'price': 700000},
  {'model': 'VW', 'year': 2011, 'price': 130000}
]


print("Sort by Year")
cars.sort(key=YearRort) 
print(cars)

print("Sort by Price")
cars.sort(key=PriceRort) 
print(cars)