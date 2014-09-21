#include <gtk/gtk.h>


static void destroy (GtkWidget*,gpointer);

int main(int argc, char *argv[]){
	GtkWidget *window, *expander, *label, *label2, *button, *fixed;

	gtk_init(&argc,&argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	fixed = gtk_fixed_new();
	gtk_window_set_title (GTK_WINDOW (window), "Expanss");
	gtk_container_set_border_width (GTK_CONTAINER(window), 20);
	gtk_widget_set_size_request (window, 200,400);
	
	expander = gtk_expander_new_with_mnemonic ("Click _Me for More!");
	label = gtk_label_new ("Hide me or show me, \n that is your choice.");
	label2 = gtk_label_new ("WHATS KICKING BITCH");
	button = gtk_button_new_with_label ("CLICK IT");

	g_signal_connect_swapped (G_OBJECT (button), "clicked", G_CALLBACK (destroy), (gpointer) window);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_fixed_put (GTK_FIXED (fixed), button, 50, 50);
	gtk_fixed_put (GTK_FIXED (fixed), label, 90, 90);
	gtk_fixed_put (GTK_FIXED (fixed), label2, 100, 120);

	gtk_container_add (GTK_CONTAINER (expander), fixed);
	gtk_container_add (GTK_CONTAINER (window), expander);

	gtk_widget_show_all (window);

	gtk_main ();
	return 0;
}
static void destroy (GtkWidget *window, gpointer data){
	gtk_main_quit();
}
