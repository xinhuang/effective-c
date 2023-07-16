int do_something(void) {
    FILE *file1, *file2;
    object_t *obj;
    int ret_val = 0;

    file1 = fopen("a_file", "w");
    if (file1 == NULL) {
        puts("a_file failed to open");
        ret_val = -1;
        goto FAIL_FILE1;
    }

    file2 = fopen("another_file", "w");
    if (file2 == NULL) {
        puts("another_file failed to open");
        ret_val = -1;
        goto FAIL_FILE2;
    }

    obj = malloc(sizeof(object_t));
    if (obj == NULL) {
        puts("failed to allocate space for obj");
        ret_val = -1;
        goto FAIL_OBJ;
    }

    // do_something with allocated resources

    free(obj);
FAIL_OBJ:
    fclose(file2);
FAIL_FILE2:
    fclose(file1);
FAIL_FILE1:
    return ret_val;
}
