void removeList(void* removeBlockPointer)
{
    //case 1: check if the list is empty
    if (free_listp == NULL){
        return;
    }
    //case 2: check if the user is remove the last element in the list
    else if (*removeBlockPointer == removeBlockPointer){
        free_listp = NULL;
        *removeBlockPointer = NULL;
        *(removeBlockPointer + DSIZE) = NULL;
    }
    //case 3: generic remove
    else {
        //check if user is removing the head of the list
        if (removeBlockPointer == free_listp){
            //the next block to what the user is trying to remove.
            free_listp = *(removeBlockPointer + DSIZE);
        }
        *(*(removeBlockPointer + DSIZE)) = *removeBlockPointer;
        **removeBlockPointer = *(removeBlockPointer + DSIZE);
    }
}