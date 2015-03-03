#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int main (int   argc, char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://localhost:27017/");
    collection = mongoc_client_get_collection (client, "purls", "users");

    insert(client,collection);
    
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}
int insert(mongoc_client_t *client,mongoc_collection_t *collection){
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc;

    doc = bson_new ();
    bson_oid_init (&oid, NULL);
    BSON_APPEND_OID (doc, "_id", &oid);

    char buff[128];
    char str1[sizeof(buff)];
    char str2[sizeof(buff)];
    int count;
    int i;

    printf("How many entries?\n");
    fgets(buff,sizeof(buff),stdin);
    count = strtod(buff,NULL);

    for(i = 0; i <= count; i++){
        printf("Enter the Key\n");
        fgets(buff,sizeof(buff),stdin);
        strcpy(str1,strtok(buff,"\n"));

        printf("Enter the Value\n");
        fgets(buff,sizeof(buff),stdin);
        strcpy(str2,strtok(buff,"\n"));

        BSON_APPEND_UTF8 (doc, str1, str2);
    }

    if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
        printf ("Insert failed: %s\n", error.message);
    }

    bson_destroy (doc);

    doc = bson_new ();
    //BSON_APPEND_OID (doc, "_id", &oid);

    //if (!mongoc_collection_delete (collection, MONGOC_DELETE_SINGLE_REMOVE, doc, NULL, &error)) {
     //   printf ("Delete failed: %s\n", error.message);
    //}

    //Free Memory
    //bson_destroy (doc);
}
