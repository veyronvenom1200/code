from urllib.request import urlopen
from bs4 import BeautifulSoup as bs

quote_page = 'http://www.bloomberg.com/quote/SPX:IND'
page = urlopen(quote_page)
soup = bs(page, 'html.parser')
name_box = soup.find('h1', attrs={'class': 'name'})
name = name_box.text.strip()
print(name)

price_box = soup.find('div', attrs={'class':'price'})
price = price_box.text.strip()
print(price)
