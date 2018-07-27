#参考:
# https://qiita.com/tkt989/items/84c6581dfa1d9a42dc2d
from icrawler.builtin import GoogleImageCrawler

crawler = GoogleImageCrawler(storage={"root_dir": "images"})
crawler.crawl(keyword="おぼれている人", max_num=50)
