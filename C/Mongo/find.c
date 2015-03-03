#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;
    bson_t q = BSON_INITIALIZER;
    const bson_t *doc;
    bson_t *query;
    char *str;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://localhost:27017/");
    collection = mongoc_client_get_collection (client, "purls", "users");
    query = bson_new ();

    char buff[128];
    char str1[sizeof(buff)];
    char str2[sizeof(buff)];

    printf("Search for what Key\n");
    fgets(buff,sizeof(buff),stdin);
    strcpy(str1,strtok(buff,"\n"));

    printf("Search for what Value\n");
    fgets(buff,sizeof(buff),stdin);
    strcpy(str2,strtok(buff,"\n"));

    //str1 IS THE KEY
    //str2 is the VALUE
    //REGEX SEARCH
    //case i_nsensitive

    BSON_APPEND_REGEX (&q, str1, str2, "i");
    //BSON_APPEND_UTF8 (query, str1, "Ro");

    cursor = mongoc_collection_find (collection, MONGOC_QUERY_NONE, 0, 0, 0, &q, NULL, NULL);

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }

    bson_destroy (query);
    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}
