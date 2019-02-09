bool bin_search(const int list[], int listSize, int value){
    
    bool found = false;
    int first = 0;
    int middle;
    int last = listSize - 1;
    
    while (!found && first <= last){
        middle = (first + last) / 2;
        
        if (list[middle] == value)
            found = true;
        else if (list[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
        
        }
        return found;
    }
    return -1;
}


