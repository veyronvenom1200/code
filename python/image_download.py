import requests
from bs4 import BeautifulSoup
from urllib2.request import urlretrieve
import os

def image_down(start_img, stop_img):
    for numb in range(start_img, stop_img):
        url = 'http://xkcd.com/{}/'.format(numb)
        url_get = requests.get(url)
        soup = BeautifulSoup(url_get.content, 'html.parser')
        link = soup.find('div', id='comic').find('img').get('src')
        link = link.replace('//', 'http://')
        img_name = os.path.basename(link)
        try:
            urlretrieve(link, img_name)
        except:
            # Just want images don't care about errors
            pass

if __name__ == '__main__':
    start_img = 1
    stop_img = 20
    image_down(start_img, stop_img)
