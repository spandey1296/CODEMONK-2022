# -*- coding: utf-8 -*-
"""
Created on Fri Jul  8 19:39:03 2022

@author: Sudatra
"""
from instabot import Bot
import requests
from bs4 import BeautifulSoup

bot = Bot()
bot.login(username = 'username', password = 'password')

bot.follow('username_to_follow')
bot.unfollow('username to unfollow')
bot.unfollow_everyone()

followers = bot.get_user_followers('username')
print(len(followers))

bot.send_message('hello', 'user_to_recieve_message')
bot.send_like('user_to_like')

bot.upload_photo('filename.jpg', caption = 'write ur caption here')

URL = "https://www.instagram.com/{}/"

def parseData(s):
    data = {}
    
    s = s.split('-')[0]
    s = s.split(' ')
    
    data['followers'] = s[0]
    data['following'] = s[2]
    data['posts'] = s[4]
    
    return data

def scrapeData(username):
    r = requests.get(URL.format(username))
    s = BeautifulSoup(r.text, 'html.parser')
    meta = s.find('meta', property = 'og:description')
    
    return parseData(meta.attrs['content'])

if __name__=="__main__":
    username = "sudatraghosh"
    data = scrapeData(username)
    print(data)