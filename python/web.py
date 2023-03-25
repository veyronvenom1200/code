import sys
import os
import webbrowser
import pyperclip
import requests
import bs4
# from urllib.request import urlopen
# from bs4 import BeautifulSoup

class Test:
    def __init__(self, text, num):
        self.text = text
        self.extra = None
        print("This is num: " + str(num))

class Extra:
    def __init__(self, extra):
        self.extra = "nice"

name = '/Users/nathandohm/code/python'

print(len(os.listdir(name)))
for i in range(0, 10):
    Test("num", i)
testy.extra = "Cool"
print(testy.extra)



default = 'https://www.google.com/maps/place/'
pri
# if len(sys.argv) > 1:
#     address = '+'.join(sys.argv[1:])
# else:
#     address = pyperclip.paste()

# print(address)
# address = str(address)
# webbrowser.open(default + address)

res = requests.get('https://en.wikipedia.org/wiki/China')
res.raise_for_status()

china_file = open('China.txt', 'wb')
for chunk in res.iter_content(1000):
    china_file.write(chunk)
print(res.text[:250])

china_soup = bs4.BeautifulSoup(res.text, 'html.parser')
elems = china_soup.select('p')
print(elems[1].getText())
print(elems[1].attrs)


china_file.close()

# url = "http://news.bbc.co.uk/2/hi/health/2284783.stm"
# html = urlopen(url).read()
# soup = BeautifulSoup(html, features="html.parser")

# # kill all script and style elements
# for script in soup(["script", "style"]):
#     script.extract()    # rip it out

# # get text
# text = soup.get_text()

# # break into lines and remove leading and trailing space on each
# lines = (line.strip() for line in text.splitlines())
# # break multi-headlines into a line each
# chunks = (phrase.strip() for line in lines for phrase in line.split("  "))
# # drop blank lines
# text = '\n'.join(chunk for chunk in chunks if chunk)

# print(text)