#! /usr/bin/env python
# -*- coding: utf-8 -*-

import requests
import bs4
import json
import time

if __name__ == '__main__':
    with open("29027415.html", "r") as fw:
        content = fw.read()
    htmlSoup = bs4.BeautifulSoup(content, features="html.parser")
    # txt = htmlSoup.find_all('div', class_='d2txt')
    d2txt_con = htmlSoup.find('div', class_='d2txt_con')
    # print(d2txt_con)
    para = d2txt_con.findAll('p')[1:]
    for p in para:
        print(p.text)

