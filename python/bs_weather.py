_Author_= "Nathan Dohm"
_email_="dohmnath@msu.edu"
_version_="3.6.2"

"""bs_weather.py (bs = beautiful soup) is an application capable of scraping data
off of weather.com and returning the weather for the user specified zip code. It
is also capable of returning the weather for a user specified time frame (day,
hourly, 5 day, or 10 day). This terminal application was made for my presonal
educational benefit, and will most likely not be open-sourced."""

"""To install beautiful soup (on macOS), make sure python 3 is installed and run:
sudo easy_install pip
sudo pip install beautifulsoup4"""

# import libraries
from urllib.request import urlopen
from bs4 import BeautifulSoup
import re

url_list = ["today", "hourbyhour", "5day", "10day"]

if __name__ == '__main__':
    area = input("Enter a zip code: ")

    kind = input("What is the time frame for the weather forecast: ")

    if kind == "day" or kind == "now":
        weather_page = "https://weather.com/weather/today/l/" + area
        # query the website and return the html to the variable ‘page’
        page = urlopen(weather_page)

        # parse the html using beautiful soap and store in variable `soup`
        soup = BeautifulSoup(page, 'html.parser')

        # Take out the <div> of name and get its value
        temp_box = soup.find('div',class_= "today_nowcard-temp").find('span', class_="").text
        # print()
        print("Temp: ")
        print(temp_box)

    if kind == "hourly":
        time_list = []
        temp_list = []
        description_list = []
        weather_page = "https://weather.com/weather/hourbyhour/l/" + area
        # query the website and return the html to the variable ‘page’
        page = urlopen(weather_page)

        # parse the html using beautiful soap and store in variable `soup`
        soup = BeautifulSoup(page, 'html.parser')

        # Take out the <div> of name and get its value
        count = 0
        temp_box = soup.findAll('td' , {'headers': 'temp'})
        time = soup.findAll('div', {'class': 'hourly-time'})
        description = soup.findAll('td', {'headers': 'description'})
        for i in time:
            hour = i.find('span', {'class': 'dsx-date'}).text
            time_list.append(hour)
        for x in temp_box:
            temp = x.find("span", {"class": ''}).text
            temp_list.append(temp)
        for z in description:
            desc = z.find("span", {"class": None}).text
            description_list.append(desc)
        count = 0
        print("Time: ", '{:>9}'.format("Temp: "))
        while count < len(time_list):
            print('{:9}'.format(time_list[count]), '{:6}'.format(temp_list[count]), '{:6}'.format(description_list[count]))
            count += 1

    if kind == "5 day":
        time_list = []
        hi_list = []
        low_list = []
        weather_page = "https://weather.com/weather/5day/l/" + area
        # query the website and return the html to the variable ‘page’
        page = urlopen(weather_page)

        # parse the html using beautiful soap and store in variable `soup`
        soup = BeautifulSoup(page, 'html.parser')

        # Take out the <div> of name and get its value
        count = 0
        high_box = soup.findAll("td" , {"headers": "hi-lo"})
        low_box = soup.findAll("td" , {"headers": "hi-lo"})
        time = soup.findAll('td', {'headers': 'day'})
        for i in time:
            hour = i.find('span', {'class': 'date-time'}).text
            time_list.append(hour)
        for x in high_box:
            high = x.find("span", {"class": ''}).text
            hi_list.append(high)
        for z in low_box:
            low = z.findAll("span", {"class": ''})[1].text
            low_list.append(low)
        count = 0
        print("Time: ", '{:>10}'.format("High: "), '{:>4}'.format("Low: "))
        while count < len(hi_list):
            print('{:7}'.format(time_list[count]), '{:>6}'.format(hi_list[count]), '{:>6}'.format(low_list[count]))
            count += 1

    if kind == "10 day":
        time_list = []
        hi_list = []
        low_list = []
        weather_page = "https://weather.com/weather/10day/l/" + area
        # query the website and return the html to the variable ‘page’
        page = urlopen(weather_page)

        # parse the html using beautiful soap and store in variable `soup`
        soup = BeautifulSoup(page, 'html.parser')

        # Take out the <div> of name and get its value
        count = 0
        high_box = soup.findAll("td" , {"headers": "hi-lo"})
        low_box = soup.findAll("td" , {"headers": "hi-lo"})
        time = soup.findAll('td', {'headers': 'day'})
        for i in time:
            hour = i.find('span', {'class': 'date-time'}).text
            time_list.append(hour)
        for x in high_box:
            high = x.find("span", {"class": ''}).text
            hi_list.append(high)
        for z in low_box:
            low = z.findAll("span", {"class": ''})[1].text
            low_list.append(low)
        count = 0
        print("Time: ", '{:>10}'.format("High: "), '{:>4}'.format("Low: "))
        while count < len(hi_list):
            print('{:7}'.format(time_list[count]), '{:>6}'.format(hi_list[count]), '{:>6}'.format(low_list[count]))
            count += 1

    print()
    print("Uses data from weather.com. Please do not redistribute this script as it may violate their policy.")
