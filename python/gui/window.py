import sys
import os
from webbrowser import *
from PyQt4.QtGui import *
from PyQt4.QtCore import *

class Window(QMainWindow):
    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(50, 50, 400, 320)
        self.setWindowTitle("Youtube")

        extractAction = QAction("Exit", self)
        extractAction.setShortcut("Ctrl+Q")
        extractAction.setStatusTip('&Leave the App')
        extractAction.triggered.connect(self.close_application)

        openAction = QAction("New", self)
        openAction.setShortcut("Ctrl+N")
        openAction.setStatusTip('&New Window')
        openAction.triggered.connect(self.__init__)

        YoutubeAction = QAction("Open Youtube", self)
        YoutubeAction.triggered.connect(self.web)

        self.statusBar()

        mainMenu = self.menuBar()
        mainMenu.setNativeMenuBar(False)
        youtubeMenu = mainMenu.addMenu('&Youtube')
        youtubeMenu.addAction(YoutubeAction)
        fileMenu = mainMenu.addMenu('&File')
        fileMenu.addAction(openAction)
        fileMenu.addAction(extractAction)
        self.setStyleSheet("""QAction:hover:!pressed {
                           border: 1px solid blue;
                           }
                           QMenuBar{
                           background-color: #232323;
                           color: white
                           }

                            QMenuBar::item {
                            background: #232323;
                            }

                            QStatusBar{
                            background-color: #111111;
                            color: white
                           }

                            QStatusBar::item {
                            background: #111111;
                            }

                            Window {
                            background-color: #111111;
                            }""")

        self.home()

    def home(self):
        openBtn = QPushButton("Open Youtube", self)
        openBtn.clicked.connect(self.web)
        openBtn.setStyleSheet("""QPushButton{
                           background-color: #111111;
                           color: white
                           }""")

        self.setStyleSheet("""QStatusBar{
                            background-color: #111111;
                            color: white
                            }

                            QStatusBar::item {
                            background: #111111;
                            }
                                   """)
        openBtn.move(10, 30)
        openBtn.resize(openBtn.sizeHint())
        self.show()

    def web(self):
        webbrowser.open('https://www.youtube.com')

    def close_application(self):
        quit_msg = 'Are you sure that you want to quit?'
        reply = QMessageBox.question(self, 'Message', quit_msg, QMessageBox.Yes, QMessageBox.No)

        if reply == QMessageBox.Yes:
            sys.exit()
        else:
            pass


if __name__ == '__main__':
    app = QApplication(sys.argv)
    path = os.path.join(os.path.dirname(sys.modules[__name__].__file__), 'YouTubelogo.png')
    app.setWindowIcon(QIcon(path))
    gui = Window()
    palette = gui.palette()

    palette.setColor(gui.backgroundRole(), QColor(17, 17, 17))
    gui.setPalette(palette)
    sys.exit(app.exec_())
