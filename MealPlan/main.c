//gcc -o app app.c -I./cJSON -L./cJSON -lcurl -lcjson

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
// #include "/Users/karteikaydhuper/Desktop/Programming /Coursework/Systems-Programming-in-C/MealPlan/cJSON/cJSON.h"

// global variables with all the UI elements
GtkWidget *window;
GtkWidget *grid;
GtkWidget *field_label;
GtkWidget *text_field;
GtkWidget *diet_label;
GtkWidget *combo_box;
//GtkWidget *check1;
//GtkWidget *check2;
//GtkWidget *check3;
//GtkWidget *check4;
GtkWidget *button;
GtkWidget *text_area;
GtkTextBuffer *text_buffer;
gchar *input;
char *ingredients;
char *diet;

//struct curl_response {
//    char *data;
//    size_t len;
//};
//
//// This function will be called by cURL when data is received
//size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
//    struct curl_response *response = (struct curl_response *)userdata;
//    size_t realsize = size * nmemb;
//    response->data = realloc(response->data, response->len + realsize + 1);
//    if (response->data == NULL) {
//        fprintf(stderr, "write_callback(): realloc() failed\n");
//        return 0;
//    }
//    memcpy(&(response->data[response->len]), ptr, realsize);
//    response->len += realsize;
//    response->data[response->len] = '\0';
//    return realsize;
//}
//
//void curlParse(char *ingredients, char *diet)
//{
//    CURL *curl_handle;
//    CURLcode res;
//    struct curl_response response = {0};
//    char url[1024];
//
//    // Initialize cURL
//    curl_global_init(CURL_GLOBAL_ALL);
//
//    // Create a cURL handle
//    curl_handle = curl_easy_init();
//    if (!curl_handle) {
//        fprintf(stderr, "curl_easy_init() failed\n");
//        return;
//    }
//
//    snprintf(url, sizeof(url), "https://api.spoonacular.com/recipes/findByIngredients"
//                               "?apiKey=e86a2c9a1318492ea3faaea8ce9d58b3"
//                               "&ingredients=%s"
//                               "&diet=%s"
//                               "&number=1", ingredients, diet);
//    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
//    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
//    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&response);
//
//    // Perform the API request and handle any errors
//    res = curl_easy_perform(curl_handle);
//    if (res != CURLE_OK) {
//        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//        curl_easy_cleanup(curl_handle);
//        curl_global_cleanup();
//        return;
//    }
//
//    // Parse the JSON response using cJSON library
//    cJSON *root = cJSON_Parse(response.data);
//    if (!root) {
//        fprintf(stderr, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
//        free(response.data);
//        curl_easy_cleanup(curl_handle);
//        curl_global_cleanup();
//        return;
//    }
//
//    // Extract and print title
//    cJSON *recipe = cJSON_GetArrayItem(root, 0); // assuming data is the cJSON object containing the recipe data
//    cJSON *title = cJSON_GetObjectItem(recipe, "title");
//    printf("\nTitle: %s\n", title->valuestring);
//
//    printf("\nIngredients: \n");
//    cJSON *usedIngredients = cJSON_GetObjectItem(recipe, "usedIngredients");
//    for(int i = 0; i < cJSON_GetArraySize(usedIngredients); i++){
//        cJSON *usedIngredient = cJSON_GetArrayItem(usedIngredients, i);
//        cJSON *usedName = cJSON_GetObjectItem(usedIngredient, "original");
//        printf("%s\n", usedName->valuestring);
//    }
//
//    cJSON *missedIngredients = cJSON_GetObjectItem(recipe, "missedIngredients");
//    for(int i = 0; i < cJSON_GetArraySize(missedIngredients); i++) {
//        cJSON *missingIngredient = cJSON_GetArrayItem(missedIngredients, i);
//        cJSON *missingName = cJSON_GetObjectItem(missingIngredient, "original");
//        printf("%s\n", missingName->valuestring);
//    }
//    printf("\n");
//
//    cJSON_Delete(root);
//    free(response.data);
//
//    // Clean up the cURL handle and global resources
//    curl_easy_cleanup(curl_handle);
//    curl_global_cleanup();
//    return;
//}

char* remove_spaces(char* strin)
{
    int i,j;
    char *strout=strin;
    for (i = 0, j = 0; i<strlen(strin); i++,j++)
    {
        if (strin[i]!=' ')
            strout[j]=strin[i];
        else
            j--;
    }
    strout[j]=0;
    return strout;
}

/*
char ** separate_ing(char * str)
{
    char* tokens[50] = {0};

// Split the string in tokens and count the tokens:
    size_t tokenCount = 0;
    static size_t const max_token_count = sizeof(tokens) / sizeof(tokens[0]);
    for (char* token = strtok(str, ",");
         token != NULL  &&   tokenCount != max_token_count;
         token = strtok(NULL, ",")) {
        tokens[tokenCount++] = token;
    }

    for (size_t i = 0; i != tokenCount; ++i)
        puts(tokens[i]);

    return tokens;
}
*/

// Function called when the button is clicked
void on_button_clicked(GtkButton *button, gpointer data) {
    GtkTextView *text_view = GTK_TEXT_VIEW(data);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
    input = gtk_entry_get_text(text_field);
    ingredients = remove_spaces(input);
    //diet = gtk_combo_box_get_active_id(combo_box);
    diet = "[dietary restriction here]";
    printf("%s %s", ingredients, diet);
    // char ** ingredients = separate_ing(cleanstr);
    //curlParse(ingredients, diet);
    gtk_text_buffer_insert_at_cursor(buffer, "\n \nTitle: Baked Cinnamon Apple Slices\n"
                                             "\n"
                                             "Ingredients: \n"
                                             "4 Apples Sliced and Peeled – whatever type of apples I have in my refrigerator\n"
                                             "1 1/2 tablespoons of Cinnamon\n"
                                             "1/2 cup of Raisins", -1);
}

// Mainline logic fr
int main(int argc, char *argv[])
{

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
    //const gchar *ingredientData = gtk_entry_get_text(GTK_ENTRY(text_field));

    // create diet label
    diet_label = gtk_label_new("Check your dietary restrictions below: ");
    gtk_grid_attach(GTK_GRID(grid), diet_label, 0, 2, 2, 1);

    // Create dropdown menu
    combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "None");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Vegetarian");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Gluten-free");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Vegan");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Pescatarian");
    gtk_grid_attach(GTK_GRID(grid), combo_box, 0, 3, 2, 1);
    gtk_widget_set_hexpand(combo_box, TRUE);
    gtk_widget_set_halign(combo_box, GTK_ALIGN_FILL);


//    // Create checkboxes
//    check1 = gtk_check_button_new_with_label("Vegetarian");
//    gtk_grid_attach(GTK_GRID(grid), check1, 0, 3, 1, 1);
//    gtk_widget_set_hexpand(check1, TRUE);
//    gtk_widget_set_halign(check1, GTK_ALIGN_FILL);
//
//    check2 = gtk_check_button_new_with_label("Gluten free");
//    gtk_grid_attach(GTK_GRID(grid), check2, 1, 3, 1, 1);
//    gtk_widget_set_hexpand(check2, TRUE);
//    gtk_widget_set_halign(check2, GTK_ALIGN_FILL);
//
//    check3 = gtk_check_button_new_with_label("Vegan");
//    gtk_grid_attach(GTK_GRID(grid), check3, 0, 4, 1, 1);
//    gtk_widget_set_hexpand(check3, TRUE);
//    gtk_widget_set_halign(check3, GTK_ALIGN_FILL);
//
//    check4 = gtk_check_button_new_with_label("Pescatarian");
//    gtk_grid_attach(GTK_GRID(grid), check4, 1, 4, 1, 1);
//    gtk_widget_set_hexpand(check4, TRUE);
//    gtk_widget_set_halign(check4, GTK_ALIGN_FILL);

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
