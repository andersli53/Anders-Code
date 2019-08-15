#PIC 16
#Assignment 5W
#Li, Chak Yin (Anders)
#704950093

from PyQt5.QtWidgets import QApplication, QWidget, QColorDialog
from PyQt5.QtGui import QPainter, QColor
from PyQt5.QtCore import Qt

class Square(QWidget):
    def __init__(self):
        super(Square, self).__init__()

        self.square_x = 0
        self.square_y = 0
        self.velocity = 1
        self.r = 255
        self.g = 0
        self.b = 0
        self.square_size = 50
        self.difference_x = 0
        self.difference_y = 0
        self.initUI()

    def initUI(self):
        self.setGeometry(300,300,600,400)
        self.setWindowTitle("Assignment 5W")
        self.setAutoFillBackground(True)
        p = self.palette()
        p.setColor(self.backgroundRole(), Qt.white)
        self.setPalette(p)
        self.show()

    def paintEvent(self, event):
        qp = QPainter()
        qp.begin(self)
        qp.setBrush(QColor(self.r, self.g, self.b))
        qp.drawRect(self.square_x,self.square_y,self.square_size,
                                self.square_size)
        qp.end()

    def mousePressEvent(self, e):
        self.within = False
        if self.square_x <= e.x() <= self.square_x + self.square_size and self.square_y <= e.y() <= self.square_y + self.square_size:
            self.within = True
            self.difference_x = e.x() - self.square_x
            self.difference_y = e.y() - self.square_y

    def mouseMoveEvent(self, e):
        if self.within == True:
            self.square_x = e.x() - self.difference_x
            self.square_y = e.y() - self.difference_y
            self.animate()

    def mouseDoubleClickEvent(self, e):
        if self.square_x <= e.x() <= self.square_x + self.square_size and self.square_y <= e.y() <= self.square_y + self.square_size:
            self.colorDialog()

    def animate(self):
        self.square_x += self.velocity
        self.square_y += self.velocity
        self.update()

    def colorDialog(self):
        self.col = QColorDialog.getColor()
        if self.col.isValid():
            self.r  = self.col.red()
            self.g = self.col.green()
            self.b = self.col.blue()

        self.update()
def main():
    app = QApplication([])
    sq = Square()
    app.exec_()

if __name__ == "__main__":
    main()
