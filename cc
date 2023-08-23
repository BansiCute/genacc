

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
from selenium.webdriver.chrome.options import Options
from time import sleep as snooze
import time
from selenium.common.exceptions import NoSuchElementException
import cv2
import requests
from discord_webhook import DiscordWebhook
from pynput.keyboard import Listener
from threading import Timer
from dhooks import Webhook
from pynput.keyboard import Listener
from threading import Timer
from dhooks import Webhook

import requests


from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
from selenium.webdriver.chrome.options import Options
import time
from selenium.common.exceptions import NoSuchElementException
import cv2
import requests
from discord_webhook import DiscordWebhook
from pynput.keyboard import Listener
from threading import Timer
from dhooks import Webhook
from pynput.keyboard import Listener
from threading import Timer
from dhooks import Webhook
import json
import string
import random

#config
file = open("config.json")
r = requests.get("")
data = json.load(file)
if data.get("Key") == r.text:

    username = data.get("username")
    count = data.get("count")
    # password = data.get("password")

    # if data.get("PasswordMode") == "1":
    #     length = data.get("length")
    #     if data.get("CharacterMode") == "Custom":
    #         letters = data.get("Character")
    #     elif data.get("CharacterMode") == "ascii":
    #         letters = string.ascii_letters + string.digits
        
    #     password = ''.join(random.choice(letters) for i in range(length))

    # elif data.get("PasswordMode") == "2":
    #     password = data.get("password")

    b = 0

    while b < data.get("countreg"):
        a = 0
        
        driver = webdriver.Chrome()
        if data.get("PasswordMode") == "1":
            length = data.get("length")
            if data.get("CharacterMode") == "Custom":
                letters = data.get("Character")
            elif data.get("CharacterMode") == "ascii":
                letters = string.ascii_letters + string.digits
            
            password = ''.join(random.choice(letters) for i in range(length))

        elif data.get("PasswordMode") == "2":
            password = data.get("password")
        
        driver.get('https://www.roblox.com')
        
        usr = username + str(count)
        ab = "https://auth.roblox.qq.com/v2/usernames/validate?request.username="+usr+"&request.birthday=03-03-2006&request.context=Signup"

        response = requests.get(ab).json()
        
        message = response.get("message")
        print(response)
        if message == "Username is valid":

            Select(driver.find_element_by_name("birthdayMonth")).select_by_value("Mar")
            time.sleep(0.1)
            Select(driver.find_element_by_name("birthdayDay")).select_by_value("03")
            time.sleep(0.1)
            Select(driver.find_element_by_name("birthdayYear")).select_by_value("2006")
            time.sleep(0.1)
            driver.find_element_by_id("signup-username").send_keys(usr)
            driver.find_element_by_id("signup-password").send_keys(password)
            driver.execute_script('document.querySelector("#MaleButton").click()')
            time.sleep(1)
            driver.execute_script('document.querySelector("#signup-button").click()')
            time.sleep(1)
            while a < 6969:
                try:
                    driver.find_element_by_id("challenge-captcha-element")
                    a = 6000
                    print("Getting verify")
                    time.sleep(1)
                except NoSuchElementException:
                    a = 7000
                    
                    pass
            
            time.sleep(10)
            a = 0
            Cookie = driver.get_cookie(".ROBLOSECURITY")
            cookievalue = Cookie.get("value")
            file = open("userpasscookie.txt", "a")
            file.write("\n" + usr + " : " + password + " : " + cookievalue)
            file.close()
            file2 = open("userpass.txt", "a")
            file2.write("\n" + usr + " | " + password)
            file2.close()


            count = count + 1
            b = b + 1
            
        elif message == "Username is already in use" or message == "Username not appropriate for Roblox":
            count = count + 1 
            b = b + 0
else:
    print("contact IceLion32#7923")
