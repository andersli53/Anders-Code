#PIC16
#Assignment10M
#Keith Atienza
#Li, Chak Yin (Anders) 704950093



import sys
import socket
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QTextEdit, QVBoxLayout, QSizePolicy, QLineEdit, QMessageBox       
# from PyQt5.QtGui import QPainter, QColor


class ChatWindow(QWidget):
    
    def __init__(self):
        super(ChatWindow, self).__init__()
        self.initUi()
        self.setServer()
        
        
    def initUi(self):
        self.setWindowTitle('Chat App')
        self.resize(350,130)
        
        self.textLabel = QLabel('started') # to display the message
        self.textBox = QLineEdit(self) #so enter can be pressed
        
        ###### for appearance only when window is resized #####
        self.layout = QVBoxLayout()
        self.textBox.setMaximumHeight(30)
        self.textBox.setSizePolicy(QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Maximum))
        self.layout.addWidget(self.textLabel)
        self.layout.addWidget(self.textBox)
        self.setLayout(self.layout)
        ##########################################################
        
        
        self.timer = QTimer()
        self.timer.setInterval(2000)
        self.timer.timeout.connect(self.receive)
        self.timer.start()
        
        self.textBox.returnPressed.connect(self.send)
        
    
    def setServer(self):
        self.mySocket = socket.socket()
        self.host = '127.0.0.1'
        self.port = 5001
        
        try:
            self.mySocket.connect((self.host, self.port))
            self.textLabel.setText('client <connected>')
            self.timer.start() 

        except:
            self.mySocket = socket.socket()
            self.mySocket.bind((self.host,self.port))
            self.mySocket.listen(1)            
            self.mySocket, addr = self.mySocket.accept()
            self.textLabel.setText('server <connected>')
            self.timer.start() 
    
    
    def receive(self):
        self.mySocket.settimeout(0.25)
        try:
            data = self.mySocket.recv(1024)
            if data == '<connection closed>':
                self.timer.stop() 
                self.textBox.returnPressed.disconnect(self.send)
            self.textLabel.setText(data)
        except:
            pass
    
    def send(self):
        try:
            self.mySocket.send(self.textBox.text())
        except:
            pass
        
    def closeEvent(self, event):
        self.mySocket.send('<connection closed>')
        self.mySocket.close() 


def main():
    
    app = QApplication(sys.argv)
    ex = ChatWindow()
    ex.show()
    app.exec_()   
    
    
if __name__ == "__main__":
    main()