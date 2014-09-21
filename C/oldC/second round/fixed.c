#include <gtk/gtk.h>


static void destroy (GtkWidget*,gpointer);
int main (int argc, char *argv[]){
	GtkWidget *window, *fixed, *button1, *button2, *button3;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Fixed");
	
	fixed = gtk_fixed_new();
	button1 = gtk_button_new_with_label ("Pixel by pixel...");
	button2 = gtk_button_new_with_label ("you choose my butt.");
	button3 = gtk_button_new_with_label ("and Lick it.");

	g_signal_connect_swapped (G_OBJECT (button1), "clicked", G_CALLBACK (destroy), (gpointer) window);
	g_signal_connect_swapped (G_OBJECT (button2), "clicked", G_CALLBACK (destroy), (gpointer) window);
	g_signal_connect_swapped (G_OBJECT (button3), "clicked", G_CALLBACK (destroy), (gpointer) window);

	/* Place two buttons on the GtkFixed Container */
	gtk_fixed_put (GTK_FIXED (fixed), button1, 0, 0);
	gtk_fixed_put (GTK_FIXED (fixed), button2, 20, 30);
	gtk_fixed_put (GTK_FIXED (fixed), button3, 70, 90);
	
	gtk_container_add (GTK_CONTAINER (window), fixed);
	gtk_widget_show_all (window);
	
	gtk_main();
	return 0;
}

static void destroy (GtkWidget *window, gpointer data){
	gtk_main_quit();
}
