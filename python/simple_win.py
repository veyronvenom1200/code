from PyQt5.QtCore    import pyqtSlot
from PyQt5.QtWidgets import QApplication, QWidget, QHBoxLayout, QVBoxLayout, QPushButton

class MainWindow(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        self.setWindowTitle('Pusher')
        Left = 500; Top = 200; Width = 225; Hight = 100
        self.setGeometry(Left, Top, Width, Hight)
        # -----
        self.btnPush = QPushButton('Push')
        self.btnPush.clicked.connect(self.Pushed)
        # -----
        HBox = QHBoxLayout()
        HBox.addStretch(1)
        HBox.addWidget(self.btnPush)
        HBox.addStretch(1)
        # -----
        VBox = QVBoxLayout()
        VBox.addStretch(1)
        VBox.addLayout(HBox)
        VBox.addStretch(1)
        # -----
        self.setLayout(VBox)

    @pyqtSlot()
    def Pushed(self):
        print('I was pushed')

if __name__ == '__main__':
    MainEventThread = QApplication([])

    MainApp = MainWindow()
    MainApp.show()

    MainEventThread.exec()