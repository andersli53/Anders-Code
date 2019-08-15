#PIC 16
#Assignment 5M
#Li, Chak Yin (Anders)
#704950093

from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QPainter, QColor
from PyQt5.QtCore import Qt, QTimer

class Bounce(QWidget):
    def __init__(self):
        super(Bounce, self).__init__()

        self.diameter = 30
        self.x = 0
        self.y = 0


        self.x_velocity = 1
        self.y_velocity = 1

        self.timer = QTimer()
        self.timer.timeout.connect(self.animate)
        self.timer.start(30)

        self.initUI()



    def initUI(self):

        self.setGeometry(300, 300, 300, 400)
        self.setAutoFillBackground(True)
        p = self.palette()
        p.setColor(self.backgroundRole(), Qt.white)
        self.setPalette(p)
        self.setWindowTitle('Bouncing Ball')
        self.show()


    def paintEvent(self, event):
        qp = QPainter()
        qp.begin(self)
        qp.setBrush(QColor(255, 0, 0))
        qp.drawEllipse(self.x,self.y,self.diameter,self.diameter)
        qp.end()


    def animate(self):
        self.checkCollision()
        self.x += self.x_velocity
        self.y += self.y_velocity
        self.update()

    def checkCollision(self):
        if self.x < 0 or self.x > self.width() - self.diameter:
            self.x_velocity *= -1

        if self.y < 0 or self.y > self.height() - self.diameter:
            self.y_velocity *= -1

def main():
    app = QApplication([])
    bounce = Bounce()
    app.exec_()

if __name__ == "__main__":
    main()
