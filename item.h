#ifndef MODIFY_BROWN_ITEM_H
#define MODIFY_BROWN_ITEM_H

#define ITEM_KEY(item_ptr) ((Item*)item_ptr)->key
#define ITEM_KEY_LEN(item_ptr)  ((Item * )item_ptr)->key_len
#define ITEM_VALUE(item_ptr) ((Item * )item_ptr)->value
#define ITEM_VALUE_LEN(item_ptr)  ((Item * )item_ptr)->value_len


struct Item{
    char key[32];
    char value[32];
    uint32_t key_len;
    uint32_t value_len;
    //char buf[];
};



#endif //MODIFY_BROWN_ITEM_H
