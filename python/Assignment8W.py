#PIC16
#Assignment8W
#Li, Chak Yin (Anders)
#704950093

from __future__ import division

#1
import nltk
import re
from nltk.corpus import wordnet as wn
from nltk.wsd import lesk
#nltk.download()
print "\n"

#2
from urllib import urlopen
url = 'http://www.gutenberg.org/files/863/863-0.txt'
response = urlopen(url)
raw = response.read().decode('utf8')

#3
start = raw.find('CHAPTER I. I GO TO STYLES')
end = raw.find('THE END')
book = raw[start:end+len('THE END')]

#4
print "#4"
fdist1 = nltk.FreqDist(book.split())
print fdist1

words2M = book.split()
wordFreq = {}
for i in words2M:
    if i not in wordFreq:
        wordFreq[i] = 0
    wordFreq[i] += 1

print '# of "foul" in fdsit1: {}'.format(fdist1['foul'])
print '# of "foul" in wordFreq: {}'.format(wordFreq['foul'])


def lexical_diversity(text):
    return len(set(text))/len(text)

print 'lexical diversity: {}'.format(lexical_diversity(words2M))

print '\n'

#5
print '#5'
new_book = re.sub('_', '', book)
new_words = nltk.tokenize.word_tokenize(new_book)
fdist2 = nltk.FreqDist(new_words)
print 'new lexical diversity (w/o "_"): {}'.format(lexical_diversity(new_words))

print '\n'

#6
print '#6'
lower_cased_words = [w.lower() for w in new_words]
fdist3 = nltk.FreqDist(lower_cased_words)
print 'new lexical diversity (letter case): {}'.format(lexical_diversity(lower_cased_words))
print '\n'

#7
porter = nltk.PorterStemmer()
vocab = [porter.stem(t) for t in lower_cased_words]
fdist4 = nltk.FreqDist(vocab)

#8
print '#8'
text = nltk.Text(new_words)
print text.concordance('point')
print '\n'

#9
print '#9'
point_synsets = wn.synsets('point')
print point_synsets

def word_appearance(word):
    lst = []
    sents = nltk.sent_tokenize(new_book)
    for i in sents:
        if i.find(word) >= 0:
            lst.append(i)
    return lst


sents = word_appearance('point')

for i in sents:
    print lesk(i,'point')


for i in sents:
    text = nltk.word_tokenize(i)
    speech_tagger = nltk.pos_tag(text)
    tag = ''
    for word in speech_tagger:
        if word[0].find('point') >= 0:
            if word[1] == 'NN' or word[1] == 'NNS':
                tag = 'n'
            elif word[1] == 'VBP' or word[1] == 'VB' or word[1] == 'VBD':
                tag = 'v'
            print lesk(i,'point',tag)
print '\n'

#10
print '#10'
print 'fdist2.most_common(30):',fdist2.most_common(30)
print '\n'

#11
print '#11'
freq_list = [(i,fdist2[i]) for i in fdist2]

sorted_freq_list = sorted(freq_list,key=lambda x:x[1], reverse=True)

print 'sorted_freq_list:',sorted_freq_list


regex = r'^[a-zA-Z]'
n = 0
for i in sorted_freq_list:
    if re.search(regex,i[0]) and n != 30:
        print '{}: {}'.format(i[0].encode('ascii','ignore'), i[1])
        n += 1
