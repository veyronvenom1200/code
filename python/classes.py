# class Employee:
#     empCount = 0

#     def __init__(self, name, salary):
#         self.name = name
#         self.salary = salary
#         Employee.empCount += 1

#     def displayCount(self):
#         print('total employee %d' % Employee.empCount)

#     def displayEmployee(self):
#         print('name:', self.name, ", salary:", self.salary)

# emp1 = Employee('Zara', 2000)

# emp1.displayCount()
# emp1.displayEmployee()

# emp1.age = 8
# print(emp1.age)

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton
from PyQt5.QtGui import QIcon, QPalette
from PyQt5.QtCore import pyqtSlot, Qt


class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 simple window - pythonspot.com'
        self.left = 10
        self.top = 10
        self.width = 640
        self.height = 480
        self.initUI()
        
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        button = QPushButton('pyqt button', self)
        button.setToolTip('This is an example button')
        button.move(100, 70)
        button.clicked.connect(self.on_click)
        app.setStyle("Fusion")
        qp = QPalette()
        qp.setColor(QPalette.Window, Qt.black)
        app.setPalette(qp)
        self.show()

    @pyqtSlot()
    def on_click(self):
        print('Pyqt button clicked')
    
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())