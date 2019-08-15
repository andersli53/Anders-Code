#PIC16
#Assignment7M
#Li, Chak Yin (Anders)
#704950093

def lambda_handler(request, context):
    if request['request']['type'] == 'LaunchRequest':
        return speech('Hello World!')

    if request['request']['type'] == 'IntentRequest':
        if request['request']['intent']['name'] == 'AMAZON.HelpIntent':
            return speech('No help is available right now.')

        if request['request']['intent']['name'] == 'RandomNumberIntent':
            if 'value' in request['request']['intent']['slots']['low'] and 'value' in request['request']['intent']['slots']['high']:
                low = request['request']['intent']['slots']['low']['value']
                high = request['request']['intent']['slots']['high']['value']
                try:
                    return speech(str(random(int(low), int(high))))
                except ValueError as e:
                    if low == '?':
                        return speech(str(high))
                    elif high == '?':
                        return speech(str(low))
                    elif low == '?' and high == '?':
                        return speech('Sorry, I did not understand.')
            else:
                return speech(str(random(1,11)))

        if request['request']['intent']['name'] == 'DoArithmeticIntent':
            first_num = request['request']['intent']['slots']['first_num']
            second_num = request['request']['intent']['slots']['second_num']
            operation = request['request']['intent']['slots']['operation']
            session = request['session']
            if 'attributes' in request['session']:
                if 'second_num' in session['attributes'] and 'operation' in session['attributes']:
                    return speech(str(arithmetic(second_num['value'], session['attributes']['second_num'], session['attributes']['operation'])))
                elif 'first_num' in session['attributes'] and 'operation' in session['attributes']:
                    return speech(str(arithmetic(second_num['value'], session['attributes']['first_num'], session['attributes']['operation'])))
                elif 'second_num' not in session['attributes'] and 'first_num' not in session['attributes'] and 'operation' in session['attributes']:
                    return speech(str(arithmetic(first_num['value'], second_num['value'], session['attributes']['operation'])))
            else:
                try:
                    num1 = first_num['value']
                    num2 = second_num['value']
                    return speech(str(arithmetic (num1, num2, operation['value'])))

                except ValueError as e:
                    if first_num['value'] == '?' or 'value' not in first_num:
                        outputSpeech = {'type': 'PlainText', 'text': 'Excuse you! What was the first number?'}
                        r = {'outputSpeech': outputSpeech, 'shouldEndSession': False}
                        sessionAttributes = {'operation': operation['value'],'second_num': second_num['value']}
                        response = {'version': '1.0', 'response': r,  'sessionAttributes': sessionAttributes}
                        return response
                    elif second_num['value'] == '?' or 'value' not in second_num:
                        outputSpeech = {'type': 'PlainText', 'text': 'Excuse you! What was the second number?'}
                        r = {'outputSpeech': outputSpeech, 'shouldEndSession': False}
                        sessionAttributes = {'operation': operation['value'],'first_num': first_num['value']}
                        response = {'version': '1.0', 'response': r,  'sessionAttributes': sessionAttributes}
                        return response

                except KeyError as e:
                    if 'value' not in first_num and second_num['value'] == '?' or 'value' not in second_num and first_num['value'] == '?':
                        outputSpeech = {'type': 'PlainText', 'text': 'Sorry, I did not understand. What were the numbers again?'}
                        r = {'outputSpeech': outputSpeech, 'shouldEndSession': False}
                        sessionAttributes = {'operation': operation['value']}
                        response = {'version': '1.0', 'response': r,  'sessionAttributes': sessionAttributes}
                        return response
                    elif first_num['value'] != '?' and 'value' not in second_num:
                        outputSpeech = {'type': 'PlainText', 'text': 'Excuse you! What was the second number?'}
                        r = {'outputSpeech': outputSpeech, 'shouldEndSession': False}
                        sessionAttributes = {'operation': operation['value'],'first_num': first_num['value']}
                        response = {'version': '1.0', 'response': r,  'sessionAttributes': sessionAttributes}
                        return response
                    elif second_num['value'] != '?' and 'value' not in first_num:
                        outputSpeech = {'type': 'PlainText', 'text': 'Excuse you! What was the first number?'}
                        r = {'outputSpeech': outputSpeech, 'shouldEndSession': False}
                        sessionAttributes = {'operation': operation['value'],'second_num': second_num['value']}
                        response = {'version': '1.0', 'response': r,  'sessionAttributes': sessionAttributes}
                        return response
def random(num1, num2):
    import random
    return random.randint(num1, num2)

def speech(text):
    outputSpeech = {'type': 'PlainText', 'text': text}
    r = {'outputSpeech': outputSpeech, 'shouldEndSession': True}
    response = {'version': '1.0', 'response': r}
    return response

def arithmetic(num1, num2, operation):
    if operation == 'plus' or operation == 'add':
        result = int(num1) + int(num2)
    elif operation == 'minus' or operation =='subtract':
        result = int(num1) - int(num2)
    elif operation == 'times' or operation =='multiply':
        result = int(num1) * int(num2)
    elif operation == 'divided':
        result = float(num1)/float(num2)
    return result
