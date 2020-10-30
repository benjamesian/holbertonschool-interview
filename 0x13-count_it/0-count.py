#!/usr/bin/python3
'''Counts words count em!!!'''
from collections import Counter, defaultdict
import requests


def count_words(subreddit, word_list, res=defaultdict(int), after=None):
    '''Count words whooo'''
    agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36\
            (KHTML, like Gecko)\
            Chrome/86.0.4240.111 Safari/537.36"
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    if after:
        url += '?after={}'.format(after)
    r = requests.get(
        url,
        headers={"User-Agent": agent},
        allow_redirects=False
    ).json()
    for title in r.get('data').get('children'):
        c = Counter(title.get('data').get('title').lower().split(' '))
        for word in word_list:
            if word.lower() in c:
                res[word] += c.get(word.lower())
    after = r.get('data').get('after')
    if after:
        return count_words(subreddit, word_list, res, after)
    by_name = sorted(res.items(), key=lambda x: x[0])
    for k, v in sorted(by_name, key=lambda x: x[1], reverse=True):
        print('{}: {}'.format(k, v))
