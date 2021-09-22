#! /usr/bin/env python
# -*- coding: utf-8 -*-

import requests
import bs4
import json
import os
import time

def download_article(title, input_date, article_id):
    file_name = title + input_date + ".txt"
    file_path = os.path.join("articles", file_name)
    if os.path.exists(file_path):
        print("%s already exists" % file_name)
        return

    user_agent = {
        'User-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36'}
    user_agent[
        'Cookie'] = '__jsluid_h=d77539c267d4eb1b664043e3b91ebaab; wdcid=5c94e8fb21f10a4c; MONITOR_WEB_ID=edb1c5e3-6bea-45ff-ae90-e47e86fb44b3; wdses=527befc50571c3c0; ci_session=qna7ak37i8agf99u5gdojpnddculp5s9; wdlast=1632210588'

    url_pattern = "http://jhsjk.people.cn/article/%s"
    url = url_pattern % article_id
    try:
        res = requests.get(url, headers=user_agent, timeout=4)
    except Exception as ex:
        print(str(ex))
        return

    htmlSoup = bs4.BeautifulSoup(res.text, features="html.parser")
    d2txt_con = htmlSoup.find('div', class_='d2txt_con')
    # print(d2txt_con)
    para = d2txt_con.findAll('p')[1:]
    with open(file_path, "w") as fw:
        for p in para:
            fw.write(p.text)
            fw.write("\n")

    time.sleep(2)
    print("new file: %s" % article_id)


def read_meta():
    # with open("article_id567-596.txt", "r") as fw:
    # with open("article_id461-567.txt", "r") as fw:
    with open("article_id460.txt", "r") as fw:
        content = fw.read()
    meta_list = json.loads(content)
    for meta in meta_list:
        title = meta['title']
        input_date = meta['input_date']
        article_id = meta['article_id']
        origin_name = meta['origin_name']
        if '人民网' in origin_name:
            # print("%s %s %s %s" %(title, input_date, article_id, origin_name))
            download_article(title, input_date, article_id)
        else:
            print(origin_name)



if __name__ == '__main__':
    read_meta()


