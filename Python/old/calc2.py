#!/usr/bin/env python
 
import pygtk
pygtk.require('2.0')
import gtk
 
class MyProgram:

        

    def num(self,widget,x):
        globnum1 = x
        globnum2 = x+2
        print globnum1
        print globnum2
        
    
    def add(self,widget,x):
        global sign
        sign = x
        print sign

    def equals(self,widget,z):
        print z
        
 
    def __init__(self):

        global globnum1
        global globnum2
        global z
        z = 0
           
        # create a new window
 
        app_window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        app_window.set_size_request(500, 350)
        app_window.set_border_width(10)
        app_window.set_title("My Calculator")
        app_window.connect("delete_event", lambda w,e: gtk.main_quit())
 
        vbox_app = gtk.VBox(False,0)
        app_window.add(vbox_app)
        vbox_app.show()

        h_box = gtk.HBox(False,0)
        h_2box = gtk.HBox(False,0)
        h_3box = gtk.HBox(False,0)
        h_4box = gtk.HBox(False,0)
        h_5box = gtk.HBox(False,0)

        buttons = []
        
        for x in range(0, 5):
            buttons.extend("button"+str(x))
            buttons[x] = gtk.Button(str(x))
            h_3box.pack_start(buttons[x], True, True, 5)
            buttons[x].show()
            buttons[x].connect("clicked", self.num,x)


        for x in range(5, 9):
            buttons.extend("button"+str(x))
            buttons[x] = gtk.Button(str(x))
            h_4box.pack_start(buttons[x], True, True, 5)
            buttons[x].show()
            buttons[x].connect("clicked", self.num,x)
        
        signss = ["+","-","*","/"]
        signs = []
        for x in range(0, 4):
            signs.extend("button"+signss[x])
            signs[x] = gtk.Button(signss[x])
            h_5box.pack_start(signs[x], True, True, 5)
            signs[x].show()
            signs[x].connect("clicked", self.add,signss[x])

        equals = gtk.Button("=")
        h_5box.pack_start(equals, True, True, 5)
        equals.show()
        equals.connect("clicked", self.equals,z)


        
        h_box.show()
        h_2box.show()
        h_3box.show()
        h_4box.show()
        h_5box.show()
        
        
        vbox_app.add(h_3box)
        vbox_app.add(h_4box)
        vbox_app.add(h_5box)

        app_window.show()
 
        return
 
def main():
    gtk.main()
    return 0
 
if __name__ == "__main__":
    MyProgram()
    main()