import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QTextEdit, QLineEdit
from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtGui import QColor, QTextCharFormat
from wordanalysis import colorcode as cc
from wordanalysis import wordcolorprocessing as wcp

class CustomLineEdit(QLineEdit):
    enter_pressed = pyqtSignal()

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Return or event.key() == Qt.Key_Enter:
            self.enter_pressed.emit()
        else:
            super().keyPressEvent(event)

def display_colored_text():
    input_text = line_edit.text()
    pos = wcp.words_to_color(input_text)
    print()
    delimiter = ''
    result = delimiter.join(pos)
    print(result)
    text_edit.setTextColor(cc.qcolors.PASTEL_PURPLE)
    text_edit.append(input_text + f" [{result}]")

def main():
    app = QApplication(sys.argv)

    window = QWidget()
    window.setWindowTitle("PyQt5 Colored Text Example")
    window.setGeometry(100, 100, 400, 200)

    layout = QVBoxLayout()

    global text_edit
    text_edit = QTextEdit()
    text_edit.setReadOnly(True)  # Make the QTextEdit read-only
    layout.addWidget(text_edit)

    global line_edit
    line_edit = CustomLineEdit()
    line_edit.enter_pressed.connect(display_colored_text)
    layout.addWidget(line_edit)

    window.setLayout(layout)
    window.show()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
