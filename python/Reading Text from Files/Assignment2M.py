#PIC 16
#Assignment 2M
#Li, Chak Yin (Anders)
#704950093


sampleText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

words = sampleText.split(" ")

wordDict = {i : words.count(i) for i in words}

print "# of 'dolore' :", wordDict.get("dolore")

print "# of unique words :", len(set(words))


text = open('The Mysterious Affair at Styles.txt', 'r')

content = text.read()

wordList = content.split()

wordFreq = {}
for i in wordList:
    if i not in wordFreq:
        wordFreq[i] = 0
    wordFreq[i] += 1

print "# of 'found' :", wordFreq.get("found")

text.close()
