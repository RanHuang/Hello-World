#! /usr/bin/env python
# -*- coding: utf-8 -*-

import requests
import json
import time

if __name__ == '__main__':
    user_agent = {'User-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36'}
    user_agent['Cookie'] = '__jsluid_h=d77539c267d4eb1b664043e3b91ebaab; wdcid=5c94e8fb21f10a4c; MONITOR_WEB_ID=edb1c5e3-6bea-45ff-ae90-e47e86fb44b3; wdses=527befc50571c3c0; ci_session=qna7ak37i8agf99u5gdojpnddculp5s9; wdlast=1632210588'

    url_pattern = "http://jhsjk.people.cn/testnew/result?keywords=&isFuzzy=0&searchArea=0&year=2021,2020,2019,2018,2017&form=0&type=0&page=%s&origin=全部&source=2"

    article_lists = []
    for index in range(567, 597):
        url = url_pattern % index
        res = requests.get(url, headers=user_agent)
        if res.status_code != 200:
            print("{}: {}" % (res.status_code, url))
            continue
        key_val = json.loads(res.text)
        list_data = key_val['list']
        if len(list_data) < 10:
            print("item num:%d %s" % (len(list_data), url))
        else:
            print("index %d" % index)
        article_lists.extend(list_data)
        time.sleep(2)
    # {'title': '习近平将出席第76届联合国大会一般性辩论', 'input_date': '2021-09-21 08:48:11', 'article_id': '32232243', 'publishdate': '0', 'publishdep': '', 'origin_name': '人民网－人民日报'}
    with open("article_id567-596.txt", "w") as fw:
        fw.write(json.dumps(article_lists))

    print("Done")
