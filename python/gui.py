import sys
from PyQt6.QtWidgets import (QWidget, QToolTip,
    QPushButton, QApplication)
from PyQt6.QtGui import QFont

class Example(QWidget):
	def __init__(self):
		super().__init__()
		self.asuna = "asuna"
		self.initUI()

	def initUI(self):
		qbtn = QPushButton('Quit', self)
		qbtn.clicked.connect(QApplication.instance().quit)
		qbtn.resize(qbtn.sizeHint())
		QToolTip.setFont(QFont('SansSerif', 10))
		self.setToolTip('This is a <b>QWidget</b> widget')
		btn = QPushButton('Button', self)
		btn.setToolTip('This is a QPushButton widget')
		btn.resize(btn.sizeHint())
		btn.move(50, 50)
		self.setGeometry(300, 300, 300, 200)
		self.setWindowTitle('Tooltips')
		self.show()

	def closeEvent(self, event):
		reply = QMessageBox.question(self, 'Message', "Are you sure to quit?", QMessageBox.Yes |
                    QMessageBox.No, QMessageBox.No)

		if reply == QMessageBox.StandardButton.Yes:
			event.accept()
		else:
			event.ignore()

def main():
	app = QApplication(sys.argv)
	ex = Example()
	print(ex.asuna)
	sys.exit(app.exec())


if __name__ == '__main__':
	main()