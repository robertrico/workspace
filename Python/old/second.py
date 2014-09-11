#!/usr/bin/env python
 
import pygtk
pygtk.require('2.0')
import gtk
 
class MyProgram:
 
    def __init__(self):
 
        # create a new window
 
        app_window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        app_window.set_size_request(500, 350)
        app_window.set_border_width(10)
        app_window.set_title("MY WINDOW")
        app_window.connect("delete_event", lambda w,e: gtk.main_quit())
 
        vbox_app = gtk.VBox(False,0)
        app_window.add(vbox_app)
        vbox_app.show()

        label_app = gtk.Label("WORDS GO HERE")
        label_app.show()
        vbox_app.pack_start(label_app,False,False,6)

        label_app2 = gtk.Label("HEROO WRRLD")
        label_app2.show()
        vbox_app.pack_start(label_app2,False,False,6)

        h_box = gtk.HBox(False,0)
        label_close = gtk.Label("Fuck You")
        label_close.show()

        h_2box = gtk.HBox(False,0)
        labeled_close = gtk.Label("Fuck Yous")
        labeled_close.show()

        labely_app = gtk.Label("GO HERE")
        labely_app.show()
        h_box.pack_start(labely_app,False,False,6)

        
        h_box.pack_start(label_close, True, True, 0)
        h_2box.pack_start(labeled_close, True, True, 0)
        
        h_box.show()
        h_2box.show()
        
        vbox_app.add(h_2box)
        vbox_app.add(h_box)



        button1 = gtk.Button("Fuck")
        button1.connect("pressed", lambda w: theworld())
        zbutton1.connect("released", lambda w: fucktheworld())
        h_box.pack_start(button1, True, True, 5)
        button1.show()
 		


        app_window.show()
 
        return
 
def main():
    gtk.main()
    return 0

def theworld():
	print "I am a man and "
def fucktheworld():
    print "I hate all the orphans in the world!"
 
if __name__ == "__main__":
    MyProgram()
    main()