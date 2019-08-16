#PIC16
#Assignment9W
#Li, Chak Yin (Anders)
#704950093

import scrapy

class PokemondbSpider(scrapy.Spider):
    name = 'pokemondb'
    start_urls = ['https://pokemondb.net/pokedex/national']

    def parse(self, response):
        pokemons = response.css('span.infocard-lg-data.text-muted')
        for pokemon in pokemons:
            dict = {
                'Number': pokemon.css('small::text').extract_first(),
                'Name': pokemon.css('a.ent-name::text').extract_first()
            }
            rel_url = pokemon.css('a.ent-name::attr(href)').extract_first()
            full_url = response.urljoin(rel_url)
            request = scrapy.Request(full_url, self.parse_page, meta = {'dict': dict})
            yield request

    def parse_page(self, response):
        dict = response.meta['dict']
        pokedex = response.css('div.resp-scroll tbody tr td.cell-med-text')
        dict['Pokedex Entry'] = pokedex.css('::text').extract_first()
        return dict
