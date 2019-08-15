#PIC 16
#Assignment 3W
#Li, Chak Yin (Anders)
#704950093

import copy

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    
    def __str__(self):
        return str(self.data)
    
    def __repr__(self):
        return repr(self.data)

    
    
class LinkedList:    
    def __init__(self, data):
        self.head = Node(data)
        self.first = self.head
        self.last = self.head
        self.n = 1
        
    def append(self, data):
        new_node = Node(data)
        current = self.head
        while current.next != None:
            current = current.next
        current.next = new_node
        self.n += 1
    
    def iterate(self):
        current = self.head
        while current is not None:
            yield current
            current = current.next
    
    def __iter__(self):
        current = self.head
        while current:
            yield current.data
            current = current.next

    
#    def next(self):
#        current = self.head
#        if current is None:
#            raise StopIteration()
#        result = current.data
#        current = current.next
#        return result
    
    def __len__(self):
        return self.n
    
    def __str__(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(str(current))
            current = current.next
        return '[' + '->'.join(nodes) + ']'

    def __repr__(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(repr(current))
            current = current.next
        return repr('[' + '->'.join(nodes) + ']')
    
    def __setitem__(self, index, data):
        if index > self.n:
            raise IndexError
        pos = 0
        current = self.head
        while pos < index:
            current = current.next
            pos += 1
        current.data = data
        
    def __getitem__(self, index):
        if index > self.n:
            raise IndexError
        pos = 0
        current = self.head
        while pos < index:
            current = current.next
            pos += 1
        return current.data
    
    
    def __add__(self,data):
        clone = copy.deepcopy(self)
        clone.append(data)
        return clone


a = LinkedList(0);
a.append(1)
a.append(2)
 
print "40 points if this works"
for n in a:
    print n
 
print ""
 
print "10 points if this works"
for n in a:
    print n
     
print ""
     
print "15 points if both of these work"
for n in a:
    if n == 2: # if you wrote your code for n.data == 2, that's OK too
        break
    else:
        print n
  
print ""
        
for n in a:
    if n == 2: 
        break
    else:
        print n
 
print ""
 
a.append(3)
a.append(4)
a.append(5)
a.append(6)
a.append(7)
a.append(8)
 
print ""
 
print "5 points each"
print len(a)
print str(a)
print repr(a)
 
print ""
 
print "5 points each. That is, 10 points if the output of the next line is correct"
a[5] = 20
print a[5]
 
print ""
 
print "10 points for correct operation of +"
a+9 # doesn't modify a
print a
 
print ""
 
a = a+9 # appends 9 to a
print a