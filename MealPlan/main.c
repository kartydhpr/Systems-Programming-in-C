#include <gtk/gtk.h>

// Function called when the button is clicked
void on_button_clicked(GtkButton *button, gpointer data)
{
    GtkTextView *text_view = GTK_TEXT_VIEW(data);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
    gtk_text_buffer_insert_at_cursor(buffer, "[ Example recipe ]\n", -1);
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *field_label;
    GtkWidget *text_field;
    GtkWidget *diet_label;
    GtkWidget *check1;
    GtkWidget *check2;
    GtkWidget *check3;
    GtkWidget *check4;
    GtkWidget *button;
    GtkWidget *text_area;
    GtkTextBuffer *text_buffer;

    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "My Program");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // create  text label
    field_label = gtk_label_new("Type the ingredients you have access to below separated by commas: ");
    gtk_grid_attach(GTK_GRID(grid), field_label, 0, 0, 2, 1);

    // Create text field
    text_field = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), text_field, 0, 1, 2, 1);
    gtk_widget_set_hexpand(text_field, TRUE);
    gtk_widget_set_halign(text_field, GTK_ALIGN_FILL);

    // create diet label
    diet_label = gtk_label_new("Check your dietary restrictions below: ");
    gtk_grid_attach(GTK_GRID(grid), diet_label, 0, 2, 2, 1);

    // Create checkboxes
    check1 = gtk_check_button_new_with_label("Vegetarian");
    gtk_grid_attach(GTK_GRID(grid), check1, 0, 3, 1, 1);
    gtk_widget_set_hexpand(check1, TRUE);
    gtk_widget_set_halign(check1, GTK_ALIGN_FILL);

    check2 = gtk_check_button_new_with_label("Halal");
    gtk_grid_attach(GTK_GRID(grid), check2, 1, 3, 1, 1);
    gtk_widget_set_hexpand(check2, TRUE);
    gtk_widget_set_halign(check2, GTK_ALIGN_FILL);

    check3 = gtk_check_button_new_with_label("Kosher");
    gtk_grid_attach(GTK_GRID(grid), check3, 0, 4, 1, 1);
    gtk_widget_set_hexpand(check3, TRUE);
    gtk_widget_set_halign(check3, GTK_ALIGN_FILL);

    check4 = gtk_check_button_new_with_label("Pescatarian");
    gtk_grid_attach(GTK_GRID(grid), check4, 1, 4, 1, 1);
    gtk_widget_set_hexpand(check4, TRUE);
    gtk_widget_set_halign(check4, GTK_ALIGN_FILL);

    // Create button
    button = gtk_button_new_with_label("Find Recipes!");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 2, 1);
    gtk_widget_set_hexpand(button, TRUE);
    gtk_widget_set_halign(button, GTK_ALIGN_FILL);
    text_area = gtk_text_view_new();
    text_buffer = gtk_text_buffer_new(NULL);
    gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_area), text_buffer);
    gtk_grid_attach(GTK_GRID(grid), text_area, 0, 6, 2, 5);
    gtk_widget_set_hexpand(text_area, TRUE);
    gtk_widget_set_halign(text_area, GTK_ALIGN_FILL);

    // Connect button signal
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), text_area);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
