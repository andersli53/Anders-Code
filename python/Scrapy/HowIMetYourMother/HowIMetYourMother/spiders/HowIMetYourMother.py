#How I Met Your Mother

import scrapy

class HowIMetYourMotherSpider(scrapy.Spider):
    name = "himym"
    start_urls = ["https://en.wikipedia.org/wiki/List_of_How_I_Met_Your_Mother_episodes"]

    def parse(self,response):
        table = response.css("table.wikitable.plainrowheaders.wikiepisodetable")
        number_of_seasons = len(table)
        air_date = {table[i].css('td.summary a::text')[j].extract(): table[i].css('tr.vevent td span.bday.dtstart.published.updated::text')[j].extract() for i in range(len(table)) for j in range(len(table[i].css('td.summary a::text').extract()))}
        name_of_episodes = {'Season'+str(i+1): table[i].css('td.summary a::text').extract() for i in range(len(table))}
        views = {table[i].css('td.summary a::text')[j].extract(): table[i].css('tr.vevent td:nth-child(8)::text')[j].extract() for i in range(len(table)) for j in range(len(table[i].css('td.summary a::text').extract()))}
        yield{
            'Name of Episodes': name_of_episodes,
            'Air Date': air_date,
            'Views': views
        }
