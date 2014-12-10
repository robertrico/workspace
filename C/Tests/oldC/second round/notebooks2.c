#include <gtk/gtk.h>
#include <string.h>


static void destroy (GtkWidget*,gpointer);
static void switch_page (GtkButton*, GtkNotebook*);
const gchar* names [] = {"Prev","Next"};
const gchar* tabs [] = {"Page 0", "Page 1", "Page 2","Page 3","Page 4","Page 5","Page 6","Page 7","Page 8","Page 9","Page 10","Page 11","Page 12","Page 13","Page 14"};
const gchar* pages [] = {"","This is a page","And this is a page","This may also be a page","Guess what. Another page.","Pages a many","So many pages","PAGES PAGES PAGES","This can't be the last","No it isnt.","PAGES SO MANY PAGES","But will it work?","My guess is yes."};
const gint PAGE_NUM  = 12;
int main (int argc, char *argv[]){
	gint i;

	GtkWidget *window, *notebook;
	GtkWidget *hbox2 ,*hbox, *vbox;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Notebook");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	//gtk_widget_set_size_request (window, 610, 250);

	vbox = gtk_vbox_new (TRUE, 5);
	hbox = gtk_hbox_new (TRUE, 5);
	hbox2 = gtk_hbox_new (TRUE, 5);
	notebook = gtk_notebook_new ();
	
	
	for (i=1; i <= PAGE_NUM; i++){
		GtkWidget *label = gtk_label_new (tabs[i]);	
	    GtkWidget *child = gtk_label_new (pages[i]);	
		gtk_notebook_append_page (GTK_NOTEBOOK (notebook), child, label);
	}

	/* Notice that two widgets were connected to the same callback function! */
	g_signal_connect (G_OBJECT (window), "destroy",
					  G_CALLBACK(destroy), (gpointer) window);


	for (i=0; i < 2; i++){
		GtkWidget *button = gtk_button_new_with_label (names[i]);
		gtk_box_pack_start_defaults (GTK_BOX (hbox2), button);
		g_signal_connect (G_OBJECT (button), "clicked",
					  G_CALLBACK(switch_page),  (gpointer) notebook);
	}

	/* Append to pages to the notebook container.*/

	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);


	gtk_box_pack_start_defaults (GTK_BOX (hbox), notebook);
	gtk_box_pack_start_defaults (GTK_BOX (vbox), hbox);
	gtk_box_pack_start_defaults (GTK_BOX (vbox), hbox2);
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show_all (window);

	gtk_main();
	return 0;
}
	
static void destroy (GtkWidget *window, gpointer data){
	gtk_main_quit();
}

/* Switch pages*/
static void switch_page (GtkButton *button, GtkNotebook *notebook){
	gint page = gtk_notebook_get_current_page (notebook);

		if(strcmp(gtk_button_get_label(button),"Next") == 0){
			page++;
			if (page == PAGE_NUM){
				page = 0;
			}
			gtk_notebook_set_current_page (notebook, page);
		}else{
			page--;
			if (page < 0){
				page = PAGE_NUM-1;
			}
			gtk_notebook_set_current_page (notebook, page);
		}
	}
