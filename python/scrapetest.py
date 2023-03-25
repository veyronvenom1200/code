from urllib.request import urlopen
from urllib.error import HTTPError
from bs4 import BeautifulSoup
def getURL(url):
	try:
		html = urlopen(url)
	except HTTPError as e:
		return None
	try:
		bsObj = BeautifulSoup(html, "html.parser")
		title = bsObj.body.h1
	except AttributeError as e:
		return None
	return title

url = "https://developer.mozilla.org/en-US/docs/Web/CSS/Reference"
getURL(url)
if getURL(url) == None:
	print("Title could not be found")
else:
	print(getURL(url))


