#find months and days
days = int(input("enter the days"))
years = int(days/365)
days2=days%365
month = int(days2/30)
days3=days2%30
print('years={} months = {} days = {}'.format(years,month,days3)) 
