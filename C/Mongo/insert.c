#include "bson.h"
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
    bson_oid_t idd;
    bson_t *doc;
    bson_t *b;
    bson_t *nest;



/*Working */
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
/*Not Working */
    b = bson_new ();
    nest = bson_new ();
    bson_oid_init (&idd, NULL);


    char *arr[10] = {1,2,3,4,5,6,7,89,9};
    int k;
    for(k = 0 ; k < 10; k++){
        printf("%d\n",arr[k]);
    }

    BSON_APPEND_OID (b, "_id", &idd);

    /**
     * XXX
     * We have to attach a document, THEN append to it. Unless the bson object
     * is already made.
     * This is a tri nest document and works PERFECTLY.
     * Run and check robo mongo to see results
     * XXX
     */
    BSON_APPEND_DOCUMENT_BEGIN (b, "Wor", doc);
    BSON_APPEND_DOCUMENT_BEGIN (doc, "Gam", nest);
    BSON_APPEND_UTF8 (nest, "First", "Rob");
    BSON_APPEND_UTF8 (nest, "Last", "Samuelson");
    BSON_APPEND_UTF8 (nest, "Garen", "Worthlast");

    //Close the document appendage
    bson_append_document_end(doc,nest);
    //Close the document appendage
    bson_append_document_end(b,doc);

    if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, b, NULL, &error)) {
        printf ("Insert failed: %s\n", error.message);
    }

    bson_destroy(b);
/*End Not Working */
    bson_destroy (doc);

    doc = bson_new ();
    //BSON_APPEND_OID (doc, "_id", &oid);

    //if (!mongoc_collection_delete (collection, MONGOC_DELETE_SINGLE_REMOVE, doc, NULL, &error)) {
     //   printf ("Delete failed: %s\n", error.message);
    //}

    //Free Memory
    //bson_destroy (doc);
}
