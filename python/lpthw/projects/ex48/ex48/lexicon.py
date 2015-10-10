directions = ['north', 'south', 'east', 'west', 'down', 'up', 'left', 'right','back', 'forward']
verbs = ['go', 'stop', 'kill', 'eat']
stops = ['the', 'in', 'of', 'from', 'at', 'it']
nouns = ['door', 'bear', 'princess', 'cabinet']

def convert_numbers(s):
    try:
        return int(s)
    except ValueError:
        return None

def scan(string):
    words = string.split()
    sentence = []

    for word in words:
        if word in directions:
            sentence.append(('direction', word))
        elif word in verbs:
            sentence.append(('verb', word))
        elif word in stops:
            sentence.append(('stop', word))
        elif word in nouns:
            sentence.append(('noun', word))
        else:
            num = convert_numbers(word)
            if isinstance(num, int):
                sentence.append(('number', word))
            else:
                sentence.append(('error', word))
    return sentence
