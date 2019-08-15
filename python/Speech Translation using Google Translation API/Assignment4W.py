#PIC 16
#Assignment 4W
#Li, Chak Yin (Anders)
#704950093

import requests
import json
import base64


with open("api_key.txt", "r") as f:
    api_key = f.read()


def speechTranslation(file_name, audioFormat, lang):
    with open(str(file_name), 'rb') as f:
        audioFile = base64.b64encode(f.read())
        
    config = {
            "encoding" : str(audioFormat),
            "sampleRateHertz" : 16000,
            "languageCode" : str(lang)
            }
    
    audio = {"content" : audioFile.decode('UTF8')}
    
    r = {"config" : config, "audio" : audio}
    
    speech_resource = r"https://speech.googleapis.com/v1/speech:recognize"
    speech_response = requests.post(speech_resource, data = json.dumps(r), params = {"key" : api_key})
    t = speech_response.text
    d = json.loads(t)
    transcript = d['results'][0]['alternatives'][0]['transcript']
    
    
    detect_resource = r"https://translation.googleapis.com/language/translate/v2/detect"
    r1 = {'q' : transcript}
    detect_response = requests.post(detect_resource, data = json.dumps(r1), params = {"key":api_key})
    t1 = detect_response.text
    d1 = json.loads(t1)
    detectedLang = d1['data']['detections'][0][0]['language']
    
    
    translate_resource = r"https://translation.googleapis.com/language/translate/v2"
    source = ''
    target = ''
    if detectedLang != 'en':
        source = detectedLang
        target = 'en'
    else:
        source = detectedLang
        target = 'zh-TW'
    r2 = {
            'q' : transcript,
            'source' : source,
            'target' : target,
            'format' : 'text'   
         }
    translate_response = requests.post(translate_resource, data = json.dumps(r2), params = {"key" : api_key})
    t2 = translate_response.text
    d2 = json.loads(t2)
    translatedText = d2['data']['translations'][0]['translatedText']
    print(translatedText)

speechTranslation("Name.ogg", "OGG_OPUS","yue-Hant-HK")
