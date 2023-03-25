import nasdaqdatalink
nasdaqdatalink.ApiConfig.api_key = "TzsBnf5V2-Rbyiz1ZDdK"
mydata = nasdaqdatalink.get_table('ZACKS/FC', ticker='AMD')
print(mydata)