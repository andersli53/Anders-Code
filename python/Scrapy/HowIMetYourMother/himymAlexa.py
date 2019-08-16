#How I Met Your Mother alexa

import json

with open(r'C:\Users\Anders\Scrapy Projects\HowIMetYourMother\himym.json','r') as f:
    content = f.read()

d = json.loads(content)

len(d[0]['Name of Episodes']['Season2'])
d[0]['Air Date']['Duel Citizenship']
d[0]['Views']['Ring Up!']


l = [i for i in d[0]['Views'].keys() if float(d[0]['Views'][i]) > 10]
print l

def speech(text):
    outputSpeech = {'type': 'PlainText', 'text':text}
    r = {'outputSpeech': outputSpeech, 'shouldEndSession': True}
    response = {'version': '1.0', 'response': r}
    return response

def handler(event,content):
    if event['request']['type'] == 'LaunchRequest':
        return speech('Welcome to "How I Met Your Mother" info session.')

    elif event['request']['type'] == 'IntentRequest':
        if event['request']['intent']['name'] == 'AMAZON.HelpIntent':
            return speech('Ask me anything about "How I Met Your Mother".')
        elif event['request']['intent']['name'] == 'NameIntent':
            if 'value' in event['request']['intent']['slots']['episode'] and 'value' in event['request']['intent']['slots']['season']:
                season = event['request']['intent']['slots']['season']['value']
                episode = event['request']['intent']['slots']['episode']['value']
                return speech(str(d[0]['Name of Episodes']['Season'+season][episode-1]))
        elif event['request']['intent']['name'] == 'EpisodeIntent':
            if 'value' in event['request']['intent']['slots']['season']:
                season = event['request']['intent']['slots']['season']['value']
                num_of_ep = len(d[0]['Name of Episodes']['Season'+season])
                return speech(str(num_of_ep))
        elif event['request']['intent']['slots']['name'] == 'AirTimeIntent':
            if 'value' in event['request']['intent']['slots']['episode_name']:
                episode_name = event['request']['intent']['slots']['episode_name']['value']
                return speech(str(d[0]['Air Date'][episode_name]))
        elif event['request']['intent']['slots']['name'] == 'ViewsIntent':
            if 'value' in event['request']['intent']['slots']['views']:
                views = event['request']['intent']['slots']['views']['value']
                l = [i for i in d[0]['Views'].keys() if float(d[0]['Views'][i])>10]
                return speech(str(len(l)))
